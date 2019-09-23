#include <gtest/gtest.h>
#include <nmea2000/PGNs.hpp>

using namespace std;
using namespace nmea2000;
using namespace nmea2000::pgns;

struct PGNsTest : public ::testing::Test {
};

template<typename M>
M parse_message(vector<uint8_t> const& payload, int size = 0);

TEST_F(PGNsTest, it_generates_the_ID_constant) {
    ASSERT_EQ(59392, ISOAcknowledgement::ID);
}

TEST_F(PGNsTest, it_generates_the_size_constant) {
    ASSERT_EQ(8, ISOAcknowledgement::BYTE_LENGTH);
}

TEST_F(PGNsTest, it_throws_if_the_expected_and_actual_IDs_differ) {
    Message message;
    message.pgn = ISOAcknowledgement::ID + 1;
    message.size = ISOAcknowledgement::BYTE_LENGTH;
    ASSERT_THROW(ISOAcknowledgement::fromMessage(message), std::invalid_argument);
}

TEST_F(PGNsTest, it_throws_if_the_message_has_too_few_payload_bytes) {
    Message message;
    message.pgn = ISOAcknowledgement::ID;
    message.size = ISOAcknowledgement::BYTE_LENGTH - 1;
    ASSERT_THROW(ISOAcknowledgement::fromMessage(message), std::invalid_argument);
}

TEST_F(PGNsTest, it_throws_if_the_message_has_too_many_payload_bytes) {
    Message message;
    message.pgn = ISOAcknowledgement::ID;
    message.size = ISOAcknowledgement::BYTE_LENGTH + 1;
    ASSERT_THROW(ISOAcknowledgement::fromMessage(message), std::invalid_argument);
}



TEST_F(PGNsTest, it_parses_byte_aligned_positive_int8_fields) {
    auto parsed = parse_message<NMEARequestGroupFunction>(
        { 0x0F, 0, 0, 0, 0, 0, 0, 0, 0 }
    );
    ASSERT_EQ(15, parsed.function_code);
}

TEST_F(PGNsTest, it_parses_byte_aligned_negative_int8_fields) {
    auto parsed = parse_message<NMEARequestGroupFunction>(
        { 0xF0, 0, 0, 0, 0, 0, 0, 0, 0 }
    );
    ASSERT_EQ(-16, parsed.function_code);
}

TEST_F(PGNsTest, it_parses_byte_aligned_positive_int16_fields) {
    auto parsed = parse_message<NMEARequestGroupFunction>(
        { 0, 0, 0, 0, 0, 0, 0, 0x0F, 0x1E }
    );
    ASSERT_EQ(0x1E0F, parsed.parameter_value);
}

TEST_F(PGNsTest, it_parses_byte_aligned_negative_int16_fields) {
    auto parsed = parse_message<NMEARequestGroupFunction>(
        { 0, 0, 0, 0, 0, 0, 0, 0xF0, 0xE1 }
    );
    ASSERT_EQ(-0x1E0F - 1, parsed.parameter_value);
}

TEST_F(PGNsTest, it_parses_byte_aligned_positive_int32_fields) {
    auto parsed = parse_message<AISAssignmentModeCommand>(
        { 0, 0x01, 0x1E, 0x2C, 0x3D, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    );
    ASSERT_EQ(0x3D2C1E01, parsed.source_id);
}

TEST_F(PGNsTest, it_parses_byte_aligned_negative_int32_fields) {
    auto parsed = parse_message<AISAssignmentModeCommand>(
        { 0, 0xFE, 0xE1, 0xD3, 0xC2, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    );
    ASSERT_EQ(-0x3D2C1E01 - 1, parsed.source_id);
}

TEST_F(PGNsTest, it_parses_byte_aligned_uint8_fields) {
    auto parsed = parse_message<ISOAcknowledgement>(
        { 0, 4, 0, 0, 0, 0, 0, 0 }
    );
    ASSERT_EQ(4, parsed.group_function);
}

TEST_F(PGNsTest, it_parses_byte_aligned_uint8_fields_whose_value_would_not_fit_in_an_int8) {
    auto parsed = parse_message<ISOAcknowledgement>(
        { 0, 0xFF, 0, 0, 0, 0, 0, 0 }
    );
    ASSERT_EQ(255, parsed.group_function);
}

TEST_F(PGNsTest, it_parses_non_aligned_uint8_fields) {
    auto parsed = parse_message<SimnetConfigureTemperatureSensor>(
        { 0, 0b0011000 }
    );
    ASSERT_EQ(0b11, parsed.reserved);
}

TEST_F(PGNsTest, it_masks_non_aligned_uint8_fields_properly) {
    auto parsed = parse_message<SimnetConfigureTemperatureSensor>(
        { 0, 0b1111111 }
    );
    ASSERT_EQ(0b11, parsed.reserved);
}

TEST_F(PGNsTest, it_parses_byte_aligned_uint16_fields) {
    auto parsed = parse_message<MaretronSlaveResponse>(
        { 0, 0, 0x12, 0x34, 0, 0, 0, 0 }
    );
    ASSERT_EQ(0x3412, parsed.product_code);
}

TEST_F(PGNsTest, it_parses_byte_aligned_uint16_fields_whose_value_would_not_fit_in_an_int16) {
    auto parsed = parse_message<MaretronSlaveResponse>(
        { 0, 0, 0x12, 0xC4, 0, 0, 0, 0 }
    );
    ASSERT_EQ(0xC412, parsed.product_code);
}

TEST_F(PGNsTest, it_parses_non_aligned_uint16_fields) {
    auto parsed = parse_message<ISOCommandedAddress>(
        { 0, 0, 0xA0, 0xAA, 0, 0, 0, 0, 0, 0 }
    );
    ASSERT_EQ(0x555, parsed.manufacturer_code);
}

TEST_F(PGNsTest, it_masks_non_aligned_uint16_fields_properly) {
    auto parsed = parse_message<ISOCommandedAddress>(
        { 0, 0, 0xAF, 0xAA, 0, 0, 0, 0, 0, 0 }
    );
    ASSERT_EQ(0x555, parsed.manufacturer_code);
}

TEST_F(PGNsTest, it_parses_byte_aligned_uint32_fields) {
    auto parsed = parse_message<EngineParametersDynamic>(
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0x78, 0x56, 0x34, 0x12,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    );
    ASSERT_EQ(0x12345678, parsed.total_engine_hours);
}

TEST_F(PGNsTest, it_parses_byte_aligned_uint32_fields_whose_value_would_not_fit_in_an_int32) {
    auto parsed = parse_message<EngineParametersDynamic>(
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0x78, 0x56, 0x34, 0xC2,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    );
    ASSERT_EQ(0xC2345678, parsed.total_engine_hours);
}

TEST_F(PGNsTest, it_parses_non_aligned_uint32_fields) {
    auto parsed = parse_message<ISOAcknowledgement>(
        { 0, 0, 0, 0, 0, 0x12, 0x34, 0x56 }
    );
    ASSERT_EQ(0x563412, parsed.pgn);
}

TEST_F(PGNsTest, it_masks_non_aligned_uint32_fields_properly) {
    auto parsed = parse_message<ISOAcknowledgement>(
        { 0, 0, 0, 0, 0, 0x12, 0x34, 0x56, 0x78 }, 8
    );
    ASSERT_EQ(0x563412, parsed.pgn);
}



TEST_F(PGNsTest, it_parses_byte_aligned_Enum_fields) {
    auto parsed = parse_message<ISOAcknowledgement>(
        { 5, 0, 0, 0, 0, 0, 0, 0 }
    );
    ASSERT_EQ(5, parsed.control);
}

TEST_F(PGNsTest, it_parses_non_aligned_Enum_fields) {
    auto parsed = parse_message<ISOAddressClaim>(
        { 0, 0, 0, 0, 0, 0, 0xAA, 0 }
    );
    ASSERT_EQ(0x55, parsed.device_class);
}

TEST_F(PGNsTest, it_parses_positive_Dbl_fields_without_offset) {
    auto parsed = parse_message<AirmarDeviceInformation>(
        { 0, 0, 0, 0, 0, 0x12, 0x34, 0 }
    );
    ASSERT_FLOAT_EQ(0x3412 * 0.01, parsed.supply_voltage);
}

TEST_F(PGNsTest, it_parses_positive_Dbl_fields_with_offset) {
    auto parsed = parse_message<AirmarDeviceInformation>(
        { 0, 0, 0, 0, 0, 0x12, 0x34, 0 }
    );
    ASSERT_FLOAT_EQ(0x3412 * 0.01, parsed.supply_voltage);
}

TEST_F(PGNsTest, it_parses_negative_Dbl_fields) {
    auto parsed = parse_message<AirmarDeviceInformation>(
        { 0, 0, 0, 0, 0, 0x12, 0xC4, 0 }
    );
    ASSERT_FLOAT_EQ(-0x3BEE * 0.01, parsed.supply_voltage);
}

TEST_F(PGNsTest, it_parses_UDbl_fields_without_offset) {
    auto parsed = parse_message<SystemTime>(
        { 0, 0, 0, 0, 0x12, 0x34, 0, 0 }
    );
    ASSERT_FLOAT_EQ(0x3412 * 0.0001, parsed.time);
}

TEST_F(PGNsTest, it_parses_UDbl_fields_with_offset) {
    auto parsed = parse_message<AirmarDeviceInformation>(
        { 0, 0, 0, 0x12, 0x34, 0, 0, 0 }
    );
    ASSERT_FLOAT_EQ(0x3412 * 0.01 - 273.15, parsed.internal_device_temperature);
}

TEST_F(PGNsTest, it_parses_UDbl_fields_whose_values_would_not_fit_in_Dbl) {
    auto parsed = parse_message<AirmarDeviceInformation>(
        { 0, 0, 0, 0x12, 0xC4, 0, 0, 0 }
    );
    ASSERT_FLOAT_EQ(0xC412 * 0.01 - 273.15, parsed.internal_device_temperature);
}

TEST_F(PGNsTest, it_parses_zero_terminated_ASCII_fields) {
    auto parsed = parse_message<Datum>(
        { 'a', 'b', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    );
    ASSERT_EQ("ab", parsed.local_datum);
}

TEST_F(PGNsTest, it_parses_non_zero_terminated_ASCII_fields) {
    auto parsed = parse_message<Datum>(
        { 'a', 'b', 'c', 'd', 'e', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    );
    ASSERT_EQ("abcd", parsed.local_datum);
}

template<typename M>
M parse_message(vector<uint8_t> const& payload, int size) {
    Message message;
    message.pgn = M::ID;
    message.size = size == 0 ? payload.size() : size;
    std::copy(payload.begin(), payload.end(), message.payload);
    return M::fromMessage(message);
}
