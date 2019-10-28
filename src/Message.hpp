#ifndef NMEA2000_MESSAGE_HPP
#define NMEA2000_MESSAGE_HPP

#include <base/Time.hpp>
#include <canbus/Message.hpp>

namespace nmea2000 {
    /** A NMEA2000 message */
    struct Message {
        static const int MAX_PAYLOAD_LENGTH = 223; // with fast packet
        static const int NO_DESTINATION = 0xFF; // with fast packet

        base::Time time;

        uint8_t priority = 0;
        uint8_t source = 0;
        uint8_t destination = 0;
        uint32_t pgn = 0;
        uint8_t size = 0;
        uint8_t payload[MAX_PAYLOAD_LENGTH];

        canbus::Message toCAN() const;
        static Message fromCAN(canbus::Message const& can);

        bool operator == (Message const& other) const;
    };
}

#endif