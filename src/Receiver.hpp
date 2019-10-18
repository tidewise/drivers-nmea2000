#ifndef NMEA2000_RECEIVER_HPP
#define NMEA2000_RECEIVER_HPP

#include <utility>
#include <map>
#include <nmea2000/Message.hpp>
#include <nmea2000/PGNs.hpp>

namespace nmea2000 {
    class PGNLibrary;
    class PGNInfo;

    /**
     * Packet receiver and reassembly
     */
    class Receiver {
    public:
        enum State {
            /** Received message has a PGN we don't know about */
            UNKNOWN_PGN,
            /** Received message has an unexpected sequence number */
            INVALID_SEQUENCE_NUMBER,
            /**
             * Received message has been processed, and was part of a
             * multi-message group
             */
            PROCESSED,
            /** A message was fully reassembled. All values above this one
             * mean 'complete'
             */
            COMPLETE,
            /**
             * A message was fully reassembled, and it contained device
             * information
             */
            COMPLETE_DEVICE_INFO
        };

        /** Known information about a given device on the bus
         *
         * The class stores this information opportunistically
         * when a corresponding message is received by 'process'
         */
        struct DeviceInfo {
            uint8_t id;
            pgns::ISOAddressClaim address_claim;
            pgns::ProductInformation product_information;
        };

    private:
        PGNLibrary& m_library;

        /** Device information per bus-id */
        std::map<uint8_t, DeviceInfo> m_device_info;

        /** Internal state-tracking for packet reassembly */
        struct MessageState {
            Message message;
            int expected_size = 0;
            int current_count = 0;

            /** Create the MessageState from the first packet in a sequence
             */
            static MessageState fromFirst(Message const& msg, PGNInfo const& info);

            /** Append the data from a message to this message
             *
             * This does not test for compatibility. Tests regarding whether
             * this message does indeed follow the previous one are done in
             * Receiver::add
             *
             * @return true if we received as many messages as expected
             */
            State add(Message const& msg);
        };

        std::map<uint64_t, MessageState> m_reassembly;

        /** Return fast packet reassembly key for the given message
         */
        uint64_t getKey(Message const& msg);

        /** Possibly update internal structures based on information in this
         * complete message
         */
        State processCompleteMessage(Message const& msg);

    public:
        Receiver(PGNLibrary& library);

        /** Process a single message
         *
         * @return whether information about what happened to the message
         *   received. The Message will be invalid in LOST and COMPLETE
         *   states
         */
        std::pair<State, Message> process(Message const& msg);

        /** Query a given PGN
         *
         * @param destination the ID of the target of the query. Use 0xff for
         *   broadcast
         */
        static Message queryPGN(
            uint32_t pgn, uint8_t destination = 0xff, uint8_t source = 0
        );

        /** Query address information
         *
         * @param destination the ID of the target of the query. Use 0xff for
         *   broadcast
         */
        static Message queryAddressClaim(uint8_t destination = 0xff, uint8_t source = 0);

        /** Query product information
         *
         * @param target the ID of the target of the query. Do not broadcast it.
         */
        static Message queryProductInformation(uint8_t destination, uint8_t source = 0);

        /** Whether we have device information on the give bus ID */
        bool hasDeviceInformation(uint8_t id) const;

        /** Whether we have device information on the give bus ID
         *
         * @throw std::invalid_argument if there is no info for the given ID
         */
        DeviceInfo getDeviceInformation(uint8_t id) const;
    };
}

#endif