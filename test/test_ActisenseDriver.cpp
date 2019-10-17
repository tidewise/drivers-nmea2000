#include <gtest/gtest.h>
#include <iodrivers_base/FixtureGTest.hpp>

#include <vector>
#include <nmea2000/ActisenseDriver.hpp>

using namespace std;
using namespace nmea2000;

struct ActisenseDriverTest : public ::testing::Test,
                             public iodrivers_base::Fixture<ActisenseDriver> {
    ActisenseDriverTest() {
        driver.openURI("test://");
    }

    vector<uint8_t> getValidMessage() const {
        return {
            0x10, 0x02, /* Command */ 0x93,
            /* Message size */ 15,
            /* Priority */ 4,  /* PGN */ 5, 6, 7,
            /* destination */ 8, /* Source */ 9,
            /* ???? */ 10, 11, 12, 13,
            /* Payload size */ 4,
            /* payload */ 0x11, 0x12, 0x13, 0x14,
            187,
            0x10, 0x03
        };
    }

    vector<uint8_t> getValidEscapedMessage() const {
        return {
            0x10, 0x02, /* Command */ 0x93,
            /* Message size */ 0x10, 0x10,
            /* Priority */ 0x10, 0x10, /* PGN */ 5, 6, 7,
            /* destination */ 0x10, 0x10, /* Source */ 9,
            /* ???? */ 10, 11, 12, 13,
            /* Payload size */ 5,
            /* payload */ 0x10, 0x10, 0x11, 0x12, 0x13, 0x14,
            149,
            0x10, 0x03
        };
    }
};

TEST_F(ActisenseDriverTest, it_demarshals_a_valid_message) {
    pushDataToDriver(getValidMessage());
    auto message = driver.readMessage();
    ASSERT_EQ(4, message.priority);
    ASSERT_EQ(0x070605, message.pgn);
    ASSERT_EQ(8, message.destination);
    ASSERT_EQ(9, message.source);
    ASSERT_EQ(4, message.size);
    ASSERT_EQ((vector<uint8_t> { 0x11, 0x12, 0x13, 0x14 }),
              vector<uint8_t>(message.payload, message.payload + 4));
}

TEST_F(ActisenseDriverTest, it_handles_escapes) {
    pushDataToDriver(getValidEscapedMessage());
    auto message = driver.readMessage();
    ASSERT_EQ(0x10, message.priority);
    ASSERT_EQ(0x070605, message.pgn);
    ASSERT_EQ(0x10, message.destination);
    ASSERT_EQ(9, message.source);
    ASSERT_EQ(5, message.size);
    ASSERT_EQ((vector<uint8_t> { 0x10, 0x11, 0x12, 0x13, 0x14 }),
              vector<uint8_t>(message.payload, message.payload + 5));
}

TEST_F(ActisenseDriverTest, it_rejects_a_message_whose_length_is_not_sufficient_to_include_a_zero_byte_message) {
    vector<uint8_t> msg = {
        0x10, 0x02, 0x93, 11,
        4, 5, 6, 7,    8, 9,    10, 11, 12, 13,
        171,
        0x10, 0x03
    };
    pushDataToDriver(msg);
    ASSERT_THROW(driver.readMessage(), iodrivers_base::TimeoutError);
}

TEST_F(ActisenseDriverTest, it_rejects_a_message_whose_payload_length_does_not_match_the_message_length) {
    vector<uint8_t> msg = getValidMessage();
    msg[14] += 1;
    msg[msg.size() - 3] -= 1; // correct CRC
    pushDataToDriver(msg);
    ASSERT_THROW(driver.readMessage(), iodrivers_base::TimeoutError);
}

TEST_F(ActisenseDriverTest, it_rejects_a_message_with_escapes_whose_payload_length_does_not_match_the_message_length) {
    vector<uint8_t> msg = getValidEscapedMessage();
    msg[17] += 1;
    msg[msg.size() - 3] -= 1; // correct CRC
    pushDataToDriver(msg);
    ASSERT_THROW(driver.readMessage(), iodrivers_base::TimeoutError);
}

TEST_F(ActisenseDriverTest, it_rejects_a_message_whose_CRC_is_invalid) {
    vector<uint8_t> msg = getValidMessage();
    msg[msg.size() - 3] = 0;
    pushDataToDriver(msg);
    ASSERT_THROW(driver.readMessage(), iodrivers_base::TimeoutError);
}

TEST_F(ActisenseDriverTest, it_rejects_a_message_which_does_not_finish_with_escape_and_end_of_text_1) {
    vector<uint8_t> msg = getValidMessage();
    msg[msg.size() - 2] = 0;
    pushDataToDriver(msg);
    ASSERT_THROW(driver.readMessage(), iodrivers_base::TimeoutError);
}

TEST_F(ActisenseDriverTest, it_rejects_a_message_which_does_not_finish_with_escape_and_end_of_text_2) {
    vector<uint8_t> msg = getValidMessage();
    msg[msg.size() - 1] = 0;
    pushDataToDriver(msg);
    ASSERT_THROW(driver.readMessage(), iodrivers_base::TimeoutError);
}

TEST_F(ActisenseDriverTest, it_handles_partial_buffers) {
    vector<uint8_t> msg = getValidMessage();
    for (size_t i = 0; i < msg.size(); ++i) {
        ASSERT_THROW(driver.readMessage(), iodrivers_base::TimeoutError);
        pushDataToDriver(&msg[i], &msg[i + 1]);
    }
    driver.readMessage();
}

TEST_F(ActisenseDriverTest, it_handles_partial_buffers_with_escapes) {
    vector<uint8_t> msg = getValidEscapedMessage();
    for (size_t i = 0; i < msg.size(); ++i) {
        ASSERT_THROW(driver.readMessage(), iodrivers_base::TimeoutError);
        pushDataToDriver(&msg[i], &msg[i + 1]);
    }
    driver.readMessage();
}

TEST_F(ActisenseDriverTest, it_writes_down_a_command) {

    uint8_t message[4] = { 1, 2, 3, 4 };
    driver.writeCommand(ActisenseDriver::ACTISENSE_CMD_SEND, message, 4);
    auto bytes = readDataFromDriver();

    vector<uint8_t> expected {
        0x10, 0x02, 0xA1,
        4,
        1, 2, 3, 4,
        81,
        0x10, 0x03
    };
    ASSERT_EQ(expected, bytes);
}