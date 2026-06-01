#include <canbus/Message.hpp>
#include <cmath>
#include <cstring>
#include <nmea2000/Message.hpp>

using namespace nmea2000;

std::vector<canbus::Message> Message::toCAN() const
{
    std::vector<canbus::Message> msgs(0);
    if (fastPacket()) {
        msgs = fastPacketFrames();
    }
    else {
        canbus::Message can;
        can.size = size;
        std::memcpy(can.data, payload, size);
        msgs = {can};
    }

    const uint32_t can_id = canID();
    for (auto& can : msgs) {
        can.time = time;
        can.can_id = can_id;
    }

    return msgs;
}

uint32_t Message::canID() const
{
    uint32_t can_id = source | (priority & 0x7) << 26 | pgn << 8;

    bool pdu2 = 0xF000 == (pgn & 0xF000);
    if (!pdu2) {
        can_id |= (static_cast<uint32_t>(destination) << 8);
    }

    return can_id | canbus::FLAG_EXTENDED_FRAME;
}

bool Message::fastPacket() const
{
    return size > MAX_CAN_PAYLOAD_SIZE;
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