#include <nmea2000/Message.hpp>
#include <cstring>

using namespace nmea2000;

Message Message::fromCAN(canbus::Message const& can) {
    Message n2k;

    n2k.time = can.time;
    n2k.size = can.size;
    std::memcpy(n2k.payload, can.data, can.size);
    n2k.source   = can.can_id & 0xFF;
    n2k.priority = (can.can_id >> 26) & 0x7;

    bool pdu2 = 0xF0 == ((can.can_id >> 16) & 0xF0);
    if (pdu2) {
        // PDU2 format
        n2k.destination = NO_DESTINATION;
        n2k.pgn = (can.can_id >> 8) & 0x3FFFF;
    }
    else {
        // PDU1 format
        n2k.destination = (can.can_id >> 8) & 0xFF;
        n2k.pgn = (can.can_id >> 8) & 0x3FF00;
    }
    return n2k;
}

bool Message::operator == (Message const& other) const {
    return time == other.time &&
        priority == other.priority &&
        source == other.source &&
        destination == other.destination &&
        pgn == other.pgn &&
        size == other.size &&
        std::memcmp(payload, other.payload, size) == 0;
}