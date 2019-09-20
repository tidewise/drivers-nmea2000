#include <gtest/gtest.h>
#include <nmea2000/Message.hpp>

using namespace nmea2000;

struct MessageTest : public ::testing::Test {
};

TEST_F(MessageTest, it_initializes_a_Message_from_a_CAN_frame_in_PDU1) {
    // Example taken from https://michael.chtoen.com/convert-j1939-id-to-pgn.php
    uint32_t id = 0x1CEC523D;
    canbus::Message can;
    can.can_id = id;
    Message msg = Message::fromCAN(can);
    ASSERT_EQ(0b111, msg.priority);
    ASSERT_EQ(60416, msg.pgn);
    ASSERT_EQ(0x52, msg.destination);
    ASSERT_EQ(0x3D, msg.source);
}

TEST_F(MessageTest, it_initializes_a_Message_from_a_CAN_frame_in_PDU2) {
    uint32_t id = 0xFFE6CEE;
    canbus::Message can;
    can.can_id = id;
    Message msg = Message::fromCAN(can);

    ASSERT_EQ(0b011, msg.priority);
    ASSERT_EQ(0x3fe6c, msg.pgn);
    ASSERT_EQ(0xFF, msg.destination);
    ASSERT_EQ(238, msg.source);

}

TEST_F(MessageTest, it_copies_the_package_time_data_and_length) {
    canbus::Message can;
    can.can_id = 0x1234;
    can.time = base::Time::fromMilliseconds(1000);
    can.size = 5;
    uint8_t data[5] = { 1, 2, 3, 4, 5 };
    memcpy(can.data, data, 5);

    Message msg = Message::fromCAN(can);
    ASSERT_EQ(base::Time::fromMilliseconds(1000), msg.time);
    ASSERT_EQ(5, msg.size);
    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(i + 1, msg.payload[i]);
    }
}
