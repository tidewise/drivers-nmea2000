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
            0x10, 0x02, 0x93, 16,
            4, 5, 6, 7,    8, 9,    10, 11, 12, 13,
            4,    0x10, 0x11, 0x12, 0x13,
            97,
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
    ASSERT_EQ((vector<uint8_t> { 0x10, 0x11, 0x12, 0x13 }),
              vector<uint8_t>(message.payload, message.payload + 4));
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
    msg[msg.size() - 3] -= 1;
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