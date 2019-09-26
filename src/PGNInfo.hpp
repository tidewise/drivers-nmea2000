#ifndef NMEA2000_PGNINFO_HPP
#define NMEA2000_PGNINFO_HPP

#include <cstdint>

namespace nmea2000 {
    struct PGNInfo {
        uint32_t pgn;
        uint16_t size;

        bool isFastPacket() const;
    };
}

#endif