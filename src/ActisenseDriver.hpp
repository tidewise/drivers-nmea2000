#ifndef NMEA2000_ACTISENSEDRIVER_HPP
#define NMEA2000_ACTISENSEDRIVER_HPP

#include <iodrivers_base/Driver.hpp>
#include <nmea2000/Message.hpp>

namespace nmea2000 {
    /**
     * Driver to read and write N2k frames from an Actisense gateway
     */
    class ActisenseDriver : public iodrivers_base::Driver {
    private:
        /**
         * Size of the package framing prologue (start byte, command and message
         * size)
         */
        static const uint8_t PROLOGUE_SIZE = 4;
        /** Size of the package framing epilogue (CRC + stop bytes)
         */
        static const uint8_t EPILOGUE_SIZE = 3;
        /** Size of the message header outside the Actisense packet framing
         */
        static const uint8_t HEADER_SIZE = 11;
        /** Size in bytes of the parts of prologue and epilogue that
         * need to be escaped
         */
        static const uint8_t ESCAPED_PROLOGUE_EPILOGUE_SIZE = 2;

        static const uint8_t ESCAPE = 0x10;
        static const uint8_t START_OF_TEXT = 0x02;
        static const uint8_t END_OF_TEXT = 0x03;

        static const uint8_t N2K_MSG_RECEIVED = 0x93;
        static const uint8_t ACTISENSE_CMD_RECEIVED = 0xA0;

    public:
        static const int MAX_RAW_MESSAGE_SIZE =
            Message::MAX_PAYLOAD_LENGTH + HEADER_SIZE;
        static const int MAX_ESCAPED_MESSAGE_SIZE =
            PROLOGUE_SIZE + EPILOGUE_SIZE +
            MAX_RAW_MESSAGE_SIZE * 2 +
            ESCAPED_PROLOGUE_EPILOGUE_SIZE;
        static const int INTERNAL_BUFFER_SIZE = MAX_ESCAPED_MESSAGE_SIZE * 4;

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