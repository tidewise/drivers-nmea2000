#include <gtest/gtest.h>
#include <cstring>

#include <nmea2000/Message.hpp>
#include <nmea2000/Receiver.hpp>
#include <nmea2000/PGNs.hpp>

using namespace std;
using namespace nmea2000;

struct CANWithReceiverTest : public ::testing::Test {
    PGNLibrary library;
    Receiver receiver;

    CANWithReceiverTest()
        : library(pgns::getLibrary())
        , receiver(library) {
    }

    canbus::Message makeCANMessage(uint32_t can_id, std::vector<uint8_t> const& data) {
        canbus::Message can;
        can.can_id = can_id;
        can.size = data.size();
        copy(data.begin(), data.end(), can.data);
        return can;
    }
};

TEST_F(CANWithReceiverTest, it_decodes_a_fluid_level_message_from_CAN) {
    canbus::Message can = makeCANMessage(
        0x19f21190,
        { 0x00, 0x3e, 0x49, 0xff, 0xff, 0xff, 0xff, 0xff }
    );

    auto state = receiver.process(Message::fromCAN(can));
    ASSERT_EQ(state.first, Receiver::COMPLETE);

    auto msg = state.second;
    ASSERT_EQ(msg.pgn, pgns::FluidLevel::ID);
    ASSERT_EQ(msg.source, 144);
    ASSERT_EQ(msg.destination, 0xff);

    auto fluid_level = pgns::FluidLevel::fromMessage(msg);
    ASSERT_EQ(75, fluid_level.level);
    ASSERT_FLOAT_EQ(-0.1, fluid_level.capacity);

}

TEST_F(CANWithReceiverTest, it_returns_an_address_claim_query) {
    auto can = receiver.queryAddressClaim().toCAN();
    auto expected = makeCANMessage(0x1CEAFF00, { 0, 0xee, 0 });
    ASSERT_EQ(can.can_id, expected.can_id);
    ASSERT_EQ(can.size, expected.size);
    ASSERT_EQ(vector<uint8_t>(can.data, can.data + can.size),
              vector<uint8_t>(expected.data, expected.data + can.size));
}

TEST_F(CANWithReceiverTest, it_returns_a_product_information_query) {
    auto can = receiver.queryProductInformation(144).toCAN();
    auto expected = makeCANMessage(0x1CEA9000, { 0x14, 0xf0, 0x1 });
    ASSERT_EQ(can.can_id, expected.can_id);
    ASSERT_EQ(can.size, expected.size);
    ASSERT_EQ(vector<uint8_t>(can.data, can.data + can.size),
              vector<uint8_t>(expected.data, expected.data + can.size));
}

TEST_F(CANWithReceiverTest, it_processes_an_address_claim_message) {
    // Note: message obtained by sniffing a bus with an actisense reader and
    // a KUS fluid level sensor
    canbus::Message can = makeCANMessage(
        0x18EEFF90,
        { 0xBE, 0x0A, 0x80, 0x50, 0x00, 0x96, 0x96, 0xC0 }
    );
    auto result = receiver.process(Message::fromCAN(can));
    ASSERT_EQ(result.first, Receiver::COMPLETE_DEVICE_INFO);

    Receiver::DeviceInfo info = receiver.getDeviceInformation(144);
    auto claim = info.address_claim;
    ASSERT_EQ(150, claim.device_function);
    ASSERT_EQ(75, claim.device_class);
    ASSERT_EQ(4, claim.industry_group);
}

TEST_F(CANWithReceiverTest, it_processes_a_product_information_message) {
    // Note: messages obtained by sniffing a bus with an actisense reader and
    // a KUS fluid level sensor
    vector<canbus::Message> messages {
        makeCANMessage(0x19F01490, { 0x20, 0x86, 0xD0, 0x07, 0xEE, 0x3A, 0x4E, 0x53 }),
        makeCANMessage(0x19F01490, { 0x21, 0x35, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00 }),
        makeCANMessage(0x19F01490, { 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }),
        makeCANMessage(0x19F01490, { 0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }),
        makeCANMessage(0x19F01490, { 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }),
        makeCANMessage(0x19F01490, { 0x25, 0x00, 0x00, 0x56, 0x31, 0x2E, 0x30, 0x31 }),
        makeCANMessage(0x19F01490, { 0x26, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }),
        makeCANMessage(0x19F01490, { 0x27, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }),
        makeCANMessage(0x19F01490, { 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }),
        makeCANMessage(0x19F01490, { 0x29, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x56 }),
        makeCANMessage(0x19F01490, { 0x2A, 0x31, 0x2E, 0x30, 0x31, 0x00, 0x00, 0x00 }),
        makeCANMessage(0x19F01490, { 0x2B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }),
        makeCANMessage(0x19F01490, { 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }),
        makeCANMessage(0x19F01490, { 0x2D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }),
        makeCANMessage(0x19F01490, { 0x2E, 0x00, 0x00, 0x00, 0x30, 0x30, 0x30, 0x32 }),
        makeCANMessage(0x19F01490, { 0x2F, 0x37, 0x35, 0x30, 0x00, 0x00, 0x00, 0x00 }),
        makeCANMessage(0x19F01490, { 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }),
        makeCANMessage(0x19F01490, { 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }),
        makeCANMessage(0x19F01490, { 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 })
    };

    canbus::Message final_message =
        makeCANMessage(0x19F01490, { 0x33, 0x01, 0x04, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF });

    for (auto msg : messages) {
        auto result = receiver.process(Message::fromCAN(msg));
        ASSERT_EQ(result.first, Receiver::PROCESSED);
    }

    auto result = receiver.process(Message::fromCAN(final_message));
    ASSERT_EQ(result.first, Receiver::COMPLETE_DEVICE_INFO);

    Receiver::DeviceInfo info = receiver.getDeviceInformation(144);
    auto product = info.product_information;
    ASSERT_EQ(2000, product.nmea_2000_version); // 2.000
    ASSERT_EQ("V1.01", product.software_version_code);
    ASSERT_EQ("V1.01", product.model_version);
    ASSERT_EQ("NS5", product.model_id);
    ASSERT_EQ("0002750", product.model_serial_code);
    ASSERT_EQ(1, product.certification_level);
    ASSERT_EQ(4, product.load_equivalency);
}
