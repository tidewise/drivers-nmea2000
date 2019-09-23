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
        static const uint8_t PRELUDE_SIZE = 4;
        static const uint8_t EPILOG_SIZE = 2;
        static const uint8_t HEADER_SIZE = 15;
        static const uint8_t ESCAPE = 0x10;
        static const uint8_t START_OF_TEXT = 0x02;
        static const uint8_t END_OF_TEXT = 0x03;
        static const uint8_t N2K_DATA_RECEIVED = 0x93;
        static const uint8_t BEM_CMD_RECEIVED = 0xA0;

    protected:
        virtual int extractPacket(uint8_t const* buffer, size_t buffer_size) const;

    public:
        ActisenseDriver();

        Message readMessage();
    };
}

#endif