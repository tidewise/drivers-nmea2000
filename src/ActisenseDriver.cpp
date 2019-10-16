#include <nmea2000/ActisenseDriver.hpp>

using namespace nmea2000;

ActisenseDriver::ActisenseDriver()
    : iodrivers_base::Driver(INTERNAL_BUFFER_SIZE) {
}

int ActisenseDriver::extractPacket(uint8_t const* buffer, size_t buffer_size) const {
    if (buffer_size < 3) {
        return 0;
    }
    else if (buffer[0] != ESCAPE || buffer[1] != START_OF_TEXT) {
        return -1;
    }
    else if (buffer[2] != N2K_MSG_RECEIVED) {
        return -1;
    }

    for (size_t i = 2; i < buffer_size - 1; ++i) {
        if (buffer[i] == ESCAPE && buffer[i + 1] == START_OF_TEXT) {
            return -i;
        }
        if (buffer[i] == ESCAPE && buffer[i + 1] == END_OF_TEXT) {
            return validateFramedPacket(buffer, i + 2);
        }

    }

    return 0;
}

int ActisenseDriver::validateFramedPacket(uint8_t const* buffer, size_t length) const {
    // First validate the message length. We need to count the actual payload
    // bytes to compute the CRC anyways
    size_t count = 0;
    uint8_t crc = 0;
    for (size_t i = 2; i < length - EPILOGUE_SIZE; ++i, ++count) {
        uint8_t b = buffer[i];
        crc += b;
        if (b == ESCAPE) {
            ++i;
        }

        if (count == 12) {
            if (b + 11 != buffer[3]) {
                return -length;
            }
        }
    }
    count -= 2; // counted the command and length bytes

    if (((crc + buffer[length - EPILOGUE_SIZE]) & 0xFF) != 0) {
        return -length;
    }
    else if (count != buffer[3]) {
        return -length;
    }
    return length;
}

Message ActisenseDriver::readMessage() {
    uint8_t buffer[INTERNAL_BUFFER_SIZE];
    size_t length = readPacket(buffer, INTERNAL_BUFFER_SIZE);

    size_t out = 0;
    // Decode the ESCAPE + ESCAPE patterns once and for all
    // Only keep the "useful" parts
    for (size_t in = 2; in < length - 3; ++in, ++out) {
        uint8_t b = buffer[in];
        buffer[out] = b;
        if (b == ESCAPE) {
            ++in;
        }
    }

    Message message;
    message.time = base::Time::now();
    message.priority = buffer[2];
    message.pgn = buffer[3] |
                  static_cast<uint32_t>(buffer[4]) << 8 |
                  static_cast<uint32_t>(buffer[5]) << 16;
    message.destination = buffer[6];
    message.source = buffer[7];
    message.size = buffer[12];
    std::copy(buffer + 13, buffer + 13 + message.size, message.payload);

    return message;
}
