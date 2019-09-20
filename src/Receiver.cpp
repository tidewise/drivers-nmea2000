#include <nmea2000/Receiver.hpp>
#include <nmea2000/PGNLibrary.hpp>
#include <cstring>

using namespace std;
using namespace nmea2000;

Receiver::Receiver(PGNLibrary& library)
    : m_library(library) {
}

uint64_t Receiver::getKey(Message const& msg) {
    return (msg.payload[0] >> 5 & 0x7) |
           static_cast<uint64_t>(msg.pgn) << 8 |
           static_cast<uint64_t>(msg.source) << 32 |
           static_cast<uint64_t>(msg.destination) << 40;
}

Receiver::State Receiver::MessageState::add(Message const& incoming) {
    int sequence_id = incoming.payload[0] & 0x1F;

    if (current_count != sequence_id) {
        return INVALID_SEQUENCE_NUMBER;
    }
    else if (expected_size < message.size + incoming.size - 1) {
        return TOO_MANY_BYTES;
    }

    memcpy(message.payload + message.size, incoming.payload + 1, incoming.size - 1);
    message.size += incoming.size - 1;
    current_count += 1;
    return current_count == total_count ? COMPLETE : PROCESSED;
}

Receiver::MessageState Receiver::MessageState::fromFirst(
    Message const& msg, PGNInfo const& info
) {
    MessageState state;
    state.message = msg;
    state.message.size -= 2;
    state.expected_size = info.size;
    memcpy(state.message.payload, msg.payload + 2, msg.size - 2);
    state.current_count = 1;
    state.total_count = msg.payload[1];
    return state;
}

pair<Receiver::State, Message> Receiver::process(Message const& msg) {
    uint64_t key = getKey(msg);

    auto it = m_reassembly.find(key);
    if (it == m_reassembly.end()) {
        int sequence_id = msg.payload[0] & 0x1F;
        PGNInfo const* info = m_library.find(msg.pgn);
        if (!info) {
            return make_pair(UNKNOWN_PGN, msg);
        }
        else if (!info->isFastPacket()) {
            return make_pair(COMPLETE, msg);
        }
        else if (sequence_id != 0) {
            return make_pair(INVALID_SEQUENCE_NUMBER, msg);
        }

        m_reassembly[key] = MessageState::fromFirst(msg, *info);
        return make_pair(PROCESSED, Message());
    }

    State state = it->second.add(msg);
    Message return_message;
    if (state == COMPLETE)
        return_message = it->second.message;
    else if (state != PROCESSED)
        return_message = msg;

    if (state != PROCESSED) {
        m_reassembly.erase(it);
    }
    return make_pair(state, return_message);

}
