#include <atomic>
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

std::vector<canbus::Message> Message::fastPacketFrames() const
{
    if (size <= MAX_CAN_PAYLOAD_SIZE || size > MAX_PAYLOAD_LENGTH) {
        throw std::invalid_argument(
            "Fast packet messages size must be grater than 8 bytes");
    }

    const uint8_t subsequent_size = size - FAST_PACKET_FIRST_PAYLOAD_LENGTH;
    const uint8_t subsequent_msgs =
        (subsequent_size + FAST_PACKET_SUBSEQUENT_PAYLOAD_LENGTH - 1) /
        FAST_PACKET_SUBSEQUENT_PAYLOAD_LENGTH;
    std::vector<canbus::Message> msgs(1 + subsequent_msgs);

    const uint8_t seq_num = fastPacketSequenceNumber();
    { // 0th frame
        canbus::Message& msg0 = msgs[0];
        msg0.data[0] = (seq_num << 5);
        msg0.data[1] = size;
        std::copy(payload, (payload + FAST_PACKET_FIRST_PAYLOAD_LENGTH), msg0.data + 2);
        msg0.size = 8;
    }

    uint8_t const* subsequent_payload = payload + FAST_PACKET_FIRST_PAYLOAD_LENGTH;
    for (uint8_t i = 0; i < subsequent_msgs; i++) {
        canbus::Message& msg = msgs[i + 1];
        msg.data[0] = (seq_num << 5) | (i + 1);

        const uint8_t n = FAST_PACKET_SUBSEQUENT_PAYLOAD_LENGTH;
        const uint8_t offset = i * n;
        const uint8_t this_payload_size = std::min<uint8_t>(n, subsequent_size - offset);
        std::copy(subsequent_payload + offset,
            subsequent_payload + offset + this_payload_size,
            msg.data + 1);
        msg.size = this_payload_size + 1;
    }

    return msgs;
}

std::uint8_t Message::fastPacketSequenceNumber()
{
    static std::atomic<uint8_t> seq{0};
    return (seq++) % 8;
}

Message Message::fromCAN(canbus::Message const& can)
{
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