#include <nmea2000/Message.hpp>
#include <cstring>

using namespace nmea2000;

canbus::Message Message::toCAN() const {
    canbus::Message can;

    can.time = time;
    can.size = size;
    std::memcpy(can.data, payload, size);

    uint32_t can_id =
        source |
        (priority & 0x7) << 26 |
        pgn << 8;

    bool pdu2 = 0xF000 == (pgn & 0xF000);
    if (!pdu2) {
        can_id |= (static_cast<uint32_t>(destination) << 8);
    }
    can.can_id = can_id;
    return can;
}

Message Message::fromCAN(canbus::Message const& can) {
    Message n2k;

    n2k.time = can.time;
    n2k.size = can.size;
    std::memcpy(n2k.payload, can.data, can.size);
    n2k.source   = can.can_id & 0xFF;
    n2k.priority = (can.can_id >> 26) & 0x7;
    uint32_t pgn = (can.can_id >> 8) & 0x3FFFF;

    bool pdu2 = 0xF000 == (pgn & 0xF000);
    if (pdu2) {
        // PDU2 format
        n2k.destination = NO_DESTINATION;
        n2k.pgn = pgn;
    }
    else {
        // PDU1 format
        n2k.destination = pgn & 0xFF;
        n2k.pgn = pgn & 0x3FF00;
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