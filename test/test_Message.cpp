#include <gtest/gtest.h>
#include <nmea2000/Message.hpp>
#include <nmea2000/Receiver.hpp>

using namespace nmea2000;

struct MessageTest : public ::testing::Test {
    void assertEqual(char const* expected, uint8_t const* actual, std::size_t n)
    {
        for (std::size_t i = 0; i < n; i++) {
            EXPECT_EQ(expected[i], actual[i]);
        }
    }
};

TEST_F(MessageTest, it_initializes_a_Message_from_a_CAN_frame_in_PDU1) {
    // Example taken from https://michael.chtoen.com/convert-j1939-id-to-pgn.php
    uint32_t id = 0x1CEC523D;
    auto can = canbus::Message::Zeroed();
    can.can_id = id;
    Message msg = Message::fromCAN(can);
    ASSERT_EQ(0b111, msg.priority);
    ASSERT_EQ(60416, msg.pgn);
    ASSERT_EQ(0x52, msg.destination);
    ASSERT_EQ(0x3D, msg.source);
}

TEST_F(MessageTest, it_initializes_a_Message_from_a_CAN_frame_in_PDU2) {
    uint32_t id = 0xFFE6CEE;
    auto can = canbus::Message::Zeroed();
    can.can_id = id;
    Message msg = Message::fromCAN(can);

    ASSERT_EQ(0b011, msg.priority);
    ASSERT_EQ(0x3fe6c, msg.pgn);
    ASSERT_EQ(0xFF, msg.destination);
    ASSERT_EQ(238, msg.source);

}

TEST_F(MessageTest, it_copies_the_package_time_data_and_length) {
    auto can = canbus::Message::Zeroed();
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

TEST_F(MessageTest, it_creates_a_CAN_id_from_a_message_in_PDU1) {
    Message msg;
    msg.priority = 0b111;
    msg.pgn = 60416;
    msg.destination = 0x52;
    msg.source = 0x3d;
    auto can = msg.toCAN();
    ASSERT_EQ(1, can.size());
    ASSERT_EQ(0x1CEC523D | canbus::FLAG_EXTENDED_FRAME, can.at(0).can_id);
}

TEST_F(MessageTest, it_creates_a_CAN_id_from_a_message_in_PDU2) {
    Message msg;
    msg.priority = 0b011;
    msg.pgn = 0x3fe6c;
    msg.destination = 0xff;
    msg.source = 238;
    auto can = msg.toCAN();
    ASSERT_EQ(1, can.size());
    ASSERT_EQ(0xFFE6CEE | canbus::FLAG_EXTENDED_FRAME, can.at(0).can_id);
}

TEST_F(MessageTest, it_copies_the_package_time_data_and_length_to_the_CAN_frame) {
    Message msg;
    msg.time = base::Time::fromMilliseconds(1000);
    msg.size = 5;
    uint8_t data[5] = { 1, 2, 3, 4, 5 };
    memcpy(msg.payload, data, 5);

    std::vector<canbus::Message> to_can = msg.toCAN();
    ASSERT_EQ(1, to_can.size());
    auto const& can = to_can.at(0);
    ASSERT_EQ(base::Time::fromMilliseconds(1000), can.time);
    ASSERT_EQ(5, can.size);
    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(i + 1, can.data[i]);
    }
}

TEST_F(MessageTest, it_produces_fast_packet_messages)
{
    Message msg;
    msg.pgn = 0xf123;

    uint8_t payload[] = "first1second2third3";
    msg.size = sizeof(payload) - 1; // -1 -> do not copy '/0'
    std::copy((char*)&payload, (char*)&payload + msg.size, msg.payload);

    auto can = msg.toCAN();
    ASSERT_EQ(3, can.size());
    EXPECT_EQ(19, can.at(0).data[1]);

    ASSERT_EQ(8, can.at(0).size);
    EXPECT_EQ(0, can.at(0).data[0] & 0x1f);
    assertEqual("first1", &(can.at(0).data[2]), 6);

    ASSERT_EQ(8, can.at(1).size);
    EXPECT_EQ(1, can.at(1).data[0] & 0x1f);
    assertEqual("second2", &(can.at(1).data[1]), 7);

    ASSERT_EQ(7, can.at(2).size);
    EXPECT_EQ(2, can.at(2).data[0] & 0x1f);
    assertEqual("third3", &(can.at(2).data[1]), 6);

    PGNLibrary lib({
        {0xf123, msg.size}
    });

    Receiver recv(lib);
    auto[s0, m0] = recv.process(Message::fromCAN(can.at(0)));
    EXPECT_EQ(Receiver::State::PROCESSED, s0);

    auto[s1, m1] = recv.process(Message::fromCAN(can.at(1)));
    EXPECT_EQ(Receiver::State::PROCESSED, s1);

    auto[s2, m2] = recv.process(Message::fromCAN(can.at(2)));
    EXPECT_EQ(Receiver::State::COMPLETE, s2);
    ASSERT_EQ(19, m2.size);
    assertEqual("first1second2third3", m2.payload, 19);
}

TEST_F(MessageTest, it_increments_the_sequence_number)
{
    Message msg;

    uint8_t payload[] = "first1second2third3";
    msg.size = sizeof(payload) - 1; // -1 -> do not copy '/0'
    std::copy(payload, payload + msg.size, msg.payload);

    auto first = msg.toCAN();
    EXPECT_EQ(first.at(0).data[0] >> 5, first.at(1).data[0] >> 5);
    EXPECT_EQ(first.at(1).data[0] >> 5, first.at(2).data[0] >> 5);
    uint8_t first_seq_num = first.at(0).data[0] >> 5;

    auto second = msg.toCAN();
    uint8_t second_seq_num = (first_seq_num + 1) % 8;
    for(auto const& can_msg : second) {
        EXPECT_EQ(second_seq_num, can_msg.data[0] >> 5);
    }
}