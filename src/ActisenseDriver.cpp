#include <nmea2000/ActisenseDriver.hpp>
#include <nmea2000/PGNs.hpp>

using namespace nmea2000;

ActisenseDriver::ActisenseDriver()
    : iodrivers_base::Driver(INTERNAL_BUFFER_SIZE) {
}

static uint8_t STARTUP_SEQUENCE[] = {
    0x11, /* msg byte 1, meaning ? */
    0x02, /* msg byte 2, meaning ? */
    0x00  /* msg byte 3, meaning ? */
};

void ActisenseDriver::sendStartupSequence() {
    writeCommand(ACTISENSE_CMD_SEND, STARTUP_SEQUENCE, sizeof(STARTUP_SEQUENCE));
}

void ActisenseDriver::queryDeviceEnumeration() {
    Message iso_request;
    iso_request.priority = 1;
    iso_request.source = 255;
    iso_request.destination = 255;
    iso_request.pgn = pgns::ISORequest::ID;
    iso_request.size = 3;
    iso_request.payload[0] = (pgns::ISOAddressClaim::ID >> 16) & 0xFF;
    iso_request.payload[1] = (pgns::ISOAddressClaim::ID >> 8) & 0xFF;
    iso_request.payload[2] = (pgns::ISOAddressClaim::ID >> 0) & 0xFF;
    writeMessage(iso_request);
}

void ActisenseDriver::writeMessage(Message const& message) {
    uint8_t encoded[256];
    encoded[0] = message.priority;
    encoded[1] = message.pgn & 0xFF;
    encoded[2] = (message.pgn >> 8) & 0xFF;
    encoded[3] = (message.pgn >> 16) & 0xFF;
    encoded[4] = message.destination;
    encoded[5] = message.source;
    encoded[6] = 0;
    encoded[7] = 0;
    encoded[8] = 0;
    encoded[9] = 0;
    encoded[10] = message.size;
    std::copy(message.payload, message.payload + message.size, encoded + 11);

    writeCommand(N2K_MSG_SEND, encoded, message.size + 11);
}

void ActisenseDriver::writeCommand(uint8_t command, uint8_t const* message,
                                   uint8_t message_size) {
    uint8_t out_buffer[512];
    out_buffer[0] = ESCAPE;
    out_buffer[1] = START_OF_TEXT;
    out_buffer[2] = command;
    out_buffer[3] = message_size;

    uint8_t crc = command + message_size;
    uint8_t out = 4;
    if (message_size == ESCAPE) {
        out_buffer[out++] = ESCAPE;
    }

    for (uint8_t in = 0; in < message_size; ++in, ++out) {
        uint8_t b = message[in];
        out_buffer[out] = b;
        if (b == ESCAPE) {
            out_buffer[++out] = ESCAPE;
        }
        crc += b;
    }
    crc = 256 - (int)crc;
    out_buffer[out++] = crc;
    if (crc == ESCAPE) {
        out_buffer[out++] = ESCAPE;
    }
    out_buffer[out++] = ESCAPE;
    out_buffer[out++] = END_OF_TEXT;

    writePacket(out_buffer, out);
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
