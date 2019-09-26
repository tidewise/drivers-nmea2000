#ifndef NMEA2000_RECEIVER_HPP
#define NMEA2000_RECEIVER_HPP

#include <utility>
#include <map>
#include <nmea2000/Message.hpp>

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
            /** Received bytes in this stream is bigger than expected PGN size */
            TOO_MANY_BYTES,
            /**
             * Received message has been processed, and was part of a
             * multi-message group
             */
            PROCESSED,
            /** A message was fully reassembled
             */
            COMPLETE
        };

    private:
        PGNLibrary& m_library;

        /** Internal state-tracking for packet reassembly */
        struct MessageState {
            Message message;
            int expected_size = 0;
            int current_count = 0;
            int total_count = 0;

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

    public:
        Receiver(PGNLibrary& library);

        /** Process a single message
         *
         * @return whether information about what happened to the message
         *   received. The Message will be invalid in LOST and COMPLETE
         *   states
         */
        std::pair<State, Message> process(Message const& msg);
    };
}

#endif