#ifndef NMEA2000_ACTISENSEDRIVER_HPP
#define NMEA2000_ACTISENSEDRIVER_HPP

#include <iodrivers_base/Driver.hpp>
#include <nmea2000/Message.hpp>

namespace nmea2000 {
    /**
     * Driver to read and write N2k frames from an Actisense gateway
     */
    class ActisenseDriver : public iodrivers_base::Driver {
    public:
        static const int MAX_PACKET_SIZE = 262;
        static const int INTERNAL_BUFFER_SIZE = MAX_PACKET_SIZE * 4;

    private:
        static const uint8_t PROLOGUE_SIZE = 4;
        static const uint8_t EPILOGUE_SIZE = 3;
        static const uint8_t HEADER_SIZE = 15;
        static const uint8_t ESCAPE = 0x10;
        static const uint8_t START_OF_TEXT = 0x02;
        static const uint8_t END_OF_TEXT = 0x03;

        static const uint8_t N2K_MSG_RECEIVED = 0x93;
        static const uint8_t ACTISENSE_CMD_RECEIVED = 0xA0;

    public:
        static const uint8_t N2K_MSG_SEND = 0x94;
        static const uint8_t ACTISENSE_CMD_SEND = 0xA1;

    protected:
        virtual int extractPacket(uint8_t const* buffer, size_t buffer_size) const;
        int validateFramedPacket(uint8_t const* buffer, size_t length) const;

    public:
        ActisenseDriver();

        /** Send a message to tell the Actisense gateway that we want to receive
         */
        void sendStartupSequence();

        /** Query the product information of all devices on the bus */
        void queryDeviceEnumeration();

        /** Send a N2K message
         */
        void writeMessage(Message const& message);

        /** Send a command understood by the Actisense gateway itself
         *
         * @param command one of N2K_MSG_SEND or ACTISENSE_CMD_SEND
         * @param message the command payload
         * @param message_size number of bytes in \c message
         */
        void writeCommand(uint8_t command, uint8_t const* message,
                          uint8_t message_size);

        Message readMessage();
    };
}

#endif