#include <cmath>
#include <gtest/gtest.h>
#include <nmea2000/PGNs.hpp>

using namespace std;
using namespace nmea2000;
using namespace nmea2000::pgns;

struct PGNsTest : public ::testing::Test {};

template <typename M>
M parse_message(vector<uint8_t> const& payload,
    int size = 0,
    base::Time const& time = base::Time::now());

TEST_F(PGNsTest, it_generates_the_ID_constant)
{
    ASSERT_EQ(59392, ISOAcknowledgement::ID);
}

TEST_F(PGNsTest, it_generates_the_size_constant)
{
    ASSERT_EQ(8, ISOAcknowledgement::BYTE_LENGTH);
}

TEST_F(PGNsTest, it_throws_if_the_expected_and_actual_IDs_differ)
{
    Message message;
    message.pgn = ISOAcknowledgement::ID + 1;
    message.size = ISOAcknowledgement::BYTE_LENGTH;
    ASSERT_THROW(ISOAcknowledgement::fromMessage(message), std::invalid_argument);
}

TEST_F(PGNsTest, it_throws_if_the_message_has_too_few_payload_bytes)
{
    Message message;
    message.pgn = ISOAcknowledgement::ID;
    message.size = ISOAcknowledgement::BYTE_LENGTH - 1;
    ASSERT_THROW(ISOAcknowledgement::fromMessage(message), std::invalid_argument);
}

TEST_F(PGNsTest, it_lets_the_message_have_too_many_payload_bytes)
{
    Message message;
    message.pgn = ISOAcknowledgement::ID;
    message.size = ISOAcknowledgement::BYTE_LENGTH + 1;
    ISOAcknowledgement::fromMessage(message);
}

TEST_F(PGNsTest, it_forwards_the_time_field)
{
    auto time = base::Time::fromSeconds(10);
    auto parsed =
        parse_message<NMEARequestGroupFunction>({0x0F, 0, 0, 0, 0, 0, 0, 0, 0}, 9, time);
    ASSERT_EQ(time, parsed.time);
}

TEST_F(PGNsTest, it_parses_byte_aligned_positive_int8_fields)
{
    auto parsed = parse_message<NMEARequestGroupFunction>({0x0F, 0, 0, 0, 0, 0, 0, 0, 0});
    ASSERT_EQ(15, parsed.function_code);
}

TEST_F(PGNsTest, it_parses_byte_aligned_negative_int8_fields)
{
    auto parsed = parse_message<NMEARequestGroupFunction>({0xF0, 0, 0, 0, 0, 0, 0, 0, 0});
    ASSERT_EQ(-16, parsed.function_code);
}

TEST_F(PGNsTest, it_parses_byte_aligned_positive_int16_fields)
{
    auto parsed =
        parse_message<NMEARequestGroupFunction>({0, 0, 0, 0, 0, 0, 0, 0x0F, 0x1E});
    ASSERT_EQ(0x1E0F, parsed.parameter_value);
}

TEST_F(PGNsTest, it_parses_byte_aligned_negative_int16_fields)
{
    auto parsed =
        parse_message<NMEARequestGroupFunction>({0, 0, 0, 0, 0, 0, 0, 0xF0, 0xE1});
    ASSERT_EQ(-0x1E0F - 1, parsed.parameter_value);
}

TEST_F(PGNsTest, it_parses_byte_aligned_positive_int32_fields)
{
    auto parsed = parse_message<AISAssignmentModeCommand>(
        {0, 0x01, 0x1E, 0x2C, 0x3D, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    ASSERT_EQ(0x3D2C1E01, parsed.source_id);
}

TEST_F(PGNsTest, it_parses_byte_aligned_negative_int32_fields)
{
    auto parsed = parse_message<AISAssignmentModeCommand>(
        {0, 0xFE, 0xE1, 0xD3, 0xC2, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    ASSERT_EQ(-0x3D2C1E01 - 1, parsed.source_id);
}

TEST_F(PGNsTest, it_parses_byte_aligned_uint8_fields)
{
    auto parsed = parse_message<ISOAcknowledgement>({0, 4, 0, 0, 0, 0, 0, 0});
    ASSERT_EQ(4, parsed.group_function);
}

TEST_F(PGNsTest, it_parses_byte_aligned_uint8_fields_whose_value_would_not_fit_in_an_int8)
{
    auto parsed = parse_message<ISOAcknowledgement>({0, 0xFF, 0, 0, 0, 0, 0, 0});
    ASSERT_EQ(255, parsed.group_function);
}

TEST_F(PGNsTest, it_parses_non_aligned_uint8_fields)
{
    auto parsed = parse_message<SimnetConfigureTemperatureSensor>({0, 0b0011000});
    ASSERT_EQ(0b11, parsed.reserved);
}

TEST_F(PGNsTest, it_masks_non_aligned_uint8_fields_properly)
{
    auto parsed = parse_message<SimnetConfigureTemperatureSensor>({0, 0b1111111});
    ASSERT_EQ(0b11, parsed.reserved);
}

TEST_F(PGNsTest, it_parses_byte_aligned_uint16_fields)
{
    auto parsed = parse_message<MaretronSlaveResponse>({0, 0, 0x12, 0x34, 0, 0, 0, 0});
    ASSERT_EQ(0x3412, parsed.product_code);
}

TEST_F(PGNsTest,
    it_parses_byte_aligned_uint16_fields_whose_value_would_not_fit_in_an_int16)
{
    auto parsed = parse_message<MaretronSlaveResponse>({0, 0, 0x12, 0xC4, 0, 0, 0, 0});
    ASSERT_EQ(0xC412, parsed.product_code);
}

TEST_F(PGNsTest, it_parses_non_aligned_uint16_fields)
{
    auto parsed =
        parse_message<ISOCommandedAddress>({0, 0, 0xA0, 0xAA, 0, 0, 0, 0, 0, 0});
    ASSERT_EQ(0x555, parsed.manufacturer_code);
}

TEST_F(PGNsTest, it_masks_non_aligned_uint16_fields_properly)
{
    auto parsed =
        parse_message<ISOCommandedAddress>({0, 0, 0xAF, 0xAA, 0, 0, 0, 0, 0, 0});
    ASSERT_EQ(0x555, parsed.manufacturer_code);
}

TEST_F(PGNsTest, it_parses_byte_aligned_uint32_fields)
{
    auto parsed = parse_message<EngineParametersDynamic>({0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0x78,
        0x56,
        0x34,
        0x12,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0});
    ASSERT_EQ(0x12345678, parsed.total_engine_hours);
}

TEST_F(PGNsTest,
    it_parses_byte_aligned_uint32_fields_whose_value_would_not_fit_in_an_int32)
{
    auto parsed = parse_message<EngineParametersDynamic>({0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0x78,
        0x56,
        0x34,
        0xC2,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0});
    ASSERT_EQ(0xC2345678, parsed.total_engine_hours);
}

TEST_F(PGNsTest, it_parses_non_aligned_uint32_fields)
{
    auto parsed = parse_message<ISOAcknowledgement>({0, 0, 0, 0, 0, 0x12, 0x34, 0x56});
    ASSERT_EQ(0x563412, parsed.pgn);
}

TEST_F(PGNsTest, it_masks_non_aligned_uint32_fields_properly)
{
    auto parsed =
        parse_message<ISOAcknowledgement>({0, 0, 0, 0, 0, 0x12, 0x34, 0x56, 0x78}, 8);
    ASSERT_EQ(0x563412, parsed.pgn);
}

TEST_F(PGNsTest, it_parses_byte_aligned_Enum_fields)
{
    auto parsed = parse_message<ISOAcknowledgement>({5, 0, 0, 0, 0, 0, 0, 0});
    ASSERT_EQ(5, parsed.control);
}

TEST_F(PGNsTest, it_parses_non_aligned_Enum_fields)
{
    auto parsed = parse_message<ISOAddressClaim>({0, 0, 0, 0, 0, 0, 0xAA, 0});
    ASSERT_EQ(0x55, parsed.device_class);
}

TEST_F(PGNsTest, it_parses_positive_Dbl_fields_without_offset)
{
    auto parsed = parse_message<AirmarDeviceInformation>({0, 0, 0, 0, 0, 0x12, 0x34, 0});
    ASSERT_FLOAT_EQ(0x3412 * 0.01, parsed.supply_voltage);
}

TEST_F(PGNsTest, it_parses_positive_Dbl_fields_with_offset)
{
    auto parsed = parse_message<AirmarDeviceInformation>({0, 0, 0, 0, 0, 0x12, 0x34, 0});
    ASSERT_FLOAT_EQ(0x3412 * 0.01, parsed.supply_voltage);
}

TEST_F(PGNsTest, it_parses_negative_Dbl_fields)
{
    auto parsed = parse_message<AirmarDeviceInformation>({0, 0, 0, 0, 0, 0x12, 0xC4, 0});
    ASSERT_FLOAT_EQ(-0x3BEE * 0.01, parsed.supply_voltage);
}

TEST_F(PGNsTest, it_parses_UDbl_fields_without_offset)
{
    auto parsed = parse_message<SystemTime>({0, 0, 0, 0, 0x12, 0x34, 0, 0});
    ASSERT_FLOAT_EQ(0x3412 * 0.0001, parsed.seconds_since_midnight);
}

TEST_F(PGNsTest, it_parses_UDbl_fields_with_offset)
{
    auto parsed = parse_message<AirmarDeviceInformation>({0, 0, 0, 0x12, 0x34, 0, 0, 0});
    ASSERT_FLOAT_EQ(0x3412 * 0.01 - 273.15, parsed.internal_device_temperature);
}

TEST_F(PGNsTest, it_parses_UDbl_fields_whose_values_would_not_fit_in_Dbl)
{
    auto parsed = parse_message<AirmarDeviceInformation>({0, 0, 0, 0x12, 0xC4, 0, 0, 0});
    ASSERT_FLOAT_EQ(0xC412 * 0.01 - 273.15, parsed.internal_device_temperature);
}

TEST_F(PGNsTest, it_parses_zero_terminated_ASCII_fields)
{
    auto parsed = parse_message<Datum>(
        {'a', 'b', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    ASSERT_EQ("ab", parsed.local_datum);
}

TEST_F(PGNsTest, it_parses_non_zero_terminated_ASCII_fields)
{
    auto parsed = parse_message<Datum>(
        {'a', 'b', 'c', 'd', 'e', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    ASSERT_EQ("abcd", parsed.local_datum);
}

TEST_F(PGNsTest, it_parses_AISClassAPositionReport)
{
    auto parsed = parse_message<AISClassAPositionReport>({
        1, // payload[0]: msg_id (1), repeat_indicator (0)
        189,
        216,
        87,
        42, // payload[1..4]: user_id (710400189)
        187,
        62,
        21,
        227, // payload[5..8]: longitude -> -48.51469421
        158,
        173,
        204,
        240, // payload[9..12]: latitude -> -25.50216674
        123, // payload[13]: pos_accuracy(1), raim(1), time_stamp(30)
        255,
        255, // payload[14..15]: cog -> 375.4878845
        5,
        0, // payload[16..17]: sog (5)
        126,
        132,
        0, // payload[18..20]: communication state(skipped), ais transceiver
           // information(0)
        255,
        255, // payload[21..22]: heading -> 375.4878845
        255,
        127, // payload[23..24]: rate of turn -> 187.7410736084
        192, // payload[25]: nav status (192)
        248, // payload[26]: reserved for regional (248)
        255, // payload[27]: spare(255)
    });

    ASSERT_EQ(1, parsed.message_id);
    ASSERT_EQ(0, parsed.repeat_indicator);
    ASSERT_EQ(710400189, parsed.user_id);
    ASSERT_NEAR(-48.51469421, parsed.longitude, 1e-6);
    ASSERT_NEAR(-25.50216674, parsed.latitude, 1e-6);
    ASSERT_EQ(1, parsed.position_accuracy);
    ASSERT_EQ(1, parsed.raim);
    ASSERT_EQ(30, parsed.time_stamp);
    ASSERT_TRUE(std::isnan(parsed.cog));
    ASSERT_NEAR(0.05, parsed.sog, 1e-6);
    ASSERT_EQ(0, parsed.ais_transceiver_information);
    ASSERT_TRUE(std::isnan(parsed.heading));
    ASSERT_NEAR(187.7410736084, parsed.rate_of_turn, 1e-6);
    ASSERT_EQ(192, parsed.nav_status);
}

TEST_F(PGNsTest, it_parses_AISClassBPositionReport)
{
    auto parsed = parse_message<AISClassBPositionReport>({
        18, // payload[0]: msg_id (18), repeat_indicator (0)
        164,
        219,
        87,
        42, // payload[1..4]: user_id (710400932)
        205,
        5,
        24,
        227, // payload[5..8]: longitude -> -48.4964904785
        0,
        217,
        202,
        240, // payload[9..12]: latitude -> -25.51416397094
        124, // payload[13]: pos_accuracy(0), raim(0), time_stamp(31)
        255,
        255, // payload[14..15]: cog (375.4878845) -> not available
        0,
        0, // payload[16..17]: sog (0)
        0,
        0,  // payload[18..19]: unused
        32, // payload[20]: ais_transceiver_information (4)
        255,
        255, // payload[21..22]: heading (375.4878845) -> not available
        0,   // payload[23]: regional application (0)
        112, // payload[24]: regional application(0), unit type(0), integrated display(0),
             // dsc(1), band(1), msg 22 (1), ais mode()
        254, // payload[25]: ais_communication_state (0)
    });

    ASSERT_EQ(18, parsed.message_id);
    ASSERT_EQ(0, parsed.repeat_indicator);
    ASSERT_EQ(710400932, parsed.user_id);
    ASSERT_NEAR(-48.4964904785, parsed.longitude, 1e-6);
    ASSERT_NEAR(-25.51416397094, parsed.latitude, 1e-6);
    ASSERT_EQ(0, parsed.position_accuracy);
    ASSERT_EQ(0, parsed.raim);
    ASSERT_EQ(31, parsed.time_stamp);
    ASSERT_TRUE(std::isnan(parsed.cog));
    ASSERT_NEAR(0, parsed.sog, 1e-6);
    ASSERT_EQ(4, parsed.ais_transceiver_information);
    ASSERT_TRUE(std::isnan(parsed.heading));
    ASSERT_EQ(0, parsed.regional_application);
    ASSERT_EQ(0, parsed.regional_application1);
    ASSERT_EQ(0, parsed.unit_type);
    ASSERT_EQ(0, parsed.integrated_display);
    ASSERT_EQ(1, parsed.dsc);
    ASSERT_EQ(1, parsed.band);
    ASSERT_EQ(1, parsed.can_handle_msg_22);
    ASSERT_EQ(0, parsed.ais_mode);
    ASSERT_EQ(0, parsed.ais_communication_state);
}

TEST_F(PGNsTest, it_parses_AISClassAStaticAndVoyageRelatedData)
{
    auto parsed = parse_message<AISClassAStaticAndVoyageRelatedData>({
        5, // payload[0]: msg_id (5), repeat_indicator (0)
        218,
        63,
        82,
        42, // payload[1..4]: user_id (710033370)
        106,
        181,
        150,
        0, // payload[5..8]: imo number (9876842)
        80,
        85,
        53,
        54,
        57,
        57,
        64, // payload[9..15]: call sign -> PU5699@
        83,
        65,
        65,
        77,
        32,
        69,
        76,
        69,
        67,
        84,
        82,
        65,
        65,
        64,
        64,
        64,
        64,
        64,
        64,
        64, // payload[16..35]: name -> SAAM ELECTRAA@@@@@@@@
        52, // payload[36]: type (52)
        64,
        1, // payload[37..38]: length (32.0)
        120,
        0, // payload[39..40]: beam (12.0)
        60,
        0, // payload[41..42]: position reference from starboard (6.0)
        120,
        0, // payload[43..44]: position reference from bow (12.0)
        215,
        80, // payload[45..46]: eta date (20695)
        0,
        204,
        191,
        25, // payload[47..50]: eta time (43200.0)
        78,
        2, // payload[51..52]: draft (5.9)
        80,
        65,
        82,
        65,
        78,
        65,
        71,
        85,
        65,
        32,
        80,
        82,
        64,
        64,
        64,
        64,
        64,
        64,
        64,
        64,  // payload[53..72]: destination (PARANAGUA PR)
        2,   // payload[73]: ais version (2), gnss type (0), dte (0), reserved ()
        225, // payload[74]: ais transceiver information (1)
    });

    ASSERT_EQ(5, parsed.message_id);
    ASSERT_EQ(0, parsed.repeat_indicator);
    ASSERT_EQ(710033370, parsed.user_id);
    ASSERT_EQ(9876842, parsed.imo_number);
    ASSERT_EQ("PU5699@", parsed.callsign);
    ASSERT_EQ("SAAM ELECTRAA@@@@@@@", parsed.name);
    ASSERT_EQ(52, parsed.type_of_ship);
    ASSERT_NEAR(32, parsed.length, 1e-2);
    ASSERT_NEAR(12, parsed.beam, 1e-2);
    ASSERT_NEAR(6, parsed.position_reference_from_starboard, 1e-6);
    ASSERT_NEAR(12, parsed.position_reference_from_bow, 1e-6);
    ASSERT_EQ(20695, parsed.eta_date);
    ASSERT_NEAR(43200, parsed.eta_time, 1e-6);
    ASSERT_NEAR(5.9, parsed.draft, 1e-6);
    ASSERT_EQ("PARANAGUA PR@@@@@@@@", parsed.destination);
    ASSERT_EQ(2, parsed.ais_version_indicator);
    ASSERT_EQ(0, parsed.gnss_type);
    ASSERT_EQ(0, parsed.dte);
    ASSERT_EQ(1, parsed.ais_transceiver_information);
}
TEST_F(PGNsTest, it_parses_AISClassBExtendedPositionReport)
{
    auto parsed = parse_message<AISClassBExtendedPositionReport>({
        19, // payload[0]: msg_id (19), repeat_indicator (0)
        218,
        63,
        82,
        42, // payload[1..4]: user_id (710033370)
        205,
        5,
        24,
        227, // payload[5..8]: longitude -> -48.4964904785
        0,
        217,
        202,
        240, // payload[9..12]: latitude -> -25.51416397094
        124, // payload[13]: pos_accuracy(0), raim(0), time_stamp(31)
        255,
        255, // payload[14..15]: cog (0)
        0,
        0, // payload[16..17]: sog (0)
        0,
        0,  // payload[18..19]: unused
        52, // payload[20]: type (52)
        255,
        255, // payload[21..22]: heading (0)
        16,  // payload[23]: reserved(), gnss type (1)
        64,
        1, // payload[24..25]: length (32.0)
        120,
        0, // payload[26..27]: beam (12.0)
        60,
        0, // payload[28..29]: position reference from starboard (6.0)
        120,
        0, // payload[30..31]: position reference from bow (12.0)
        83,
        65,
        65,
        77,
        32,
        69,
        76,
        69,
        67,
        84,
        82,
        65,
        65,
        64,
        64,
        64,
        64,
        64,
        64,
        64, // payload[32..51]: name -> SAAM ELECTRAA@@@@@@@@
        2,
        225, // payload[52..53]: dte(0), ais mode (1), reserved(), ais transceiver
             // information (4)
    });

    ASSERT_EQ(19, parsed.message_id);
    ASSERT_EQ(0, parsed.repeat_indicator);
    ASSERT_EQ(710033370, parsed.user_id);
    ASSERT_NEAR(-48.4964904785, parsed.longitude, 1e-6);
    ASSERT_NEAR(-25.51416397094, parsed.latitude, 1e-6);
    ASSERT_EQ(0, parsed.position_accuracy);
    ASSERT_EQ(0, parsed.ais_raim_flag);
    ASSERT_EQ(31, parsed.time_stamp);
    ASSERT_TRUE(std::isnan(parsed.cog));
    ASSERT_NEAR(0.0, parsed.sog, 1e-6);
    ASSERT_EQ(52, parsed.type_of_ship);
    ASSERT_TRUE(std::isnan(parsed.true_heading));
    ASSERT_EQ(1, parsed.gnss_type);
    ASSERT_NEAR(32, parsed.length, 1e-2);
    ASSERT_NEAR(12, parsed.beam, 1e-2);
    ASSERT_NEAR(6, parsed.position_reference_from_starboard, 1e-6);
    ASSERT_NEAR(12, parsed.position_reference_from_bow, 1e-6);
    ASSERT_EQ("SAAM ELECTRAA@@@@@@@", parsed.name);
    ASSERT_EQ(0, parsed.dte);
    ASSERT_EQ(1, parsed.ais_mode);
    ASSERT_EQ(4, parsed.ais_transceiver_information);
}

template <typename M>
M parse_message(vector<uint8_t> const& payload, int size, base::Time const& time)
{
    Message message;
    message.time = time;
    message.pgn = M::ID;
    message.size = size == 0 ? payload.size() : size;
    std::copy(payload.begin(), payload.end(), message.payload);
    return M::fromMessage(message);
}
