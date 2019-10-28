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
    bool last_message = (message.size + incoming.size - 1 >= expected_size);
    size_t incoming_size =
        last_message ? expected_size - message.size : incoming.size - 1;

    memcpy(message.payload + message.size, incoming.payload + 1, incoming_size);
    message.size += incoming_size;
    current_count += 1;
    return last_message ? COMPLETE : PROCESSED;
}

Receiver::MessageState Receiver::MessageState::fromFirst(
    Message const& msg, PGNInfo const& info
) {
    MessageState state;
    state.message = msg;
    state.message.size -= 2;
    state.expected_size = msg.payload[1];
    memcpy(state.message.payload, msg.payload + 2, msg.size - 2);
    state.current_count = 1;
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
            auto state = processCompleteMessage(msg);
            return make_pair(state, msg);
        }
        else if (sequence_id != 0) {
            return make_pair(INVALID_SEQUENCE_NUMBER, msg);
        }

        m_reassembly[key] = MessageState::fromFirst(msg, *info);
        return make_pair(PROCESSED, Message());
    }

    State state = it->second.add(msg);
    Message return_message;
    if (state == COMPLETE) {
        return_message = it->second.message;
        state = processCompleteMessage(return_message);
    }
    else if (state != PROCESSED) {
        return_message = msg;
    }

    if (state != PROCESSED) {
        m_reassembly.erase(it);
    }
    return make_pair(state, return_message);
}

Receiver::State Receiver::processCompleteMessage(Message const& msg) {
    if (msg.pgn == pgns::ISOAddressClaim::ID) {
        auto& device_info = m_device_info[msg.source];
        device_info.id = msg.source;
        device_info.address_claim =
            pgns::ISOAddressClaim::fromMessage(msg);
        return COMPLETE_DEVICE_INFO;
    }
    else if (msg.pgn == pgns::ProductInformation::ID) {
        auto& device_info = m_device_info[msg.source];
        device_info.id = msg.source;
        device_info.product_information =
            pgns::ProductInformation::fromMessage(msg);
        return COMPLETE_DEVICE_INFO;
    }
    return COMPLETE;
}

Message Receiver::queryPGN(uint32_t pgn, uint8_t destination, uint8_t source) {
    Message iso_request;
    iso_request.priority = 7;
    iso_request.source = source;
    iso_request.destination = destination;
    iso_request.pgn = pgns::ISORequest::ID;
    iso_request.size = 3;
    iso_request.payload[0] = (pgn >> 0) & 0xFF;
    iso_request.payload[1] = (pgn >> 8) & 0xFF;
    iso_request.payload[2] = (pgn >> 16) & 0xFF;
    return iso_request;
}

Message Receiver::queryAddressClaim(uint8_t destination, uint8_t source) {
    return queryPGN(pgns::ISOAddressClaim::ID, destination, source);
}

Message Receiver::queryProductInformation(uint8_t target, uint8_t source) {
    return queryPGN(pgns::ProductInformation::ID, target, source);
}

bool Receiver::hasDeviceInformation(uint8_t id) const {
    return m_device_info.count(id);
}

Receiver::DeviceInfo Receiver::getDeviceInformation(uint8_t id) const {
    auto it = m_device_info.find(id);
    if (it == m_device_info.end()) {
        throw std::invalid_argument("no device information for ID " +
                                    std::to_string(id));
    }
    return it->second;
}
