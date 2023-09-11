#include <nmea2000/PGNs.hpp>
#include <nmea2000/Decode.hpp>

/** This file is auto-generated using the codegen script
 * DO NOT MODIFY
 */

using namespace nmea2000::decode;
using namespace nmea2000::pgns;

const int ISOAcknowledgement::BYTE_LENGTH;
const int ISOAcknowledgement::ID;

ISOAcknowledgement ISOAcknowledgement::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    ISOAcknowledgement result;
    result.time = message.time;

    result.control = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.group_function = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.reserved = (decode32(
        &message.payload[2]
    ) >> 0) & 0xffffff;
    result.pgn = (decode32(
        &message.payload[5]
    ) >> 0) & 0xffffff;
    return result;
}
const int ISORequest::BYTE_LENGTH;
const int ISORequest::ID;

ISORequest ISORequest::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    ISORequest result;
    result.time = message.time;

    result.pgn = (decode32(
        &message.payload[0]
    ) >> 0) & 0xffffff;
    return result;
}
const int ISOAddressClaim::BYTE_LENGTH;
const int ISOAddressClaim::ID;

ISOAddressClaim ISOAddressClaim::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    ISOAddressClaim result;
    result.time = message.time;

    result.device_instance_lower = (decode8(
        &message.payload[4]
    ) >> 0) & 0x7;
    result.device_instance_upper = (decode8(
        &message.payload[4]
    ) >> 3) & 0x1f;
    result.device_function = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.device_class = (decode8(
        &message.payload[6]
    ) >> 1) & 0x7f;
    result.system_instance = (decode8(
        &message.payload[7]
    ) >> 0) & 0xf;
    result.industry_group = (decode8(
        &message.payload[7]
    ) >> 4) & 0x7;
    result.iso_self_configurable = (decode8(
        &message.payload[7]
    ) >> 7) & 0x1;
    return result;
}
const int ISOCommandedAddress::BYTE_LENGTH;
const int ISOCommandedAddress::ID;

ISOCommandedAddress ISOCommandedAddress::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    ISOCommandedAddress result;
    result.time = message.time;

    result.manufacturer_code = (decode16(
        &message.payload[2]
    ) >> 5) & 0x7ff;
    result.device_instance_lower = (decode8(
        &message.payload[4]
    ) >> 0) & 0x7;
    result.device_instance_upper = (decode8(
        &message.payload[4]
    ) >> 3) & 0x1f;
    result.device_function = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.reserved = (decode8(
        &message.payload[6]
    ) >> 0) & 0x1;
    result.device_class = (decode8(
        &message.payload[6]
    ) >> 1) & 0x7f;
    result.system_instance = (decode8(
        &message.payload[7]
    ) >> 0) & 0xf;
    result.industry_code = (decode8(
        &message.payload[7]
    ) >> 4) & 0x7;
    result.iso_self_configurable = (decode8(
        &message.payload[7]
    ) >> 7) & 0x1;
    result.new_source_address = (decode8(
        &message.payload[8]
    ) >> 0) & 0xff;
    return result;
}
const int AirmarBootStateAcknowledgment::BYTE_LENGTH;
const int AirmarBootStateAcknowledgment::ID;

AirmarBootStateAcknowledgment AirmarBootStateAcknowledgment::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AirmarBootStateAcknowledgment result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    result.boot_state = (decode8(
        &message.payload[2]
    ) >> 0) & 0xf;
    return result;
}
const int LowranceTemperature::BYTE_LENGTH;
const int LowranceTemperature::ID;

LowranceTemperature LowranceTemperature::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    LowranceTemperature result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    result.temperature_instance = (decode8(
        &message.payload[2]
    ) >> 0) & 0xf;
    result.temperature_source = (decode8(
        &message.payload[2]
    ) >> 4) & 0xf;
    auto actual_temperature_raw = decode16(
        &message.payload[3]
    );
    uint16_t actual_temperature_iraw =
        reinterpret_cast<uint16_t const&>(actual_temperature_raw);
    result.actual_temperature = actual_temperature_iraw * 0.01 + -273.15;
    return result;
}
const int AirmarBootStateRequest::BYTE_LENGTH;
const int AirmarBootStateRequest::ID;

AirmarBootStateRequest AirmarBootStateRequest::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AirmarBootStateRequest result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    return result;
}
const int SimnetConfigureTemperatureSensor::BYTE_LENGTH;
const int SimnetConfigureTemperatureSensor::ID;

SimnetConfigureTemperatureSensor SimnetConfigureTemperatureSensor::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetConfigureTemperatureSensor result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    return result;
}
const int AirmarAccessLevel::BYTE_LENGTH;
const int AirmarAccessLevel::ID;

AirmarAccessLevel AirmarAccessLevel::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AirmarAccessLevel result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    result.format_code = (decode8(
        &message.payload[2]
    ) >> 0) & 0x7;
    result.access_level = (decode8(
        &message.payload[2]
    ) >> 3) & 0x7;
    result.reserved1 = (decode8(
        &message.payload[2]
    ) >> 6) & 0x3;
    auto access_seed_key_raw = decode32(
        &message.payload[3]
    );
    result.access_seed_key = reinterpret_cast<int32_t const&>(
        access_seed_key_raw
    );
    return result;
}
const int SimnetTrimTabSensorCalibration::BYTE_LENGTH;
const int SimnetTrimTabSensorCalibration::ID;

SimnetTrimTabSensorCalibration SimnetTrimTabSensorCalibration::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetTrimTabSensorCalibration result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    return result;
}
const int SimnetPaddleWheelSpeedConfiguration::BYTE_LENGTH;
const int SimnetPaddleWheelSpeedConfiguration::ID;

SimnetPaddleWheelSpeedConfiguration SimnetPaddleWheelSpeedConfiguration::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetPaddleWheelSpeedConfiguration result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    return result;
}
const int SimnetClearFluidLevelWarnings::BYTE_LENGTH;
const int SimnetClearFluidLevelWarnings::ID;

SimnetClearFluidLevelWarnings SimnetClearFluidLevelWarnings::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetClearFluidLevelWarnings result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    return result;
}
const int SimnetLGC2000Configuration::BYTE_LENGTH;
const int SimnetLGC2000Configuration::ID;

SimnetLGC2000Configuration SimnetLGC2000Configuration::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetLGC2000Configuration result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    return result;
}
const int SimnetReprogramStatus::BYTE_LENGTH;
const int SimnetReprogramStatus::ID;

SimnetReprogramStatus SimnetReprogramStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetReprogramStatus result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    return result;
}
const int SimnetAutopilotMode::BYTE_LENGTH;
const int SimnetAutopilotMode::ID;

SimnetAutopilotMode SimnetAutopilotMode::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetAutopilotMode result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    return result;
}
const int AirmarDepthQualityFactor::BYTE_LENGTH;
const int AirmarDepthQualityFactor::ID;

AirmarDepthQualityFactor AirmarDepthQualityFactor::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AirmarDepthQualityFactor result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    result.sid = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    result.depth_quality_factor = (decode8(
        &message.payload[3]
    ) >> 0) & 0xf;
    return result;
}
const int AirmarDeviceInformation::BYTE_LENGTH;
const int AirmarDeviceInformation::ID;

AirmarDeviceInformation AirmarDeviceInformation::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AirmarDeviceInformation result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    result.sid = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    auto internal_device_temperature_raw = decode16(
        &message.payload[3]
    );
    uint16_t internal_device_temperature_iraw =
        reinterpret_cast<uint16_t const&>(internal_device_temperature_raw);
    result.internal_device_temperature = internal_device_temperature_iraw * 0.01 + -273.15;
    auto supply_voltage_raw = decode16(
        &message.payload[5]
    );
    int16_t supply_voltage_iraw =
        reinterpret_cast<int16_t const&>(supply_voltage_raw);
    result.supply_voltage = supply_voltage_iraw * 0.01 + 0.0;
    result.reserved1 = (decode8(
        &message.payload[7]
    ) >> 0) & 0xff;
    return result;
}
const int SimnetAutopilotMode1::BYTE_LENGTH;
const int SimnetAutopilotMode1::ID;

SimnetAutopilotMode1 SimnetAutopilotMode1::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetAutopilotMode1 result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    return result;
}
const int NMEARequestGroupFunction::BYTE_LENGTH;
const int NMEARequestGroupFunction::ID;

NMEARequestGroupFunction NMEARequestGroupFunction::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    NMEARequestGroupFunction result;
    result.time = message.time;

    auto function_code_raw = decode8(
        &message.payload[0]
    );
    result.function_code = reinterpret_cast<int8_t const&>(
        function_code_raw
    );
    result.pgn = (decode32(
        &message.payload[1]
    ) >> 0) & 0xffffff;
    result.transmission_interval = (decode8(
        &message.payload[4]
    ) >> 0) & 0xf;
    result.transmission_interval_offset = (decode8(
        &message.payload[4]
    ) >> 4) & 0xf;
    result.number_of_requested_parameters = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    auto parameter_index_raw = decode8(
        &message.payload[6]
    );
    result.parameter_index = reinterpret_cast<int8_t const&>(
        parameter_index_raw
    );
    auto parameter_value_raw = decode16(
        &message.payload[7]
    );
    result.parameter_value = reinterpret_cast<int16_t const&>(
        parameter_value_raw
    );
    return result;
}
const int NMEACommandGroupFunction::BYTE_LENGTH;
const int NMEACommandGroupFunction::ID;

NMEACommandGroupFunction NMEACommandGroupFunction::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    NMEACommandGroupFunction result;
    result.time = message.time;

    auto function_code_raw = decode8(
        &message.payload[0]
    );
    result.function_code = reinterpret_cast<int8_t const&>(
        function_code_raw
    );
    result.pgn = (decode32(
        &message.payload[1]
    ) >> 0) & 0xffffff;
    result.priority = (decode8(
        &message.payload[4]
    ) >> 0) & 0xf;
    result.reserved = (decode8(
        &message.payload[4]
    ) >> 4) & 0xf;
    result.number_of_commanded_parameters = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    auto parameter_index_raw = decode8(
        &message.payload[6]
    );
    result.parameter_index = reinterpret_cast<int8_t const&>(
        parameter_index_raw
    );
    auto parameter_value_raw = decode16(
        &message.payload[7]
    );
    result.parameter_value = reinterpret_cast<int16_t const&>(
        parameter_value_raw
    );
    return result;
}
const int NMEAAcknowledgeGroupFunction::BYTE_LENGTH;
const int NMEAAcknowledgeGroupFunction::ID;

NMEAAcknowledgeGroupFunction NMEAAcknowledgeGroupFunction::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    NMEAAcknowledgeGroupFunction result;
    result.time = message.time;

    auto function_code_raw = decode8(
        &message.payload[0]
    );
    result.function_code = reinterpret_cast<int8_t const&>(
        function_code_raw
    );
    result.pgn = (decode32(
        &message.payload[1]
    ) >> 0) & 0xffffff;
    result.pgn_error_code = (decode8(
        &message.payload[4]
    ) >> 0) & 0xf;
    result.transmission_interval_priority_error_code = (decode8(
        &message.payload[4]
    ) >> 4) & 0xf;
    result.number_of_commanded_parameters = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    auto parameter_error_raw = decode8(
        &message.payload[6]
    );
    result.parameter_error = reinterpret_cast<int8_t const&>(
        parameter_error_raw
    );
    return result;
}
const int MaretronSlaveResponse::BYTE_LENGTH;
const int MaretronSlaveResponse::ID;

MaretronSlaveResponse MaretronSlaveResponse::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    MaretronSlaveResponse result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    result.product_code = (decode16(
        &message.payload[2]
    ) >> 0) & 0xffff;
    result.software_code = (decode16(
        &message.payload[4]
    ) >> 0) & 0xffff;
    result.command = (decode8(
        &message.payload[6]
    ) >> 0) & 0xff;
    result.status = (decode8(
        &message.payload[7]
    ) >> 0) & 0xff;
    return result;
}
const int PGNListTransmitAndReceive::BYTE_LENGTH;
const int PGNListTransmitAndReceive::ID;

PGNListTransmitAndReceive PGNListTransmitAndReceive::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    PGNListTransmitAndReceive result;
    result.time = message.time;

    result.function_code = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.pgn = (decode32(
        &message.payload[1]
    ) >> 0) & 0xffffff;
    return result;
}
const int AirmarCalibrateCompass::BYTE_LENGTH;
const int AirmarCalibrateCompass::ID;

AirmarCalibrateCompass AirmarCalibrateCompass::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AirmarCalibrateCompass result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    auto proprietary_id_raw = decode8(
        &message.payload[2]
    );
    result.proprietary_id = reinterpret_cast<int8_t const&>(
        proprietary_id_raw
    );
    result.calibrate_function = (decode8(
        &message.payload[3]
    ) >> 0) & 0xff;
    result.calibration_status = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    auto verify_score_raw = decode8(
        &message.payload[5]
    );
    result.verify_score = reinterpret_cast<int8_t const&>(
        verify_score_raw
    );
    auto x_axis_gain_value_raw = decode16(
        &message.payload[6]
    );
    int16_t x_axis_gain_value_iraw =
        reinterpret_cast<int16_t const&>(x_axis_gain_value_raw);
    result.x_axis_gain_value = x_axis_gain_value_iraw * 0.01 + 0.0;
    auto y_axis_gain_value_raw = decode16(
        &message.payload[8]
    );
    int16_t y_axis_gain_value_iraw =
        reinterpret_cast<int16_t const&>(y_axis_gain_value_raw);
    result.y_axis_gain_value = y_axis_gain_value_iraw * 0.01 + 0.0;
    auto z_axis_gain_value_raw = decode16(
        &message.payload[10]
    );
    int16_t z_axis_gain_value_iraw =
        reinterpret_cast<int16_t const&>(z_axis_gain_value_raw);
    result.z_axis_gain_value = z_axis_gain_value_iraw * 0.01 + 0.0;
    auto x_axis_linear_offset_raw = decode16(
        &message.payload[12]
    );
    int16_t x_axis_linear_offset_iraw =
        reinterpret_cast<int16_t const&>(x_axis_linear_offset_raw);
    result.x_axis_linear_offset = x_axis_linear_offset_iraw * 0.01 + 0.0;
    auto y_axis_linear_offset_raw = decode16(
        &message.payload[14]
    );
    int16_t y_axis_linear_offset_iraw =
        reinterpret_cast<int16_t const&>(y_axis_linear_offset_raw);
    result.y_axis_linear_offset = y_axis_linear_offset_iraw * 0.01 + 0.0;
    auto z_axis_linear_offset_raw = decode16(
        &message.payload[16]
    );
    int16_t z_axis_linear_offset_iraw =
        reinterpret_cast<int16_t const&>(z_axis_linear_offset_raw);
    result.z_axis_linear_offset = z_axis_linear_offset_iraw * 0.01 + 0.0;
    auto x_axis_angular_offset_raw = decode16(
        &message.payload[18]
    );
    int16_t x_axis_angular_offset_iraw =
        reinterpret_cast<int16_t const&>(x_axis_angular_offset_raw);
    result.x_axis_angular_offset = x_axis_angular_offset_iraw * 0.1 + 0.0;
    auto pitch_and_roll_damping_raw = decode16(
        &message.payload[20]
    );
    int16_t pitch_and_roll_damping_iraw =
        reinterpret_cast<int16_t const&>(pitch_and_roll_damping_raw);
    result.pitch_and_roll_damping = pitch_and_roll_damping_iraw * 0.05 + 0.0;
    auto compass_rate_gyro_damping_raw = decode16(
        &message.payload[22]
    );
    int16_t compass_rate_gyro_damping_iraw =
        reinterpret_cast<int16_t const&>(compass_rate_gyro_damping_raw);
    result.compass_rate_gyro_damping = compass_rate_gyro_damping_iraw * 0.05 + 0.0;
    return result;
}
const int AirmarAttitudeOffset::BYTE_LENGTH;
const int AirmarAttitudeOffset::ID;

AirmarAttitudeOffset AirmarAttitudeOffset::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AirmarAttitudeOffset result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    auto proprietary_id_raw = decode8(
        &message.payload[2]
    );
    result.proprietary_id = reinterpret_cast<int8_t const&>(
        proprietary_id_raw
    );
    auto azimuth_offset_raw = decode16(
        &message.payload[3]
    );
    int16_t azimuth_offset_iraw =
        reinterpret_cast<int16_t const&>(azimuth_offset_raw);
    result.azimuth_offset = azimuth_offset_iraw * 0.005729577951308233 + 0.0;
    auto pitch_offset_raw = decode16(
        &message.payload[5]
    );
    int16_t pitch_offset_iraw =
        reinterpret_cast<int16_t const&>(pitch_offset_raw);
    result.pitch_offset = pitch_offset_iraw * 0.005729577951308233 + 0.0;
    auto roll_offset_raw = decode16(
        &message.payload[7]
    );
    int16_t roll_offset_iraw =
        reinterpret_cast<int16_t const&>(roll_offset_raw);
    result.roll_offset = roll_offset_iraw * 0.005729577951308233 + 0.0;
    return result;
}
const int AirmarTrueWindOptions::BYTE_LENGTH;
const int AirmarTrueWindOptions::ID;

AirmarTrueWindOptions AirmarTrueWindOptions::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AirmarTrueWindOptions result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    auto proprietary_id_raw = decode8(
        &message.payload[2]
    );
    result.proprietary_id = reinterpret_cast<int8_t const&>(
        proprietary_id_raw
    );
    result.cog_substition_for_hdg = (decode8(
        &message.payload[3]
    ) >> 0) & 0x3;
    result.calibration_status = (decode8(
        &message.payload[3]
    ) >> 2) & 0xff;
    return result;
}
const int ManufacturerPropietaryAddressableMultiFrame::BYTE_LENGTH;
const int ManufacturerPropietaryAddressableMultiFrame::ID;

ManufacturerPropietaryAddressableMultiFrame ManufacturerPropietaryAddressableMultiFrame::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    ManufacturerPropietaryAddressableMultiFrame result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    return result;
}
const int AirmarAddressableMultiFrame::BYTE_LENGTH;
const int AirmarAddressableMultiFrame::ID;

AirmarAddressableMultiFrame AirmarAddressableMultiFrame::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AirmarAddressableMultiFrame result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    auto proprietary_id_raw = decode8(
        &message.payload[2]
    );
    result.proprietary_id = reinterpret_cast<int8_t const&>(
        proprietary_id_raw
    );
    return result;
}
const int SystemTime::BYTE_LENGTH;
const int SystemTime::ID;

SystemTime SystemTime::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SystemTime result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.source = (decode8(
        &message.payload[1]
    ) >> 0) & 0xf;
    result.date = (decode16(
        &message.payload[2]
    ) >> 0) & 0xffff;
    auto seconds_since_midnight_raw = decode32(
        &message.payload[4]
    );
    uint32_t seconds_since_midnight_iraw =
        reinterpret_cast<uint32_t const&>(seconds_since_midnight_raw);
    result.seconds_since_midnight = seconds_since_midnight_iraw * 0.0001 + 0.0;
    return result;
}
const int Heartbeat::BYTE_LENGTH;
const int Heartbeat::ID;

Heartbeat Heartbeat::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    Heartbeat result;
    result.time = message.time;

    auto interval_raw = decode16(
        &message.payload[0]
    );
    uint16_t interval_iraw =
        reinterpret_cast<uint16_t const&>(interval_raw);
    result.interval = interval_iraw * 10.0 + 0.0;
    result.status = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    return result;
}
const int ProductInformation::BYTE_LENGTH;
const int ProductInformation::ID;

ProductInformation ProductInformation::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    ProductInformation result;
    result.time = message.time;

    result.nmea_2000_version = (decode16(
        &message.payload[0]
    ) >> 0) & 0xffff;
    result.product_code = (decode16(
        &message.payload[2]
    ) >> 0) & 0xffff;
    result.model_id = decodeString(&message.payload[4],
                                            32);
    result.software_version_code = decodeString(&message.payload[36],
                                            32);
    result.model_version = decodeString(&message.payload[68],
                                            32);
    result.model_serial_code = decodeString(&message.payload[100],
                                            32);
    result.certification_level = (decode8(
        &message.payload[132]
    ) >> 0) & 0xff;
    result.load_equivalency = (decode8(
        &message.payload[133]
    ) >> 0) & 0xff;
    return result;
}
const int ConfigurationInformation::BYTE_LENGTH;
const int ConfigurationInformation::ID;

ConfigurationInformation ConfigurationInformation::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    ConfigurationInformation result;
    result.time = message.time;

    return result;
}
const int HeadingTrackControl::BYTE_LENGTH;
const int HeadingTrackControl::ID;

HeadingTrackControl HeadingTrackControl::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    HeadingTrackControl result;
    result.time = message.time;

    result.rudder_limit_exceeded = (decode8(
        &message.payload[0]
    ) >> 0) & 0x3;
    result.off_heading_limit_exceeded = (decode8(
        &message.payload[0]
    ) >> 2) & 0x3;
    result.off_track_limit_exceeded = (decode8(
        &message.payload[0]
    ) >> 4) & 0x3;
    result.override = (decode8(
        &message.payload[0]
    ) >> 6) & 0x3;
    result.steering_mode = (decode8(
        &message.payload[1]
    ) >> 0) & 0xf;
    result.turn_mode = (decode8(
        &message.payload[1]
    ) >> 4) & 0xf;
    result.heading_reference = (decode8(
        &message.payload[2]
    ) >> 0) & 0x7;
    result.reserved = (decode8(
        &message.payload[2]
    ) >> 3) & 0x7;
    result.commanded_rudder_direction = (decode8(
        &message.payload[2]
    ) >> 6) & 0x3;
    auto commanded_rudder_angle_raw = decode16(
        &message.payload[3]
    );
    int16_t commanded_rudder_angle_iraw =
        reinterpret_cast<int16_t const&>(commanded_rudder_angle_raw);
    result.commanded_rudder_angle = commanded_rudder_angle_iraw * 0.005729577951308233 + 0.0;
    auto heading_to_steer_course__raw = decode16(
        &message.payload[5]
    );
    uint16_t heading_to_steer_course__iraw =
        reinterpret_cast<uint16_t const&>(heading_to_steer_course__raw);
    result.heading_to_steer_course_ = heading_to_steer_course__iraw * 0.005729577951308233 + 0.0;
    auto track_raw = decode16(
        &message.payload[7]
    );
    uint16_t track_iraw =
        reinterpret_cast<uint16_t const&>(track_raw);
    result.track = track_iraw * 0.005729577951308233 + 0.0;
    auto rudder_limit_raw = decode16(
        &message.payload[9]
    );
    uint16_t rudder_limit_iraw =
        reinterpret_cast<uint16_t const&>(rudder_limit_raw);
    result.rudder_limit = rudder_limit_iraw * 0.005729577951308233 + 0.0;
    auto off_heading_limit_raw = decode16(
        &message.payload[11]
    );
    uint16_t off_heading_limit_iraw =
        reinterpret_cast<uint16_t const&>(off_heading_limit_raw);
    result.off_heading_limit = off_heading_limit_iraw * 0.005729577951308233 + 0.0;
    auto radius_of_turn_order_raw = decode16(
        &message.payload[13]
    );
    int16_t radius_of_turn_order_iraw =
        reinterpret_cast<int16_t const&>(radius_of_turn_order_raw);
    result.radius_of_turn_order = radius_of_turn_order_iraw * 0.005729577951308233 + 0.0;
    auto rate_of_turn_order_raw = decode16(
        &message.payload[15]
    );
    int16_t rate_of_turn_order_iraw =
        reinterpret_cast<int16_t const&>(rate_of_turn_order_raw);
    result.rate_of_turn_order = rate_of_turn_order_iraw * 0.005729577951308233 + 0.0;
    result.off_track_limit = (decode16(
        &message.payload[17]
    ) >> 0) & 0xffff;
    auto vessel_heading_raw = decode16(
        &message.payload[19]
    );
    uint16_t vessel_heading_iraw =
        reinterpret_cast<uint16_t const&>(vessel_heading_raw);
    result.vessel_heading = vessel_heading_iraw * 0.005729577951308233 + 0.0;
    return result;
}
const int Rudder::BYTE_LENGTH;
const int Rudder::ID;

Rudder Rudder::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    Rudder result;
    result.time = message.time;

    result.instance = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.direction_order = (decode8(
        &message.payload[1]
    ) >> 0) & 0x7;
    auto angle_order_raw = decode16(
        &message.payload[2]
    );
    int16_t angle_order_iraw =
        reinterpret_cast<int16_t const&>(angle_order_raw);
    result.angle_order = angle_order_iraw * 0.005729577951308233 + 0.0;
    auto position_raw = decode16(
        &message.payload[4]
    );
    int16_t position_iraw =
        reinterpret_cast<int16_t const&>(position_raw);
    result.position = position_iraw * 0.005729577951308233 + 0.0;
    result.reserved = (decode16(
        &message.payload[6]
    ) >> 0) & 0xffff;
    return result;
}
const int VesselHeading::BYTE_LENGTH;
const int VesselHeading::ID;

VesselHeading VesselHeading::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    VesselHeading result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    auto heading_raw = decode16(
        &message.payload[1]
    );
    uint16_t heading_iraw =
        reinterpret_cast<uint16_t const&>(heading_raw);
    result.heading = heading_iraw * 0.005729577951308233 + 0.0;
    auto deviation_raw = decode16(
        &message.payload[3]
    );
    int16_t deviation_iraw =
        reinterpret_cast<int16_t const&>(deviation_raw);
    result.deviation = deviation_iraw * 0.005729577951308233 + 0.0;
    auto variation_raw = decode16(
        &message.payload[5]
    );
    int16_t variation_iraw =
        reinterpret_cast<int16_t const&>(variation_raw);
    result.variation = variation_iraw * 0.005729577951308233 + 0.0;
    result.reference = (decode8(
        &message.payload[7]
    ) >> 0) & 0x3;
    result.reserved = (decode8(
        &message.payload[7]
    ) >> 2) & 0x3f;
    return result;
}
const int RateOfTurn::BYTE_LENGTH;
const int RateOfTurn::ID;

RateOfTurn RateOfTurn::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RateOfTurn result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    auto rate_raw = decode32(
        &message.payload[1]
    );
    int32_t rate_iraw =
        reinterpret_cast<int32_t const&>(rate_raw);
    result.rate = rate_iraw * 1.0 + 0.0;
    return result;
}
const int Attitude::BYTE_LENGTH;
const int Attitude::ID;

Attitude Attitude::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    Attitude result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    auto yaw_raw = decode16(
        &message.payload[1]
    );
    int16_t yaw_iraw =
        reinterpret_cast<int16_t const&>(yaw_raw);
    result.yaw = yaw_iraw * 0.005729577951308233 + 0.0;
    auto pitch_raw = decode16(
        &message.payload[3]
    );
    int16_t pitch_iraw =
        reinterpret_cast<int16_t const&>(pitch_raw);
    result.pitch = pitch_iraw * 0.005729577951308233 + 0.0;
    auto roll_raw = decode16(
        &message.payload[5]
    );
    int16_t roll_iraw =
        reinterpret_cast<int16_t const&>(roll_raw);
    result.roll = roll_iraw * 0.005729577951308233 + 0.0;
    return result;
}
const int MagneticVariation::BYTE_LENGTH;
const int MagneticVariation::ID;

MagneticVariation MagneticVariation::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    MagneticVariation result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.source = (decode8(
        &message.payload[1]
    ) >> 0) & 0xf;
    result.age_of_service = (decode16(
        &message.payload[2]
    ) >> 0) & 0xffff;
    auto variation_raw = decode16(
        &message.payload[4]
    );
    int16_t variation_iraw =
        reinterpret_cast<int16_t const&>(variation_raw);
    result.variation = variation_iraw * 0.005729577951308233 + 0.0;
    return result;
}
const int EngineParametersRapidUpdate::BYTE_LENGTH;
const int EngineParametersRapidUpdate::ID;

EngineParametersRapidUpdate EngineParametersRapidUpdate::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    EngineParametersRapidUpdate result;
    result.time = message.time;

    result.engine_instance = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    auto engine_speed_raw = decode16(
        &message.payload[1]
    );
    uint16_t engine_speed_iraw =
        reinterpret_cast<uint16_t const&>(engine_speed_raw);
    result.engine_speed = engine_speed_iraw * 0.25 + 0.0;
    result.engine_boost_pressure = (decode16(
        &message.payload[3]
    ) >> 0) & 0xffff;
    auto engine_tilt_trim_raw = decode8(
        &message.payload[5]
    );
    result.engine_tilt_trim = reinterpret_cast<int8_t const&>(
        engine_tilt_trim_raw
    );
    result.reserved = (decode16(
        &message.payload[6]
    ) >> 0) & 0xffff;
    return result;
}
const int EngineParametersDynamic::BYTE_LENGTH;
const int EngineParametersDynamic::ID;

EngineParametersDynamic EngineParametersDynamic::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    EngineParametersDynamic result;
    result.time = message.time;

    result.engine_instance = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.oil_pressure = (decode16(
        &message.payload[1]
    ) >> 0) & 0xffff;
    auto oil_temperature_raw = decode16(
        &message.payload[3]
    );
    uint16_t oil_temperature_iraw =
        reinterpret_cast<uint16_t const&>(oil_temperature_raw);
    result.oil_temperature = oil_temperature_iraw * 0.1 + -273.15;
    auto temperature_raw = decode16(
        &message.payload[5]
    );
    uint16_t temperature_iraw =
        reinterpret_cast<uint16_t const&>(temperature_raw);
    result.temperature = temperature_iraw * 0.01 + -273.15;
    auto alternator_potential_raw = decode16(
        &message.payload[7]
    );
    int16_t alternator_potential_iraw =
        reinterpret_cast<int16_t const&>(alternator_potential_raw);
    result.alternator_potential = alternator_potential_iraw * 0.01 + 0.0;
    auto fuel_rate_raw = decode16(
        &message.payload[9]
    );
    int16_t fuel_rate_iraw =
        reinterpret_cast<int16_t const&>(fuel_rate_raw);
    result.fuel_rate = fuel_rate_iraw * 0.1 + 0.0;
    result.total_engine_hours = (decode32(
        &message.payload[11]
    ) >> 0) & 0xffffffff;
    result.coolant_pressure = (decode16(
        &message.payload[15]
    ) >> 0) & 0xffff;
    result.fuel_pressure = (decode16(
        &message.payload[17]
    ) >> 0) & 0xffff;
    result.reserved = (decode8(
        &message.payload[19]
    ) >> 0) & 0xff;
    auto discrete_status_1_raw = decode16(
        &message.payload[20]
    );
    result.discrete_status_1 = reinterpret_cast<int16_t const&>(
        discrete_status_1_raw
    );
    auto discrete_status_2_raw = decode16(
        &message.payload[22]
    );
    result.discrete_status_2 = reinterpret_cast<int16_t const&>(
        discrete_status_2_raw
    );
    auto percent_engine_load_raw = decode8(
        &message.payload[24]
    );
    result.percent_engine_load = reinterpret_cast<int8_t const&>(
        percent_engine_load_raw
    );
    auto percent_engine_torque_raw = decode8(
        &message.payload[25]
    );
    result.percent_engine_torque = reinterpret_cast<int8_t const&>(
        percent_engine_torque_raw
    );
    return result;
}
const int TransmissionParametersDynamic::BYTE_LENGTH;
const int TransmissionParametersDynamic::ID;

TransmissionParametersDynamic TransmissionParametersDynamic::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    TransmissionParametersDynamic result;
    result.time = message.time;

    result.engine_instance = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.transmission_gear = (decode8(
        &message.payload[1]
    ) >> 0) & 0x3;
    result.reserved = (decode8(
        &message.payload[1]
    ) >> 2) & 0x3f;
    result.oil_pressure = (decode16(
        &message.payload[2]
    ) >> 0) & 0xffff;
    auto oil_temperature_raw = decode16(
        &message.payload[4]
    );
    uint16_t oil_temperature_iraw =
        reinterpret_cast<uint16_t const&>(oil_temperature_raw);
    result.oil_temperature = oil_temperature_iraw * 0.01 + -273.15;
    auto discrete_status_1_raw = decode8(
        &message.payload[6]
    );
    result.discrete_status_1 = reinterpret_cast<int8_t const&>(
        discrete_status_1_raw
    );
    return result;
}
const int TripParametersVessel::BYTE_LENGTH;
const int TripParametersVessel::ID;

TripParametersVessel TripParametersVessel::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    TripParametersVessel result;
    result.time = message.time;

    auto time_to_empty_raw = decode32(
        &message.payload[0]
    );
    int32_t time_to_empty_iraw =
        reinterpret_cast<int32_t const&>(time_to_empty_raw);
    result.time_to_empty = time_to_empty_iraw * 0.001 + 0.0;
    auto distance_to_empty_raw = decode32(
        &message.payload[4]
    );
    int32_t distance_to_empty_iraw =
        reinterpret_cast<int32_t const&>(distance_to_empty_raw);
    result.distance_to_empty = distance_to_empty_iraw * 0.01 + 0.0;
    result.estimated_fuel_remaining = (decode16(
        &message.payload[8]
    ) >> 0) & 0xffff;
    auto trip_run_time_raw = decode32(
        &message.payload[10]
    );
    int32_t trip_run_time_iraw =
        reinterpret_cast<int32_t const&>(trip_run_time_raw);
    result.trip_run_time = trip_run_time_iraw * 0.001 + 0.0;
    return result;
}
const int TripParametersEngine::BYTE_LENGTH;
const int TripParametersEngine::ID;

TripParametersEngine TripParametersEngine::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    TripParametersEngine result;
    result.time = message.time;

    result.engine_instance = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.trip_fuel_used = (decode16(
        &message.payload[1]
    ) >> 0) & 0xffff;
    auto fuel_rate_average_raw = decode16(
        &message.payload[3]
    );
    int16_t fuel_rate_average_iraw =
        reinterpret_cast<int16_t const&>(fuel_rate_average_raw);
    result.fuel_rate_average = fuel_rate_average_iraw * 0.1 + 0.0;
    auto fuel_rate_economy_raw = decode16(
        &message.payload[5]
    );
    int16_t fuel_rate_economy_iraw =
        reinterpret_cast<int16_t const&>(fuel_rate_economy_raw);
    result.fuel_rate_economy = fuel_rate_economy_iraw * 0.1 + 0.0;
    auto instantaneous_fuel_economy_raw = decode16(
        &message.payload[7]
    );
    int16_t instantaneous_fuel_economy_iraw =
        reinterpret_cast<int16_t const&>(instantaneous_fuel_economy_raw);
    result.instantaneous_fuel_economy = instantaneous_fuel_economy_iraw * 0.1 + 0.0;
    return result;
}
const int EngineParametersStatic::BYTE_LENGTH;
const int EngineParametersStatic::ID;

EngineParametersStatic EngineParametersStatic::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    EngineParametersStatic result;
    result.time = message.time;

    result.engine_instance = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.rated_engine_speed = (decode16(
        &message.payload[1]
    ) >> 0) & 0xffff;
    result.vin = (decode8(
        &message.payload[3]
    ) >> 0) & 0xff;
    result.software_id = (decode16(
        &message.payload[4]
    ) >> 0) & 0xffff;
    return result;
}
const int BinarySwitchBankStatus::BYTE_LENGTH;
const int BinarySwitchBankStatus::ID;

BinarySwitchBankStatus BinarySwitchBankStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    BinarySwitchBankStatus result;
    result.time = message.time;

    result.indicator_bank_instance = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.indicator = (decode8(
        &message.payload[1]
    ) >> 0) & 0x3;
    return result;
}
const int SwitchBankControl::BYTE_LENGTH;
const int SwitchBankControl::ID;

SwitchBankControl SwitchBankControl::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SwitchBankControl result;
    result.time = message.time;

    result.switch_bank_instance = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.switch_state = (decode8(
        &message.payload[1]
    ) >> 0) & 0x3;
    return result;
}
const int ACInputStatus::BYTE_LENGTH;
const int ACInputStatus::ID;

ACInputStatus ACInputStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    ACInputStatus result;
    result.time = message.time;

    result.ac_instance = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.number_of_lines = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.line = (decode8(
        &message.payload[2]
    ) >> 0) & 0x3;
    result.acceptability = (decode8(
        &message.payload[2]
    ) >> 2) & 0x3;
    result.reserved = (decode8(
        &message.payload[2]
    ) >> 4) & 0xf;
    auto voltage_raw = decode16(
        &message.payload[3]
    );
    int16_t voltage_iraw =
        reinterpret_cast<int16_t const&>(voltage_raw);
    result.voltage = voltage_iraw * 0.01 + 0.0;
    auto current_raw = decode16(
        &message.payload[5]
    );
    int16_t current_iraw =
        reinterpret_cast<int16_t const&>(current_raw);
    result.current = current_iraw * 0.1 + 0.0;
    auto frequency_raw = decode16(
        &message.payload[7]
    );
    int16_t frequency_iraw =
        reinterpret_cast<int16_t const&>(frequency_raw);
    result.frequency = frequency_iraw * 0.01 + 0.0;
    auto breaker_size_raw = decode16(
        &message.payload[9]
    );
    int16_t breaker_size_iraw =
        reinterpret_cast<int16_t const&>(breaker_size_raw);
    result.breaker_size = breaker_size_iraw * 0.1 + 0.0;
    auto real_power_raw = decode32(
        &message.payload[11]
    );
    result.real_power = reinterpret_cast<int32_t const&>(
        real_power_raw
    );
    auto reactive_power_raw = decode32(
        &message.payload[15]
    );
    result.reactive_power = reinterpret_cast<int32_t const&>(
        reactive_power_raw
    );
    auto power_factor_raw = decode8(
        &message.payload[19]
    );
    int8_t power_factor_iraw =
        reinterpret_cast<int8_t const&>(power_factor_raw);
    result.power_factor = power_factor_iraw * 0.01 + 0.0;
    return result;
}
const int ACOutputStatus::BYTE_LENGTH;
const int ACOutputStatus::ID;

ACOutputStatus ACOutputStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    ACOutputStatus result;
    result.time = message.time;

    result.ac_instance = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.number_of_lines = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.line = (decode8(
        &message.payload[2]
    ) >> 0) & 0x3;
    result.waveform = (decode8(
        &message.payload[2]
    ) >> 2) & 0x7;
    result.reserved = (decode8(
        &message.payload[2]
    ) >> 5) & 0x7;
    auto voltage_raw = decode16(
        &message.payload[3]
    );
    int16_t voltage_iraw =
        reinterpret_cast<int16_t const&>(voltage_raw);
    result.voltage = voltage_iraw * 0.01 + 0.0;
    auto current_raw = decode16(
        &message.payload[5]
    );
    int16_t current_iraw =
        reinterpret_cast<int16_t const&>(current_raw);
    result.current = current_iraw * 0.1 + 0.0;
    auto frequency_raw = decode16(
        &message.payload[7]
    );
    int16_t frequency_iraw =
        reinterpret_cast<int16_t const&>(frequency_raw);
    result.frequency = frequency_iraw * 0.01 + 0.0;
    auto breaker_size_raw = decode16(
        &message.payload[9]
    );
    int16_t breaker_size_iraw =
        reinterpret_cast<int16_t const&>(breaker_size_raw);
    result.breaker_size = breaker_size_iraw * 0.1 + 0.0;
    auto real_power_raw = decode32(
        &message.payload[11]
    );
    result.real_power = reinterpret_cast<int32_t const&>(
        real_power_raw
    );
    auto reactive_power_raw = decode32(
        &message.payload[15]
    );
    result.reactive_power = reinterpret_cast<int32_t const&>(
        reactive_power_raw
    );
    auto power_factor_raw = decode8(
        &message.payload[19]
    );
    int8_t power_factor_iraw =
        reinterpret_cast<int8_t const&>(power_factor_raw);
    result.power_factor = power_factor_iraw * 0.01 + 0.0;
    return result;
}
const int FluidLevel::BYTE_LENGTH;
const int FluidLevel::ID;

FluidLevel FluidLevel::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    FluidLevel result;
    result.time = message.time;

    result.instance = (decode8(
        &message.payload[0]
    ) >> 0) & 0xf;
    result.type = (decode8(
        &message.payload[0]
    ) >> 4) & 0xf;
    auto level_raw = decode16(
        &message.payload[1]
    );
    int16_t level_iraw =
        reinterpret_cast<int16_t const&>(level_raw);
    result.level = level_iraw * 0.004 + 0.0;
    auto capacity_raw = decode32(
        &message.payload[3]
    );
    int32_t capacity_iraw =
        reinterpret_cast<int32_t const&>(capacity_raw);
    result.capacity = capacity_iraw * 0.1 + 0.0;
    result.reserved = (decode8(
        &message.payload[7]
    ) >> 0) & 0xff;
    return result;
}
const int DCDetailedStatus::BYTE_LENGTH;
const int DCDetailedStatus::ID;

DCDetailedStatus DCDetailedStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    DCDetailedStatus result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.dc_instance = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.dc_type = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    result.state_of_charge = (decode8(
        &message.payload[3]
    ) >> 0) & 0xff;
    result.state_of_health = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result.time_remaining = (decode16(
        &message.payload[5]
    ) >> 0) & 0xffff;
    auto ripple_voltage_raw = decode16(
        &message.payload[7]
    );
    int16_t ripple_voltage_iraw =
        reinterpret_cast<int16_t const&>(ripple_voltage_raw);
    result.ripple_voltage = ripple_voltage_iraw * 0.001 + 0.0;
    return result;
}
const int ChargerStatus::BYTE_LENGTH;
const int ChargerStatus::ID;

ChargerStatus ChargerStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    ChargerStatus result;
    result.time = message.time;

    result.charger_instance = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.battery_instance = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.operating_state = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    result.charge_mode = (decode8(
        &message.payload[3]
    ) >> 0) & 0xff;
    result.charger_enable_disable = (decode8(
        &message.payload[4]
    ) >> 0) & 0x3;
    result.equalization_pending = (decode8(
        &message.payload[4]
    ) >> 2) & 0x3;
    result.reserved = (decode8(
        &message.payload[4]
    ) >> 4) & 0xf;
    result.equalization_time_remaining = (decode16(
        &message.payload[5]
    ) >> 0) & 0xffff;
    return result;
}
const int BatteryStatus::BYTE_LENGTH;
const int BatteryStatus::ID;

BatteryStatus BatteryStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    BatteryStatus result;
    result.time = message.time;

    result.battery_instance = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    auto voltage_raw = decode16(
        &message.payload[1]
    );
    int16_t voltage_iraw =
        reinterpret_cast<int16_t const&>(voltage_raw);
    result.voltage = voltage_iraw * 0.01 + 0.0;
    auto current_raw = decode16(
        &message.payload[3]
    );
    int16_t current_iraw =
        reinterpret_cast<int16_t const&>(current_raw);
    result.current = current_iraw * 0.1 + 0.0;
    auto temperature_raw = decode16(
        &message.payload[5]
    );
    uint16_t temperature_iraw =
        reinterpret_cast<uint16_t const&>(temperature_raw);
    result.temperature = temperature_iraw * 0.01 + -273.15;
    result.sid = (decode8(
        &message.payload[7]
    ) >> 0) & 0xff;
    return result;
}
const int InverterStatus::BYTE_LENGTH;
const int InverterStatus::ID;

InverterStatus InverterStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    InverterStatus result;
    result.time = message.time;

    result.inverter_instance = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.ac_instance = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.dc_instance = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    result.operating_state = (decode8(
        &message.payload[3]
    ) >> 0) & 0xf;
    result.inverter = (decode8(
        &message.payload[3]
    ) >> 4) & 0x3;
    return result;
}
const int ChargerConfigurationStatus::BYTE_LENGTH;
const int ChargerConfigurationStatus::ID;

ChargerConfigurationStatus ChargerConfigurationStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    ChargerConfigurationStatus result;
    result.time = message.time;

    result.charger_instance = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.battery_instance = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.charger_enable_disable = (decode8(
        &message.payload[2]
    ) >> 0) & 0x3;
    result.reserved = (decode8(
        &message.payload[2]
    ) >> 2) & 0x3f;
    auto charge_current_limit_raw = decode16(
        &message.payload[3]
    );
    int16_t charge_current_limit_iraw =
        reinterpret_cast<int16_t const&>(charge_current_limit_raw);
    result.charge_current_limit = charge_current_limit_iraw * 0.1 + 0.0;
    result.charging_algorithm = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.charger_mode = (decode8(
        &message.payload[6]
    ) >> 0) & 0xff;
    auto estimated_temperature_raw = decode16(
        &message.payload[7]
    );
    uint16_t estimated_temperature_iraw =
        reinterpret_cast<uint16_t const&>(estimated_temperature_raw);
    result.estimated_temperature = estimated_temperature_iraw * 0.01 + -273.15;
    result.equalize_one_time_enable_disable = (decode8(
        &message.payload[9]
    ) >> 0) & 0xf;
    result.over_charge_enable_disable = (decode8(
        &message.payload[9]
    ) >> 4) & 0xf;
    result.equalize_time = (decode16(
        &message.payload[10]
    ) >> 0) & 0xffff;
    return result;
}
const int InverterConfigurationStatus::BYTE_LENGTH;
const int InverterConfigurationStatus::ID;

InverterConfigurationStatus InverterConfigurationStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    InverterConfigurationStatus result;
    result.time = message.time;

    result.inverter_instance = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.ac_instance = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.dc_instance = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    result.inverter_enable_disable = (decode8(
        &message.payload[3]
    ) >> 0) & 0x3;
    result.inverter_mode = (decode8(
        &message.payload[3]
    ) >> 2) & 0xff;
    result.load_sense_enable_disable = (decode8(
        &message.payload[4]
    ) >> 2) & 0xff;
    result.load_sense_power_threshold = (decode8(
        &message.payload[5]
    ) >> 2) & 0xff;
    result.load_sense_interval = (decode8(
        &message.payload[6]
    ) >> 2) & 0xff;
    return result;
}
const int AGSConfigurationStatus::BYTE_LENGTH;
const int AGSConfigurationStatus::ID;

AGSConfigurationStatus AGSConfigurationStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AGSConfigurationStatus result;
    result.time = message.time;

    result.ags_instance = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.generator_instance = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.ags_mode = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    return result;
}
const int BatteryConfigurationStatus::BYTE_LENGTH;
const int BatteryConfigurationStatus::ID;

BatteryConfigurationStatus BatteryConfigurationStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    BatteryConfigurationStatus result;
    result.time = message.time;

    result.battery_instance = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.battery_type = (decode8(
        &message.payload[1]
    ) >> 0) & 0xf;
    result.supports_equalization = (decode8(
        &message.payload[1]
    ) >> 4) & 0x3;
    result.reserved = (decode8(
        &message.payload[1]
    ) >> 6) & 0x3;
    result.nominal_voltage = (decode8(
        &message.payload[2]
    ) >> 0) & 0xf;
    result.chemistry = (decode8(
        &message.payload[2]
    ) >> 4) & 0xf;
    result.capacity = (decode16(
        &message.payload[3]
    ) >> 0) & 0xffff;
    result.temperature_coefficient = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.peukert_exponent = (decode8(
        &message.payload[6]
    ) >> 0) & 0xff;
    result.charge_efficiency_factor = (decode8(
        &message.payload[7]
    ) >> 0) & 0xff;
    return result;
}
const int AGSStatus::BYTE_LENGTH;
const int AGSStatus::ID;

AGSStatus AGSStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AGSStatus result;
    result.time = message.time;

    result.ags_instance = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.generator_instance = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.ags_operating_state = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    result.generator_state = (decode8(
        &message.payload[3]
    ) >> 0) & 0xff;
    result.generator_on_reason = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result.generator_off_reason = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    return result;
}
const int Speed::BYTE_LENGTH;
const int Speed::ID;

Speed Speed::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    Speed result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    auto speed_water_referenced_raw = decode16(
        &message.payload[1]
    );
    int16_t speed_water_referenced_iraw =
        reinterpret_cast<int16_t const&>(speed_water_referenced_raw);
    result.speed_water_referenced = speed_water_referenced_iraw * 0.01 + 0.0;
    auto speed_ground_referenced_raw = decode16(
        &message.payload[3]
    );
    int16_t speed_ground_referenced_iraw =
        reinterpret_cast<int16_t const&>(speed_ground_referenced_raw);
    result.speed_ground_referenced = speed_ground_referenced_iraw * 0.01 + 0.0;
    result.speed_water_referenced_type = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.reserved = (decode16(
        &message.payload[6]
    ) >> 0) & 0xffff;
    return result;
}
const int WaterDepth::BYTE_LENGTH;
const int WaterDepth::ID;

WaterDepth WaterDepth::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    WaterDepth result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    auto depth_raw = decode32(
        &message.payload[1]
    );
    uint32_t depth_iraw =
        reinterpret_cast<uint32_t const&>(depth_raw);
    result.depth = depth_iraw * 0.01 + 0.0;
    auto offset_raw = decode16(
        &message.payload[5]
    );
    int16_t offset_iraw =
        reinterpret_cast<int16_t const&>(offset_raw);
    result.offset = offset_iraw * 0.001 + 0.0;
    auto range_raw = decode8(
        &message.payload[7]
    );
    int8_t range_iraw =
        reinterpret_cast<int8_t const&>(range_raw);
    result.range = range_iraw * 10.0 + 0.0;
    return result;
}
const int DistanceLog::BYTE_LENGTH;
const int DistanceLog::ID;

DistanceLog DistanceLog::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    DistanceLog result;
    result.time = message.time;

    result.date = (decode16(
        &message.payload[0]
    ) >> 0) & 0xffff;
    auto seconds_since_midnight_raw = decode32(
        &message.payload[2]
    );
    uint32_t seconds_since_midnight_iraw =
        reinterpret_cast<uint32_t const&>(seconds_since_midnight_raw);
    result.seconds_since_midnight = seconds_since_midnight_iraw * 0.0001 + 0.0;
    result.log = (decode32(
        &message.payload[6]
    ) >> 0) & 0xffffffff;
    result.trip_log = (decode32(
        &message.payload[10]
    ) >> 0) & 0xffffffff;
    return result;
}
const int TrackedTargetData::BYTE_LENGTH;
const int TrackedTargetData::ID;

TrackedTargetData TrackedTargetData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    TrackedTargetData result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.target_id_number = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.track_status = (decode8(
        &message.payload[2]
    ) >> 0) & 0x3;
    result.reported_target = (decode8(
        &message.payload[2]
    ) >> 2) & 0x1;
    result.target_acquisition = (decode8(
        &message.payload[2]
    ) >> 3) & 0x1;
    result.bearing_reference = (decode8(
        &message.payload[2]
    ) >> 4) & 0x3;
    result.reserved = (decode8(
        &message.payload[2]
    ) >> 6) & 0x3;
    auto bearing_raw = decode16(
        &message.payload[3]
    );
    uint16_t bearing_iraw =
        reinterpret_cast<uint16_t const&>(bearing_raw);
    result.bearing = bearing_iraw * 0.005729577951308233 + 0.0;
    auto distance_raw = decode32(
        &message.payload[5]
    );
    int32_t distance_iraw =
        reinterpret_cast<int32_t const&>(distance_raw);
    result.distance = distance_iraw * 0.001 + 0.0;
    auto course_raw = decode16(
        &message.payload[9]
    );
    uint16_t course_iraw =
        reinterpret_cast<uint16_t const&>(course_raw);
    result.course = course_iraw * 0.005729577951308233 + 0.0;
    auto speed_raw = decode16(
        &message.payload[11]
    );
    uint16_t speed_iraw =
        reinterpret_cast<uint16_t const&>(speed_raw);
    result.speed = speed_iraw * 0.01 + 0.0;
    auto cpa_raw = decode32(
        &message.payload[13]
    );
    int32_t cpa_iraw =
        reinterpret_cast<int32_t const&>(cpa_raw);
    result.cpa = cpa_iraw * 0.01 + 0.0;
    auto tcpa_raw = decode32(
        &message.payload[17]
    );
    int32_t tcpa_iraw =
        reinterpret_cast<int32_t const&>(tcpa_raw);
    result.tcpa = tcpa_iraw * 0.001 + 0.0;
    auto utc_of_fix_raw = decode32(
        &message.payload[21]
    );
    uint32_t utc_of_fix_iraw =
        reinterpret_cast<uint32_t const&>(utc_of_fix_raw);
    result.utc_of_fix = utc_of_fix_iraw * 0.0001 + 0.0;
    result.name = decodeString(&message.payload[25],
                                            256);
    return result;
}
const int PositionRapidUpdate::BYTE_LENGTH;
const int PositionRapidUpdate::ID;

PositionRapidUpdate PositionRapidUpdate::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    PositionRapidUpdate result;
    result.time = message.time;

    auto latitude_raw = decode32(
        &message.payload[0]
    );
    int32_t latitude_iraw =
        reinterpret_cast<int32_t const&>(latitude_raw);
    result.latitude = latitude_iraw * 1.0e-07 + 0.0;
    auto longitude_raw = decode32(
        &message.payload[4]
    );
    int32_t longitude_iraw =
        reinterpret_cast<int32_t const&>(longitude_raw);
    result.longitude = longitude_iraw * 1.0e-07 + 0.0;
    return result;
}
const int COGSOGRapidUpdate::BYTE_LENGTH;
const int COGSOGRapidUpdate::ID;

COGSOGRapidUpdate COGSOGRapidUpdate::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    COGSOGRapidUpdate result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.cog_reference = (decode8(
        &message.payload[1]
    ) >> 0) & 0x3;
    auto cog_raw = decode16(
        &message.payload[2]
    );
    uint16_t cog_iraw =
        reinterpret_cast<uint16_t const&>(cog_raw);
    result.cog = cog_iraw * 0.005729577951308233 + 0.0;
    auto sog_raw = decode16(
        &message.payload[4]
    );
    uint16_t sog_iraw =
        reinterpret_cast<uint16_t const&>(sog_raw);
    result.sog = sog_iraw * 0.01 + 0.0;
    return result;
}
const int PositionDeltaRapidUpdate::BYTE_LENGTH;
const int PositionDeltaRapidUpdate::ID;

PositionDeltaRapidUpdate PositionDeltaRapidUpdate::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    PositionDeltaRapidUpdate result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.time_delta = (decode16(
        &message.payload[1]
    ) >> 0) & 0xffff;
    result.latitude_delta = (decode16(
        &message.payload[3]
    ) >> 0) & 0xffff;
    result.longitude_delta = (decode16(
        &message.payload[5]
    ) >> 0) & 0xffff;
    return result;
}
const int AltitudeDeltaRapidUpdate::BYTE_LENGTH;
const int AltitudeDeltaRapidUpdate::ID;

AltitudeDeltaRapidUpdate AltitudeDeltaRapidUpdate::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AltitudeDeltaRapidUpdate result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.time_delta = (decode16(
        &message.payload[1]
    ) >> 0) & 0xffff;
    result.gnss_quality = (decode8(
        &message.payload[3]
    ) >> 0) & 0x3;
    result.direction = (decode8(
        &message.payload[3]
    ) >> 2) & 0x3;
    auto course_over_ground_raw = decode32(
        &message.payload[4]
    );
    uint32_t course_over_ground_iraw =
        reinterpret_cast<uint32_t const&>(course_over_ground_raw);
    result.course_over_ground = course_over_ground_iraw * 0.005729577951308233 + 0.0;
    result.altitude_delta = (decode16(
        &message.payload[8]
    ) >> 0) & 0xffff;
    return result;
}
const int GNSSPositionData::BYTE_LENGTH;
const int GNSSPositionData::ID;

GNSSPositionData GNSSPositionData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    GNSSPositionData result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.date = (decode16(
        &message.payload[1]
    ) >> 0) & 0xffff;
    auto seconds_since_midnight_raw = decode32(
        &message.payload[3]
    );
    uint32_t seconds_since_midnight_iraw =
        reinterpret_cast<uint32_t const&>(seconds_since_midnight_raw);
    result.seconds_since_midnight = seconds_since_midnight_iraw * 0.0001 + 0.0;
    auto latitude_raw = decode64(
        &message.payload[7]
    );
    int64_t latitude_iraw =
        reinterpret_cast<int64_t const&>(latitude_raw);
    result.latitude = latitude_iraw * 1.0e-16 + 0.0;
    auto longitude_raw = decode64(
        &message.payload[15]
    );
    int64_t longitude_iraw =
        reinterpret_cast<int64_t const&>(longitude_raw);
    result.longitude = longitude_iraw * 1.0e-16 + 0.0;
    auto altitude_raw = decode64(
        &message.payload[23]
    );
    int64_t altitude_iraw =
        reinterpret_cast<int64_t const&>(altitude_raw);
    result.altitude = altitude_iraw * 1.0e-06 + 0.0;
    result.gnss_type = (decode8(
        &message.payload[31]
    ) >> 0) & 0xf;
    result.method = (decode8(
        &message.payload[31]
    ) >> 4) & 0xf;
    result.integrity = (decode8(
        &message.payload[32]
    ) >> 0) & 0x3;
    result.number_of_svs = (decode8(
        &message.payload[33]
    ) >> 0) & 0xff;
    auto hdop_raw = decode16(
        &message.payload[34]
    );
    int16_t hdop_iraw =
        reinterpret_cast<int16_t const&>(hdop_raw);
    result.hdop = hdop_iraw * 0.01 + 0.0;
    auto pdop_raw = decode16(
        &message.payload[36]
    );
    int16_t pdop_iraw =
        reinterpret_cast<int16_t const&>(pdop_raw);
    result.pdop = pdop_iraw * 0.01 + 0.0;
    auto geoidal_separation_raw = decode16(
        &message.payload[38]
    );
    int16_t geoidal_separation_iraw =
        reinterpret_cast<int16_t const&>(geoidal_separation_raw);
    result.geoidal_separation = geoidal_separation_iraw * 0.01 + 0.0;
    result.reference_stations = (decode8(
        &message.payload[40]
    ) >> 0) & 0xff;
    result.reference_station_type = (decode8(
        &message.payload[41]
    ) >> 0) & 0xf;
    result.reference_station_id = (decode16(
        &message.payload[41]
    ) >> 4) & 0xfff;
    auto age_of_dgnss_corrections_raw = decode16(
        &message.payload[43]
    );
    int16_t age_of_dgnss_corrections_iraw =
        reinterpret_cast<int16_t const&>(age_of_dgnss_corrections_raw);
    result.age_of_dgnss_corrections = age_of_dgnss_corrections_iraw * 0.01 + 0.0;
    return result;
}
const int TimeDate::BYTE_LENGTH;
const int TimeDate::ID;

TimeDate TimeDate::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    TimeDate result;
    result.time = message.time;

    result.date = (decode16(
        &message.payload[0]
    ) >> 0) & 0xffff;
    auto seconds_since_midnight_raw = decode32(
        &message.payload[2]
    );
    uint32_t seconds_since_midnight_iraw =
        reinterpret_cast<uint32_t const&>(seconds_since_midnight_raw);
    result.seconds_since_midnight = seconds_since_midnight_iraw * 0.0001 + 0.0;
    auto local_offset_raw = decode16(
        &message.payload[6]
    );
    result.local_offset = reinterpret_cast<int16_t const&>(
        local_offset_raw
    );
    return result;
}
const int AISClassAPositionReport::BYTE_LENGTH;
const int AISClassAPositionReport::ID;

AISClassAPositionReport AISClassAPositionReport::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISClassAPositionReport result;
    result.time = message.time;

    result.message_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0x3f;
    result.repeat_indicator = (decode8(
        &message.payload[0]
    ) >> 6) & 0x3;
    auto user_id_raw = decode32(
        &message.payload[1]
    );
    result.user_id = reinterpret_cast<int32_t const&>(
        user_id_raw
    );
    auto longitude_raw = decode32(
        &message.payload[5]
    );
    int32_t longitude_iraw =
        reinterpret_cast<int32_t const&>(longitude_raw);
    result.longitude = longitude_iraw * 1.0e-07 + 0.0;
    auto latitude_raw = decode32(
        &message.payload[9]
    );
    int32_t latitude_iraw =
        reinterpret_cast<int32_t const&>(latitude_raw);
    result.latitude = latitude_iraw * 1.0e-07 + 0.0;
    result.position_accuracy = (decode8(
        &message.payload[13]
    ) >> 0) & 0x1;
    result.raim = (decode8(
        &message.payload[13]
    ) >> 1) & 0x1;
    result.time_stamp = (decode8(
        &message.payload[13]
    ) >> 2) & 0x3f;
    auto cog_raw = decode16(
        &message.payload[14]
    );
    uint16_t cog_iraw =
        reinterpret_cast<uint16_t const&>(cog_raw);
    result.cog = cog_iraw * 0.005729577951308233 + 0.0;
    auto sog_raw = decode16(
        &message.payload[16]
    );
    uint16_t sog_iraw =
        reinterpret_cast<uint16_t const&>(sog_raw);
    result.sog = sog_iraw * 0.01 + 0.0;
    result.ais_transceiver_information = (decode8(
        &message.payload[20]
    ) >> 3) & 0x1f;
    auto heading_raw = decode16(
        &message.payload[21]
    );
    uint16_t heading_iraw =
        reinterpret_cast<uint16_t const&>(heading_raw);
    result.heading = heading_iraw * 0.005729577951308233 + 0.0;
    auto rate_of_turn_raw = decode16(
        &message.payload[23]
    );
    uint16_t rate_of_turn_iraw =
        reinterpret_cast<uint16_t const&>(rate_of_turn_raw);
    result.rate_of_turn = rate_of_turn_iraw * 0.005729577951308233 + 0.0;
    result.nav_status = (decode8(
        &message.payload[25]
    ) >> 0) & 0xff;
    result.reserved_for_regional_applications = (decode8(
        &message.payload[26]
    ) >> 0) & 0xff;
    result.spare = (decode8(
        &message.payload[27]
    ) >> 0) & 0xff;
    return result;
}
const int AISClassBPositionReport::BYTE_LENGTH;
const int AISClassBPositionReport::ID;

AISClassBPositionReport AISClassBPositionReport::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISClassBPositionReport result;
    result.time = message.time;

    result.message_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0x3f;
    result.repeat_indicator = (decode8(
        &message.payload[0]
    ) >> 6) & 0x3;
    auto user_id_raw = decode32(
        &message.payload[1]
    );
    result.user_id = reinterpret_cast<int32_t const&>(
        user_id_raw
    );
    auto longitude_raw = decode32(
        &message.payload[5]
    );
    int32_t longitude_iraw =
        reinterpret_cast<int32_t const&>(longitude_raw);
    result.longitude = longitude_iraw * 1.0e-07 + 0.0;
    auto latitude_raw = decode32(
        &message.payload[9]
    );
    int32_t latitude_iraw =
        reinterpret_cast<int32_t const&>(latitude_raw);
    result.latitude = latitude_iraw * 1.0e-07 + 0.0;
    result.position_accuracy = (decode8(
        &message.payload[13]
    ) >> 0) & 0x1;
    result.raim = (decode8(
        &message.payload[13]
    ) >> 1) & 0x1;
    result.time_stamp = (decode8(
        &message.payload[13]
    ) >> 2) & 0x3f;
    auto cog_raw = decode16(
        &message.payload[14]
    );
    uint16_t cog_iraw =
        reinterpret_cast<uint16_t const&>(cog_raw);
    result.cog = cog_iraw * 0.005729577951308233 + 0.0;
    auto sog_raw = decode16(
        &message.payload[16]
    );
    uint16_t sog_iraw =
        reinterpret_cast<uint16_t const&>(sog_raw);
    result.sog = sog_iraw * 0.01 + 0.0;
    result.ais_transceiver_information = (decode8(
        &message.payload[20]
    ) >> 3) & 0x1f;
    auto heading_raw = decode16(
        &message.payload[21]
    );
    uint16_t heading_iraw =
        reinterpret_cast<uint16_t const&>(heading_raw);
    result.heading = heading_iraw * 0.005729577951308233 + 0.0;
    result.regional_application = (decode8(
        &message.payload[23]
    ) >> 0) & 0xff;
    result.regional_application1 = (decode8(
        &message.payload[24]
    ) >> 0) & 0x3;
    result.unit_type = (decode8(
        &message.payload[24]
    ) >> 2) & 0x1;
    result.integrated_display = (decode8(
        &message.payload[24]
    ) >> 3) & 0x1;
    result.dsc = (decode8(
        &message.payload[24]
    ) >> 4) & 0x1;
    result.band = (decode8(
        &message.payload[24]
    ) >> 5) & 0x1;
    result.can_handle_msg_22 = (decode8(
        &message.payload[24]
    ) >> 6) & 0x1;
    result.ais_mode = (decode8(
        &message.payload[24]
    ) >> 7) & 0x1;
    result.ais_communication_state = (decode8(
        &message.payload[25]
    ) >> 0) & 0x1;
    return result;
}
const int AISClassBExtendedPositionReport::BYTE_LENGTH;
const int AISClassBExtendedPositionReport::ID;

AISClassBExtendedPositionReport AISClassBExtendedPositionReport::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISClassBExtendedPositionReport result;
    result.time = message.time;

    result.message_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0x3f;
    result.repeat_indicator = (decode8(
        &message.payload[0]
    ) >> 6) & 0x3;
    auto user_id_raw = decode32(
        &message.payload[1]
    );
    result.user_id = reinterpret_cast<int32_t const&>(
        user_id_raw
    );
    auto longitude_raw = decode32(
        &message.payload[5]
    );
    int32_t longitude_iraw =
        reinterpret_cast<int32_t const&>(longitude_raw);
    result.longitude = longitude_iraw * 1.0e-07 + 0.0;
    auto latitude_raw = decode32(
        &message.payload[9]
    );
    int32_t latitude_iraw =
        reinterpret_cast<int32_t const&>(latitude_raw);
    result.latitude = latitude_iraw * 1.0e-07 + 0.0;
    result.position_accuracy = (decode8(
        &message.payload[13]
    ) >> 0) & 0x1;
    result.ais_raim_flag = (decode8(
        &message.payload[13]
    ) >> 1) & 0x1;
    result.time_stamp = (decode8(
        &message.payload[13]
    ) >> 2) & 0x3f;
    auto cog_raw = decode16(
        &message.payload[14]
    );
    uint16_t cog_iraw =
        reinterpret_cast<uint16_t const&>(cog_raw);
    result.cog = cog_iraw * 0.005729577951308233 + 0.0;
    auto sog_raw = decode16(
        &message.payload[16]
    );
    uint16_t sog_iraw =
        reinterpret_cast<uint16_t const&>(sog_raw);
    result.sog = sog_iraw * 0.01 + 0.0;
    result.regional_application = (decode8(
        &message.payload[18]
    ) >> 0) & 0xff;
    result.regional_application1 = (decode8(
        &message.payload[19]
    ) >> 0) & 0xf;
    result.type_of_ship = (decode8(
        &message.payload[20]
    ) >> 0) & 0xff;
    auto true_heading_raw = decode16(
        &message.payload[21]
    );
    uint16_t true_heading_iraw =
        reinterpret_cast<uint16_t const&>(true_heading_raw);
    result.true_heading = true_heading_iraw * 0.005729577951308233 + 0.0;
    result.gnss_type = (decode8(
        &message.payload[23]
    ) >> 4) & 0xf;
    auto length_raw = decode16(
        &message.payload[24]
    );
    int16_t length_iraw =
        reinterpret_cast<int16_t const&>(length_raw);
    result.length = length_iraw * 0.1 + 0.0;
    auto beam_raw = decode16(
        &message.payload[26]
    );
    int16_t beam_iraw =
        reinterpret_cast<int16_t const&>(beam_raw);
    result.beam = beam_iraw * 0.1 + 0.0;
    auto position_reference_from_starboard_raw = decode16(
        &message.payload[28]
    );
    int16_t position_reference_from_starboard_iraw =
        reinterpret_cast<int16_t const&>(position_reference_from_starboard_raw);
    result.position_reference_from_starboard = position_reference_from_starboard_iraw * 0.1 + 0.0;
    auto position_reference_from_bow_raw = decode16(
        &message.payload[30]
    );
    int16_t position_reference_from_bow_iraw =
        reinterpret_cast<int16_t const&>(position_reference_from_bow_raw);
    result.position_reference_from_bow = position_reference_from_bow_iraw * 0.1 + 0.0;
    result.name = decodeString(&message.payload[32],
                                            32);
    result.dte = (decode8(
        &message.payload[52]
    ) >> 0) & 0x1;
    result.ais_mode = (decode8(
        &message.payload[52]
    ) >> 1) & 0x1;
    result.ais_transceiver_information = (decode8(
        &message.payload[52]
    ) >> 6) & 0x1f;
    return result;
}
const int Datum::BYTE_LENGTH;
const int Datum::ID;

Datum Datum::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    Datum result;
    result.time = message.time;

    result.local_datum = decodeString(&message.payload[0],
                                            4);
    auto delta_latitude_raw = decode32(
        &message.payload[4]
    );
    int32_t delta_latitude_iraw =
        reinterpret_cast<int32_t const&>(delta_latitude_raw);
    result.delta_latitude = delta_latitude_iraw * 1.0e-07 + 0.0;
    auto delta_longitude_raw = decode32(
        &message.payload[8]
    );
    int32_t delta_longitude_iraw =
        reinterpret_cast<int32_t const&>(delta_longitude_raw);
    result.delta_longitude = delta_longitude_iraw * 1.0e-07 + 0.0;
    auto delta_altitude_raw = decode32(
        &message.payload[12]
    );
    int32_t delta_altitude_iraw =
        reinterpret_cast<int32_t const&>(delta_altitude_raw);
    result.delta_altitude = delta_altitude_iraw * 1.0 + 0.0;
    result.reference_datum = decodeString(&message.payload[16],
                                            4);
    return result;
}
const int UserDatum::BYTE_LENGTH;
const int UserDatum::ID;

UserDatum UserDatum::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    UserDatum result;
    result.time = message.time;

    auto delta_x_raw = decode32(
        &message.payload[0]
    );
    int32_t delta_x_iraw =
        reinterpret_cast<int32_t const&>(delta_x_raw);
    result.delta_x = delta_x_iraw * 0.01 + 0.0;
    auto delta_y_raw = decode32(
        &message.payload[4]
    );
    int32_t delta_y_iraw =
        reinterpret_cast<int32_t const&>(delta_y_raw);
    result.delta_y = delta_y_iraw * 0.01 + 0.0;
    auto delta_z_raw = decode32(
        &message.payload[8]
    );
    int32_t delta_z_iraw =
        reinterpret_cast<int32_t const&>(delta_z_raw);
    result.delta_z = delta_z_iraw * 0.01 + 0.0;
    auto rotation_in_x_raw = decode32(
        &message.payload[12]
    );
    int32_t rotation_in_x_iraw =
        reinterpret_cast<int32_t const&>(rotation_in_x_raw);
    result.rotation_in_x = rotation_in_x_iraw * 1.0 + 0.0;
    auto rotation_in_y_raw = decode32(
        &message.payload[16]
    );
    int32_t rotation_in_y_iraw =
        reinterpret_cast<int32_t const&>(rotation_in_y_raw);
    result.rotation_in_y = rotation_in_y_iraw * 1.0 + 0.0;
    auto rotation_in_z_raw = decode32(
        &message.payload[20]
    );
    int32_t rotation_in_z_iraw =
        reinterpret_cast<int32_t const&>(rotation_in_z_raw);
    result.rotation_in_z = rotation_in_z_iraw * 1.0 + 0.0;
    auto scale_raw = decode32(
        &message.payload[24]
    );
    int32_t scale_iraw =
        reinterpret_cast<int32_t const&>(scale_raw);
    result.scale = scale_iraw * 1.0 + 0.0;
    auto ellipsoid_semi_major_axis_raw = decode32(
        &message.payload[28]
    );
    int32_t ellipsoid_semi_major_axis_iraw =
        reinterpret_cast<int32_t const&>(ellipsoid_semi_major_axis_raw);
    result.ellipsoid_semi_major_axis = ellipsoid_semi_major_axis_iraw * 0.01 + 0.0;
    auto ellipsoid_flattening_inverse_raw = decode32(
        &message.payload[32]
    );
    int32_t ellipsoid_flattening_inverse_iraw =
        reinterpret_cast<int32_t const&>(ellipsoid_flattening_inverse_raw);
    result.ellipsoid_flattening_inverse = ellipsoid_flattening_inverse_iraw * 1.0 + 0.0;
    result.datum_name = decodeString(&message.payload[36],
                                            4);
    return result;
}
const int CrossTrackError::BYTE_LENGTH;
const int CrossTrackError::ID;

CrossTrackError CrossTrackError::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    CrossTrackError result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.xte_mode = (decode8(
        &message.payload[1]
    ) >> 0) & 0xf;
    result.navigation_terminated = (decode8(
        &message.payload[1]
    ) >> 6) & 0x3;
    auto xte_raw = decode32(
        &message.payload[2]
    );
    int32_t xte_iraw =
        reinterpret_cast<int32_t const&>(xte_raw);
    result.xte = xte_iraw * 0.01 + 0.0;
    return result;
}
const int NavigationData::BYTE_LENGTH;
const int NavigationData::ID;

NavigationData NavigationData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    NavigationData result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    auto distance_to_waypoint_raw = decode32(
        &message.payload[1]
    );
    int32_t distance_to_waypoint_iraw =
        reinterpret_cast<int32_t const&>(distance_to_waypoint_raw);
    result.distance_to_waypoint = distance_to_waypoint_iraw * 0.01 + 0.0;
    result.course_bearing_reference = (decode8(
        &message.payload[5]
    ) >> 0) & 0x3;
    result.perpendicular_crossed = (decode8(
        &message.payload[5]
    ) >> 2) & 0x3;
    result.arrival_circle_entered = (decode8(
        &message.payload[5]
    ) >> 4) & 0x3;
    result.calculation_type = (decode8(
        &message.payload[5]
    ) >> 6) & 0x3;
    auto eta_time_raw = decode32(
        &message.payload[6]
    );
    uint32_t eta_time_iraw =
        reinterpret_cast<uint32_t const&>(eta_time_raw);
    result.eta_time = eta_time_iraw * 0.0001 + 0.0;
    result.eta_date = (decode16(
        &message.payload[10]
    ) >> 0) & 0xffff;
    auto bearing_origin_to_destination_waypoint_raw = decode16(
        &message.payload[12]
    );
    uint16_t bearing_origin_to_destination_waypoint_iraw =
        reinterpret_cast<uint16_t const&>(bearing_origin_to_destination_waypoint_raw);
    result.bearing_origin_to_destination_waypoint = bearing_origin_to_destination_waypoint_iraw * 0.005729577951308233 + 0.0;
    auto bearing_position_to_destination_waypoint_raw = decode16(
        &message.payload[14]
    );
    uint16_t bearing_position_to_destination_waypoint_iraw =
        reinterpret_cast<uint16_t const&>(bearing_position_to_destination_waypoint_raw);
    result.bearing_position_to_destination_waypoint = bearing_position_to_destination_waypoint_iraw * 0.005729577951308233 + 0.0;
    result.origin_waypoint_number = (decode32(
        &message.payload[16]
    ) >> 0) & 0xffffffff;
    result.destination_waypoint_number = (decode32(
        &message.payload[20]
    ) >> 0) & 0xffffffff;
    auto destination_latitude_raw = decode32(
        &message.payload[24]
    );
    int32_t destination_latitude_iraw =
        reinterpret_cast<int32_t const&>(destination_latitude_raw);
    result.destination_latitude = destination_latitude_iraw * 1.0e-07 + 0.0;
    auto destination_longitude_raw = decode32(
        &message.payload[28]
    );
    int32_t destination_longitude_iraw =
        reinterpret_cast<int32_t const&>(destination_longitude_raw);
    result.destination_longitude = destination_longitude_iraw * 1.0e-07 + 0.0;
    auto waypoint_closing_velocity_raw = decode16(
        &message.payload[32]
    );
    int16_t waypoint_closing_velocity_iraw =
        reinterpret_cast<int16_t const&>(waypoint_closing_velocity_raw);
    result.waypoint_closing_velocity = waypoint_closing_velocity_iraw * 0.01 + 0.0;
    return result;
}
const int NavigationRouteWPInformation::BYTE_LENGTH;
const int NavigationRouteWPInformation::ID;

NavigationRouteWPInformation NavigationRouteWPInformation::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    NavigationRouteWPInformation result;
    result.time = message.time;

    result.start_rpsnumber = (decode16(
        &message.payload[0]
    ) >> 0) & 0xffff;
    result.nitems = (decode16(
        &message.payload[2]
    ) >> 0) & 0xffff;
    result.database_id = (decode16(
        &message.payload[4]
    ) >> 0) & 0xffff;
    result.route_id = (decode16(
        &message.payload[6]
    ) >> 0) & 0xffff;
    result.navigation_direction_in_route = (decode8(
        &message.payload[8]
    ) >> 0) & 0x3;
    result.supplementary_route_wp_data_available = (decode8(
        &message.payload[8]
    ) >> 2) & 0x3;
    result.wp_id = (decode16(
        &message.payload[265]
    ) >> 0) & 0xffff;
    auto wp_latitude_raw = decode32(
        &message.payload[522]
    );
    int32_t wp_latitude_iraw =
        reinterpret_cast<int32_t const&>(wp_latitude_raw);
    result.wp_latitude = wp_latitude_iraw * 1.0e-07 + 0.0;
    auto wp_longitude_raw = decode32(
        &message.payload[526]
    );
    int32_t wp_longitude_iraw =
        reinterpret_cast<int32_t const&>(wp_longitude_raw);
    result.wp_longitude = wp_longitude_iraw * 1.0e-07 + 0.0;
    return result;
}
const int SetDriftRapidUpdate::BYTE_LENGTH;
const int SetDriftRapidUpdate::ID;

SetDriftRapidUpdate SetDriftRapidUpdate::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SetDriftRapidUpdate result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.set_reference = (decode8(
        &message.payload[1]
    ) >> 0) & 0x3;
    auto set_raw = decode16(
        &message.payload[2]
    );
    uint16_t set_iraw =
        reinterpret_cast<uint16_t const&>(set_raw);
    result.set = set_iraw * 0.005729577951308233 + 0.0;
    auto drift_raw = decode16(
        &message.payload[4]
    );
    int16_t drift_iraw =
        reinterpret_cast<int16_t const&>(drift_raw);
    result.drift = drift_iraw * 0.01 + 0.0;
    return result;
}
const int NavigationRouteTimeToFromMark::BYTE_LENGTH;
const int NavigationRouteTimeToFromMark::ID;

NavigationRouteTimeToFromMark NavigationRouteTimeToFromMark::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    NavigationRouteTimeToFromMark result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    auto time_to_mark_raw = decode32(
        &message.payload[1]
    );
    int32_t time_to_mark_iraw =
        reinterpret_cast<int32_t const&>(time_to_mark_raw);
    result.time_to_mark = time_to_mark_iraw * 0.001 + 0.0;
    result.mark_type = (decode8(
        &message.payload[5]
    ) >> 0) & 0xf;
    result.mark_id = (decode32(
        &message.payload[6]
    ) >> 0) & 0xffffffff;
    return result;
}
const int BearingAndDistanceBetweenTwoMarks::BYTE_LENGTH;
const int BearingAndDistanceBetweenTwoMarks::ID;

BearingAndDistanceBetweenTwoMarks BearingAndDistanceBetweenTwoMarks::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    BearingAndDistanceBetweenTwoMarks result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.bearing_reference = (decode8(
        &message.payload[1]
    ) >> 0) & 0xf;
    result.calculation_type = (decode8(
        &message.payload[1]
    ) >> 4) & 0x3;
    auto bearing_origin_to_destination_raw = decode16(
        &message.payload[2]
    );
    uint16_t bearing_origin_to_destination_iraw =
        reinterpret_cast<uint16_t const&>(bearing_origin_to_destination_raw);
    result.bearing_origin_to_destination = bearing_origin_to_destination_iraw * 0.005729577951308233 + 0.0;
    auto distance_raw = decode32(
        &message.payload[4]
    );
    int32_t distance_iraw =
        reinterpret_cast<int32_t const&>(distance_raw);
    result.distance = distance_iraw * 0.01 + 0.0;
    result.origin_mark_type = (decode8(
        &message.payload[8]
    ) >> 0) & 0xf;
    result.destination_mark_type = (decode8(
        &message.payload[8]
    ) >> 4) & 0xf;
    result.origin_mark_id = (decode32(
        &message.payload[9]
    ) >> 0) & 0xffffffff;
    result.destination_mark_id = (decode32(
        &message.payload[13]
    ) >> 0) & 0xffffffff;
    return result;
}
const int GNSSControlStatus::BYTE_LENGTH;
const int GNSSControlStatus::ID;

GNSSControlStatus GNSSControlStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    GNSSControlStatus result;
    result.time = message.time;

    result.sv_elevation_mask = (decode16(
        &message.payload[0]
    ) >> 0) & 0xffff;
    auto pdop_mask_raw = decode16(
        &message.payload[2]
    );
    int16_t pdop_mask_iraw =
        reinterpret_cast<int16_t const&>(pdop_mask_raw);
    result.pdop_mask = pdop_mask_iraw * 0.01 + 0.0;
    auto pdop_switch_raw = decode16(
        &message.payload[4]
    );
    int16_t pdop_switch_iraw =
        reinterpret_cast<int16_t const&>(pdop_switch_raw);
    result.pdop_switch = pdop_switch_iraw * 0.01 + 0.0;
    auto snr_mask_raw = decode16(
        &message.payload[6]
    );
    int16_t snr_mask_iraw =
        reinterpret_cast<int16_t const&>(snr_mask_raw);
    result.snr_mask = snr_mask_iraw * 0.01 + 0.0;
    result.gnss_mode_desired_ = (decode8(
        &message.payload[8]
    ) >> 0) & 0x7;
    result.dgnss_mode_desired_ = (decode8(
        &message.payload[8]
    ) >> 3) & 0x7;
    result.position_velocity_filter = (decode8(
        &message.payload[8]
    ) >> 6) & 0x3;
    result.max_correction_age = (decode16(
        &message.payload[9]
    ) >> 0) & 0xffff;
    auto antenna_altitude_for_2d_mode_raw = decode16(
        &message.payload[11]
    );
    int16_t antenna_altitude_for_2d_mode_iraw =
        reinterpret_cast<int16_t const&>(antenna_altitude_for_2d_mode_raw);
    result.antenna_altitude_for_2d_mode = antenna_altitude_for_2d_mode_iraw * 0.01 + 0.0;
    result.use_antenna_altitude_for_2d_mode = (decode8(
        &message.payload[13]
    ) >> 0) & 0x3;
    return result;
}
const int GNSSDOPs::BYTE_LENGTH;
const int GNSSDOPs::ID;

GNSSDOPs GNSSDOPs::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    GNSSDOPs result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.desired_mode = (decode8(
        &message.payload[1]
    ) >> 0) & 0x7;
    result.actual_mode = (decode8(
        &message.payload[1]
    ) >> 3) & 0x7;
    auto hdop_raw = decode16(
        &message.payload[2]
    );
    int16_t hdop_iraw =
        reinterpret_cast<int16_t const&>(hdop_raw);
    result.hdop = hdop_iraw * 0.01 + 0.0;
    auto vdop_raw = decode16(
        &message.payload[4]
    );
    int16_t vdop_iraw =
        reinterpret_cast<int16_t const&>(vdop_raw);
    result.vdop = vdop_iraw * 0.01 + 0.0;
    auto tdop_raw = decode16(
        &message.payload[6]
    );
    int16_t tdop_iraw =
        reinterpret_cast<int16_t const&>(tdop_raw);
    result.tdop = tdop_iraw * 0.01 + 0.0;
    return result;
}
const int GNSSSatsInView::BYTE_LENGTH;
const int GNSSSatsInView::ID;

GNSSSatsInView GNSSSatsInView::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    GNSSSatsInView result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.mode = (decode8(
        &message.payload[1]
    ) >> 0) & 0x3;
    result.sats_in_view = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    result.sat_number = (decode8(
        &message.payload[3]
    ) >> 0) & 0xff;
    auto elevation_raw = decode16(
        &message.payload[4]
    );
    int16_t elevation_iraw =
        reinterpret_cast<int16_t const&>(elevation_raw);
    result.elevation = elevation_iraw * 0.005729577951308233 + 0.0;
    auto azimuth_raw = decode16(
        &message.payload[6]
    );
    int16_t azimuth_iraw =
        reinterpret_cast<int16_t const&>(azimuth_raw);
    result.azimuth = azimuth_iraw * 0.005729577951308233 + 0.0;
    auto snr_raw = decode16(
        &message.payload[8]
    );
    int16_t snr_iraw =
        reinterpret_cast<int16_t const&>(snr_raw);
    result.snr = snr_iraw * 0.01 + 0.0;
    result.range_residuals = (decode32(
        &message.payload[10]
    ) >> 0) & 0xffffffff;
    result.status = (decode8(
        &message.payload[14]
    ) >> 0) & 0xf;
    result.sat_number1 = (decode8(
        &message.payload[15]
    ) >> 0) & 0xff;
    auto elevation1_raw = decode16(
        &message.payload[16]
    );
    int16_t elevation1_iraw =
        reinterpret_cast<int16_t const&>(elevation1_raw);
    result.elevation1 = elevation1_iraw * 0.005729577951308233 + 0.0;
    auto azimuth1_raw = decode16(
        &message.payload[18]
    );
    int16_t azimuth1_iraw =
        reinterpret_cast<int16_t const&>(azimuth1_raw);
    result.azimuth1 = azimuth1_iraw * 0.005729577951308233 + 0.0;
    auto snr1_raw = decode16(
        &message.payload[20]
    );
    int16_t snr1_iraw =
        reinterpret_cast<int16_t const&>(snr1_raw);
    result.snr1 = snr1_iraw * 0.01 + 0.0;
    result.range_residuals1 = (decode32(
        &message.payload[22]
    ) >> 0) & 0xffffffff;
    result.status1 = (decode8(
        &message.payload[26]
    ) >> 0) & 0xf;
    result.sat_number2 = (decode8(
        &message.payload[27]
    ) >> 0) & 0xff;
    auto elevation2_raw = decode16(
        &message.payload[28]
    );
    int16_t elevation2_iraw =
        reinterpret_cast<int16_t const&>(elevation2_raw);
    result.elevation2 = elevation2_iraw * 0.005729577951308233 + 0.0;
    auto azimuth2_raw = decode16(
        &message.payload[30]
    );
    int16_t azimuth2_iraw =
        reinterpret_cast<int16_t const&>(azimuth2_raw);
    result.azimuth2 = azimuth2_iraw * 0.005729577951308233 + 0.0;
    auto snr2_raw = decode16(
        &message.payload[32]
    );
    int16_t snr2_iraw =
        reinterpret_cast<int16_t const&>(snr2_raw);
    result.snr2 = snr2_iraw * 0.01 + 0.0;
    result.range_residuals2 = (decode32(
        &message.payload[34]
    ) >> 0) & 0xffffffff;
    result.status2 = (decode8(
        &message.payload[38]
    ) >> 0) & 0xf;
    result.sat_number3 = (decode8(
        &message.payload[39]
    ) >> 0) & 0xff;
    auto elevation3_raw = decode16(
        &message.payload[40]
    );
    int16_t elevation3_iraw =
        reinterpret_cast<int16_t const&>(elevation3_raw);
    result.elevation3 = elevation3_iraw * 0.005729577951308233 + 0.0;
    auto azimuth3_raw = decode16(
        &message.payload[42]
    );
    int16_t azimuth3_iraw =
        reinterpret_cast<int16_t const&>(azimuth3_raw);
    result.azimuth3 = azimuth3_iraw * 0.005729577951308233 + 0.0;
    auto snr3_raw = decode16(
        &message.payload[44]
    );
    int16_t snr3_iraw =
        reinterpret_cast<int16_t const&>(snr3_raw);
    result.snr3 = snr3_iraw * 0.01 + 0.0;
    result.range_residuals3 = (decode32(
        &message.payload[46]
    ) >> 0) & 0xffffffff;
    result.status3 = (decode8(
        &message.payload[50]
    ) >> 0) & 0xf;
    result.sat_number4 = (decode8(
        &message.payload[51]
    ) >> 0) & 0xff;
    auto elevation4_raw = decode16(
        &message.payload[52]
    );
    int16_t elevation4_iraw =
        reinterpret_cast<int16_t const&>(elevation4_raw);
    result.elevation4 = elevation4_iraw * 0.005729577951308233 + 0.0;
    auto azimuth4_raw = decode16(
        &message.payload[54]
    );
    int16_t azimuth4_iraw =
        reinterpret_cast<int16_t const&>(azimuth4_raw);
    result.azimuth4 = azimuth4_iraw * 0.005729577951308233 + 0.0;
    auto snr4_raw = decode16(
        &message.payload[56]
    );
    int16_t snr4_iraw =
        reinterpret_cast<int16_t const&>(snr4_raw);
    result.snr4 = snr4_iraw * 0.01 + 0.0;
    result.range_residuals4 = (decode32(
        &message.payload[58]
    ) >> 0) & 0xffffffff;
    result.status4 = (decode8(
        &message.payload[62]
    ) >> 0) & 0xf;
    result.sat_number5 = (decode8(
        &message.payload[63]
    ) >> 0) & 0xff;
    auto elevation5_raw = decode16(
        &message.payload[64]
    );
    int16_t elevation5_iraw =
        reinterpret_cast<int16_t const&>(elevation5_raw);
    result.elevation5 = elevation5_iraw * 0.005729577951308233 + 0.0;
    auto azimuth5_raw = decode16(
        &message.payload[66]
    );
    int16_t azimuth5_iraw =
        reinterpret_cast<int16_t const&>(azimuth5_raw);
    result.azimuth5 = azimuth5_iraw * 0.005729577951308233 + 0.0;
    auto snr5_raw = decode16(
        &message.payload[68]
    );
    int16_t snr5_iraw =
        reinterpret_cast<int16_t const&>(snr5_raw);
    result.snr5 = snr5_iraw * 0.01 + 0.0;
    result.range_residuals5 = (decode32(
        &message.payload[70]
    ) >> 0) & 0xffffffff;
    result.status5 = (decode8(
        &message.payload[74]
    ) >> 0) & 0xf;
    result.sat_number6 = (decode8(
        &message.payload[75]
    ) >> 0) & 0xff;
    auto elevation6_raw = decode16(
        &message.payload[76]
    );
    int16_t elevation6_iraw =
        reinterpret_cast<int16_t const&>(elevation6_raw);
    result.elevation6 = elevation6_iraw * 0.005729577951308233 + 0.0;
    auto azimuth6_raw = decode16(
        &message.payload[78]
    );
    int16_t azimuth6_iraw =
        reinterpret_cast<int16_t const&>(azimuth6_raw);
    result.azimuth6 = azimuth6_iraw * 0.005729577951308233 + 0.0;
    auto snr6_raw = decode16(
        &message.payload[80]
    );
    int16_t snr6_iraw =
        reinterpret_cast<int16_t const&>(snr6_raw);
    result.snr6 = snr6_iraw * 0.01 + 0.0;
    result.range_residuals6 = (decode32(
        &message.payload[82]
    ) >> 0) & 0xffffffff;
    result.status6 = (decode8(
        &message.payload[86]
    ) >> 0) & 0xf;
    result.sat_number7 = (decode8(
        &message.payload[87]
    ) >> 0) & 0xff;
    auto elevation7_raw = decode16(
        &message.payload[88]
    );
    int16_t elevation7_iraw =
        reinterpret_cast<int16_t const&>(elevation7_raw);
    result.elevation7 = elevation7_iraw * 0.005729577951308233 + 0.0;
    auto azimuth7_raw = decode16(
        &message.payload[90]
    );
    int16_t azimuth7_iraw =
        reinterpret_cast<int16_t const&>(azimuth7_raw);
    result.azimuth7 = azimuth7_iraw * 0.005729577951308233 + 0.0;
    auto snr7_raw = decode16(
        &message.payload[92]
    );
    int16_t snr7_iraw =
        reinterpret_cast<int16_t const&>(snr7_raw);
    result.snr7 = snr7_iraw * 0.01 + 0.0;
    result.range_residuals7 = (decode32(
        &message.payload[94]
    ) >> 0) & 0xffffffff;
    result.status7 = (decode8(
        &message.payload[98]
    ) >> 0) & 0xf;
    result.sat_number8 = (decode8(
        &message.payload[99]
    ) >> 0) & 0xff;
    auto elevation8_raw = decode16(
        &message.payload[100]
    );
    int16_t elevation8_iraw =
        reinterpret_cast<int16_t const&>(elevation8_raw);
    result.elevation8 = elevation8_iraw * 0.005729577951308233 + 0.0;
    auto azimuth8_raw = decode16(
        &message.payload[102]
    );
    int16_t azimuth8_iraw =
        reinterpret_cast<int16_t const&>(azimuth8_raw);
    result.azimuth8 = azimuth8_iraw * 0.005729577951308233 + 0.0;
    auto snr8_raw = decode16(
        &message.payload[104]
    );
    int16_t snr8_iraw =
        reinterpret_cast<int16_t const&>(snr8_raw);
    result.snr8 = snr8_iraw * 0.01 + 0.0;
    result.range_residuals8 = (decode32(
        &message.payload[106]
    ) >> 0) & 0xffffffff;
    result.status8 = (decode8(
        &message.payload[110]
    ) >> 0) & 0xf;
    result.sat_number9 = (decode8(
        &message.payload[111]
    ) >> 0) & 0xff;
    auto elevation9_raw = decode16(
        &message.payload[112]
    );
    int16_t elevation9_iraw =
        reinterpret_cast<int16_t const&>(elevation9_raw);
    result.elevation9 = elevation9_iraw * 0.005729577951308233 + 0.0;
    auto azimuth9_raw = decode16(
        &message.payload[114]
    );
    int16_t azimuth9_iraw =
        reinterpret_cast<int16_t const&>(azimuth9_raw);
    result.azimuth9 = azimuth9_iraw * 0.005729577951308233 + 0.0;
    auto snr9_raw = decode16(
        &message.payload[116]
    );
    int16_t snr9_iraw =
        reinterpret_cast<int16_t const&>(snr9_raw);
    result.snr9 = snr9_iraw * 0.01 + 0.0;
    result.range_residuals9 = (decode32(
        &message.payload[118]
    ) >> 0) & 0xffffffff;
    result.status9 = (decode8(
        &message.payload[122]
    ) >> 0) & 0xf;
    result.sat_number10 = (decode8(
        &message.payload[123]
    ) >> 0) & 0xff;
    auto elevation10_raw = decode16(
        &message.payload[124]
    );
    int16_t elevation10_iraw =
        reinterpret_cast<int16_t const&>(elevation10_raw);
    result.elevation10 = elevation10_iraw * 0.005729577951308233 + 0.0;
    auto azimuth10_raw = decode16(
        &message.payload[126]
    );
    int16_t azimuth10_iraw =
        reinterpret_cast<int16_t const&>(azimuth10_raw);
    result.azimuth10 = azimuth10_iraw * 0.005729577951308233 + 0.0;
    auto snr10_raw = decode16(
        &message.payload[128]
    );
    int16_t snr10_iraw =
        reinterpret_cast<int16_t const&>(snr10_raw);
    result.snr10 = snr10_iraw * 0.01 + 0.0;
    result.range_residuals10 = (decode32(
        &message.payload[130]
    ) >> 0) & 0xffffffff;
    result.status10 = (decode8(
        &message.payload[134]
    ) >> 0) & 0xf;
    result.sat_number11 = (decode8(
        &message.payload[135]
    ) >> 0) & 0xff;
    auto elevation11_raw = decode16(
        &message.payload[136]
    );
    int16_t elevation11_iraw =
        reinterpret_cast<int16_t const&>(elevation11_raw);
    result.elevation11 = elevation11_iraw * 0.005729577951308233 + 0.0;
    auto azimuth11_raw = decode16(
        &message.payload[138]
    );
    int16_t azimuth11_iraw =
        reinterpret_cast<int16_t const&>(azimuth11_raw);
    result.azimuth11 = azimuth11_iraw * 0.005729577951308233 + 0.0;
    auto snr11_raw = decode16(
        &message.payload[140]
    );
    int16_t snr11_iraw =
        reinterpret_cast<int16_t const&>(snr11_raw);
    result.snr11 = snr11_iraw * 0.01 + 0.0;
    result.range_residuals11 = (decode32(
        &message.payload[142]
    ) >> 0) & 0xffffffff;
    result.status11 = (decode8(
        &message.payload[146]
    ) >> 0) & 0xf;
    result.sat_number12 = (decode8(
        &message.payload[147]
    ) >> 0) & 0xff;
    auto elevation12_raw = decode16(
        &message.payload[148]
    );
    int16_t elevation12_iraw =
        reinterpret_cast<int16_t const&>(elevation12_raw);
    result.elevation12 = elevation12_iraw * 0.005729577951308233 + 0.0;
    auto azimuth12_raw = decode16(
        &message.payload[150]
    );
    int16_t azimuth12_iraw =
        reinterpret_cast<int16_t const&>(azimuth12_raw);
    result.azimuth12 = azimuth12_iraw * 0.005729577951308233 + 0.0;
    auto snr12_raw = decode16(
        &message.payload[152]
    );
    int16_t snr12_iraw =
        reinterpret_cast<int16_t const&>(snr12_raw);
    result.snr12 = snr12_iraw * 0.01 + 0.0;
    result.range_residuals12 = (decode32(
        &message.payload[154]
    ) >> 0) & 0xffffffff;
    result.status12 = (decode8(
        &message.payload[158]
    ) >> 0) & 0xf;
    result.sat_number13 = (decode8(
        &message.payload[159]
    ) >> 0) & 0xff;
    auto elevation13_raw = decode16(
        &message.payload[160]
    );
    int16_t elevation13_iraw =
        reinterpret_cast<int16_t const&>(elevation13_raw);
    result.elevation13 = elevation13_iraw * 0.005729577951308233 + 0.0;
    auto azimuth13_raw = decode16(
        &message.payload[162]
    );
    int16_t azimuth13_iraw =
        reinterpret_cast<int16_t const&>(azimuth13_raw);
    result.azimuth13 = azimuth13_iraw * 0.005729577951308233 + 0.0;
    auto snr13_raw = decode16(
        &message.payload[164]
    );
    int16_t snr13_iraw =
        reinterpret_cast<int16_t const&>(snr13_raw);
    result.snr13 = snr13_iraw * 0.01 + 0.0;
    result.range_residuals13 = (decode32(
        &message.payload[166]
    ) >> 0) & 0xffffffff;
    result.status13 = (decode8(
        &message.payload[170]
    ) >> 0) & 0xf;
    result.sat_number14 = (decode8(
        &message.payload[171]
    ) >> 0) & 0xff;
    auto elevation14_raw = decode16(
        &message.payload[172]
    );
    int16_t elevation14_iraw =
        reinterpret_cast<int16_t const&>(elevation14_raw);
    result.elevation14 = elevation14_iraw * 0.005729577951308233 + 0.0;
    auto azimuth14_raw = decode16(
        &message.payload[174]
    );
    int16_t azimuth14_iraw =
        reinterpret_cast<int16_t const&>(azimuth14_raw);
    result.azimuth14 = azimuth14_iraw * 0.005729577951308233 + 0.0;
    auto snr14_raw = decode16(
        &message.payload[176]
    );
    int16_t snr14_iraw =
        reinterpret_cast<int16_t const&>(snr14_raw);
    result.snr14 = snr14_iraw * 0.01 + 0.0;
    result.range_residuals14 = (decode32(
        &message.payload[178]
    ) >> 0) & 0xffffffff;
    result.status14 = (decode8(
        &message.payload[182]
    ) >> 0) & 0xf;
    result.sat_number15 = (decode8(
        &message.payload[183]
    ) >> 0) & 0xff;
    auto elevation15_raw = decode16(
        &message.payload[184]
    );
    int16_t elevation15_iraw =
        reinterpret_cast<int16_t const&>(elevation15_raw);
    result.elevation15 = elevation15_iraw * 0.005729577951308233 + 0.0;
    auto azimuth15_raw = decode16(
        &message.payload[186]
    );
    int16_t azimuth15_iraw =
        reinterpret_cast<int16_t const&>(azimuth15_raw);
    result.azimuth15 = azimuth15_iraw * 0.005729577951308233 + 0.0;
    auto snr15_raw = decode16(
        &message.payload[188]
    );
    int16_t snr15_iraw =
        reinterpret_cast<int16_t const&>(snr15_raw);
    result.snr15 = snr15_iraw * 0.01 + 0.0;
    result.range_residuals15 = (decode32(
        &message.payload[190]
    ) >> 0) & 0xffffffff;
    result.status15 = (decode8(
        &message.payload[194]
    ) >> 0) & 0xf;
    result.sat_number16 = (decode8(
        &message.payload[195]
    ) >> 0) & 0xff;
    auto elevation16_raw = decode16(
        &message.payload[196]
    );
    int16_t elevation16_iraw =
        reinterpret_cast<int16_t const&>(elevation16_raw);
    result.elevation16 = elevation16_iraw * 0.005729577951308233 + 0.0;
    auto azimuth16_raw = decode16(
        &message.payload[198]
    );
    int16_t azimuth16_iraw =
        reinterpret_cast<int16_t const&>(azimuth16_raw);
    result.azimuth16 = azimuth16_iraw * 0.005729577951308233 + 0.0;
    auto snr16_raw = decode16(
        &message.payload[200]
    );
    int16_t snr16_iraw =
        reinterpret_cast<int16_t const&>(snr16_raw);
    result.snr16 = snr16_iraw * 0.01 + 0.0;
    result.range_residuals16 = (decode32(
        &message.payload[202]
    ) >> 0) & 0xffffffff;
    result.status16 = (decode8(
        &message.payload[206]
    ) >> 0) & 0xf;
    result.sat_number17 = (decode8(
        &message.payload[207]
    ) >> 0) & 0xff;
    auto elevation17_raw = decode16(
        &message.payload[208]
    );
    int16_t elevation17_iraw =
        reinterpret_cast<int16_t const&>(elevation17_raw);
    result.elevation17 = elevation17_iraw * 0.005729577951308233 + 0.0;
    auto azimuth17_raw = decode16(
        &message.payload[210]
    );
    int16_t azimuth17_iraw =
        reinterpret_cast<int16_t const&>(azimuth17_raw);
    result.azimuth17 = azimuth17_iraw * 0.005729577951308233 + 0.0;
    auto snr17_raw = decode16(
        &message.payload[212]
    );
    int16_t snr17_iraw =
        reinterpret_cast<int16_t const&>(snr17_raw);
    result.snr17 = snr17_iraw * 0.01 + 0.0;
    result.range_residuals17 = (decode32(
        &message.payload[214]
    ) >> 0) & 0xffffffff;
    result.status17 = (decode8(
        &message.payload[218]
    ) >> 0) & 0xf;
    return result;
}
const int GPSAlmanacData::BYTE_LENGTH;
const int GPSAlmanacData::ID;

GPSAlmanacData GPSAlmanacData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    GPSAlmanacData result;
    result.time = message.time;

    result.prn = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.gps_week_number = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.sv_health_bits = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    result.eccentricity = (decode8(
        &message.payload[3]
    ) >> 0) & 0xff;
    result.almanac_reference_time = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result.inclination_angle = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.right_of_right_ascension = (decode8(
        &message.payload[6]
    ) >> 0) & 0xff;
    result.root_of_semi_major_axis = (decode8(
        &message.payload[7]
    ) >> 0) & 0xff;
    result.argument_of_perigee = (decode8(
        &message.payload[8]
    ) >> 0) & 0xff;
    result.longitude_of_ascension_node = (decode8(
        &message.payload[9]
    ) >> 0) & 0xff;
    result.mean_anomaly = (decode8(
        &message.payload[10]
    ) >> 0) & 0xff;
    result.clock_parameter_1 = (decode8(
        &message.payload[11]
    ) >> 0) & 0xff;
    result.clock_parameter_2 = (decode8(
        &message.payload[12]
    ) >> 0) & 0xff;
    return result;
}
const int GNSSPseudorangeNoiseStatistics::BYTE_LENGTH;
const int GNSSPseudorangeNoiseStatistics::ID;

GNSSPseudorangeNoiseStatistics GNSSPseudorangeNoiseStatistics::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    GNSSPseudorangeNoiseStatistics result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.rms_of_position_uncertainty = (decode16(
        &message.payload[1]
    ) >> 0) & 0xffff;
    result.std_of_major_axis = (decode8(
        &message.payload[3]
    ) >> 0) & 0xff;
    result.std_of_minor_axis = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result.orientation_of_major_axis = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.std_of_lat_error = (decode8(
        &message.payload[6]
    ) >> 0) & 0xff;
    result.std_of_lon_error = (decode8(
        &message.payload[7]
    ) >> 0) & 0xff;
    result.std_of_alt_error = (decode8(
        &message.payload[8]
    ) >> 0) & 0xff;
    return result;
}
const int GNSSRAIMOutput::BYTE_LENGTH;
const int GNSSRAIMOutput::ID;

GNSSRAIMOutput GNSSRAIMOutput::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    GNSSRAIMOutput result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.integrity_flag = (decode8(
        &message.payload[1]
    ) >> 0) & 0xf;
    result.latitude_expected_error = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    result.longitude_expected_error = (decode8(
        &message.payload[3]
    ) >> 0) & 0xff;
    result.altitude_expected_error = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result.sv_id_of_most_likely_failed_sat = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.probability_of_missed_detection = (decode8(
        &message.payload[6]
    ) >> 0) & 0xff;
    result.estimate_of_pseudorange_bias = (decode8(
        &message.payload[7]
    ) >> 0) & 0xff;
    result.std_deviation_of_bias = (decode8(
        &message.payload[8]
    ) >> 0) & 0xff;
    return result;
}
const int GNSSRAIMSettings::BYTE_LENGTH;
const int GNSSRAIMSettings::ID;

GNSSRAIMSettings GNSSRAIMSettings::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    GNSSRAIMSettings result;
    result.time = message.time;

    result.radial_position_error_maximum_threshold = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.probability_of_false_alarm = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.probability_of_missed_detection = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    result.pseudorange_residual_filtering_time_constant = (decode8(
        &message.payload[3]
    ) >> 0) & 0xff;
    return result;
}
const int GNSSPseudorangeErrorStatistics::BYTE_LENGTH;
const int GNSSPseudorangeErrorStatistics::ID;

GNSSPseudorangeErrorStatistics GNSSPseudorangeErrorStatistics::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    GNSSPseudorangeErrorStatistics result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.rms_std_dev_of_range_inputs = (decode16(
        &message.payload[1]
    ) >> 0) & 0xffff;
    result.std_dev_of_major_error_ellipse = (decode8(
        &message.payload[3]
    ) >> 0) & 0xff;
    result.std_dev_of_minor_error_ellipse = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result.orientation_of_error_ellipse = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.std_dev_lat_error = (decode8(
        &message.payload[6]
    ) >> 0) & 0xff;
    result.std_dev_lon_error = (decode8(
        &message.payload[7]
    ) >> 0) & 0xff;
    result.std_dev_alt_error = (decode8(
        &message.payload[8]
    ) >> 0) & 0xff;
    return result;
}
const int DGNSSCorrections::BYTE_LENGTH;
const int DGNSSCorrections::ID;

DGNSSCorrections DGNSSCorrections::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    DGNSSCorrections result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.reference_station_id = (decode16(
        &message.payload[1]
    ) >> 0) & 0xffff;
    result.reference_station_type = (decode16(
        &message.payload[3]
    ) >> 0) & 0xffff;
    result.time_of_corrections = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.station_health = (decode8(
        &message.payload[6]
    ) >> 0) & 0xff;
    result.reserved_bits = (decode8(
        &message.payload[7]
    ) >> 0) & 0xff;
    result.satellite_id = (decode8(
        &message.payload[8]
    ) >> 0) & 0xff;
    result.prc = (decode8(
        &message.payload[9]
    ) >> 0) & 0xff;
    result.rrc = (decode8(
        &message.payload[10]
    ) >> 0) & 0xff;
    result.udre = (decode8(
        &message.payload[11]
    ) >> 0) & 0xff;
    result.iod = (decode8(
        &message.payload[12]
    ) >> 0) & 0xff;
    return result;
}
const int GNSSDifferentialCorrectionReceiverInterface::BYTE_LENGTH;
const int GNSSDifferentialCorrectionReceiverInterface::ID;

GNSSDifferentialCorrectionReceiverInterface GNSSDifferentialCorrectionReceiverInterface::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    GNSSDifferentialCorrectionReceiverInterface result;
    result.time = message.time;

    result.channel = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.frequency = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.serial_interface_bit_rate = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    result.serial_interface_detection_mode = (decode8(
        &message.payload[3]
    ) >> 0) & 0xff;
    result.differential_source = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result.differential_operation_mode = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    return result;
}
const int GNSSDifferentialCorrectionReceiverSignal::BYTE_LENGTH;
const int GNSSDifferentialCorrectionReceiverSignal::ID;

GNSSDifferentialCorrectionReceiverSignal GNSSDifferentialCorrectionReceiverSignal::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    GNSSDifferentialCorrectionReceiverSignal result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.channel = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.signal_strength = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    result.signal_snr = (decode8(
        &message.payload[3]
    ) >> 0) & 0xff;
    result.frequency = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result.station_type = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.station_id = (decode8(
        &message.payload[6]
    ) >> 0) & 0xff;
    result.differential_signal_bit_rate = (decode8(
        &message.payload[7]
    ) >> 0) & 0xff;
    result.differential_signal_detection_mode = (decode8(
        &message.payload[8]
    ) >> 0) & 0xff;
    result.used_as_correction_source = (decode8(
        &message.payload[9]
    ) >> 0) & 0xff;
    result.reserved = (decode8(
        &message.payload[10]
    ) >> 0) & 0xff;
    result.differential_source = (decode8(
        &message.payload[11]
    ) >> 0) & 0xff;
    result.time_since_last_sat_differential_sync = (decode8(
        &message.payload[12]
    ) >> 0) & 0xff;
    result.satellite_service_id_no_ = (decode8(
        &message.payload[13]
    ) >> 0) & 0xff;
    return result;
}
const int GLONASSAlmanacData::BYTE_LENGTH;
const int GLONASSAlmanacData::ID;

GLONASSAlmanacData GLONASSAlmanacData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    GLONASSAlmanacData result;
    result.time = message.time;

    result.prn = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.na = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.cna = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    result.hna = (decode8(
        &message.payload[3]
    ) >> 0) & 0xff;
    result._epsilon_na = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result._deltatna_dot = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result._omega_na = (decode8(
        &message.payload[6]
    ) >> 0) & 0xff;
    result._delta_tna = (decode8(
        &message.payload[7]
    ) >> 0) & 0xff;
    result.tna = (decode8(
        &message.payload[8]
    ) >> 0) & 0xff;
    result._lambda_na = (decode8(
        &message.payload[9]
    ) >> 0) & 0xff;
    result._delta_ina = (decode8(
        &message.payload[10]
    ) >> 0) & 0xff;
    result.tca = (decode8(
        &message.payload[11]
    ) >> 0) & 0xff;
    result.tna1 = (decode8(
        &message.payload[12]
    ) >> 0) & 0xff;
    return result;
}
const int AISDGNSSBroadcastBinaryMessage::BYTE_LENGTH;
const int AISDGNSSBroadcastBinaryMessage::ID;

AISDGNSSBroadcastBinaryMessage AISDGNSSBroadcastBinaryMessage::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISDGNSSBroadcastBinaryMessage result;
    result.time = message.time;

    result.message_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.repeat_indicator = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.source_id = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    result.nmea_2000_reserved = (decode8(
        &message.payload[3]
    ) >> 0) & 0xff;
    result.ais_tranceiver_information = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result.spare = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.longitude = (decode8(
        &message.payload[6]
    ) >> 0) & 0xff;
    result.latitude = (decode8(
        &message.payload[7]
    ) >> 0) & 0xff;
    result.nmea_2000_reserved1 = (decode8(
        &message.payload[8]
    ) >> 0) & 0xff;
    result.spare1 = (decode8(
        &message.payload[9]
    ) >> 0) & 0xff;
    result.number_of_bits_in_binary_data_field = (decode8(
        &message.payload[10]
    ) >> 0) & 0xff;
    return result;
}
const int AISUTCAndDateReport::BYTE_LENGTH;
const int AISUTCAndDateReport::ID;

AISUTCAndDateReport AISUTCAndDateReport::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISUTCAndDateReport result;
    result.time = message.time;

    result.message_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0x3f;
    result.repeat_indicator = (decode8(
        &message.payload[0]
    ) >> 6) & 0x3;
    auto user_id_raw = decode32(
        &message.payload[1]
    );
    result.user_id = reinterpret_cast<int32_t const&>(
        user_id_raw
    );
    auto longitude_raw = decode32(
        &message.payload[5]
    );
    int32_t longitude_iraw =
        reinterpret_cast<int32_t const&>(longitude_raw);
    result.longitude = longitude_iraw * 1.0e-07 + 0.0;
    auto latitude_raw = decode32(
        &message.payload[9]
    );
    int32_t latitude_iraw =
        reinterpret_cast<int32_t const&>(latitude_raw);
    result.latitude = latitude_iraw * 1.0e-07 + 0.0;
    result.position_accuracy = (decode8(
        &message.payload[13]
    ) >> 0) & 0x1;
    result.raim = (decode8(
        &message.payload[13]
    ) >> 1) & 0x1;
    auto position_time_raw = decode32(
        &message.payload[14]
    );
    uint32_t position_time_iraw =
        reinterpret_cast<uint32_t const&>(position_time_raw);
    result.position_time = position_time_iraw * 0.0001 + 0.0;
    result.ais_transceiver_information = (decode8(
        &message.payload[20]
    ) >> 3) & 0x1f;
    result.position_date = (decode16(
        &message.payload[21]
    ) >> 0) & 0xffff;
    result.gnss_type = (decode8(
        &message.payload[23]
    ) >> 4) & 0xf;
    return result;
}
const int AISClassAStaticAndVoyageRelatedData::BYTE_LENGTH;
const int AISClassAStaticAndVoyageRelatedData::ID;

AISClassAStaticAndVoyageRelatedData AISClassAStaticAndVoyageRelatedData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISClassAStaticAndVoyageRelatedData result;
    result.time = message.time;

    result.message_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0x3f;
    result.repeat_indicator = (decode8(
        &message.payload[0]
    ) >> 6) & 0x3;
    auto user_id_raw = decode32(
        &message.payload[1]
    );
    result.user_id = reinterpret_cast<int32_t const&>(
        user_id_raw
    );
    auto imo_number_raw = decode32(
        &message.payload[5]
    );
    result.imo_number = reinterpret_cast<int32_t const&>(
        imo_number_raw
    );
    result.callsign = decodeString(&message.payload[9],
                                            8);
    result.name = decodeString(&message.payload[16],
                                            32);
    result.type_of_ship = (decode8(
        &message.payload[36]
    ) >> 0) & 0xff;
    auto length_raw = decode16(
        &message.payload[37]
    );
    int16_t length_iraw =
        reinterpret_cast<int16_t const&>(length_raw);
    result.length = length_iraw * 0.1 + 0.0;
    auto beam_raw = decode16(
        &message.payload[39]
    );
    int16_t beam_iraw =
        reinterpret_cast<int16_t const&>(beam_raw);
    result.beam = beam_iraw * 0.1 + 0.0;
    auto position_reference_from_starboard_raw = decode16(
        &message.payload[41]
    );
    int16_t position_reference_from_starboard_iraw =
        reinterpret_cast<int16_t const&>(position_reference_from_starboard_raw);
    result.position_reference_from_starboard = position_reference_from_starboard_iraw * 0.1 + 0.0;
    auto position_reference_from_bow_raw = decode16(
        &message.payload[43]
    );
    int16_t position_reference_from_bow_iraw =
        reinterpret_cast<int16_t const&>(position_reference_from_bow_raw);
    result.position_reference_from_bow = position_reference_from_bow_iraw * 0.1 + 0.0;
    result.eta_date = (decode16(
        &message.payload[45]
    ) >> 0) & 0xffff;
    auto eta_time_raw = decode32(
        &message.payload[47]
    );
    uint32_t eta_time_iraw =
        reinterpret_cast<uint32_t const&>(eta_time_raw);
    result.eta_time = eta_time_iraw * 0.0001 + 0.0;
    auto draft_raw = decode16(
        &message.payload[51]
    );
    int16_t draft_iraw =
        reinterpret_cast<int16_t const&>(draft_raw);
    result.draft = draft_iraw * 0.01 + 0.0;
    result.destination = decodeString(&message.payload[53],
                                            32);
    result.ais_version_indicator = (decode8(
        &message.payload[73]
    ) >> 0) & 0x3;
    result.gnss_type = (decode8(
        &message.payload[73]
    ) >> 2) & 0xf;
    result.dte = (decode8(
        &message.payload[73]
    ) >> 6) & 0x1;
    result.ais_transceiver_information = (decode8(
        &message.payload[74]
    ) >> 0) & 0x1f;
    return result;
}
const int AISAddressedBinaryMessage::BYTE_LENGTH;
const int AISAddressedBinaryMessage::ID;

AISAddressedBinaryMessage AISAddressedBinaryMessage::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISAddressedBinaryMessage result;
    result.time = message.time;

    result.message_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0x3f;
    result.repeat_indicator = (decode8(
        &message.payload[0]
    ) >> 6) & 0x3;
    auto source_id_raw = decode32(
        &message.payload[1]
    );
    result.source_id = reinterpret_cast<int32_t const&>(
        source_id_raw
    );
    result.ais_transceiver_information = (decode8(
        &message.payload[5]
    ) >> 1) & 0x1f;
    result.sequence_number = (decode8(
        &message.payload[5]
    ) >> 6) & 0x3;
    auto destination_id_raw = decode32(
        &message.payload[6]
    );
    result.destination_id = reinterpret_cast<int32_t const&>(
        destination_id_raw
    );
    result.retransmit_flag = (decode8(
        &message.payload[10]
    ) >> 6) & 0x1;
    auto number_of_bits_in_binary_data_field_raw = decode16(
        &message.payload[11]
    );
    result.number_of_bits_in_binary_data_field = reinterpret_cast<int16_t const&>(
        number_of_bits_in_binary_data_field_raw
    );
    return result;
}
const int AISAcknowledge::BYTE_LENGTH;
const int AISAcknowledge::ID;

AISAcknowledge AISAcknowledge::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISAcknowledge result;
    result.time = message.time;

    result.message_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0x3f;
    result.repeat_indicator = (decode8(
        &message.payload[0]
    ) >> 6) & 0x3;
    result.source_id = (decode32(
        &message.payload[1]
    ) >> 0) & 0xffffffff;
    result.ais_transceiver_information = (decode8(
        &message.payload[5]
    ) >> 1) & 0x1f;
    result.destination_id_number1 = (decode32(
        &message.payload[6]
    ) >> 0) & 0xffffffff;
    return result;
}
const int AISBinaryBroadcastMessage::BYTE_LENGTH;
const int AISBinaryBroadcastMessage::ID;

AISBinaryBroadcastMessage AISBinaryBroadcastMessage::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISBinaryBroadcastMessage result;
    result.time = message.time;

    result.message_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0x3f;
    result.repeat_indicator = (decode8(
        &message.payload[0]
    ) >> 6) & 0x3;
    result.source_id = (decode32(
        &message.payload[1]
    ) >> 0) & 0xffffffff;
    result.ais_transceiver_information = (decode8(
        &message.payload[5]
    ) >> 1) & 0x1f;
    result.number_of_bits_in_binary_data_field = (decode16(
        &message.payload[6]
    ) >> 0) & 0xffff;
    return result;
}
const int AISSARAircraftPositionReport::BYTE_LENGTH;
const int AISSARAircraftPositionReport::ID;

AISSARAircraftPositionReport AISSARAircraftPositionReport::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISSARAircraftPositionReport result;
    result.time = message.time;

    result.message_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0x3f;
    result.repeat_indicator = (decode8(
        &message.payload[0]
    ) >> 6) & 0x3;
    auto user_id_raw = decode32(
        &message.payload[1]
    );
    result.user_id = reinterpret_cast<int32_t const&>(
        user_id_raw
    );
    auto longitude_raw = decode32(
        &message.payload[5]
    );
    int32_t longitude_iraw =
        reinterpret_cast<int32_t const&>(longitude_raw);
    result.longitude = longitude_iraw * 1.0e-07 + 0.0;
    auto latitude_raw = decode32(
        &message.payload[9]
    );
    int32_t latitude_iraw =
        reinterpret_cast<int32_t const&>(latitude_raw);
    result.latitude = latitude_iraw * 1.0e-07 + 0.0;
    result.position_accuracy = (decode8(
        &message.payload[13]
    ) >> 0) & 0x1;
    result.raim = (decode8(
        &message.payload[13]
    ) >> 1) & 0x1;
    result.time_stamp = (decode8(
        &message.payload[13]
    ) >> 2) & 0x3f;
    auto cog_raw = decode16(
        &message.payload[14]
    );
    uint16_t cog_iraw =
        reinterpret_cast<uint16_t const&>(cog_raw);
    result.cog = cog_iraw * 0.005729577951308233 + 0.0;
    auto sog_raw = decode16(
        &message.payload[16]
    );
    uint16_t sog_iraw =
        reinterpret_cast<uint16_t const&>(sog_raw);
    result.sog = sog_iraw * 0.1 + 0.0;
    result.ais_transceiver_information = (decode8(
        &message.payload[20]
    ) >> 3) & 0x1f;
    auto altitude_raw = decode64(
        &message.payload[21]
    );
    int64_t altitude_iraw =
        reinterpret_cast<int64_t const&>(altitude_raw);
    result.altitude = altitude_iraw * 1.0 + 0.0;
    result.reserved_for_regional_applications = (decode8(
        &message.payload[29]
    ) >> 0) & 0xff;
    result.dte = (decode8(
        &message.payload[30]
    ) >> 0) & 0x1;
    return result;
}
const int RadioFrequencyModePower::BYTE_LENGTH;
const int RadioFrequencyModePower::ID;

RadioFrequencyModePower RadioFrequencyModePower::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RadioFrequencyModePower result;
    result.time = message.time;

    auto rx_frequency_raw = decode32(
        &message.payload[0]
    );
    int32_t rx_frequency_iraw =
        reinterpret_cast<int32_t const&>(rx_frequency_raw);
    result.rx_frequency = rx_frequency_iraw * 10.0 + 0.0;
    auto tx_frequency_raw = decode32(
        &message.payload[4]
    );
    int32_t tx_frequency_iraw =
        reinterpret_cast<int32_t const&>(tx_frequency_raw);
    result.tx_frequency = tx_frequency_iraw * 10.0 + 0.0;
    result.radio_channel = (decode8(
        &message.payload[8]
    ) >> 0) & 0xff;
    result.tx_power = (decode8(
        &message.payload[9]
    ) >> 0) & 0xff;
    result.mode = (decode8(
        &message.payload[10]
    ) >> 0) & 0xff;
    result.channel_bandwidth = (decode8(
        &message.payload[11]
    ) >> 0) & 0xff;
    return result;
}
const int AISUTCDateInquiry::BYTE_LENGTH;
const int AISUTCDateInquiry::ID;

AISUTCDateInquiry AISUTCDateInquiry::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISUTCDateInquiry result;
    result.time = message.time;

    result.message_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0x3f;
    result.repeat_indicator = (decode8(
        &message.payload[0]
    ) >> 6) & 0x3;
    result.source_id = (decode32(
        &message.payload[1]
    ) >> 0) & 0x3fffffff;
    result.ais_transceiver_information = (decode8(
        &message.payload[5]
    ) >> 0) & 0x1f;
    result.destination_id = (decode32(
        &message.payload[6]
    ) >> 0) & 0x3fffffff;
    return result;
}
const int AISAddressedSafetyRelatedMessage::BYTE_LENGTH;
const int AISAddressedSafetyRelatedMessage::ID;

AISAddressedSafetyRelatedMessage AISAddressedSafetyRelatedMessage::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISAddressedSafetyRelatedMessage result;
    result.time = message.time;

    result.message_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0x3f;
    result.repeat_indicator = (decode8(
        &message.payload[0]
    ) >> 6) & 0x3;
    result.source_id = (decode32(
        &message.payload[1]
    ) >> 0) & 0xffffffff;
    result.ais_transceiver_information = (decode8(
        &message.payload[5]
    ) >> 1) & 0x1f;
    result.sequence_number = (decode8(
        &message.payload[5]
    ) >> 6) & 0x3;
    result.destination_id = (decode32(
        &message.payload[6]
    ) >> 0) & 0xffffffff;
    result.retransmit_flag = (decode8(
        &message.payload[10]
    ) >> 6) & 0x1;
    result.safety_related_text = decodeString(&message.payload[11],
                                            256);
    return result;
}
const int AISSafetyRelatedBroadcastMessage::BYTE_LENGTH;
const int AISSafetyRelatedBroadcastMessage::ID;

AISSafetyRelatedBroadcastMessage AISSafetyRelatedBroadcastMessage::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISSafetyRelatedBroadcastMessage result;
    result.time = message.time;

    result.message_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0x3f;
    result.repeat_indicator = (decode8(
        &message.payload[0]
    ) >> 6) & 0x3;
    result.ais_transceiver_information = (decode8(
        &message.payload[5]
    ) >> 0) & 0x1f;
    return result;
}
const int AISInterrogation::BYTE_LENGTH;
const int AISInterrogation::ID;

AISInterrogation AISInterrogation::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISInterrogation result;
    result.time = message.time;

    result.message_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0x3f;
    result.repeat_indicator = (decode8(
        &message.payload[0]
    ) >> 6) & 0x3;
    result.ais_transceiver_information = (decode8(
        &message.payload[5]
    ) >> 0) & 0x1f;
    auto message_id_a_raw = decode8(
        &message.payload[10]
    );
    result.message_id_a = reinterpret_cast<int8_t const&>(
        message_id_a_raw
    );
    auto message_id_b_raw = decode8(
        &message.payload[13]
    );
    result.message_id_b = reinterpret_cast<int8_t const&>(
        message_id_b_raw
    );
    return result;
}
const int AISAssignmentModeCommand::BYTE_LENGTH;
const int AISAssignmentModeCommand::ID;

AISAssignmentModeCommand AISAssignmentModeCommand::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISAssignmentModeCommand result;
    result.time = message.time;

    result.message_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0x3f;
    result.repeat_indicator = (decode8(
        &message.payload[0]
    ) >> 6) & 0x3;
    auto source_id_raw = decode32(
        &message.payload[1]
    );
    result.source_id = reinterpret_cast<int32_t const&>(
        source_id_raw
    );
    result.ais_transceiver_information = (decode8(
        &message.payload[5]
    ) >> 1) & 0x1f;
    auto destination_id_raw = decode32(
        &message.payload[6]
    );
    result.destination_id = reinterpret_cast<int32_t const&>(
        destination_id_raw
    );
    auto offset_raw = decode16(
        &message.payload[10]
    );
    result.offset = reinterpret_cast<int16_t const&>(
        offset_raw
    );
    auto increment_raw = decode16(
        &message.payload[12]
    );
    result.increment = reinterpret_cast<int16_t const&>(
        increment_raw
    );
    return result;
}
const int AISDataLinkManagementMessage::BYTE_LENGTH;
const int AISDataLinkManagementMessage::ID;

AISDataLinkManagementMessage AISDataLinkManagementMessage::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISDataLinkManagementMessage result;
    result.time = message.time;

    result.message_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0x3f;
    result.repeat_indicator = (decode8(
        &message.payload[0]
    ) >> 6) & 0x3;
    result.ais_transceiver_information = (decode8(
        &message.payload[5]
    ) >> 0) & 0x1f;
    return result;
}
const int AISChannelManagement::BYTE_LENGTH;
const int AISChannelManagement::ID;

AISChannelManagement AISChannelManagement::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISChannelManagement result;
    result.time = message.time;

    result.message_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0x3f;
    result.repeat_indicator = (decode8(
        &message.payload[0]
    ) >> 6) & 0x3;
    result.ais_transceiver_information = (decode8(
        &message.payload[5]
    ) >> 0) & 0x1f;
    result.channel_a = (decode8(
        &message.payload[6]
    ) >> 0) & 0x7f;
    result.channel_b = (decode8(
        &message.payload[6]
    ) >> 7) & 0x7f;
    result.power = (decode8(
        &message.payload[8]
    ) >> 0) & 0xff;
    auto tx_rx_mode_raw = decode8(
        &message.payload[9]
    );
    result.tx_rx_mode = reinterpret_cast<int8_t const&>(
        tx_rx_mode_raw
    );
    auto north_east_longitude_corner_1_raw = decode32(
        &message.payload[10]
    );
    int32_t north_east_longitude_corner_1_iraw =
        reinterpret_cast<int32_t const&>(north_east_longitude_corner_1_raw);
    result.north_east_longitude_corner_1 = north_east_longitude_corner_1_iraw * 1.0e-07 + 0.0;
    auto north_east_latitude_corner_1_raw = decode32(
        &message.payload[14]
    );
    int32_t north_east_latitude_corner_1_iraw =
        reinterpret_cast<int32_t const&>(north_east_latitude_corner_1_raw);
    result.north_east_latitude_corner_1 = north_east_latitude_corner_1_iraw * 1.0e-07 + 0.0;
    auto south_west_longitude_corner_1_raw = decode32(
        &message.payload[18]
    );
    int32_t south_west_longitude_corner_1_iraw =
        reinterpret_cast<int32_t const&>(south_west_longitude_corner_1_raw);
    result.south_west_longitude_corner_1 = south_west_longitude_corner_1_iraw * 1.0e-07 + 0.0;
    auto south_west_latitude_corner_2_raw = decode32(
        &message.payload[22]
    );
    int32_t south_west_latitude_corner_2_iraw =
        reinterpret_cast<int32_t const&>(south_west_latitude_corner_2_raw);
    result.south_west_latitude_corner_2 = south_west_latitude_corner_2_iraw * 1.0e-07 + 0.0;
    result.addressed_or_broadcast_message_indicator = (decode8(
        &message.payload[26]
    ) >> 6) & 0x3;
    result.transitional_zone_size = (decode8(
        &message.payload[29]
    ) >> 0) & 0xff;
    return result;
}
const int AISClassBGroupAssignment::BYTE_LENGTH;
const int AISClassBGroupAssignment::ID;

AISClassBGroupAssignment AISClassBGroupAssignment::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISClassBGroupAssignment result;
    result.time = message.time;

    result.message_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0x3f;
    result.repeat_indicator = (decode8(
        &message.payload[0]
    ) >> 6) & 0x3;
    auto north_east_longitude_corner_1_raw = decode32(
        &message.payload[6]
    );
    int32_t north_east_longitude_corner_1_iraw =
        reinterpret_cast<int32_t const&>(north_east_longitude_corner_1_raw);
    result.north_east_longitude_corner_1 = north_east_longitude_corner_1_iraw * 1.0e-07 + 0.0;
    auto north_east_latitude_corner_1_raw = decode32(
        &message.payload[10]
    );
    int32_t north_east_latitude_corner_1_iraw =
        reinterpret_cast<int32_t const&>(north_east_latitude_corner_1_raw);
    result.north_east_latitude_corner_1 = north_east_latitude_corner_1_iraw * 1.0e-07 + 0.0;
    auto south_west_longitude_corner_1_raw = decode32(
        &message.payload[14]
    );
    int32_t south_west_longitude_corner_1_iraw =
        reinterpret_cast<int32_t const&>(south_west_longitude_corner_1_raw);
    result.south_west_longitude_corner_1 = south_west_longitude_corner_1_iraw * 1.0e-07 + 0.0;
    auto south_west_latitude_corner_2_raw = decode32(
        &message.payload[18]
    );
    int32_t south_west_latitude_corner_2_iraw =
        reinterpret_cast<int32_t const&>(south_west_latitude_corner_2_raw);
    result.south_west_latitude_corner_2 = south_west_latitude_corner_2_iraw * 1.0e-07 + 0.0;
    result.station_type = (decode8(
        &message.payload[22]
    ) >> 0) & 0xff;
    result.ship_and_cargo_filter = (decode8(
        &message.payload[23]
    ) >> 2) & 0x3f;
    result.reporting_interval = (decode16(
        &message.payload[24]
    ) >> 2) & 0xffff;
    result.quiet_time = (decode16(
        &message.payload[26]
    ) >> 2) & 0xffff;
    return result;
}
const int DSCCallInformation::BYTE_LENGTH;
const int DSCCallInformation::ID;

DSCCallInformation DSCCallInformation::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    DSCCallInformation result;
    result.time = message.time;

    result.dsc_format_symbol = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.dsc_category_symbol = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.dsc_message_address = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    result.nature_of_distress_or_1st_telecommand = (decode8(
        &message.payload[3]
    ) >> 0) & 0xff;
    result.subsequent_communication_mode_or_2nd_telecommand = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result.proposed_rx_frequency_channel = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.proposed_tx_frequency_channel = (decode8(
        &message.payload[6]
    ) >> 0) & 0xff;
    result.telephone_number = (decode8(
        &message.payload[7]
    ) >> 0) & 0xff;
    auto latitude_of_vessel_reported_raw = decode32(
        &message.payload[8]
    );
    int32_t latitude_of_vessel_reported_iraw =
        reinterpret_cast<int32_t const&>(latitude_of_vessel_reported_raw);
    result.latitude_of_vessel_reported = latitude_of_vessel_reported_iraw * 1.0e-07 + 0.0;
    auto longitude_of_vessel_reported_raw = decode32(
        &message.payload[12]
    );
    int32_t longitude_of_vessel_reported_iraw =
        reinterpret_cast<int32_t const&>(longitude_of_vessel_reported_raw);
    result.longitude_of_vessel_reported = longitude_of_vessel_reported_iraw * 1.0e-07 + 0.0;
    auto time_of_position_raw = decode32(
        &message.payload[16]
    );
    uint32_t time_of_position_iraw =
        reinterpret_cast<uint32_t const&>(time_of_position_raw);
    result.time_of_position = time_of_position_iraw * 0.0001 + 0.0;
    auto user_id_of_ship_in_distress_raw = decode32(
        &message.payload[20]
    );
    result.user_id_of_ship_in_distress = reinterpret_cast<int32_t const&>(
        user_id_of_ship_in_distress_raw
    );
    result.dsc_eos_symbol = (decode8(
        &message.payload[24]
    ) >> 0) & 0xff;
    result.expansion_enabled = (decode8(
        &message.payload[25]
    ) >> 0) & 0xff;
    result.calling_rx_frequency_channel = (decode8(
        &message.payload[26]
    ) >> 0) & 0xff;
    result.calling_tx_frequency_channel = (decode8(
        &message.payload[27]
    ) >> 0) & 0xff;
    auto time_of_receipt_raw = decode32(
        &message.payload[28]
    );
    uint32_t time_of_receipt_iraw =
        reinterpret_cast<uint32_t const&>(time_of_receipt_raw);
    result.time_of_receipt = time_of_receipt_iraw * 0.0001 + 0.0;
    result.date_of_receipt = (decode16(
        &message.payload[32]
    ) >> 0) & 0xffff;
    result.dsc_equipment_assigned_message_id = (decode8(
        &message.payload[34]
    ) >> 0) & 0xff;
    result.dsc_expansion_field_symbol = (decode8(
        &message.payload[35]
    ) >> 0) & 0xff;
    result.dsc_expansion_field_data = (decode8(
        &message.payload[36]
    ) >> 0) & 0xff;
    return result;
}
const int AISClassBStaticDataMsg24PartA::BYTE_LENGTH;
const int AISClassBStaticDataMsg24PartA::ID;

AISClassBStaticDataMsg24PartA AISClassBStaticDataMsg24PartA::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISClassBStaticDataMsg24PartA result;
    result.time = message.time;

    result.message_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0x3f;
    result.repeat_indicator = (decode8(
        &message.payload[0]
    ) >> 6) & 0x3;
    auto user_id_raw = decode32(
        &message.payload[1]
    );
    result.user_id = reinterpret_cast<int32_t const&>(
        user_id_raw
    );
    result.name = decodeString(&message.payload[5],
                                            32);
    return result;
}
const int AISClassBStaticDataMsg24PartB::BYTE_LENGTH;
const int AISClassBStaticDataMsg24PartB::ID;

AISClassBStaticDataMsg24PartB AISClassBStaticDataMsg24PartB::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISClassBStaticDataMsg24PartB result;
    result.time = message.time;

    result.message_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0x3f;
    result.repeat_indicator = (decode8(
        &message.payload[0]
    ) >> 6) & 0x3;
    auto user_id_raw = decode32(
        &message.payload[1]
    );
    result.user_id = reinterpret_cast<int32_t const&>(
        user_id_raw
    );
    result.type_of_ship = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.vendor_id = decodeString(&message.payload[6],
                                            8);
    result.callsign = decodeString(&message.payload[13],
                                            8);
    auto length_raw = decode16(
        &message.payload[20]
    );
    int16_t length_iraw =
        reinterpret_cast<int16_t const&>(length_raw);
    result.length = length_iraw * 0.1 + 0.0;
    auto beam_raw = decode16(
        &message.payload[22]
    );
    int16_t beam_iraw =
        reinterpret_cast<int16_t const&>(beam_raw);
    result.beam = beam_iraw * 0.1 + 0.0;
    auto position_reference_from_starboard_raw = decode16(
        &message.payload[24]
    );
    int16_t position_reference_from_starboard_iraw =
        reinterpret_cast<int16_t const&>(position_reference_from_starboard_raw);
    result.position_reference_from_starboard = position_reference_from_starboard_iraw * 0.1 + 0.0;
    auto position_reference_from_bow_raw = decode16(
        &message.payload[26]
    );
    int16_t position_reference_from_bow_iraw =
        reinterpret_cast<int16_t const&>(position_reference_from_bow_raw);
    result.position_reference_from_bow = position_reference_from_bow_iraw * 0.1 + 0.0;
    auto mothership_user_id_raw = decode32(
        &message.payload[28]
    );
    result.mothership_user_id = reinterpret_cast<int32_t const&>(
        mothership_user_id_raw
    );
    return result;
}
const int RouteAndWPServiceDatabaseList::BYTE_LENGTH;
const int RouteAndWPServiceDatabaseList::ID;

RouteAndWPServiceDatabaseList RouteAndWPServiceDatabaseList::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RouteAndWPServiceDatabaseList result;
    result.time = message.time;

    result.start_database_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.nitems = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.number_of_databases_available = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    result.database_id = (decode8(
        &message.payload[3]
    ) >> 0) & 0xff;
    result.database_name = decodeString(&message.payload[4],
                                            8);
    auto database_timestamp_raw = decode32(
        &message.payload[12]
    );
    uint32_t database_timestamp_iraw =
        reinterpret_cast<uint32_t const&>(database_timestamp_raw);
    result.database_timestamp = database_timestamp_iraw * 0.0001 + 0.0;
    result.database_datestamp = (decode16(
        &message.payload[16]
    ) >> 0) & 0xffff;
    result.wp_position_resolution = (decode8(
        &message.payload[18]
    ) >> 0) & 0x3f;
    result.number_of_routes_in_database = (decode16(
        &message.payload[19]
    ) >> 0) & 0xffff;
    result.number_of_wps_in_database = (decode16(
        &message.payload[21]
    ) >> 0) & 0xffff;
    result.number_of_bytes_in_database = (decode16(
        &message.payload[23]
    ) >> 0) & 0xffff;
    return result;
}
const int RouteAndWPServiceRouteList::BYTE_LENGTH;
const int RouteAndWPServiceRouteList::ID;

RouteAndWPServiceRouteList RouteAndWPServiceRouteList::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RouteAndWPServiceRouteList result;
    result.time = message.time;

    result.start_route_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.nitems = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.number_of_routes_in_database = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    result.database_id = (decode8(
        &message.payload[3]
    ) >> 0) & 0xff;
    result.route_id = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result.route_name = decodeString(&message.payload[5],
                                            8);
    result.wp_identification_method = (decode8(
        &message.payload[13]
    ) >> 4) & 0x3;
    result.route_status = (decode8(
        &message.payload[13]
    ) >> 6) & 0x3;
    return result;
}
const int RouteAndWPServiceRouteWPListAttributes::BYTE_LENGTH;
const int RouteAndWPServiceRouteWPListAttributes::ID;

RouteAndWPServiceRouteWPListAttributes RouteAndWPServiceRouteWPListAttributes::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RouteAndWPServiceRouteWPListAttributes result;
    result.time = message.time;

    result.database_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.route_id = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.route_wp_list_name = decodeString(&message.payload[2],
                                            8);
    auto route_wp_list_timestamp_raw = decode32(
        &message.payload[10]
    );
    uint32_t route_wp_list_timestamp_iraw =
        reinterpret_cast<uint32_t const&>(route_wp_list_timestamp_raw);
    result.route_wp_list_timestamp = route_wp_list_timestamp_iraw * 0.0001 + 0.0;
    result.route_wp_list_datestamp = (decode16(
        &message.payload[14]
    ) >> 0) & 0xffff;
    result.change_at_last_timestamp = (decode8(
        &message.payload[16]
    ) >> 0) & 0xff;
    result.number_of_wps_in_the_route_wp_list = (decode16(
        &message.payload[17]
    ) >> 0) & 0xffff;
    result.critical_supplementary_parameters = (decode8(
        &message.payload[19]
    ) >> 0) & 0xff;
    result.navigation_method = (decode8(
        &message.payload[20]
    ) >> 0) & 0x3;
    result.wp_identification_method = (decode8(
        &message.payload[20]
    ) >> 2) & 0x3;
    result.route_status = (decode8(
        &message.payload[20]
    ) >> 4) & 0x3;
    result.xte_limit_for_the_route = (decode16(
        &message.payload[20]
    ) >> 6) & 0xffff;
    return result;
}
const int RouteAndWPServiceRouteWPNamePosition::BYTE_LENGTH;
const int RouteAndWPServiceRouteWPNamePosition::ID;

RouteAndWPServiceRouteWPNamePosition RouteAndWPServiceRouteWPNamePosition::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RouteAndWPServiceRouteWPNamePosition result;
    result.time = message.time;

    result.start_rpsnumber = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.nitems = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.number_of_wps_in_the_route_wp_list = (decode16(
        &message.payload[2]
    ) >> 0) & 0xffff;
    result.database_id = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result.route_id = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.wp_id = (decode8(
        &message.payload[6]
    ) >> 0) & 0xff;
    result.wp_name = decodeString(&message.payload[7],
                                            8);
    auto wp_latitude_raw = decode32(
        &message.payload[15]
    );
    int32_t wp_latitude_iraw =
        reinterpret_cast<int32_t const&>(wp_latitude_raw);
    result.wp_latitude = wp_latitude_iraw * 1.0e-07 + 0.0;
    auto wp_longitude_raw = decode32(
        &message.payload[19]
    );
    int32_t wp_longitude_iraw =
        reinterpret_cast<int32_t const&>(wp_longitude_raw);
    result.wp_longitude = wp_longitude_iraw * 1.0e-07 + 0.0;
    return result;
}
const int RouteAndWPServiceRouteWPName::BYTE_LENGTH;
const int RouteAndWPServiceRouteWPName::ID;

RouteAndWPServiceRouteWPName RouteAndWPServiceRouteWPName::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RouteAndWPServiceRouteWPName result;
    result.time = message.time;

    result.start_rpsnumber = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.nitems = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.number_of_wps_in_the_route_wp_list = (decode16(
        &message.payload[2]
    ) >> 0) & 0xffff;
    result.database_id = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result.route_id = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.wp_id = (decode8(
        &message.payload[6]
    ) >> 0) & 0xff;
    result.wp_name = decodeString(&message.payload[7],
                                            8);
    return result;
}
const int RouteAndWPServiceXTELimitNavigationMethod::BYTE_LENGTH;
const int RouteAndWPServiceXTELimitNavigationMethod::ID;

RouteAndWPServiceXTELimitNavigationMethod RouteAndWPServiceXTELimitNavigationMethod::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RouteAndWPServiceXTELimitNavigationMethod result;
    result.time = message.time;

    result.start_rpsnumber = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.nitems = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.number_of_wps_with_a_specific_xte_limit_or_nav_method = (decode16(
        &message.payload[2]
    ) >> 0) & 0xffff;
    result.database_id = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result.route_id = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.rpsnumber = (decode8(
        &message.payload[6]
    ) >> 0) & 0xff;
    result.xte_limit_in_the_leg_after_wp = (decode16(
        &message.payload[7]
    ) >> 0) & 0xffff;
    result.nav_method_in_the_leg_after_wp = (decode8(
        &message.payload[9]
    ) >> 0) & 0xf;
    return result;
}
const int RouteAndWPServiceWPComment::BYTE_LENGTH;
const int RouteAndWPServiceWPComment::ID;

RouteAndWPServiceWPComment RouteAndWPServiceWPComment::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RouteAndWPServiceWPComment result;
    result.time = message.time;

    result.start_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.nitems = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.number_of_wps_with_comments = (decode16(
        &message.payload[2]
    ) >> 0) & 0xffff;
    result.database_id = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result.route_id = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.wp_id_rpsnumber = (decode8(
        &message.payload[6]
    ) >> 0) & 0xff;
    result.comment = decodeString(&message.payload[7],
                                            8);
    return result;
}
const int RouteAndWPServiceRouteComment::BYTE_LENGTH;
const int RouteAndWPServiceRouteComment::ID;

RouteAndWPServiceRouteComment RouteAndWPServiceRouteComment::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RouteAndWPServiceRouteComment result;
    result.time = message.time;

    result.start_route_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.nitems = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.number_of_routes_with_comments = (decode16(
        &message.payload[2]
    ) >> 0) & 0xffff;
    result.database_id = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result.route_id = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.comment = decodeString(&message.payload[6],
                                            8);
    return result;
}
const int RouteAndWPServiceDatabaseComment::BYTE_LENGTH;
const int RouteAndWPServiceDatabaseComment::ID;

RouteAndWPServiceDatabaseComment RouteAndWPServiceDatabaseComment::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RouteAndWPServiceDatabaseComment result;
    result.time = message.time;

    result.start_database_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.nitems = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.number_of_databases_with_comments = (decode16(
        &message.payload[2]
    ) >> 0) & 0xffff;
    result.database_id = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result.comment = decodeString(&message.payload[5],
                                            8);
    return result;
}
const int RouteAndWPServiceRadiusOfTurn::BYTE_LENGTH;
const int RouteAndWPServiceRadiusOfTurn::ID;

RouteAndWPServiceRadiusOfTurn RouteAndWPServiceRadiusOfTurn::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RouteAndWPServiceRadiusOfTurn result;
    result.time = message.time;

    result.start_rpsnumber = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.nitems = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.number_of_wps_with_a_specific_radius_of_turn = (decode16(
        &message.payload[2]
    ) >> 0) & 0xffff;
    result.database_id = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result.route_id = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.rpsnumber = (decode8(
        &message.payload[6]
    ) >> 0) & 0xff;
    result.radius_of_turn = (decode16(
        &message.payload[7]
    ) >> 0) & 0xffff;
    return result;
}
const int RouteAndWPServiceWPListWPNamePosition::BYTE_LENGTH;
const int RouteAndWPServiceWPListWPNamePosition::ID;

RouteAndWPServiceWPListWPNamePosition RouteAndWPServiceWPListWPNamePosition::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RouteAndWPServiceWPListWPNamePosition result;
    result.time = message.time;

    result.start_wp_id = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.nitems = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.number_of_valid_wps_in_the_wp_list = (decode16(
        &message.payload[2]
    ) >> 0) & 0xffff;
    result.database_id = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result.reserved = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.wp_id = (decode8(
        &message.payload[6]
    ) >> 0) & 0xff;
    result.wp_name = decodeString(&message.payload[7],
                                            8);
    auto wp_latitude_raw = decode32(
        &message.payload[15]
    );
    int32_t wp_latitude_iraw =
        reinterpret_cast<int32_t const&>(wp_latitude_raw);
    result.wp_latitude = wp_latitude_iraw * 1.0e-07 + 0.0;
    auto wp_longitude_raw = decode32(
        &message.payload[19]
    );
    int32_t wp_longitude_iraw =
        reinterpret_cast<int32_t const&>(wp_longitude_raw);
    result.wp_longitude = wp_longitude_iraw * 1.0e-07 + 0.0;
    return result;
}
const int WindData::BYTE_LENGTH;
const int WindData::ID;

WindData WindData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    WindData result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    auto wind_speed_raw = decode16(
        &message.payload[1]
    );
    int16_t wind_speed_iraw =
        reinterpret_cast<int16_t const&>(wind_speed_raw);
    result.wind_speed = wind_speed_iraw * 0.01 + 0.0;
    auto wind_angle_raw = decode16(
        &message.payload[3]
    );
    uint16_t wind_angle_iraw =
        reinterpret_cast<uint16_t const&>(wind_angle_raw);
    result.wind_angle = wind_angle_iraw * 0.005729577951308233 + 0.0;
    result.reference = (decode8(
        &message.payload[5]
    ) >> 0) & 0x7;
    result.reserved = (decode8(
        &message.payload[5]
    ) >> 3) & 0x1f;
    return result;
}
const int EnvironmentalParameters::BYTE_LENGTH;
const int EnvironmentalParameters::ID;

EnvironmentalParameters EnvironmentalParameters::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    EnvironmentalParameters result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    auto water_temperature_raw = decode16(
        &message.payload[1]
    );
    uint16_t water_temperature_iraw =
        reinterpret_cast<uint16_t const&>(water_temperature_raw);
    result.water_temperature = water_temperature_iraw * 0.01 + -273.15;
    auto outside_ambient_air_temperature_raw = decode16(
        &message.payload[3]
    );
    uint16_t outside_ambient_air_temperature_iraw =
        reinterpret_cast<uint16_t const&>(outside_ambient_air_temperature_raw);
    result.outside_ambient_air_temperature = outside_ambient_air_temperature_iraw * 0.01 + -273.15;
    result.atmospheric_pressure = (decode16(
        &message.payload[5]
    ) >> 0) & 0xffff;
    result.reserved = (decode8(
        &message.payload[7]
    ) >> 0) & 0xff;
    return result;
}
const int EnvironmentalParametersExt::BYTE_LENGTH;
const int EnvironmentalParametersExt::ID;

EnvironmentalParametersExt EnvironmentalParametersExt::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    EnvironmentalParametersExt result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.temperature_instance = (decode8(
        &message.payload[1]
    ) >> 0) & 0x3f;
    result.humidity_instance = (decode8(
        &message.payload[1]
    ) >> 6) & 0x3;
    auto temperature_raw = decode16(
        &message.payload[2]
    );
    uint16_t temperature_iraw =
        reinterpret_cast<uint16_t const&>(temperature_raw);
    result.temperature = temperature_iraw * 0.01 + -273.15;
    auto humidity_raw = decode16(
        &message.payload[4]
    );
    int16_t humidity_iraw =
        reinterpret_cast<int16_t const&>(humidity_raw);
    result.humidity = humidity_iraw * 0.004 + 0.0;
    result.atmospheric_pressure = (decode16(
        &message.payload[6]
    ) >> 0) & 0xffff;
    return result;
}
const int Temperature::BYTE_LENGTH;
const int Temperature::ID;

Temperature Temperature::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    Temperature result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.temperature_instance = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.temperature_source = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    auto actual_temperature_raw = decode16(
        &message.payload[3]
    );
    uint16_t actual_temperature_iraw =
        reinterpret_cast<uint16_t const&>(actual_temperature_raw);
    result.actual_temperature = actual_temperature_iraw * 0.01 + -273.15;
    auto set_temperature_raw = decode16(
        &message.payload[5]
    );
    uint16_t set_temperature_iraw =
        reinterpret_cast<uint16_t const&>(set_temperature_raw);
    result.set_temperature = set_temperature_iraw * 0.01 + -273.15;
    result.reserved = (decode8(
        &message.payload[7]
    ) >> 0) & 0xff;
    return result;
}
const int Humidity::BYTE_LENGTH;
const int Humidity::ID;

Humidity Humidity::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    Humidity result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.humidity_instance = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.humidity_source = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    result.actual_humidity = (decode16(
        &message.payload[3]
    ) >> 0) & 0xffff;
    result.set_humidity = (decode16(
        &message.payload[5]
    ) >> 0) & 0xffff;
    result.reserved = (decode8(
        &message.payload[7]
    ) >> 0) & 0xff;
    return result;
}
const int ActualPressure::BYTE_LENGTH;
const int ActualPressure::ID;

ActualPressure ActualPressure::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    ActualPressure result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.pressure_instance = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.pressure_source = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    auto pressure_raw = decode32(
        &message.payload[3]
    );
    uint32_t pressure_iraw =
        reinterpret_cast<uint32_t const&>(pressure_raw);
    result.pressure = pressure_iraw * 0.1 + 0.0;
    return result;
}
const int SetPressure::BYTE_LENGTH;
const int SetPressure::ID;

SetPressure SetPressure::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SetPressure result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.pressure_instance = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.pressure_source = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    result.set_pressure = (decode32(
        &message.payload[3]
    ) >> 0) & 0xffffffff;
    return result;
}
const int TemperatureExtendedRange::BYTE_LENGTH;
const int TemperatureExtendedRange::ID;

TemperatureExtendedRange TemperatureExtendedRange::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    TemperatureExtendedRange result;
    result.time = message.time;

    result.sid = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.temperature_instance = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    result.temperature_source = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    auto actual_temperature_raw = decode32(
        &message.payload[3]
    );
    uint32_t actual_temperature_iraw =
        reinterpret_cast<uint32_t const&>(actual_temperature_raw);
    result.actual_temperature = actual_temperature_iraw * 0.001 + -273.15;
    auto set_temperature_raw = decode16(
        &message.payload[6]
    );
    uint16_t set_temperature_iraw =
        reinterpret_cast<uint16_t const&>(set_temperature_raw);
    result.set_temperature = set_temperature_iraw * 0.1 + -273.15;
    return result;
}
const int TideStationData::BYTE_LENGTH;
const int TideStationData::ID;

TideStationData TideStationData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    TideStationData result;
    result.time = message.time;

    result.mode = (decode8(
        &message.payload[0]
    ) >> 0) & 0xf;
    result.tide_tendency = (decode8(
        &message.payload[0]
    ) >> 4) & 0x3;
    result.measurement_date = (decode16(
        &message.payload[1]
    ) >> 0) & 0xffff;
    auto measurement_time_raw = decode32(
        &message.payload[3]
    );
    uint32_t measurement_time_iraw =
        reinterpret_cast<uint32_t const&>(measurement_time_raw);
    result.measurement_time = measurement_time_iraw * 0.0001 + 0.0;
    auto station_latitude_raw = decode32(
        &message.payload[7]
    );
    int32_t station_latitude_iraw =
        reinterpret_cast<int32_t const&>(station_latitude_raw);
    result.station_latitude = station_latitude_iraw * 1.0e-07 + 0.0;
    auto station_longitude_raw = decode32(
        &message.payload[11]
    );
    int32_t station_longitude_iraw =
        reinterpret_cast<int32_t const&>(station_longitude_raw);
    result.station_longitude = station_longitude_iraw * 1.0e-07 + 0.0;
    auto tide_level_raw = decode16(
        &message.payload[15]
    );
    int16_t tide_level_iraw =
        reinterpret_cast<int16_t const&>(tide_level_raw);
    result.tide_level = tide_level_iraw * 0.001 + 0.0;
    auto tide_level_standard_deviation_raw = decode16(
        &message.payload[17]
    );
    int16_t tide_level_standard_deviation_iraw =
        reinterpret_cast<int16_t const&>(tide_level_standard_deviation_raw);
    result.tide_level_standard_deviation = tide_level_standard_deviation_iraw * 0.01 + 0.0;
    return result;
}
const int SalinityStationData::BYTE_LENGTH;
const int SalinityStationData::ID;

SalinityStationData SalinityStationData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SalinityStationData result;
    result.time = message.time;

    result.mode = (decode8(
        &message.payload[0]
    ) >> 0) & 0xf;
    result.measurement_date = (decode16(
        &message.payload[1]
    ) >> 0) & 0xffff;
    auto measurement_time_raw = decode32(
        &message.payload[3]
    );
    uint32_t measurement_time_iraw =
        reinterpret_cast<uint32_t const&>(measurement_time_raw);
    result.measurement_time = measurement_time_iraw * 0.0001 + 0.0;
    auto station_latitude_raw = decode32(
        &message.payload[7]
    );
    int32_t station_latitude_iraw =
        reinterpret_cast<int32_t const&>(station_latitude_raw);
    result.station_latitude = station_latitude_iraw * 1.0e-07 + 0.0;
    auto station_longitude_raw = decode32(
        &message.payload[11]
    );
    int32_t station_longitude_iraw =
        reinterpret_cast<int32_t const&>(station_longitude_raw);
    result.station_longitude = station_longitude_iraw * 1.0e-07 + 0.0;
    auto salinity_raw = decode32(
        &message.payload[15]
    );
    int32_t salinity_iraw =
        reinterpret_cast<int32_t const&>(salinity_raw);
    result.salinity = salinity_iraw * 1.0 + 0.0;
    auto water_temperature_raw = decode16(
        &message.payload[19]
    );
    uint16_t water_temperature_iraw =
        reinterpret_cast<uint16_t const&>(water_temperature_raw);
    result.water_temperature = water_temperature_iraw * 0.01 + -273.15;
    return result;
}
const int CurrentStationData::BYTE_LENGTH;
const int CurrentStationData::ID;

CurrentStationData CurrentStationData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    CurrentStationData result;
    result.time = message.time;

    result.mode = (decode8(
        &message.payload[0]
    ) >> 0) & 0xf;
    result.measurement_date = (decode16(
        &message.payload[1]
    ) >> 0) & 0xffff;
    auto measurement_time_raw = decode32(
        &message.payload[3]
    );
    uint32_t measurement_time_iraw =
        reinterpret_cast<uint32_t const&>(measurement_time_raw);
    result.measurement_time = measurement_time_iraw * 0.0001 + 0.0;
    auto station_latitude_raw = decode32(
        &message.payload[7]
    );
    int32_t station_latitude_iraw =
        reinterpret_cast<int32_t const&>(station_latitude_raw);
    result.station_latitude = station_latitude_iraw * 1.0e-07 + 0.0;
    auto station_longitude_raw = decode32(
        &message.payload[11]
    );
    int32_t station_longitude_iraw =
        reinterpret_cast<int32_t const&>(station_longitude_raw);
    result.station_longitude = station_longitude_iraw * 1.0e-07 + 0.0;
    auto measurement_depth_raw = decode32(
        &message.payload[15]
    );
    int32_t measurement_depth_iraw =
        reinterpret_cast<int32_t const&>(measurement_depth_raw);
    result.measurement_depth = measurement_depth_iraw * 0.01 + 0.0;
    auto current_speed_raw = decode16(
        &message.payload[19]
    );
    int16_t current_speed_iraw =
        reinterpret_cast<int16_t const&>(current_speed_raw);
    result.current_speed = current_speed_iraw * 0.01 + 0.0;
    auto current_flow_direction_raw = decode16(
        &message.payload[21]
    );
    uint16_t current_flow_direction_iraw =
        reinterpret_cast<uint16_t const&>(current_flow_direction_raw);
    result.current_flow_direction = current_flow_direction_iraw * 0.005729577951308233 + 0.0;
    auto water_temperature_raw = decode16(
        &message.payload[23]
    );
    uint16_t water_temperature_iraw =
        reinterpret_cast<uint16_t const&>(water_temperature_raw);
    result.water_temperature = water_temperature_iraw * 0.01 + -273.15;
    return result;
}
const int MeteorologicalStationData::BYTE_LENGTH;
const int MeteorologicalStationData::ID;

MeteorologicalStationData MeteorologicalStationData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    MeteorologicalStationData result;
    result.time = message.time;

    result.mode = (decode8(
        &message.payload[0]
    ) >> 0) & 0xf;
    result.measurement_date = (decode16(
        &message.payload[1]
    ) >> 0) & 0xffff;
    auto measurement_time_raw = decode32(
        &message.payload[3]
    );
    uint32_t measurement_time_iraw =
        reinterpret_cast<uint32_t const&>(measurement_time_raw);
    result.measurement_time = measurement_time_iraw * 0.0001 + 0.0;
    auto station_latitude_raw = decode32(
        &message.payload[7]
    );
    int32_t station_latitude_iraw =
        reinterpret_cast<int32_t const&>(station_latitude_raw);
    result.station_latitude = station_latitude_iraw * 1.0e-07 + 0.0;
    auto station_longitude_raw = decode32(
        &message.payload[11]
    );
    int32_t station_longitude_iraw =
        reinterpret_cast<int32_t const&>(station_longitude_raw);
    result.station_longitude = station_longitude_iraw * 1.0e-07 + 0.0;
    auto wind_speed_raw = decode16(
        &message.payload[15]
    );
    int16_t wind_speed_iraw =
        reinterpret_cast<int16_t const&>(wind_speed_raw);
    result.wind_speed = wind_speed_iraw * 0.01 + 0.0;
    auto wind_direction_raw = decode16(
        &message.payload[17]
    );
    uint16_t wind_direction_iraw =
        reinterpret_cast<uint16_t const&>(wind_direction_raw);
    result.wind_direction = wind_direction_iraw * 0.005729577951308233 + 0.0;
    result.wind_reference = (decode8(
        &message.payload[19]
    ) >> 0) & 0x7;
    auto wind_gusts_raw = decode16(
        &message.payload[20]
    );
    int16_t wind_gusts_iraw =
        reinterpret_cast<int16_t const&>(wind_gusts_raw);
    result.wind_gusts = wind_gusts_iraw * 0.01 + 0.0;
    result.atmospheric_pressure = (decode16(
        &message.payload[22]
    ) >> 0) & 0xffff;
    auto ambient_temperature_raw = decode16(
        &message.payload[24]
    );
    uint16_t ambient_temperature_iraw =
        reinterpret_cast<uint16_t const&>(ambient_temperature_raw);
    result.ambient_temperature = ambient_temperature_iraw * 0.01 + -273.15;
    return result;
}
const int MooredBuoyStationData::BYTE_LENGTH;
const int MooredBuoyStationData::ID;

MooredBuoyStationData MooredBuoyStationData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    MooredBuoyStationData result;
    result.time = message.time;

    result.mode = (decode8(
        &message.payload[0]
    ) >> 0) & 0xf;
    result.measurement_date = (decode16(
        &message.payload[1]
    ) >> 0) & 0xffff;
    auto measurement_time_raw = decode32(
        &message.payload[3]
    );
    uint32_t measurement_time_iraw =
        reinterpret_cast<uint32_t const&>(measurement_time_raw);
    result.measurement_time = measurement_time_iraw * 0.0001 + 0.0;
    auto station_latitude_raw = decode32(
        &message.payload[7]
    );
    int32_t station_latitude_iraw =
        reinterpret_cast<int32_t const&>(station_latitude_raw);
    result.station_latitude = station_latitude_iraw * 1.0e-07 + 0.0;
    auto station_longitude_raw = decode32(
        &message.payload[11]
    );
    int32_t station_longitude_iraw =
        reinterpret_cast<int32_t const&>(station_longitude_raw);
    result.station_longitude = station_longitude_iraw * 1.0e-07 + 0.0;
    auto wind_speed_raw = decode16(
        &message.payload[15]
    );
    int16_t wind_speed_iraw =
        reinterpret_cast<int16_t const&>(wind_speed_raw);
    result.wind_speed = wind_speed_iraw * 0.01 + 0.0;
    auto wind_direction_raw = decode16(
        &message.payload[17]
    );
    uint16_t wind_direction_iraw =
        reinterpret_cast<uint16_t const&>(wind_direction_raw);
    result.wind_direction = wind_direction_iraw * 0.005729577951308233 + 0.0;
    result.wind_reference = (decode8(
        &message.payload[19]
    ) >> 0) & 0x7;
    auto wind_gusts_raw = decode16(
        &message.payload[20]
    );
    int16_t wind_gusts_iraw =
        reinterpret_cast<int16_t const&>(wind_gusts_raw);
    result.wind_gusts = wind_gusts_iraw * 0.01 + 0.0;
    result.wave_height = (decode16(
        &message.payload[22]
    ) >> 0) & 0xffff;
    result.dominant_wave_period = (decode16(
        &message.payload[24]
    ) >> 0) & 0xffff;
    result.atmospheric_pressure = (decode16(
        &message.payload[26]
    ) >> 0) & 0xffff;
    result.pressure_tendency_rate = (decode16(
        &message.payload[28]
    ) >> 0) & 0xffff;
    auto air_temperature_raw = decode16(
        &message.payload[30]
    );
    uint16_t air_temperature_iraw =
        reinterpret_cast<uint16_t const&>(air_temperature_raw);
    result.air_temperature = air_temperature_iraw * 0.01 + -273.15;
    auto water_temperature_raw = decode16(
        &message.payload[32]
    );
    uint16_t water_temperature_iraw =
        reinterpret_cast<uint16_t const&>(water_temperature_raw);
    result.water_temperature = water_temperature_iraw * 0.01 + -273.15;
    result.station_id = decodeString(&message.payload[34],
                                            8);
    return result;
}
const int SmallCraftStatus::BYTE_LENGTH;
const int SmallCraftStatus::ID;

SmallCraftStatus SmallCraftStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SmallCraftStatus result;
    result.time = message.time;

    result.port_trim_tab = (decode8(
        &message.payload[0]
    ) >> 0) & 0xff;
    result.starboard_trim_tab = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    return result;
}
const int DirectionData::BYTE_LENGTH;
const int DirectionData::ID;

DirectionData DirectionData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    DirectionData result;
    result.time = message.time;

    result.data_mode = (decode8(
        &message.payload[0]
    ) >> 0) & 0xf;
    result.cog_reference = (decode8(
        &message.payload[0]
    ) >> 4) & 0x3;
    result.sid = (decode8(
        &message.payload[1]
    ) >> 0) & 0xff;
    auto cog_raw = decode16(
        &message.payload[2]
    );
    uint16_t cog_iraw =
        reinterpret_cast<uint16_t const&>(cog_raw);
    result.cog = cog_iraw * 0.005729577951308233 + 0.0;
    auto sog_raw = decode16(
        &message.payload[4]
    );
    uint16_t sog_iraw =
        reinterpret_cast<uint16_t const&>(sog_raw);
    result.sog = sog_iraw * 0.01 + 0.0;
    auto heading_raw = decode16(
        &message.payload[6]
    );
    uint16_t heading_iraw =
        reinterpret_cast<uint16_t const&>(heading_raw);
    result.heading = heading_iraw * 0.005729577951308233 + 0.0;
    auto speed_through_water_raw = decode16(
        &message.payload[8]
    );
    int16_t speed_through_water_iraw =
        reinterpret_cast<int16_t const&>(speed_through_water_raw);
    result.speed_through_water = speed_through_water_iraw * 0.01 + 0.0;
    auto set_raw = decode16(
        &message.payload[10]
    );
    uint16_t set_iraw =
        reinterpret_cast<uint16_t const&>(set_raw);
    result.set = set_iraw * 0.005729577951308233 + 0.0;
    auto drift_raw = decode16(
        &message.payload[12]
    );
    int16_t drift_iraw =
        reinterpret_cast<int16_t const&>(drift_raw);
    result.drift = drift_iraw * 0.01 + 0.0;
    return result;
}
const int VesselSpeedComponents::BYTE_LENGTH;
const int VesselSpeedComponents::ID;

VesselSpeedComponents VesselSpeedComponents::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    VesselSpeedComponents result;
    result.time = message.time;

    auto longitudinal_speed_water_referenced_raw = decode16(
        &message.payload[0]
    );
    int16_t longitudinal_speed_water_referenced_iraw =
        reinterpret_cast<int16_t const&>(longitudinal_speed_water_referenced_raw);
    result.longitudinal_speed_water_referenced = longitudinal_speed_water_referenced_iraw * 0.001 + 0.0;
    auto transverse_speed_water_referenced_raw = decode16(
        &message.payload[2]
    );
    int16_t transverse_speed_water_referenced_iraw =
        reinterpret_cast<int16_t const&>(transverse_speed_water_referenced_raw);
    result.transverse_speed_water_referenced = transverse_speed_water_referenced_iraw * 0.001 + 0.0;
    auto longitudinal_speed_ground_referenced_raw = decode16(
        &message.payload[4]
    );
    int16_t longitudinal_speed_ground_referenced_iraw =
        reinterpret_cast<int16_t const&>(longitudinal_speed_ground_referenced_raw);
    result.longitudinal_speed_ground_referenced = longitudinal_speed_ground_referenced_iraw * 0.001 + 0.0;
    auto transverse_speed_ground_referenced_raw = decode16(
        &message.payload[6]
    );
    int16_t transverse_speed_ground_referenced_iraw =
        reinterpret_cast<int16_t const&>(transverse_speed_ground_referenced_raw);
    result.transverse_speed_ground_referenced = transverse_speed_ground_referenced_iraw * 0.001 + 0.0;
    auto stern_speed_water_referenced_raw = decode16(
        &message.payload[8]
    );
    int16_t stern_speed_water_referenced_iraw =
        reinterpret_cast<int16_t const&>(stern_speed_water_referenced_raw);
    result.stern_speed_water_referenced = stern_speed_water_referenced_iraw * 0.001 + 0.0;
    auto stern_speed_ground_referenced_raw = decode16(
        &message.payload[10]
    );
    int16_t stern_speed_ground_referenced_iraw =
        reinterpret_cast<int16_t const&>(stern_speed_ground_referenced_raw);
    result.stern_speed_ground_referenced = stern_speed_ground_referenced_iraw * 0.001 + 0.0;
    return result;
}
const int SimradTextMessage::BYTE_LENGTH;
const int SimradTextMessage::ID;

SimradTextMessage SimradTextMessage::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimradTextMessage result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    auto product_code_raw = decode16(
        &message.payload[2]
    );
    result.product_code = reinterpret_cast<int16_t const&>(
        product_code_raw
    );
    result.a = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result.b = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.c = (decode8(
        &message.payload[6]
    ) >> 0) & 0xff;
    result.d = (decode8(
        &message.payload[7]
    ) >> 0) & 0xff;
    result.sid = (decode8(
        &message.payload[8]
    ) >> 0) & 0xff;
    result.prio = (decode8(
        &message.payload[9]
    ) >> 0) & 0xff;
    result.text = decodeString(&message.payload[10],
                                            32);
    return result;
}
const int NavicoProductInformation::BYTE_LENGTH;
const int NavicoProductInformation::ID;

NavicoProductInformation NavicoProductInformation::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    NavicoProductInformation result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    auto product_code_raw = decode16(
        &message.payload[2]
    );
    result.product_code = reinterpret_cast<int16_t const&>(
        product_code_raw
    );
    result.model = decodeString(&message.payload[4],
                                            32);
    result.a = (decode8(
        &message.payload[36]
    ) >> 0) & 0xff;
    result.b = (decode8(
        &message.payload[37]
    ) >> 0) & 0xff;
    result.c = (decode8(
        &message.payload[38]
    ) >> 0) & 0xff;
    result.firmware_version = decodeString(&message.payload[39],
                                            16);
    result.firmware_date = decodeString(&message.payload[49],
                                            32);
    result.firmware_time = decodeString(&message.payload[81],
                                            32);
    return result;
}
const int SimnetReprogramData::BYTE_LENGTH;
const int SimnetReprogramData::ID;

SimnetReprogramData SimnetReprogramData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetReprogramData result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    auto version_raw = decode16(
        &message.payload[2]
    );
    result.version = reinterpret_cast<int16_t const&>(
        version_raw
    );
    auto sequence_raw = decode16(
        &message.payload[4]
    );
    result.sequence = reinterpret_cast<int16_t const&>(
        sequence_raw
    );
    return result;
}
const int SimnetRequestReprogram::BYTE_LENGTH;
const int SimnetRequestReprogram::ID;

SimnetRequestReprogram SimnetRequestReprogram::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetRequestReprogram result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    return result;
}
const int SimnetReprogramStatus1::BYTE_LENGTH;
const int SimnetReprogramStatus1::ID;

SimnetReprogramStatus1 SimnetReprogramStatus1::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetReprogramStatus1 result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    result.reserved1 = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    result.status = (decode8(
        &message.payload[3]
    ) >> 0) & 0xff;
    result.reserved2 = (decode32(
        &message.payload[4]
    ) >> 0) & 0xffffff;
    return result;
}
const int LowranceUnknown::BYTE_LENGTH;
const int LowranceUnknown::ID;

LowranceUnknown LowranceUnknown::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    LowranceUnknown result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    result.a = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    result.b = (decode8(
        &message.payload[3]
    ) >> 0) & 0xff;
    result.c = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result.d = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.e = (decode16(
        &message.payload[6]
    ) >> 0) & 0xffff;
    result.f = (decode16(
        &message.payload[8]
    ) >> 0) & 0xffff;
    return result;
}
const int SimnetSetSerialNumber::BYTE_LENGTH;
const int SimnetSetSerialNumber::ID;

SimnetSetSerialNumber SimnetSetSerialNumber::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetSetSerialNumber result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    return result;
}
const int SuzukiEngineAndStorageDeviceConfig::BYTE_LENGTH;
const int SuzukiEngineAndStorageDeviceConfig::ID;

SuzukiEngineAndStorageDeviceConfig SuzukiEngineAndStorageDeviceConfig::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SuzukiEngineAndStorageDeviceConfig result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    return result;
}
const int SimnetFuelUsedHighResolution::BYTE_LENGTH;
const int SimnetFuelUsedHighResolution::ID;

SimnetFuelUsedHighResolution SimnetFuelUsedHighResolution::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetFuelUsedHighResolution result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    return result;
}
const int SimnetEngineAndTankConfiguration::BYTE_LENGTH;
const int SimnetEngineAndTankConfiguration::ID;

SimnetEngineAndTankConfiguration SimnetEngineAndTankConfiguration::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetEngineAndTankConfiguration result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    return result;
}
const int SimnetSetEngineAndTankConfiguration::BYTE_LENGTH;
const int SimnetSetEngineAndTankConfiguration::ID;

SimnetSetEngineAndTankConfiguration SimnetSetEngineAndTankConfiguration::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetSetEngineAndTankConfiguration result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    return result;
}
const int SimnetFluidLevelSensorConfiguration::BYTE_LENGTH;
const int SimnetFluidLevelSensorConfiguration::ID;

SimnetFluidLevelSensorConfiguration SimnetFluidLevelSensorConfiguration::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetFluidLevelSensorConfiguration result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    result.c = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    auto device_raw = decode8(
        &message.payload[3]
    );
    result.device = reinterpret_cast<int8_t const&>(
        device_raw
    );
    result.instance = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result.f = (decode8(
        &message.payload[5]
    ) >> 0) & 0xf;
    result.tank_type = (decode8(
        &message.payload[5]
    ) >> 4) & 0xf;
    auto capacity_raw = decode32(
        &message.payload[6]
    );
    int32_t capacity_iraw =
        reinterpret_cast<int32_t const&>(capacity_raw);
    result.capacity = capacity_iraw * 0.1 + 0.0;
    result.g = (decode8(
        &message.payload[10]
    ) >> 0) & 0xff;
    result.h = (decode16(
        &message.payload[11]
    ) >> 0) & 0xffff;
    result.i = (decode8(
        &message.payload[13]
    ) >> 0) & 0xff;
    return result;
}
const int SimnetFuelFlowTurbineConfiguration::BYTE_LENGTH;
const int SimnetFuelFlowTurbineConfiguration::ID;

SimnetFuelFlowTurbineConfiguration SimnetFuelFlowTurbineConfiguration::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetFuelFlowTurbineConfiguration result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    return result;
}
const int SimnetFluidLevelWarning::BYTE_LENGTH;
const int SimnetFluidLevelWarning::ID;

SimnetFluidLevelWarning SimnetFluidLevelWarning::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetFluidLevelWarning result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    return result;
}
const int SimnetPressureSensorConfiguration::BYTE_LENGTH;
const int SimnetPressureSensorConfiguration::ID;

SimnetPressureSensorConfiguration SimnetPressureSensorConfiguration::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetPressureSensorConfiguration result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    return result;
}
const int SimnetDataUserGroupConfiguration::BYTE_LENGTH;
const int SimnetDataUserGroupConfiguration::ID;

SimnetDataUserGroupConfiguration SimnetDataUserGroupConfiguration::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetDataUserGroupConfiguration result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    return result;
}
const int SimnetAISClassBStaticDataMsg24PartB::BYTE_LENGTH;
const int SimnetAISClassBStaticDataMsg24PartB::ID;

SimnetAISClassBStaticDataMsg24PartB SimnetAISClassBStaticDataMsg24PartB::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetAISClassBStaticDataMsg24PartB result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    result.message_id = (decode8(
        &message.payload[2]
    ) >> 0) & 0x3f;
    result.repeat_indicator = (decode8(
        &message.payload[2]
    ) >> 6) & 0x3;
    result.d = (decode8(
        &message.payload[3]
    ) >> 0) & 0xff;
    result.e = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    auto user_id_raw = decode32(
        &message.payload[5]
    );
    result.user_id = reinterpret_cast<int32_t const&>(
        user_id_raw
    );
    result.type_of_ship = (decode8(
        &message.payload[9]
    ) >> 0) & 0xff;
    result.vendor_id = decodeString(&message.payload[10],
                                            8);
    result.callsign = decodeString(&message.payload[17],
                                            8);
    auto length_raw = decode16(
        &message.payload[24]
    );
    int16_t length_iraw =
        reinterpret_cast<int16_t const&>(length_raw);
    result.length = length_iraw * 0.1 + 0.0;
    auto beam_raw = decode16(
        &message.payload[26]
    );
    int16_t beam_iraw =
        reinterpret_cast<int16_t const&>(beam_raw);
    result.beam = beam_iraw * 0.1 + 0.0;
    auto position_reference_from_starboard_raw = decode16(
        &message.payload[28]
    );
    int16_t position_reference_from_starboard_iraw =
        reinterpret_cast<int16_t const&>(position_reference_from_starboard_raw);
    result.position_reference_from_starboard = position_reference_from_starboard_iraw * 0.1 + 0.0;
    auto position_reference_from_bow_raw = decode16(
        &message.payload[30]
    );
    int16_t position_reference_from_bow_iraw =
        reinterpret_cast<int16_t const&>(position_reference_from_bow_raw);
    result.position_reference_from_bow = position_reference_from_bow_iraw * 0.1 + 0.0;
    auto mothership_user_id_raw = decode32(
        &message.payload[32]
    );
    result.mothership_user_id = reinterpret_cast<int32_t const&>(
        mothership_user_id_raw
    );
    result.reserved1 = (decode8(
        &message.payload[36]
    ) >> 0) & 0x3;
    return result;
}
const int SimnetAISClassBStaticDataMsg24PartA::BYTE_LENGTH;
const int SimnetAISClassBStaticDataMsg24PartA::ID;

SimnetAISClassBStaticDataMsg24PartA SimnetAISClassBStaticDataMsg24PartA::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetAISClassBStaticDataMsg24PartA result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    result.message_id = (decode8(
        &message.payload[2]
    ) >> 0) & 0x3f;
    result.repeat_indicator = (decode8(
        &message.payload[2]
    ) >> 6) & 0x3;
    result.d = (decode8(
        &message.payload[3]
    ) >> 0) & 0xff;
    result.e = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    auto user_id_raw = decode32(
        &message.payload[5]
    );
    result.user_id = reinterpret_cast<int32_t const&>(
        user_id_raw
    );
    result.name = decodeString(&message.payload[9],
                                            32);
    return result;
}
const int SimnetSonarStatusFrequencyAndDSPVoltage::BYTE_LENGTH;
const int SimnetSonarStatusFrequencyAndDSPVoltage::ID;

SimnetSonarStatusFrequencyAndDSPVoltage SimnetSonarStatusFrequencyAndDSPVoltage::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetSonarStatusFrequencyAndDSPVoltage result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    return result;
}
const int SimnetParameterHandle::BYTE_LENGTH;
const int SimnetParameterHandle::ID;

SimnetParameterHandle SimnetParameterHandle::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetParameterHandle result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    result.message_id = (decode8(
        &message.payload[2]
    ) >> 0) & 0x3f;
    result.repeat_indicator = (decode8(
        &message.payload[2]
    ) >> 6) & 0x3;
    result.d = (decode8(
        &message.payload[3]
    ) >> 0) & 0xff;
    result.group = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result.f = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.g = (decode8(
        &message.payload[6]
    ) >> 0) & 0xff;
    result.h = (decode8(
        &message.payload[7]
    ) >> 0) & 0xff;
    result.i = (decode8(
        &message.payload[8]
    ) >> 0) & 0xff;
    result.j = (decode8(
        &message.payload[9]
    ) >> 0) & 0xff;
    result.backlight = (decode8(
        &message.payload[10]
    ) >> 0) & 0xff;
    result.l = (decode16(
        &message.payload[11]
    ) >> 0) & 0xffff;
    return result;
}
const int SimnetEventCommandAPCommand::BYTE_LENGTH;
const int SimnetEventCommandAPCommand::ID;

SimnetEventCommandAPCommand SimnetEventCommandAPCommand::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetEventCommandAPCommand result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    result.ap_command = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    result.b = (decode16(
        &message.payload[3]
    ) >> 0) & 0xffff;
    result.controlling_device = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.event = (decode16(
        &message.payload[6]
    ) >> 0) & 0xffff;
    result.direction = (decode8(
        &message.payload[8]
    ) >> 0) & 0xff;
    auto angle_raw = decode16(
        &message.payload[9]
    );
    uint16_t angle_iraw =
        reinterpret_cast<uint16_t const&>(angle_raw);
    result.angle = angle_iraw * 0.005729577951308233 + 0.0;
    result.g = (decode8(
        &message.payload[11]
    ) >> 0) & 0xff;
    return result;
}
const int SimnetEventCommandAlarm::BYTE_LENGTH;
const int SimnetEventCommandAlarm::ID;

SimnetEventCommandAlarm SimnetEventCommandAlarm::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetEventCommandAlarm result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    result.a = (decode16(
        &message.payload[2]
    ) >> 0) & 0xffff;
    result.alarm_command = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result.c = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.alarm = (decode16(
        &message.payload[6]
    ) >> 0) & 0xffff;
    auto message_id_raw = decode16(
        &message.payload[8]
    );
    result.message_id = reinterpret_cast<int16_t const&>(
        message_id_raw
    );
    result.f = (decode8(
        &message.payload[10]
    ) >> 0) & 0xff;
    result.g = (decode8(
        &message.payload[11]
    ) >> 0) & 0xff;
    return result;
}
const int SimnetEventCommandUnknown::BYTE_LENGTH;
const int SimnetEventCommandUnknown::ID;

SimnetEventCommandUnknown SimnetEventCommandUnknown::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetEventCommandUnknown result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    result.a = (decode16(
        &message.payload[2]
    ) >> 0) & 0xffff;
    result.b = (decode16(
        &message.payload[4]
    ) >> 0) & 0xffff;
    result.c = (decode16(
        &message.payload[6]
    ) >> 0) & 0xffff;
    result.d = (decode16(
        &message.payload[8]
    ) >> 0) & 0xffff;
    result.e = (decode16(
        &message.payload[10]
    ) >> 0) & 0xffff;
    return result;
}
const int SimnetEventReplyAPCommand::BYTE_LENGTH;
const int SimnetEventReplyAPCommand::ID;

SimnetEventReplyAPCommand SimnetEventReplyAPCommand::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetEventReplyAPCommand result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    result.ap_command = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    result.b = (decode16(
        &message.payload[3]
    ) >> 0) & 0xffff;
    result.controlling_device = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.event = (decode16(
        &message.payload[6]
    ) >> 0) & 0xffff;
    result.direction = (decode8(
        &message.payload[8]
    ) >> 0) & 0xff;
    auto angle_raw = decode16(
        &message.payload[9]
    );
    uint16_t angle_iraw =
        reinterpret_cast<uint16_t const&>(angle_raw);
    result.angle = angle_iraw * 0.005729577951308233 + 0.0;
    result.g = (decode8(
        &message.payload[11]
    ) >> 0) & 0xff;
    return result;
}
const int SimnetAlarmMessage::BYTE_LENGTH;
const int SimnetAlarmMessage::ID;

SimnetAlarmMessage SimnetAlarmMessage::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetAlarmMessage result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    result.message_id = (decode16(
        &message.payload[2]
    ) >> 0) & 0xffff;
    result.b = (decode8(
        &message.payload[4]
    ) >> 0) & 0xff;
    result.c = (decode8(
        &message.payload[5]
    ) >> 0) & 0xff;
    result.text = decodeString(&message.payload[6],
                                            256);
    return result;
}
const int AirmarAdditionalWeatherData::BYTE_LENGTH;
const int AirmarAdditionalWeatherData::ID;

AirmarAdditionalWeatherData AirmarAdditionalWeatherData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AirmarAdditionalWeatherData result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    result.c = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    auto apparent_windchill_temperature_raw = decode16(
        &message.payload[3]
    );
    uint16_t apparent_windchill_temperature_iraw =
        reinterpret_cast<uint16_t const&>(apparent_windchill_temperature_raw);
    result.apparent_windchill_temperature = apparent_windchill_temperature_iraw * 0.01 + -273.15;
    auto true_windchill_temperature_raw = decode16(
        &message.payload[5]
    );
    uint16_t true_windchill_temperature_iraw =
        reinterpret_cast<uint16_t const&>(true_windchill_temperature_raw);
    result.true_windchill_temperature = true_windchill_temperature_iraw * 0.01 + -273.15;
    auto dewpoint_raw = decode16(
        &message.payload[7]
    );
    uint16_t dewpoint_iraw =
        reinterpret_cast<uint16_t const&>(dewpoint_raw);
    result.dewpoint = dewpoint_iraw * 0.01 + -273.15;
    return result;
}
const int AirmarHeaterControl::BYTE_LENGTH;
const int AirmarHeaterControl::ID;

AirmarHeaterControl AirmarHeaterControl::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AirmarHeaterControl result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    result.c = (decode8(
        &message.payload[2]
    ) >> 0) & 0xff;
    auto plate_temperature_raw = decode16(
        &message.payload[3]
    );
    uint16_t plate_temperature_iraw =
        reinterpret_cast<uint16_t const&>(plate_temperature_raw);
    result.plate_temperature = plate_temperature_iraw * 0.01 + -273.15;
    auto air_temperature_raw = decode16(
        &message.payload[5]
    );
    uint16_t air_temperature_iraw =
        reinterpret_cast<uint16_t const&>(air_temperature_raw);
    result.air_temperature = air_temperature_iraw * 0.01 + -273.15;
    auto dewpoint_raw = decode16(
        &message.payload[7]
    );
    uint16_t dewpoint_iraw =
        reinterpret_cast<uint16_t const&>(dewpoint_raw);
    result.dewpoint = dewpoint_iraw * 0.01 + -273.15;
    return result;
}
const int AirmarPOST::BYTE_LENGTH;
const int AirmarPOST::ID;

AirmarPOST AirmarPOST::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size < BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AirmarPOST result;
    result.time = message.time;

    result.reserved = (decode8(
        &message.payload[1]
    ) >> 3) & 0x3;
    result.industry_code = (decode8(
        &message.payload[1]
    ) >> 5) & 0x7;
    result.control = (decode8(
        &message.payload[2]
    ) >> 0) & 0xf;
    result.reserved1 = (decode8(
        &message.payload[2]
    ) >> 4) & 0x7f;
    result.test_id = (decode8(
        &message.payload[4]
    ) >> 3) & 0xff;
    result.test_result = (decode8(
        &message.payload[5]
    ) >> 3) & 0xff;
    return result;
}

nmea2000::PGNLibrary const& nmea2000::pgns::getLibrary() {
    static nmea2000::PGNLibrary library;

    if (library.empty()) {
        std::vector<PGNInfo> known_pgns;
        known_pgns.reserve(165);
                known_pgns.push_back({ 59392, 8 });
                known_pgns.push_back({ 59904, 3 });
                known_pgns.push_back({ 60928, 8 });
                known_pgns.push_back({ 65240, 10 });
                known_pgns.push_back({ 65285, 3 });
                known_pgns.push_back({ 65285, 5 });
                known_pgns.push_back({ 65286, 2 });
                known_pgns.push_back({ 65287, 2 });
                known_pgns.push_back({ 65287, 7 });
                known_pgns.push_back({ 65289, 2 });
                known_pgns.push_back({ 65290, 2 });
                known_pgns.push_back({ 65292, 2 });
                known_pgns.push_back({ 65293, 2 });
                known_pgns.push_back({ 65325, 2 });
                known_pgns.push_back({ 65341, 2 });
                known_pgns.push_back({ 65408, 4 });
                known_pgns.push_back({ 65410, 8 });
                known_pgns.push_back({ 65480, 2 });
                known_pgns.push_back({ 126208, 9 });
                known_pgns.push_back({ 126208, 9 });
                known_pgns.push_back({ 126208, 7 });
                known_pgns.push_back({ 126270, 8 });
                known_pgns.push_back({ 126464, 4 });
                known_pgns.push_back({ 126720, 24 });
                known_pgns.push_back({ 126720, 9 });
                known_pgns.push_back({ 126720, 24 });
                known_pgns.push_back({ 126720, 2 });
                known_pgns.push_back({ 126720, 3 });
                known_pgns.push_back({ 126992, 8 });
                known_pgns.push_back({ 126993, 8 });
                known_pgns.push_back({ 126996, 134 });
                known_pgns.push_back({ 126998, 0 });
                known_pgns.push_back({ 127237, 21 });
                known_pgns.push_back({ 127245, 6 });
                known_pgns.push_back({ 127250, 8 });
                known_pgns.push_back({ 127251, 5 });
                known_pgns.push_back({ 127257, 7 });
                known_pgns.push_back({ 127258, 6 });
                known_pgns.push_back({ 127488, 8 });
                known_pgns.push_back({ 127489, 26 });
                known_pgns.push_back({ 127493, 7 });
                known_pgns.push_back({ 127496, 14 });
                known_pgns.push_back({ 127497, 9 });
                known_pgns.push_back({ 127498, 6 });
                known_pgns.push_back({ 127501, 2 });
                known_pgns.push_back({ 127502, 2 });
                known_pgns.push_back({ 127503, 20 });
                known_pgns.push_back({ 127504, 20 });
                known_pgns.push_back({ 127505, 8 });
                known_pgns.push_back({ 127506, 9 });
                known_pgns.push_back({ 127507, 7 });
                known_pgns.push_back({ 127508, 8 });
                known_pgns.push_back({ 127509, 4 });
                known_pgns.push_back({ 127510, 12 });
                known_pgns.push_back({ 127511, 8 });
                known_pgns.push_back({ 127512, 3 });
                known_pgns.push_back({ 127513, 8 });
                known_pgns.push_back({ 127514, 6 });
                known_pgns.push_back({ 128259, 6 });
                known_pgns.push_back({ 128267, 8 });
                known_pgns.push_back({ 128275, 14 });
                known_pgns.push_back({ 128520, 280 });
                known_pgns.push_back({ 129025, 8 });
                known_pgns.push_back({ 129026, 8 });
                known_pgns.push_back({ 129027, 7 });
                known_pgns.push_back({ 129028, 10 });
                known_pgns.push_back({ 129029, 45 });
                known_pgns.push_back({ 129033, 8 });
                known_pgns.push_back({ 129038, 28 });
                known_pgns.push_back({ 129039, 26 });
                known_pgns.push_back({ 129040, 54 });
                known_pgns.push_back({ 129044, 20 });
                known_pgns.push_back({ 129045, 40 });
                known_pgns.push_back({ 129283, 6 });
                known_pgns.push_back({ 129284, 34 });
                known_pgns.push_back({ 129285, 530 });
                known_pgns.push_back({ 129291, 6 });
                known_pgns.push_back({ 129301, 10 });
                known_pgns.push_back({ 129302, 17 });
                known_pgns.push_back({ 129538, 14 });
                known_pgns.push_back({ 129539, 8 });
                known_pgns.push_back({ 129540, 219 });
                known_pgns.push_back({ 129541, 13 });
                known_pgns.push_back({ 129542, 9 });
                known_pgns.push_back({ 129545, 9 });
                known_pgns.push_back({ 129546, 4 });
                known_pgns.push_back({ 129547, 9 });
                known_pgns.push_back({ 129549, 13 });
                known_pgns.push_back({ 129550, 6 });
                known_pgns.push_back({ 129551, 14 });
                known_pgns.push_back({ 129556, 13 });
                known_pgns.push_back({ 129792, 19 });
                known_pgns.push_back({ 129793, 25 });
                known_pgns.push_back({ 129794, 75 });
                known_pgns.push_back({ 129795, 21 });
                known_pgns.push_back({ 129796, 12 });
                known_pgns.push_back({ 129797, 263 });
                known_pgns.push_back({ 129798, 31 });
                known_pgns.push_back({ 129799, 12 });
                known_pgns.push_back({ 129800, 10 });
                known_pgns.push_back({ 129801, 266 });
                known_pgns.push_back({ 129802, 42 });
                known_pgns.push_back({ 129803, 16 });
                known_pgns.push_back({ 129804, 14 });
                known_pgns.push_back({ 129805, 11 });
                known_pgns.push_back({ 129806, 30 });
                known_pgns.push_back({ 129807, 29 });
                known_pgns.push_back({ 129808, 37 });
                known_pgns.push_back({ 129809, 25 });
                known_pgns.push_back({ 129810, 33 });
                known_pgns.push_back({ 130064, 25 });
                known_pgns.push_back({ 130065, 14 });
                known_pgns.push_back({ 130066, 23 });
                known_pgns.push_back({ 130067, 23 });
                known_pgns.push_back({ 130068, 15 });
                known_pgns.push_back({ 130069, 10 });
                known_pgns.push_back({ 130070, 15 });
                known_pgns.push_back({ 130071, 14 });
                known_pgns.push_back({ 130072, 13 });
                known_pgns.push_back({ 130073, 9 });
                known_pgns.push_back({ 130074, 23 });
                known_pgns.push_back({ 130306, 6 });
                known_pgns.push_back({ 130310, 7 });
                known_pgns.push_back({ 130311, 8 });
                known_pgns.push_back({ 130312, 8 });
                known_pgns.push_back({ 130313, 8 });
                known_pgns.push_back({ 130314, 8 });
                known_pgns.push_back({ 130315, 8 });
                known_pgns.push_back({ 130316, 8 });
                known_pgns.push_back({ 130320, 23 });
                known_pgns.push_back({ 130321, 25 });
                known_pgns.push_back({ 130322, 29 });
                known_pgns.push_back({ 130323, 30 });
                known_pgns.push_back({ 130324, 42 });
                known_pgns.push_back({ 130576, 2 });
                known_pgns.push_back({ 130577, 14 });
                known_pgns.push_back({ 130578, 12 });
                known_pgns.push_back({ 130816, 42 });
                known_pgns.push_back({ 130817, 113 });
                known_pgns.push_back({ 130818, 261 });
                known_pgns.push_back({ 130819, 2 });
                known_pgns.push_back({ 130820, 7 });
                known_pgns.push_back({ 130827, 10 });
                known_pgns.push_back({ 130828, 2 });
                known_pgns.push_back({ 130831, 2 });
                known_pgns.push_back({ 130832, 2 });
                known_pgns.push_back({ 130834, 2 });
                known_pgns.push_back({ 130835, 2 });
                known_pgns.push_back({ 130836, 14 });
                known_pgns.push_back({ 130837, 2 });
                known_pgns.push_back({ 130838, 2 });
                known_pgns.push_back({ 130839, 2 });
                known_pgns.push_back({ 130840, 2 });
                known_pgns.push_back({ 130842, 37 });
                known_pgns.push_back({ 130842, 29 });
                known_pgns.push_back({ 130843, 2 });
                known_pgns.push_back({ 130845, 13 });
                known_pgns.push_back({ 130850, 12 });
                known_pgns.push_back({ 130850, 12 });
                known_pgns.push_back({ 130850, 12 });
                known_pgns.push_back({ 130851, 12 });
                known_pgns.push_back({ 130856, 261 });
                known_pgns.push_back({ 130880, 9 });
                known_pgns.push_back({ 130881, 9 });
                known_pgns.push_back({ 130944, 7 });
                library = PGNLibrary(known_pgns);
    }

    return library;
}
