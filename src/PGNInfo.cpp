#include <nmea2000/PGNInfo.hpp>

using namespace nmea2000;

bool PGNInfo::isFastPacket() const {
    return size > 8;
}