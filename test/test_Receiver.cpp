#include <gtest/gtest.h>
#include <nmea2000/PGNLibrary.hpp>
#include <nmea2000/Receiver.hpp>

using namespace nmea2000;


std::vector<PGNInfo> knownPGNs {
    { 1, 5 },
    { 2, 8 },
    { 3, 12 },
    { 4, 25 }
};

struct ReceiverTest : public ::testing::Test {
    PGNLibrary library;
    Receiver receiver;
    Message message;

    ReceiverTest()
        : library(knownPGNs)
        , receiver(library) {
    }
};

TEST_F(ReceiverTest, it_returns_a_single_packet_PGN_right_away) {
    Message message;
    message.pgn = 1;
    message.size = 5;
    auto result = receiver.process(message);
    ASSERT_EQ(Receiver::COMPLETE, result.first);
    ASSERT_EQ(message, result.second);
}

TEST_F(ReceiverTest, it_rejects_a_first_packet_whose_sequence_number_is_not_zero) {
    Message message;
    message.pgn = 3;
    message.size = 8;
    message.payload[0] = 0xA1;
    message.payload[1] = 2;
    auto result = receiver.process(message);
    ASSERT_EQ(Receiver::INVALID_SEQUENCE_NUMBER, result.first);
}

TEST_F(ReceiverTest, it_rejects_a_packet_whose_PGN_is_unknown) {
    Message message;
    message.pgn = 10;
    auto result = receiver.process(message);
    ASSERT_EQ(Receiver::UNKNOWN_PGN, result.first);
}

struct ReceiverFastPacketReassemblyTest : ReceiverTest {
    Message message;

    ReceiverFastPacketReassemblyTest() {
        message.time = base::Time::fromMilliseconds(1000);
        message.pgn = 3;
        message.size = 8;
        message.payload[0] = 0xA0;
        message.payload[1] = 12;
        for (int i = 0; i < 6; ++i) {
            message.payload[i + 2] = i;
        }
    }
};

TEST_F(ReceiverFastPacketReassemblyTest, it_reassembles_a_two_packet_PGN) {
    auto result = receiver.process(message);
    ASSERT_EQ(Receiver::PROCESSED, result.first);

    message.time = base::Time::fromMilliseconds(1100);
    message.size = 7;
    message.payload[0] = 0xA1;
    for (int i = 0; i < 7; ++i) {
        message.payload[i + 1] = 10 + i;
    }
    result = receiver.process(message);

    ASSERT_EQ(Receiver::COMPLETE, result.first);
    auto msg = result.second;
    ASSERT_EQ(base::Time::fromMilliseconds(1000), msg.time);
    ASSERT_EQ(3, msg.pgn);
    ASSERT_EQ(12, msg.size);
    for (int i = 0; i < 6; ++i) {
        ASSERT_EQ(i, msg.payload[i]);
        ASSERT_EQ(10 + i, msg.payload[6 + i]);
    }
}

TEST_F(ReceiverFastPacketReassemblyTest, it_rejects_a_second_packet_whose_sequence_number_is_unexpected) {
    receiver.process(message);

    message.size = 7;
    message.payload[0] = 0xA2;
    message.source = 10;
    auto result = receiver.process(message);
    ASSERT_EQ(Receiver::INVALID_SEQUENCE_NUMBER, result.first);
}

TEST_F(ReceiverFastPacketReassemblyTest, it_rejects_a_second_packet_whose_sequence_id_changed) {
    receiver.process(message);

    message.size = 7;
    message.payload[0] = 0xE1;
    auto result = receiver.process(message);

    ASSERT_EQ(Receiver::INVALID_SEQUENCE_NUMBER, result.first);
}

TEST_F(ReceiverFastPacketReassemblyTest, it_rejects_a_second_packet_whose_destination_changed) {
    receiver.process(message);

    message.size = 7;
    message.payload[0] = 0xA1;
    message.destination = 10;
    auto result = receiver.process(message);
    ASSERT_EQ(Receiver::INVALID_SEQUENCE_NUMBER, result.first);
}

TEST_F(ReceiverFastPacketReassemblyTest, it_rejects_a_second_packet_whose_source_changed) {
    receiver.process(message);

    message.size = 7;
    message.payload[0] = 0xA1;
    message.source = 10;
    auto result = receiver.process(message);
    ASSERT_EQ(Receiver::INVALID_SEQUENCE_NUMBER, result.first);
}

TEST_F(ReceiverFastPacketReassemblyTest, it_truncates_the_last_message_size_to_the_expected_size) {
    receiver.process(message);

    message.size = 10;
    message.payload[0] = 0xA1;
    message.payload[7] = rand();
    message.payload[8] = rand();
    message.payload[9] = rand();
    auto result = receiver.process(message);
    ASSERT_EQ(Receiver::COMPLETE, result.first);
    for (int i = 0; i < 3; ++i) {
        ASSERT_NE(message.payload[7 + i], result.second.payload[12 + i]);
    }
}