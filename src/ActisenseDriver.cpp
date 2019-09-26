#include <nmea2000/ActisenseDriver.hpp>

using namespace nmea2000;

ActisenseDriver::ActisenseDriver()
    : iodrivers_base::Driver(INTERNAL_BUFFER_SIZE) {
}

int ActisenseDriver::extractPacket(uint8_t const* buffer, size_t buffer_size) const {
    if (buffer_size < PRELUDE_SIZE) {
        return 0;
    }

    if (buffer[0] != ESCAPE ||
        buffer[1] != START_OF_TEXT ||
        buffer[2] != N2K_DATA_RECEIVED) {
        return -1;
    }

    uint8_t message_length = buffer[3];
    if (message_length < HEADER_SIZE - PRELUDE_SIZE + 1) {
        return -1;
    }

    size_t epilog_index = PRELUDE_SIZE + message_length;
    if (buffer_size < epilog_index + EPILOG_SIZE) {
        return 0;
    }
    else if (buffer[epilog_index] != ESCAPE ||
             buffer[epilog_index + 1] != END_OF_TEXT) {
        return -1;
    }

    uint8_t payload_length = buffer[14];
    if (payload_length != message_length - 12) {
        return -1; // two lengths do not agree
    }

    int sum = 0;
    for (size_t i = PRELUDE_SIZE; i < epilog_index; ++i) {
        sum += buffer[i];
    }
    if ((sum & 0xFF) != 0) { // invalid CRC
        return -1;
    }

    return PRELUDE_SIZE + message_length + EPILOG_SIZE;
}

Message ActisenseDriver::readMessage() {
    uint8_t buffer[INTERNAL_BUFFER_SIZE];
    readPacket(buffer, INTERNAL_BUFFER_SIZE);

    Message message;
    message.time = base::Time::now();
    message.priority = buffer[4];
    message.pgn = buffer[5] |
                  static_cast<uint32_t>(buffer[6]) << 8 |
                  static_cast<uint32_t>(buffer[7]) << 16;
    message.destination = buffer[8];
    message.source = buffer[9];
    message.size = buffer[14];
    std::copy(buffer + 15, buffer + 15 + message.size, message.payload);
    return message;
}
