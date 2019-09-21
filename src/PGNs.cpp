#include <nmea2000/PGNs.hpp>
#include <nmea2000/Decode.hpp>

using namespace nmea2000::decode;
using namespace nmea2000::pgns;

ISOAcknowledgement ISOAcknowledgement::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    ISOAcknowledgement result;

    result.control = decode8(
        &message.payload[0]
    ) >> 0;
    result.group_function = decode8(
        &message.payload[1]
    ) >> 0;
    result.reserved = decode32(
        &message.payload[2]
    ) >> 0;
    result.pgn = decode32(
        &message.payload[5]
    ) >> 0;
    return result;
}
ISORequest ISORequest::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    ISORequest result;

    result.pgn = decode32(
        &message.payload[0]
    ) >> 0;
    return result;
}
ISOAddressClaim ISOAddressClaim::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    ISOAddressClaim result;

    result.device_function = decode8(
        &message.payload[5]
    ) >> 0;
    result.device_class = decode8(
        &message.payload[6]
    ) >> 1;
    result.industry_group = decode8(
        &message.payload[7]
    ) >> 4;
    result.iso_self_configurable = decode8(
        &message.payload[7]
    ) >> 7;
    return result;
}
ISOCommandedAddress ISOCommandedAddress::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    ISOCommandedAddress result;

    result.manufacturer_code = decode16(
        &message.payload[2]
    ) >> 5;
    result.device_function = decode8(
        &message.payload[5]
    ) >> 0;
    result.reserved = decode8(
        &message.payload[6]
    ) >> 0;
    result.device_class = decode8(
        &message.payload[6]
    ) >> 1;
    result.industry_code = decode8(
        &message.payload[7]
    ) >> 4;
    result.iso_self_configurable = decode8(
        &message.payload[7]
    ) >> 7;
    result.new_source_address = decode8(
        &message.payload[8]
    ) >> 0;
    return result;
}
LowranceTemperature LowranceTemperature::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    LowranceTemperature result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    result.temperature_source = decode8(
        &message.payload[2]
    ) >> 4;
    result.actual_temperature = decode16(
        &message.payload[3]
    ) >> 0;
    return result;
}
AirmarBootStateRequest AirmarBootStateRequest::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AirmarBootStateRequest result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    return result;
}
AirmarAccessLevel AirmarAccessLevel::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AirmarAccessLevel result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    result.format_code = decode8(
        &message.payload[2]
    ) >> 0;
    result.access_level = decode8(
        &message.payload[2]
    ) >> 3;
    result.reserved1 = decode8(
        &message.payload[2]
    ) >> 6;
    auto access_seed_key_raw = decode32(
        &message.payload[3]
    );
    result.access_seed_key = reinterpret_cast<int32_t const&>(
        access_seed_key_raw
    );
    return result;
}
SimnetTrimTabSensorCalibration SimnetTrimTabSensorCalibration::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetTrimTabSensorCalibration result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    return result;
}
SimnetPaddleWheelSpeedConfiguration SimnetPaddleWheelSpeedConfiguration::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetPaddleWheelSpeedConfiguration result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    return result;
}
SimnetClearFluidLevelWarnings SimnetClearFluidLevelWarnings::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetClearFluidLevelWarnings result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    return result;
}
SimnetLGC2000Configuration SimnetLGC2000Configuration::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetLGC2000Configuration result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    return result;
}
SimnetReprogramStatus SimnetReprogramStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetReprogramStatus result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    return result;
}
SimnetAutopilotMode SimnetAutopilotMode::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetAutopilotMode result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    return result;
}
AirmarDepthQualityFactor AirmarDepthQualityFactor::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AirmarDepthQualityFactor result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    result.sid = decode8(
        &message.payload[2]
    ) >> 0;
    result.depth_quality_factor = decode8(
        &message.payload[3]
    ) >> 0;
    return result;
}
AirmarDeviceInformation AirmarDeviceInformation::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AirmarDeviceInformation result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    result.sid = decode8(
        &message.payload[2]
    ) >> 0;
    result.internal_device_temperature = decode16(
        &message.payload[3]
    ) >> 0;
    auto supply_voltage_raw = decode16(
        &message.payload[5]
    );
    result.supply_voltage = reinterpret_cast<float const&>(
        supply_voltage_raw
    );
    result.reserved1 = decode8(
        &message.payload[7]
    ) >> 0;
    return result;
}
SimnetAutopilotMode1 SimnetAutopilotMode1::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetAutopilotMode1 result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    return result;
}
NMEAAcknowledgeGroupFunction NMEAAcknowledgeGroupFunction::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    NMEAAcknowledgeGroupFunction result;

    auto function_code_raw = decode8(
        &message.payload[0]
    );
    result.function_code = reinterpret_cast<int8_t const&>(
        function_code_raw
    );
    result.pgn = decode32(
        &message.payload[1]
    ) >> 0;
    result.pgn_error_code = decode8(
        &message.payload[4]
    ) >> 0;
    result.transmission_interval_priority_error_code = decode8(
        &message.payload[4]
    ) >> 4;
    result.number_of_commanded_parameters = decode8(
        &message.payload[5]
    ) >> 0;
    auto parameter_error_raw = decode8(
        &message.payload[6]
    );
    result.parameter_error = reinterpret_cast<int8_t const&>(
        parameter_error_raw
    );
    return result;
}
MaretronSlaveResponse MaretronSlaveResponse::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    MaretronSlaveResponse result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    result.product_code = decode16(
        &message.payload[2]
    ) >> 0;
    result.software_code = decode16(
        &message.payload[4]
    ) >> 0;
    result.command = decode8(
        &message.payload[6]
    ) >> 0;
    result.status = decode8(
        &message.payload[7]
    ) >> 0;
    return result;
}
PGNListTransmitAndReceive PGNListTransmitAndReceive::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    PGNListTransmitAndReceive result;

    result.function_code = decode8(
        &message.payload[0]
    ) >> 0;
    result.pgn = decode32(
        &message.payload[1]
    ) >> 0;
    return result;
}
AirmarAddressableMultiFrame AirmarAddressableMultiFrame::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AirmarAddressableMultiFrame result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    auto proprietary_id_raw = decode8(
        &message.payload[2]
    );
    result.proprietary_id = reinterpret_cast<int8_t const&>(
        proprietary_id_raw
    );
    return result;
}
SystemTime SystemTime::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SystemTime result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.source = decode8(
        &message.payload[1]
    ) >> 0;
    result.date = decode16(
        &message.payload[2]
    ) >> 0;
    result.time = decode32(
        &message.payload[4]
    ) >> 0;
    return result;
}
Heartbeat Heartbeat::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    Heartbeat result;

    result.interval = decode16(
        &message.payload[0]
    ) >> 0;
    result.status = decode8(
        &message.payload[2]
    ) >> 0;
    return result;
}
ProductInformation ProductInformation::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    ProductInformation result;

    result.nmea_2000_version = decode16(
        &message.payload[0]
    ) >> 0;
    result.product_code = decode16(
        &message.payload[2]
    ) >> 0;
    result.certification_level = decode8(
        &message.payload[132]
    ) >> 0;
    result.load_equivalency = decode8(
        &message.payload[133]
    ) >> 0;
    return result;
}
ConfigurationInformation ConfigurationInformation::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    ConfigurationInformation result;

    return result;
}
HeadingTrackControl HeadingTrackControl::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    HeadingTrackControl result;

    result.rudder_limit_exceeded = decode8(
        &message.payload[0]
    ) >> 0;
    result.off_heading_limit_exceeded = decode8(
        &message.payload[0]
    ) >> 2;
    result.off_track_limit_exceeded = decode8(
        &message.payload[0]
    ) >> 4;
    result.override = decode8(
        &message.payload[0]
    ) >> 6;
    result.steering_mode = decode8(
        &message.payload[1]
    ) >> 0;
    result.turn_mode = decode8(
        &message.payload[1]
    ) >> 4;
    result.heading_reference = decode8(
        &message.payload[2]
    ) >> 0;
    result.reserved = decode8(
        &message.payload[2]
    ) >> 3;
    result.commanded_rudder_direction = decode8(
        &message.payload[2]
    ) >> 6;
    auto commanded_rudder_angle_raw = decode16(
        &message.payload[3]
    );
    result.commanded_rudder_angle = reinterpret_cast<float const&>(
        commanded_rudder_angle_raw
    );
    result.heading_to_steer_course_ = decode16(
        &message.payload[5]
    ) >> 0;
    result.track = decode16(
        &message.payload[7]
    ) >> 0;
    result.rudder_limit = decode16(
        &message.payload[9]
    ) >> 0;
    result.off_heading_limit = decode16(
        &message.payload[11]
    ) >> 0;
    auto radius_of_turn_order_raw = decode16(
        &message.payload[13]
    );
    result.radius_of_turn_order = reinterpret_cast<float const&>(
        radius_of_turn_order_raw
    );
    auto rate_of_turn_order_raw = decode16(
        &message.payload[15]
    );
    result.rate_of_turn_order = reinterpret_cast<float const&>(
        rate_of_turn_order_raw
    );
    result.off_track_limit = decode16(
        &message.payload[17]
    ) >> 0;
    result.vessel_heading = decode16(
        &message.payload[19]
    ) >> 0;
    return result;
}
Rudder Rudder::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    Rudder result;

    result.direction_order = decode8(
        &message.payload[1]
    ) >> 0;
    auto angle_order_raw = decode16(
        &message.payload[2]
    );
    result.angle_order = reinterpret_cast<float const&>(
        angle_order_raw
    );
    auto position_raw = decode16(
        &message.payload[4]
    );
    result.position = reinterpret_cast<float const&>(
        position_raw
    );
    result.reserved = decode16(
        &message.payload[6]
    ) >> 0;
    return result;
}
VesselHeading VesselHeading::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    VesselHeading result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.heading = decode16(
        &message.payload[1]
    ) >> 0;
    auto deviation_raw = decode16(
        &message.payload[3]
    );
    result.deviation = reinterpret_cast<float const&>(
        deviation_raw
    );
    auto variation_raw = decode16(
        &message.payload[5]
    );
    result.variation = reinterpret_cast<float const&>(
        variation_raw
    );
    result.reference = decode8(
        &message.payload[7]
    ) >> 0;
    result.reserved = decode8(
        &message.payload[7]
    ) >> 2;
    return result;
}
RateOfTurn RateOfTurn::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RateOfTurn result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    auto rate_raw = decode32(
        &message.payload[1]
    );
    result.rate = reinterpret_cast<float const&>(
        rate_raw
    );
    return result;
}
Attitude Attitude::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    Attitude result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    auto yaw_raw = decode16(
        &message.payload[1]
    );
    result.yaw = reinterpret_cast<float const&>(
        yaw_raw
    );
    auto pitch_raw = decode16(
        &message.payload[3]
    );
    result.pitch = reinterpret_cast<float const&>(
        pitch_raw
    );
    auto roll_raw = decode16(
        &message.payload[5]
    );
    result.roll = reinterpret_cast<float const&>(
        roll_raw
    );
    return result;
}
MagneticVariation MagneticVariation::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    MagneticVariation result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.source = decode8(
        &message.payload[1]
    ) >> 0;
    result.age_of_service = decode16(
        &message.payload[2]
    ) >> 0;
    auto variation_raw = decode16(
        &message.payload[4]
    );
    result.variation = reinterpret_cast<float const&>(
        variation_raw
    );
    return result;
}
EngineParametersRapidUpdate EngineParametersRapidUpdate::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    EngineParametersRapidUpdate result;

    result.engine_speed = decode16(
        &message.payload[1]
    ) >> 0;
    result.engine_boost_pressure = decode16(
        &message.payload[3]
    ) >> 0;
    auto engine_tilt_trim_raw = decode8(
        &message.payload[5]
    );
    result.engine_tilt_trim = reinterpret_cast<int8_t const&>(
        engine_tilt_trim_raw
    );
    result.reserved = decode16(
        &message.payload[6]
    ) >> 0;
    return result;
}
EngineParametersDynamic EngineParametersDynamic::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    EngineParametersDynamic result;

    result.oil_pressure = decode16(
        &message.payload[1]
    ) >> 0;
    result.oil_temperature = decode16(
        &message.payload[3]
    ) >> 0;
    result.temperature = decode16(
        &message.payload[5]
    ) >> 0;
    auto alternator_potential_raw = decode16(
        &message.payload[7]
    );
    result.alternator_potential = reinterpret_cast<float const&>(
        alternator_potential_raw
    );
    auto fuel_rate_raw = decode16(
        &message.payload[9]
    );
    result.fuel_rate = reinterpret_cast<float const&>(
        fuel_rate_raw
    );
    result.total_engine_hours = decode32(
        &message.payload[11]
    ) >> 0;
    result.coolant_pressure = decode16(
        &message.payload[15]
    ) >> 0;
    result.fuel_pressure = decode16(
        &message.payload[17]
    ) >> 0;
    result.reserved = decode8(
        &message.payload[19]
    ) >> 0;
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
TransmissionParametersDynamic TransmissionParametersDynamic::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    TransmissionParametersDynamic result;

    result.transmission_gear = decode8(
        &message.payload[1]
    ) >> 0;
    result.reserved = decode8(
        &message.payload[1]
    ) >> 2;
    result.oil_pressure = decode16(
        &message.payload[2]
    ) >> 0;
    result.oil_temperature = decode16(
        &message.payload[4]
    ) >> 0;
    auto discrete_status_1_raw = decode8(
        &message.payload[6]
    );
    result.discrete_status_1 = reinterpret_cast<int8_t const&>(
        discrete_status_1_raw
    );
    return result;
}
TripParametersVessel TripParametersVessel::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    TripParametersVessel result;

    auto time_to_empty_raw = decode32(
        &message.payload[0]
    );
    result.time_to_empty = reinterpret_cast<float const&>(
        time_to_empty_raw
    );
    auto distance_to_empty_raw = decode32(
        &message.payload[4]
    );
    result.distance_to_empty = reinterpret_cast<float const&>(
        distance_to_empty_raw
    );
    result.estimated_fuel_remaining = decode16(
        &message.payload[8]
    ) >> 0;
    auto trip_run_time_raw = decode32(
        &message.payload[10]
    );
    result.trip_run_time = reinterpret_cast<float const&>(
        trip_run_time_raw
    );
    return result;
}
TripParametersEngine TripParametersEngine::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    TripParametersEngine result;

    result.trip_fuel_used = decode16(
        &message.payload[1]
    ) >> 0;
    auto fuel_rate_average_raw = decode16(
        &message.payload[3]
    );
    result.fuel_rate_average = reinterpret_cast<float const&>(
        fuel_rate_average_raw
    );
    auto fuel_rate_economy_raw = decode16(
        &message.payload[5]
    );
    result.fuel_rate_economy = reinterpret_cast<float const&>(
        fuel_rate_economy_raw
    );
    auto instantaneous_fuel_economy_raw = decode16(
        &message.payload[7]
    );
    result.instantaneous_fuel_economy = reinterpret_cast<float const&>(
        instantaneous_fuel_economy_raw
    );
    return result;
}
EngineParametersStatic EngineParametersStatic::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    EngineParametersStatic result;

    result.rated_engine_speed = decode16(
        &message.payload[1]
    ) >> 0;
    result.vin = decode8(
        &message.payload[3]
    ) >> 0;
    result.software_id = decode16(
        &message.payload[4]
    ) >> 0;
    return result;
}
BinarySwitchBankStatus BinarySwitchBankStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    BinarySwitchBankStatus result;

    result.indicator = decode8(
        &message.payload[1]
    ) >> 0;
    return result;
}
SwitchBankControl SwitchBankControl::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SwitchBankControl result;

    result.switch_state = decode8(
        &message.payload[1]
    ) >> 0;
    return result;
}
ACInputStatus ACInputStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    ACInputStatus result;

    result.number_of_lines = decode8(
        &message.payload[1]
    ) >> 0;
    result.line = decode8(
        &message.payload[2]
    ) >> 0;
    result.acceptability = decode8(
        &message.payload[2]
    ) >> 2;
    result.reserved = decode8(
        &message.payload[2]
    ) >> 4;
    auto voltage_raw = decode16(
        &message.payload[3]
    );
    result.voltage = reinterpret_cast<float const&>(
        voltage_raw
    );
    auto current_raw = decode16(
        &message.payload[5]
    );
    result.current = reinterpret_cast<float const&>(
        current_raw
    );
    auto frequency_raw = decode16(
        &message.payload[7]
    );
    result.frequency = reinterpret_cast<float const&>(
        frequency_raw
    );
    auto breaker_size_raw = decode16(
        &message.payload[9]
    );
    result.breaker_size = reinterpret_cast<float const&>(
        breaker_size_raw
    );
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
    result.power_factor = reinterpret_cast<float const&>(
        power_factor_raw
    );
    return result;
}
ACOutputStatus ACOutputStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    ACOutputStatus result;

    result.number_of_lines = decode8(
        &message.payload[1]
    ) >> 0;
    result.line = decode8(
        &message.payload[2]
    ) >> 0;
    result.waveform = decode8(
        &message.payload[2]
    ) >> 2;
    result.reserved = decode8(
        &message.payload[2]
    ) >> 5;
    auto voltage_raw = decode16(
        &message.payload[3]
    );
    result.voltage = reinterpret_cast<float const&>(
        voltage_raw
    );
    auto current_raw = decode16(
        &message.payload[5]
    );
    result.current = reinterpret_cast<float const&>(
        current_raw
    );
    auto frequency_raw = decode16(
        &message.payload[7]
    );
    result.frequency = reinterpret_cast<float const&>(
        frequency_raw
    );
    auto breaker_size_raw = decode16(
        &message.payload[9]
    );
    result.breaker_size = reinterpret_cast<float const&>(
        breaker_size_raw
    );
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
    result.power_factor = reinterpret_cast<float const&>(
        power_factor_raw
    );
    return result;
}
FluidLevel FluidLevel::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    FluidLevel result;

    result.type = decode8(
        &message.payload[0]
    ) >> 4;
    auto level_raw = decode16(
        &message.payload[1]
    );
    result.level = reinterpret_cast<float const&>(
        level_raw
    );
    auto capacity_raw = decode32(
        &message.payload[3]
    );
    result.capacity = reinterpret_cast<float const&>(
        capacity_raw
    );
    result.reserved = decode8(
        &message.payload[7]
    ) >> 0;
    return result;
}
DCDetailedStatus DCDetailedStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    DCDetailedStatus result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.dc_type = decode8(
        &message.payload[2]
    ) >> 0;
    result.state_of_charge = decode8(
        &message.payload[3]
    ) >> 0;
    result.state_of_health = decode8(
        &message.payload[4]
    ) >> 0;
    result.time_remaining = decode16(
        &message.payload[5]
    ) >> 0;
    auto ripple_voltage_raw = decode16(
        &message.payload[7]
    );
    result.ripple_voltage = reinterpret_cast<float const&>(
        ripple_voltage_raw
    );
    return result;
}
ChargerStatus ChargerStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    ChargerStatus result;

    result.operating_state = decode8(
        &message.payload[2]
    ) >> 0;
    result.charge_mode = decode8(
        &message.payload[3]
    ) >> 0;
    result.charger_enable_disable = decode8(
        &message.payload[4]
    ) >> 0;
    result.equalization_pending = decode8(
        &message.payload[4]
    ) >> 2;
    result.reserved = decode8(
        &message.payload[4]
    ) >> 4;
    result.equalization_time_remaining = decode16(
        &message.payload[5]
    ) >> 0;
    return result;
}
BatteryStatus BatteryStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    BatteryStatus result;

    auto voltage_raw = decode16(
        &message.payload[1]
    );
    result.voltage = reinterpret_cast<float const&>(
        voltage_raw
    );
    auto current_raw = decode16(
        &message.payload[3]
    );
    result.current = reinterpret_cast<float const&>(
        current_raw
    );
    result.temperature = decode16(
        &message.payload[5]
    ) >> 0;
    result.sid = decode8(
        &message.payload[7]
    ) >> 0;
    return result;
}
InverterStatus InverterStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    InverterStatus result;

    result.operating_state = decode8(
        &message.payload[3]
    ) >> 0;
    result.inverter = decode8(
        &message.payload[3]
    ) >> 4;
    return result;
}
ChargerConfigurationStatus ChargerConfigurationStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    ChargerConfigurationStatus result;

    result.charger_enable_disable = decode8(
        &message.payload[2]
    ) >> 0;
    result.reserved = decode8(
        &message.payload[2]
    ) >> 2;
    auto charge_current_limit_raw = decode16(
        &message.payload[3]
    );
    result.charge_current_limit = reinterpret_cast<float const&>(
        charge_current_limit_raw
    );
    result.charging_algorithm = decode8(
        &message.payload[5]
    ) >> 0;
    result.charger_mode = decode8(
        &message.payload[6]
    ) >> 0;
    result.estimated_temperature = decode16(
        &message.payload[7]
    ) >> 0;
    result.equalize_one_time_enable_disable = decode8(
        &message.payload[9]
    ) >> 0;
    result.over_charge_enable_disable = decode8(
        &message.payload[9]
    ) >> 4;
    result.equalize_time = decode16(
        &message.payload[10]
    ) >> 0;
    return result;
}
InverterConfigurationStatus InverterConfigurationStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    InverterConfigurationStatus result;

    result.inverter_enable_disable = decode8(
        &message.payload[3]
    ) >> 0;
    result.inverter_mode = decode8(
        &message.payload[3]
    ) >> 2;
    result.load_sense_enable_disable = decode8(
        &message.payload[4]
    ) >> 2;
    result.load_sense_power_threshold = decode8(
        &message.payload[5]
    ) >> 2;
    result.load_sense_interval = decode8(
        &message.payload[6]
    ) >> 2;
    return result;
}
AGSConfigurationStatus AGSConfigurationStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AGSConfigurationStatus result;

    result.ags_mode = decode8(
        &message.payload[2]
    ) >> 0;
    return result;
}
BatteryConfigurationStatus BatteryConfigurationStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    BatteryConfigurationStatus result;

    result.battery_type = decode8(
        &message.payload[1]
    ) >> 0;
    result.supports_equalization = decode8(
        &message.payload[1]
    ) >> 4;
    result.reserved = decode8(
        &message.payload[1]
    ) >> 6;
    result.nominal_voltage = decode8(
        &message.payload[2]
    ) >> 0;
    result.chemistry = decode8(
        &message.payload[2]
    ) >> 4;
    result.capacity = decode16(
        &message.payload[3]
    ) >> 0;
    result.temperature_coefficient = decode8(
        &message.payload[5]
    ) >> 0;
    result.peukert_exponent = decode8(
        &message.payload[6]
    ) >> 0;
    result.charge_efficiency_factor = decode8(
        &message.payload[7]
    ) >> 0;
    return result;
}
AGSStatus AGSStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AGSStatus result;

    result.ags_operating_state = decode8(
        &message.payload[2]
    ) >> 0;
    result.generator_state = decode8(
        &message.payload[3]
    ) >> 0;
    result.generator_on_reason = decode8(
        &message.payload[4]
    ) >> 0;
    result.generator_off_reason = decode8(
        &message.payload[5]
    ) >> 0;
    return result;
}
Speed Speed::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    Speed result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    auto speed_water_referenced_raw = decode16(
        &message.payload[1]
    );
    result.speed_water_referenced = reinterpret_cast<float const&>(
        speed_water_referenced_raw
    );
    auto speed_ground_referenced_raw = decode16(
        &message.payload[3]
    );
    result.speed_ground_referenced = reinterpret_cast<float const&>(
        speed_ground_referenced_raw
    );
    result.speed_water_referenced_type = decode8(
        &message.payload[5]
    ) >> 0;
    result.reserved = decode16(
        &message.payload[6]
    ) >> 0;
    return result;
}
WaterDepth WaterDepth::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    WaterDepth result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.depth = decode32(
        &message.payload[1]
    ) >> 0;
    auto offset_raw = decode16(
        &message.payload[5]
    );
    result.offset = reinterpret_cast<float const&>(
        offset_raw
    );
    auto offset1_raw = decode8(
        &message.payload[7]
    );
    result.offset1 = reinterpret_cast<float const&>(
        offset1_raw
    );
    return result;
}
DistanceLog DistanceLog::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    DistanceLog result;

    result.date = decode16(
        &message.payload[0]
    ) >> 0;
    result.time = decode32(
        &message.payload[2]
    ) >> 0;
    result.log = decode32(
        &message.payload[6]
    ) >> 0;
    result.trip_log = decode32(
        &message.payload[10]
    ) >> 0;
    return result;
}
TrackedTargetData TrackedTargetData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    TrackedTargetData result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.target_id_number = decode8(
        &message.payload[1]
    ) >> 0;
    result.track_status = decode8(
        &message.payload[2]
    ) >> 0;
    result.reported_target = decode8(
        &message.payload[2]
    ) >> 2;
    result.target_acquisition = decode8(
        &message.payload[2]
    ) >> 3;
    result.bearing_reference = decode8(
        &message.payload[2]
    ) >> 4;
    result.reserved = decode8(
        &message.payload[2]
    ) >> 6;
    result.bearing = decode16(
        &message.payload[3]
    ) >> 0;
    auto distance_raw = decode32(
        &message.payload[5]
    );
    result.distance = reinterpret_cast<float const&>(
        distance_raw
    );
    result.course = decode16(
        &message.payload[9]
    ) >> 0;
    result.speed = decode16(
        &message.payload[11]
    ) >> 0;
    auto cpa_raw = decode32(
        &message.payload[13]
    );
    result.cpa = reinterpret_cast<float const&>(
        cpa_raw
    );
    auto tcpa_raw = decode32(
        &message.payload[17]
    );
    result.tcpa = reinterpret_cast<float const&>(
        tcpa_raw
    );
    result.utc_of_fix = decode32(
        &message.payload[21]
    ) >> 0;
    return result;
}
PositionRapidUpdate PositionRapidUpdate::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    PositionRapidUpdate result;

    auto latitude_raw = decode32(
        &message.payload[0]
    );
    result.latitude = reinterpret_cast<float const&>(
        latitude_raw
    );
    auto longitude_raw = decode32(
        &message.payload[4]
    );
    result.longitude = reinterpret_cast<float const&>(
        longitude_raw
    );
    return result;
}
COGSOGRapidUpdate COGSOGRapidUpdate::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    COGSOGRapidUpdate result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.cog_reference = decode8(
        &message.payload[1]
    ) >> 0;
    result.cog = decode16(
        &message.payload[2]
    ) >> 0;
    result.sog = decode16(
        &message.payload[4]
    ) >> 0;
    return result;
}
PositionDeltaRapidUpdate PositionDeltaRapidUpdate::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    PositionDeltaRapidUpdate result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.time_delta = decode16(
        &message.payload[1]
    ) >> 0;
    result.latitude_delta = decode16(
        &message.payload[3]
    ) >> 0;
    result.longitude_delta = decode16(
        &message.payload[5]
    ) >> 0;
    return result;
}
AltitudeDeltaRapidUpdate AltitudeDeltaRapidUpdate::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AltitudeDeltaRapidUpdate result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.time_delta = decode16(
        &message.payload[1]
    ) >> 0;
    result.gnss_quality = decode8(
        &message.payload[3]
    ) >> 0;
    result.direction = decode8(
        &message.payload[3]
    ) >> 2;
    result.course_over_ground = decode32(
        &message.payload[4]
    ) >> 0;
    result.altitude_delta = decode16(
        &message.payload[8]
    ) >> 0;
    return result;
}
GNSSPositionData GNSSPositionData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    GNSSPositionData result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.date = decode16(
        &message.payload[1]
    ) >> 0;
    result.time = decode32(
        &message.payload[3]
    ) >> 0;
    auto latitude_raw = decode64(
        &message.payload[7]
    );
    result.latitude = reinterpret_cast<float const&>(
        latitude_raw
    );
    auto longitude_raw = decode64(
        &message.payload[15]
    );
    result.longitude = reinterpret_cast<float const&>(
        longitude_raw
    );
    auto altitude_raw = decode64(
        &message.payload[23]
    );
    result.altitude = reinterpret_cast<float const&>(
        altitude_raw
    );
    result.gnss_type = decode8(
        &message.payload[31]
    ) >> 0;
    result.method = decode8(
        &message.payload[31]
    ) >> 4;
    result.integrity = decode8(
        &message.payload[32]
    ) >> 0;
    result.number_of_svs = decode8(
        &message.payload[33]
    ) >> 0;
    auto hdop_raw = decode16(
        &message.payload[34]
    );
    result.hdop = reinterpret_cast<float const&>(
        hdop_raw
    );
    auto pdop_raw = decode16(
        &message.payload[36]
    );
    result.pdop = reinterpret_cast<float const&>(
        pdop_raw
    );
    auto geoidal_separation_raw = decode16(
        &message.payload[38]
    );
    result.geoidal_separation = reinterpret_cast<float const&>(
        geoidal_separation_raw
    );
    result.reference_stations = decode8(
        &message.payload[40]
    ) >> 0;
    result.reference_station_type = decode8(
        &message.payload[41]
    ) >> 0;
    result.reference_station_id = decode16(
        &message.payload[41]
    ) >> 4;
    auto age_of_dgnss_corrections_raw = decode16(
        &message.payload[43]
    );
    result.age_of_dgnss_corrections = reinterpret_cast<float const&>(
        age_of_dgnss_corrections_raw
    );
    return result;
}
TimeDate TimeDate::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    TimeDate result;

    result.date = decode16(
        &message.payload[0]
    ) >> 0;
    result.time = decode32(
        &message.payload[2]
    ) >> 0;
    auto local_offset_raw = decode16(
        &message.payload[6]
    );
    result.local_offset = reinterpret_cast<int16_t const&>(
        local_offset_raw
    );
    return result;
}
AISClassAPositionReport AISClassAPositionReport::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISClassAPositionReport result;

    result.message_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.repeat_indicator = decode8(
        &message.payload[0]
    ) >> 6;
    auto user_id_raw = decode32(
        &message.payload[1]
    );
    result.user_id = reinterpret_cast<int32_t const&>(
        user_id_raw
    );
    auto longitude_raw = decode32(
        &message.payload[5]
    );
    result.longitude = reinterpret_cast<float const&>(
        longitude_raw
    );
    auto latitude_raw = decode32(
        &message.payload[9]
    );
    result.latitude = reinterpret_cast<float const&>(
        latitude_raw
    );
    result.position_accuracy = decode8(
        &message.payload[13]
    ) >> 0;
    result.raim = decode8(
        &message.payload[13]
    ) >> 1;
    result.time_stamp = decode8(
        &message.payload[13]
    ) >> 2;
    result.cog = decode16(
        &message.payload[14]
    ) >> 0;
    result.sog = decode16(
        &message.payload[16]
    ) >> 0;
    result.ais_transceiver_information = decode8(
        &message.payload[20]
    ) >> 3;
    result.heading = decode16(
        &message.payload[21]
    ) >> 0;
    result.rate_of_turn = decode16(
        &message.payload[23]
    ) >> 0;
    result.nav_status = decode8(
        &message.payload[25]
    ) >> 0;
    result.reserved_for_regional_applications = decode8(
        &message.payload[26]
    ) >> 0;
    result.spare = decode8(
        &message.payload[27]
    ) >> 0;
    return result;
}
AISClassBPositionReport AISClassBPositionReport::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISClassBPositionReport result;

    result.message_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.repeat_indicator = decode8(
        &message.payload[0]
    ) >> 6;
    auto user_id_raw = decode32(
        &message.payload[1]
    );
    result.user_id = reinterpret_cast<int32_t const&>(
        user_id_raw
    );
    auto longitude_raw = decode32(
        &message.payload[5]
    );
    result.longitude = reinterpret_cast<float const&>(
        longitude_raw
    );
    auto latitude_raw = decode32(
        &message.payload[9]
    );
    result.latitude = reinterpret_cast<float const&>(
        latitude_raw
    );
    result.position_accuracy = decode8(
        &message.payload[13]
    ) >> 0;
    result.raim = decode8(
        &message.payload[13]
    ) >> 1;
    result.time_stamp = decode8(
        &message.payload[13]
    ) >> 2;
    result.cog = decode16(
        &message.payload[14]
    ) >> 0;
    result.sog = decode16(
        &message.payload[16]
    ) >> 0;
    result.ais_transceiver_information = decode8(
        &message.payload[20]
    ) >> 3;
    result.heading = decode16(
        &message.payload[21]
    ) >> 0;
    result.regional_application = decode8(
        &message.payload[23]
    ) >> 0;
    result.regional_application1 = decode8(
        &message.payload[24]
    ) >> 0;
    result.unit_type = decode8(
        &message.payload[24]
    ) >> 2;
    result.integrated_display = decode8(
        &message.payload[24]
    ) >> 3;
    result.dsc = decode8(
        &message.payload[24]
    ) >> 4;
    result.band = decode8(
        &message.payload[24]
    ) >> 5;
    result.can_handle_msg_22 = decode8(
        &message.payload[24]
    ) >> 6;
    result.ais_mode = decode8(
        &message.payload[24]
    ) >> 7;
    result.ais_communication_state = decode8(
        &message.payload[25]
    ) >> 0;
    return result;
}
AISClassBExtendedPositionReport AISClassBExtendedPositionReport::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISClassBExtendedPositionReport result;

    result.message_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.repeat_indicator = decode8(
        &message.payload[0]
    ) >> 6;
    auto user_id_raw = decode32(
        &message.payload[1]
    );
    result.user_id = reinterpret_cast<int32_t const&>(
        user_id_raw
    );
    auto longitude_raw = decode32(
        &message.payload[5]
    );
    result.longitude = reinterpret_cast<float const&>(
        longitude_raw
    );
    auto latitude_raw = decode32(
        &message.payload[9]
    );
    result.latitude = reinterpret_cast<float const&>(
        latitude_raw
    );
    result.position_accuracy = decode8(
        &message.payload[13]
    ) >> 0;
    result.ais_raim_flag = decode8(
        &message.payload[13]
    ) >> 1;
    result.time_stamp = decode8(
        &message.payload[13]
    ) >> 2;
    result.cog = decode16(
        &message.payload[14]
    ) >> 0;
    result.sog = decode16(
        &message.payload[16]
    ) >> 0;
    result.regional_application = decode8(
        &message.payload[18]
    ) >> 0;
    result.regional_application1 = decode8(
        &message.payload[19]
    ) >> 0;
    result.type_of_ship = decode8(
        &message.payload[20]
    ) >> 0;
    result.true_heading = decode16(
        &message.payload[21]
    ) >> 0;
    result.gnss_type = decode8(
        &message.payload[23]
    ) >> 4;
    auto length_raw = decode16(
        &message.payload[24]
    );
    result.length = reinterpret_cast<float const&>(
        length_raw
    );
    auto beam_raw = decode16(
        &message.payload[26]
    );
    result.beam = reinterpret_cast<float const&>(
        beam_raw
    );
    auto position_reference_from_starboard_raw = decode16(
        &message.payload[28]
    );
    result.position_reference_from_starboard = reinterpret_cast<float const&>(
        position_reference_from_starboard_raw
    );
    auto position_reference_from_bow_raw = decode16(
        &message.payload[30]
    );
    result.position_reference_from_bow = reinterpret_cast<float const&>(
        position_reference_from_bow_raw
    );
    result.dte = decode8(
        &message.payload[52]
    ) >> 0;
    result.ais_mode = decode8(
        &message.payload[52]
    ) >> 1;
    result.ais_transceiver_information = decode8(
        &message.payload[52]
    ) >> 6;
    return result;
}
Datum Datum::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    Datum result;

    auto delta_latitude_raw = decode32(
        &message.payload[4]
    );
    result.delta_latitude = reinterpret_cast<float const&>(
        delta_latitude_raw
    );
    auto delta_longitude_raw = decode32(
        &message.payload[8]
    );
    result.delta_longitude = reinterpret_cast<float const&>(
        delta_longitude_raw
    );
    auto delta_altitude_raw = decode32(
        &message.payload[12]
    );
    result.delta_altitude = reinterpret_cast<float const&>(
        delta_altitude_raw
    );
    return result;
}
UserDatum UserDatum::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    UserDatum result;

    auto delta_x_raw = decode32(
        &message.payload[0]
    );
    result.delta_x = reinterpret_cast<float const&>(
        delta_x_raw
    );
    auto delta_y_raw = decode32(
        &message.payload[4]
    );
    result.delta_y = reinterpret_cast<float const&>(
        delta_y_raw
    );
    auto delta_z_raw = decode32(
        &message.payload[8]
    );
    result.delta_z = reinterpret_cast<float const&>(
        delta_z_raw
    );
    auto rotation_in_x_raw = decode32(
        &message.payload[12]
    );
    result.rotation_in_x = reinterpret_cast<float const&>(
        rotation_in_x_raw
    );
    auto rotation_in_y_raw = decode32(
        &message.payload[16]
    );
    result.rotation_in_y = reinterpret_cast<float const&>(
        rotation_in_y_raw
    );
    auto rotation_in_z_raw = decode32(
        &message.payload[20]
    );
    result.rotation_in_z = reinterpret_cast<float const&>(
        rotation_in_z_raw
    );
    auto scale_raw = decode32(
        &message.payload[24]
    );
    result.scale = reinterpret_cast<float const&>(
        scale_raw
    );
    auto ellipsoid_semi_major_axis_raw = decode32(
        &message.payload[28]
    );
    result.ellipsoid_semi_major_axis = reinterpret_cast<float const&>(
        ellipsoid_semi_major_axis_raw
    );
    auto ellipsoid_flattening_inverse_raw = decode32(
        &message.payload[32]
    );
    result.ellipsoid_flattening_inverse = reinterpret_cast<float const&>(
        ellipsoid_flattening_inverse_raw
    );
    return result;
}
CrossTrackError CrossTrackError::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    CrossTrackError result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.xte_mode = decode8(
        &message.payload[1]
    ) >> 0;
    result.navigation_terminated = decode8(
        &message.payload[1]
    ) >> 6;
    auto xte_raw = decode32(
        &message.payload[2]
    );
    result.xte = reinterpret_cast<float const&>(
        xte_raw
    );
    return result;
}
NavigationData NavigationData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    NavigationData result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    auto distance_to_waypoint_raw = decode32(
        &message.payload[1]
    );
    result.distance_to_waypoint = reinterpret_cast<float const&>(
        distance_to_waypoint_raw
    );
    result.course_bearing_reference = decode8(
        &message.payload[5]
    ) >> 0;
    result.perpendicular_crossed = decode8(
        &message.payload[5]
    ) >> 2;
    result.arrival_circle_entered = decode8(
        &message.payload[5]
    ) >> 4;
    result.calculation_type = decode8(
        &message.payload[5]
    ) >> 6;
    result.eta_time = decode32(
        &message.payload[6]
    ) >> 0;
    result.eta_date = decode16(
        &message.payload[10]
    ) >> 0;
    result.bearing_origin_to_destination_waypoint = decode16(
        &message.payload[12]
    ) >> 0;
    result.bearing_position_to_destination_waypoint = decode16(
        &message.payload[14]
    ) >> 0;
    result.origin_waypoint_number = decode32(
        &message.payload[16]
    ) >> 0;
    result.destination_waypoint_number = decode32(
        &message.payload[20]
    ) >> 0;
    auto destination_latitude_raw = decode32(
        &message.payload[24]
    );
    result.destination_latitude = reinterpret_cast<float const&>(
        destination_latitude_raw
    );
    auto destination_longitude_raw = decode32(
        &message.payload[28]
    );
    result.destination_longitude = reinterpret_cast<float const&>(
        destination_longitude_raw
    );
    auto waypoint_closing_velocity_raw = decode16(
        &message.payload[32]
    );
    result.waypoint_closing_velocity = reinterpret_cast<float const&>(
        waypoint_closing_velocity_raw
    );
    return result;
}
NavigationRouteWPInformation NavigationRouteWPInformation::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    NavigationRouteWPInformation result;

    result.start_rpsnumber = decode16(
        &message.payload[0]
    ) >> 0;
    result.nitems = decode16(
        &message.payload[2]
    ) >> 0;
    result.database_id = decode16(
        &message.payload[4]
    ) >> 0;
    result.route_id = decode16(
        &message.payload[6]
    ) >> 0;
    result.navigation_direction_in_route = decode8(
        &message.payload[8]
    ) >> 0;
    result.supplementary_route_wp_data_available = decode8(
        &message.payload[8]
    ) >> 2;
    result.wp_id = decode16(
        &message.payload[265]
    ) >> 0;
    auto wp_latitude_raw = decode32(
        &message.payload[522]
    );
    result.wp_latitude = reinterpret_cast<float const&>(
        wp_latitude_raw
    );
    auto wp_longitude_raw = decode32(
        &message.payload[526]
    );
    result.wp_longitude = reinterpret_cast<float const&>(
        wp_longitude_raw
    );
    return result;
}
SetDriftRapidUpdate SetDriftRapidUpdate::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SetDriftRapidUpdate result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.set_reference = decode8(
        &message.payload[1]
    ) >> 0;
    result.set = decode16(
        &message.payload[2]
    ) >> 0;
    auto drift_raw = decode16(
        &message.payload[4]
    );
    result.drift = reinterpret_cast<float const&>(
        drift_raw
    );
    return result;
}
NavigationRouteTimeToFromMark NavigationRouteTimeToFromMark::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    NavigationRouteTimeToFromMark result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    auto time_to_mark_raw = decode32(
        &message.payload[1]
    );
    result.time_to_mark = reinterpret_cast<float const&>(
        time_to_mark_raw
    );
    result.mark_type = decode8(
        &message.payload[5]
    ) >> 0;
    result.mark_id = decode32(
        &message.payload[6]
    ) >> 0;
    return result;
}
BearingAndDistanceBetweenTwoMarks BearingAndDistanceBetweenTwoMarks::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    BearingAndDistanceBetweenTwoMarks result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.bearing_reference = decode8(
        &message.payload[1]
    ) >> 0;
    result.calculation_type = decode8(
        &message.payload[1]
    ) >> 4;
    result.bearing_origin_to_destination = decode16(
        &message.payload[2]
    ) >> 0;
    auto distance_raw = decode32(
        &message.payload[4]
    );
    result.distance = reinterpret_cast<float const&>(
        distance_raw
    );
    result.origin_mark_type = decode8(
        &message.payload[8]
    ) >> 0;
    result.destination_mark_type = decode8(
        &message.payload[8]
    ) >> 4;
    result.origin_mark_id = decode32(
        &message.payload[9]
    ) >> 0;
    result.destination_mark_id = decode32(
        &message.payload[13]
    ) >> 0;
    return result;
}
GNSSControlStatus GNSSControlStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    GNSSControlStatus result;

    result.sv_elevation_mask = decode16(
        &message.payload[0]
    ) >> 0;
    auto pdop_mask_raw = decode16(
        &message.payload[2]
    );
    result.pdop_mask = reinterpret_cast<float const&>(
        pdop_mask_raw
    );
    auto pdop_switch_raw = decode16(
        &message.payload[4]
    );
    result.pdop_switch = reinterpret_cast<float const&>(
        pdop_switch_raw
    );
    auto snr_mask_raw = decode16(
        &message.payload[6]
    );
    result.snr_mask = reinterpret_cast<float const&>(
        snr_mask_raw
    );
    result.gnss_mode_desired_ = decode8(
        &message.payload[8]
    ) >> 0;
    result.dgnss_mode_desired_ = decode8(
        &message.payload[8]
    ) >> 3;
    result.position_velocity_filter = decode8(
        &message.payload[8]
    ) >> 6;
    result.max_correction_age = decode16(
        &message.payload[9]
    ) >> 0;
    auto antenna_altitude_for_2d_mode_raw = decode16(
        &message.payload[11]
    );
    result.antenna_altitude_for_2d_mode = reinterpret_cast<float const&>(
        antenna_altitude_for_2d_mode_raw
    );
    result.use_antenna_altitude_for_2d_mode = decode8(
        &message.payload[13]
    ) >> 0;
    return result;
}
GNSSDOPs GNSSDOPs::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    GNSSDOPs result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.desired_mode = decode8(
        &message.payload[1]
    ) >> 0;
    result.actual_mode = decode8(
        &message.payload[1]
    ) >> 3;
    auto hdop_raw = decode16(
        &message.payload[2]
    );
    result.hdop = reinterpret_cast<float const&>(
        hdop_raw
    );
    auto vdop_raw = decode16(
        &message.payload[4]
    );
    result.vdop = reinterpret_cast<float const&>(
        vdop_raw
    );
    auto tdop_raw = decode16(
        &message.payload[6]
    );
    result.tdop = reinterpret_cast<float const&>(
        tdop_raw
    );
    return result;
}
GNSSSatsInView GNSSSatsInView::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    GNSSSatsInView result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.mode = decode8(
        &message.payload[1]
    ) >> 0;
    result.sats_in_view = decode8(
        &message.payload[2]
    ) >> 0;
    result.sat_number = decode8(
        &message.payload[3]
    ) >> 0;
    auto elevation_raw = decode16(
        &message.payload[4]
    );
    result.elevation = reinterpret_cast<float const&>(
        elevation_raw
    );
    auto azimuth_raw = decode16(
        &message.payload[6]
    );
    result.azimuth = reinterpret_cast<float const&>(
        azimuth_raw
    );
    auto snr_raw = decode16(
        &message.payload[8]
    );
    result.snr = reinterpret_cast<float const&>(
        snr_raw
    );
    result.range_residuals = decode32(
        &message.payload[10]
    ) >> 0;
    result.status = decode8(
        &message.payload[14]
    ) >> 0;
    result.sat_number1 = decode8(
        &message.payload[15]
    ) >> 0;
    auto elevation1_raw = decode16(
        &message.payload[16]
    );
    result.elevation1 = reinterpret_cast<float const&>(
        elevation1_raw
    );
    auto azimuth1_raw = decode16(
        &message.payload[18]
    );
    result.azimuth1 = reinterpret_cast<float const&>(
        azimuth1_raw
    );
    auto snr1_raw = decode16(
        &message.payload[20]
    );
    result.snr1 = reinterpret_cast<float const&>(
        snr1_raw
    );
    result.range_residuals1 = decode32(
        &message.payload[22]
    ) >> 0;
    result.status1 = decode8(
        &message.payload[26]
    ) >> 0;
    result.sat_number2 = decode8(
        &message.payload[27]
    ) >> 0;
    auto elevation2_raw = decode16(
        &message.payload[28]
    );
    result.elevation2 = reinterpret_cast<float const&>(
        elevation2_raw
    );
    auto azimuth2_raw = decode16(
        &message.payload[30]
    );
    result.azimuth2 = reinterpret_cast<float const&>(
        azimuth2_raw
    );
    auto snr2_raw = decode16(
        &message.payload[32]
    );
    result.snr2 = reinterpret_cast<float const&>(
        snr2_raw
    );
    result.range_residuals2 = decode32(
        &message.payload[34]
    ) >> 0;
    result.status2 = decode8(
        &message.payload[38]
    ) >> 0;
    result.sat_number3 = decode8(
        &message.payload[39]
    ) >> 0;
    auto elevation3_raw = decode16(
        &message.payload[40]
    );
    result.elevation3 = reinterpret_cast<float const&>(
        elevation3_raw
    );
    auto azimuth3_raw = decode16(
        &message.payload[42]
    );
    result.azimuth3 = reinterpret_cast<float const&>(
        azimuth3_raw
    );
    auto snr3_raw = decode16(
        &message.payload[44]
    );
    result.snr3 = reinterpret_cast<float const&>(
        snr3_raw
    );
    result.range_residuals3 = decode32(
        &message.payload[46]
    ) >> 0;
    result.status3 = decode8(
        &message.payload[50]
    ) >> 0;
    result.sat_number4 = decode8(
        &message.payload[51]
    ) >> 0;
    auto elevation4_raw = decode16(
        &message.payload[52]
    );
    result.elevation4 = reinterpret_cast<float const&>(
        elevation4_raw
    );
    auto azimuth4_raw = decode16(
        &message.payload[54]
    );
    result.azimuth4 = reinterpret_cast<float const&>(
        azimuth4_raw
    );
    auto snr4_raw = decode16(
        &message.payload[56]
    );
    result.snr4 = reinterpret_cast<float const&>(
        snr4_raw
    );
    result.range_residuals4 = decode32(
        &message.payload[58]
    ) >> 0;
    result.status4 = decode8(
        &message.payload[62]
    ) >> 0;
    result.sat_number5 = decode8(
        &message.payload[63]
    ) >> 0;
    auto elevation5_raw = decode16(
        &message.payload[64]
    );
    result.elevation5 = reinterpret_cast<float const&>(
        elevation5_raw
    );
    auto azimuth5_raw = decode16(
        &message.payload[66]
    );
    result.azimuth5 = reinterpret_cast<float const&>(
        azimuth5_raw
    );
    auto snr5_raw = decode16(
        &message.payload[68]
    );
    result.snr5 = reinterpret_cast<float const&>(
        snr5_raw
    );
    result.range_residuals5 = decode32(
        &message.payload[70]
    ) >> 0;
    result.status5 = decode8(
        &message.payload[74]
    ) >> 0;
    result.sat_number6 = decode8(
        &message.payload[75]
    ) >> 0;
    auto elevation6_raw = decode16(
        &message.payload[76]
    );
    result.elevation6 = reinterpret_cast<float const&>(
        elevation6_raw
    );
    auto azimuth6_raw = decode16(
        &message.payload[78]
    );
    result.azimuth6 = reinterpret_cast<float const&>(
        azimuth6_raw
    );
    auto snr6_raw = decode16(
        &message.payload[80]
    );
    result.snr6 = reinterpret_cast<float const&>(
        snr6_raw
    );
    result.range_residuals6 = decode32(
        &message.payload[82]
    ) >> 0;
    result.status6 = decode8(
        &message.payload[86]
    ) >> 0;
    result.sat_number7 = decode8(
        &message.payload[87]
    ) >> 0;
    auto elevation7_raw = decode16(
        &message.payload[88]
    );
    result.elevation7 = reinterpret_cast<float const&>(
        elevation7_raw
    );
    auto azimuth7_raw = decode16(
        &message.payload[90]
    );
    result.azimuth7 = reinterpret_cast<float const&>(
        azimuth7_raw
    );
    auto snr7_raw = decode16(
        &message.payload[92]
    );
    result.snr7 = reinterpret_cast<float const&>(
        snr7_raw
    );
    result.range_residuals7 = decode32(
        &message.payload[94]
    ) >> 0;
    result.status7 = decode8(
        &message.payload[98]
    ) >> 0;
    result.sat_number8 = decode8(
        &message.payload[99]
    ) >> 0;
    auto elevation8_raw = decode16(
        &message.payload[100]
    );
    result.elevation8 = reinterpret_cast<float const&>(
        elevation8_raw
    );
    auto azimuth8_raw = decode16(
        &message.payload[102]
    );
    result.azimuth8 = reinterpret_cast<float const&>(
        azimuth8_raw
    );
    auto snr8_raw = decode16(
        &message.payload[104]
    );
    result.snr8 = reinterpret_cast<float const&>(
        snr8_raw
    );
    result.range_residuals8 = decode32(
        &message.payload[106]
    ) >> 0;
    result.status8 = decode8(
        &message.payload[110]
    ) >> 0;
    result.sat_number9 = decode8(
        &message.payload[111]
    ) >> 0;
    auto elevation9_raw = decode16(
        &message.payload[112]
    );
    result.elevation9 = reinterpret_cast<float const&>(
        elevation9_raw
    );
    auto azimuth9_raw = decode16(
        &message.payload[114]
    );
    result.azimuth9 = reinterpret_cast<float const&>(
        azimuth9_raw
    );
    auto snr9_raw = decode16(
        &message.payload[116]
    );
    result.snr9 = reinterpret_cast<float const&>(
        snr9_raw
    );
    result.range_residuals9 = decode32(
        &message.payload[118]
    ) >> 0;
    result.status9 = decode8(
        &message.payload[122]
    ) >> 0;
    result.sat_number10 = decode8(
        &message.payload[123]
    ) >> 0;
    auto elevation10_raw = decode16(
        &message.payload[124]
    );
    result.elevation10 = reinterpret_cast<float const&>(
        elevation10_raw
    );
    auto azimuth10_raw = decode16(
        &message.payload[126]
    );
    result.azimuth10 = reinterpret_cast<float const&>(
        azimuth10_raw
    );
    auto snr10_raw = decode16(
        &message.payload[128]
    );
    result.snr10 = reinterpret_cast<float const&>(
        snr10_raw
    );
    result.range_residuals10 = decode32(
        &message.payload[130]
    ) >> 0;
    result.status10 = decode8(
        &message.payload[134]
    ) >> 0;
    result.sat_number11 = decode8(
        &message.payload[135]
    ) >> 0;
    auto elevation11_raw = decode16(
        &message.payload[136]
    );
    result.elevation11 = reinterpret_cast<float const&>(
        elevation11_raw
    );
    auto azimuth11_raw = decode16(
        &message.payload[138]
    );
    result.azimuth11 = reinterpret_cast<float const&>(
        azimuth11_raw
    );
    auto snr11_raw = decode16(
        &message.payload[140]
    );
    result.snr11 = reinterpret_cast<float const&>(
        snr11_raw
    );
    result.range_residuals11 = decode32(
        &message.payload[142]
    ) >> 0;
    result.status11 = decode8(
        &message.payload[146]
    ) >> 0;
    result.sat_number12 = decode8(
        &message.payload[147]
    ) >> 0;
    auto elevation12_raw = decode16(
        &message.payload[148]
    );
    result.elevation12 = reinterpret_cast<float const&>(
        elevation12_raw
    );
    auto azimuth12_raw = decode16(
        &message.payload[150]
    );
    result.azimuth12 = reinterpret_cast<float const&>(
        azimuth12_raw
    );
    auto snr12_raw = decode16(
        &message.payload[152]
    );
    result.snr12 = reinterpret_cast<float const&>(
        snr12_raw
    );
    result.range_residuals12 = decode32(
        &message.payload[154]
    ) >> 0;
    result.status12 = decode8(
        &message.payload[158]
    ) >> 0;
    result.sat_number13 = decode8(
        &message.payload[159]
    ) >> 0;
    auto elevation13_raw = decode16(
        &message.payload[160]
    );
    result.elevation13 = reinterpret_cast<float const&>(
        elevation13_raw
    );
    auto azimuth13_raw = decode16(
        &message.payload[162]
    );
    result.azimuth13 = reinterpret_cast<float const&>(
        azimuth13_raw
    );
    auto snr13_raw = decode16(
        &message.payload[164]
    );
    result.snr13 = reinterpret_cast<float const&>(
        snr13_raw
    );
    result.range_residuals13 = decode32(
        &message.payload[166]
    ) >> 0;
    result.status13 = decode8(
        &message.payload[170]
    ) >> 0;
    result.sat_number14 = decode8(
        &message.payload[171]
    ) >> 0;
    auto elevation14_raw = decode16(
        &message.payload[172]
    );
    result.elevation14 = reinterpret_cast<float const&>(
        elevation14_raw
    );
    auto azimuth14_raw = decode16(
        &message.payload[174]
    );
    result.azimuth14 = reinterpret_cast<float const&>(
        azimuth14_raw
    );
    auto snr14_raw = decode16(
        &message.payload[176]
    );
    result.snr14 = reinterpret_cast<float const&>(
        snr14_raw
    );
    result.range_residuals14 = decode32(
        &message.payload[178]
    ) >> 0;
    result.status14 = decode8(
        &message.payload[182]
    ) >> 0;
    result.sat_number15 = decode8(
        &message.payload[183]
    ) >> 0;
    auto elevation15_raw = decode16(
        &message.payload[184]
    );
    result.elevation15 = reinterpret_cast<float const&>(
        elevation15_raw
    );
    auto azimuth15_raw = decode16(
        &message.payload[186]
    );
    result.azimuth15 = reinterpret_cast<float const&>(
        azimuth15_raw
    );
    auto snr15_raw = decode16(
        &message.payload[188]
    );
    result.snr15 = reinterpret_cast<float const&>(
        snr15_raw
    );
    result.range_residuals15 = decode32(
        &message.payload[190]
    ) >> 0;
    result.status15 = decode8(
        &message.payload[194]
    ) >> 0;
    result.sat_number16 = decode8(
        &message.payload[195]
    ) >> 0;
    auto elevation16_raw = decode16(
        &message.payload[196]
    );
    result.elevation16 = reinterpret_cast<float const&>(
        elevation16_raw
    );
    auto azimuth16_raw = decode16(
        &message.payload[198]
    );
    result.azimuth16 = reinterpret_cast<float const&>(
        azimuth16_raw
    );
    auto snr16_raw = decode16(
        &message.payload[200]
    );
    result.snr16 = reinterpret_cast<float const&>(
        snr16_raw
    );
    result.range_residuals16 = decode32(
        &message.payload[202]
    ) >> 0;
    result.status16 = decode8(
        &message.payload[206]
    ) >> 0;
    result.sat_number17 = decode8(
        &message.payload[207]
    ) >> 0;
    auto elevation17_raw = decode16(
        &message.payload[208]
    );
    result.elevation17 = reinterpret_cast<float const&>(
        elevation17_raw
    );
    auto azimuth17_raw = decode16(
        &message.payload[210]
    );
    result.azimuth17 = reinterpret_cast<float const&>(
        azimuth17_raw
    );
    auto snr17_raw = decode16(
        &message.payload[212]
    );
    result.snr17 = reinterpret_cast<float const&>(
        snr17_raw
    );
    result.range_residuals17 = decode32(
        &message.payload[214]
    ) >> 0;
    result.status17 = decode8(
        &message.payload[218]
    ) >> 0;
    return result;
}
GPSAlmanacData GPSAlmanacData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    GPSAlmanacData result;

    result.prn = decode8(
        &message.payload[0]
    ) >> 0;
    result.gps_week_number = decode8(
        &message.payload[1]
    ) >> 0;
    result.sv_health_bits = decode8(
        &message.payload[2]
    ) >> 0;
    result.eccentricity = decode8(
        &message.payload[3]
    ) >> 0;
    result.almanac_reference_time = decode8(
        &message.payload[4]
    ) >> 0;
    result.inclination_angle = decode8(
        &message.payload[5]
    ) >> 0;
    result.right_of_right_ascension = decode8(
        &message.payload[6]
    ) >> 0;
    result.root_of_semi_major_axis = decode8(
        &message.payload[7]
    ) >> 0;
    result.argument_of_perigee = decode8(
        &message.payload[8]
    ) >> 0;
    result.longitude_of_ascension_node = decode8(
        &message.payload[9]
    ) >> 0;
    result.mean_anomaly = decode8(
        &message.payload[10]
    ) >> 0;
    result.clock_parameter_1 = decode8(
        &message.payload[11]
    ) >> 0;
    result.clock_parameter_2 = decode8(
        &message.payload[12]
    ) >> 0;
    return result;
}
GNSSPseudorangeNoiseStatistics GNSSPseudorangeNoiseStatistics::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    GNSSPseudorangeNoiseStatistics result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.rms_of_position_uncertainty = decode16(
        &message.payload[1]
    ) >> 0;
    result.std_of_major_axis = decode8(
        &message.payload[3]
    ) >> 0;
    result.std_of_minor_axis = decode8(
        &message.payload[4]
    ) >> 0;
    result.orientation_of_major_axis = decode8(
        &message.payload[5]
    ) >> 0;
    result.std_of_lat_error = decode8(
        &message.payload[6]
    ) >> 0;
    result.std_of_lon_error = decode8(
        &message.payload[7]
    ) >> 0;
    result.std_of_alt_error = decode8(
        &message.payload[8]
    ) >> 0;
    return result;
}
GNSSRAIMOutput GNSSRAIMOutput::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    GNSSRAIMOutput result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.integrity_flag = decode8(
        &message.payload[1]
    ) >> 0;
    result.latitude_expected_error = decode8(
        &message.payload[2]
    ) >> 0;
    result.longitude_expected_error = decode8(
        &message.payload[3]
    ) >> 0;
    result.altitude_expected_error = decode8(
        &message.payload[4]
    ) >> 0;
    result.sv_id_of_most_likely_failed_sat = decode8(
        &message.payload[5]
    ) >> 0;
    result.probability_of_missed_detection = decode8(
        &message.payload[6]
    ) >> 0;
    result.estimate_of_pseudorange_bias = decode8(
        &message.payload[7]
    ) >> 0;
    result.std_deviation_of_bias = decode8(
        &message.payload[8]
    ) >> 0;
    return result;
}
GNSSRAIMSettings GNSSRAIMSettings::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    GNSSRAIMSettings result;

    result.radial_position_error_maximum_threshold = decode8(
        &message.payload[0]
    ) >> 0;
    result.probability_of_false_alarm = decode8(
        &message.payload[1]
    ) >> 0;
    result.probability_of_missed_detection = decode8(
        &message.payload[2]
    ) >> 0;
    result.pseudorange_residual_filtering_time_constant = decode8(
        &message.payload[3]
    ) >> 0;
    return result;
}
GNSSPseudorangeErrorStatistics GNSSPseudorangeErrorStatistics::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    GNSSPseudorangeErrorStatistics result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.rms_std_dev_of_range_inputs = decode16(
        &message.payload[1]
    ) >> 0;
    result.std_dev_of_major_error_ellipse = decode8(
        &message.payload[3]
    ) >> 0;
    result.std_dev_of_minor_error_ellipse = decode8(
        &message.payload[4]
    ) >> 0;
    result.orientation_of_error_ellipse = decode8(
        &message.payload[5]
    ) >> 0;
    result.std_dev_lat_error = decode8(
        &message.payload[6]
    ) >> 0;
    result.std_dev_lon_error = decode8(
        &message.payload[7]
    ) >> 0;
    result.std_dev_alt_error = decode8(
        &message.payload[8]
    ) >> 0;
    return result;
}
DGNSSCorrections DGNSSCorrections::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    DGNSSCorrections result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.reference_station_id = decode16(
        &message.payload[1]
    ) >> 0;
    result.reference_station_type = decode16(
        &message.payload[3]
    ) >> 0;
    result.time_of_corrections = decode8(
        &message.payload[5]
    ) >> 0;
    result.station_health = decode8(
        &message.payload[6]
    ) >> 0;
    result.reserved_bits = decode8(
        &message.payload[7]
    ) >> 0;
    result.satellite_id = decode8(
        &message.payload[8]
    ) >> 0;
    result.prc = decode8(
        &message.payload[9]
    ) >> 0;
    result.rrc = decode8(
        &message.payload[10]
    ) >> 0;
    result.udre = decode8(
        &message.payload[11]
    ) >> 0;
    result.iod = decode8(
        &message.payload[12]
    ) >> 0;
    return result;
}
GNSSDifferentialCorrectionReceiverInterface GNSSDifferentialCorrectionReceiverInterface::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    GNSSDifferentialCorrectionReceiverInterface result;

    result.channel = decode8(
        &message.payload[0]
    ) >> 0;
    result.frequency = decode8(
        &message.payload[1]
    ) >> 0;
    result.serial_interface_bit_rate = decode8(
        &message.payload[2]
    ) >> 0;
    result.serial_interface_detection_mode = decode8(
        &message.payload[3]
    ) >> 0;
    result.differential_source = decode8(
        &message.payload[4]
    ) >> 0;
    result.differential_operation_mode = decode8(
        &message.payload[5]
    ) >> 0;
    return result;
}
GNSSDifferentialCorrectionReceiverSignal GNSSDifferentialCorrectionReceiverSignal::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    GNSSDifferentialCorrectionReceiverSignal result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.channel = decode8(
        &message.payload[1]
    ) >> 0;
    result.signal_strength = decode8(
        &message.payload[2]
    ) >> 0;
    result.signal_snr = decode8(
        &message.payload[3]
    ) >> 0;
    result.frequency = decode8(
        &message.payload[4]
    ) >> 0;
    result.station_type = decode8(
        &message.payload[5]
    ) >> 0;
    result.station_id = decode8(
        &message.payload[6]
    ) >> 0;
    result.differential_signal_bit_rate = decode8(
        &message.payload[7]
    ) >> 0;
    result.differential_signal_detection_mode = decode8(
        &message.payload[8]
    ) >> 0;
    result.used_as_correction_source = decode8(
        &message.payload[9]
    ) >> 0;
    result.reserved = decode8(
        &message.payload[10]
    ) >> 0;
    result.differential_source = decode8(
        &message.payload[11]
    ) >> 0;
    result.time_since_last_sat_differential_sync = decode8(
        &message.payload[12]
    ) >> 0;
    result.satellite_service_id_no_ = decode8(
        &message.payload[13]
    ) >> 0;
    return result;
}
GLONASSAlmanacData GLONASSAlmanacData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    GLONASSAlmanacData result;

    result.prn = decode8(
        &message.payload[0]
    ) >> 0;
    result.na = decode8(
        &message.payload[1]
    ) >> 0;
    result.cna = decode8(
        &message.payload[2]
    ) >> 0;
    result.hna = decode8(
        &message.payload[3]
    ) >> 0;
    result._epsilon_na = decode8(
        &message.payload[4]
    ) >> 0;
    result._deltatna_dot = decode8(
        &message.payload[5]
    ) >> 0;
    result._omega_na = decode8(
        &message.payload[6]
    ) >> 0;
    result._delta_tna = decode8(
        &message.payload[7]
    ) >> 0;
    result.tna = decode8(
        &message.payload[8]
    ) >> 0;
    result._lambda_na = decode8(
        &message.payload[9]
    ) >> 0;
    result._delta_ina = decode8(
        &message.payload[10]
    ) >> 0;
    result.tca = decode8(
        &message.payload[11]
    ) >> 0;
    result.tna1 = decode8(
        &message.payload[12]
    ) >> 0;
    return result;
}
AISDGNSSBroadcastBinaryMessage AISDGNSSBroadcastBinaryMessage::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISDGNSSBroadcastBinaryMessage result;

    result.message_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.repeat_indicator = decode8(
        &message.payload[1]
    ) >> 0;
    result.source_id = decode8(
        &message.payload[2]
    ) >> 0;
    result.nmea_2000_reserved = decode8(
        &message.payload[3]
    ) >> 0;
    result.ais_tranceiver_information = decode8(
        &message.payload[4]
    ) >> 0;
    result.spare = decode8(
        &message.payload[5]
    ) >> 0;
    result.longitude = decode8(
        &message.payload[6]
    ) >> 0;
    result.latitude = decode8(
        &message.payload[7]
    ) >> 0;
    result.nmea_2000_reserved1 = decode8(
        &message.payload[8]
    ) >> 0;
    result.spare1 = decode8(
        &message.payload[9]
    ) >> 0;
    result.number_of_bits_in_binary_data_field = decode8(
        &message.payload[10]
    ) >> 0;
    return result;
}
AISUTCAndDateReport AISUTCAndDateReport::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISUTCAndDateReport result;

    result.message_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.repeat_indicator = decode8(
        &message.payload[0]
    ) >> 6;
    auto user_id_raw = decode32(
        &message.payload[1]
    );
    result.user_id = reinterpret_cast<int32_t const&>(
        user_id_raw
    );
    auto longitude_raw = decode32(
        &message.payload[5]
    );
    result.longitude = reinterpret_cast<float const&>(
        longitude_raw
    );
    auto latitude_raw = decode32(
        &message.payload[9]
    );
    result.latitude = reinterpret_cast<float const&>(
        latitude_raw
    );
    result.position_accuracy = decode8(
        &message.payload[13]
    ) >> 0;
    result.raim = decode8(
        &message.payload[13]
    ) >> 1;
    result.position_time = decode32(
        &message.payload[14]
    ) >> 0;
    result.ais_transceiver_information = decode8(
        &message.payload[20]
    ) >> 3;
    result.position_date = decode16(
        &message.payload[21]
    ) >> 0;
    result.gnss_type = decode8(
        &message.payload[23]
    ) >> 4;
    return result;
}
AISClassAStaticAndVoyageRelatedData AISClassAStaticAndVoyageRelatedData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISClassAStaticAndVoyageRelatedData result;

    result.message_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.repeat_indicator = decode8(
        &message.payload[0]
    ) >> 6;
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
    result.type_of_ship = decode8(
        &message.payload[36]
    ) >> 0;
    auto length_raw = decode16(
        &message.payload[37]
    );
    result.length = reinterpret_cast<float const&>(
        length_raw
    );
    auto beam_raw = decode16(
        &message.payload[39]
    );
    result.beam = reinterpret_cast<float const&>(
        beam_raw
    );
    auto position_reference_from_starboard_raw = decode16(
        &message.payload[41]
    );
    result.position_reference_from_starboard = reinterpret_cast<float const&>(
        position_reference_from_starboard_raw
    );
    auto position_reference_from_bow_raw = decode16(
        &message.payload[43]
    );
    result.position_reference_from_bow = reinterpret_cast<float const&>(
        position_reference_from_bow_raw
    );
    result.eta_date = decode16(
        &message.payload[45]
    ) >> 0;
    result.eta_time = decode32(
        &message.payload[47]
    ) >> 0;
    auto draft_raw = decode16(
        &message.payload[51]
    );
    result.draft = reinterpret_cast<float const&>(
        draft_raw
    );
    result.ais_version_indicator = decode8(
        &message.payload[73]
    ) >> 0;
    result.gnss_type = decode8(
        &message.payload[73]
    ) >> 2;
    result.dte = decode8(
        &message.payload[73]
    ) >> 6;
    result.ais_transceiver_information = decode8(
        &message.payload[74]
    ) >> 0;
    return result;
}
AISAddressedBinaryMessage AISAddressedBinaryMessage::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISAddressedBinaryMessage result;

    result.message_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.repeat_indicator = decode8(
        &message.payload[0]
    ) >> 6;
    auto source_id_raw = decode32(
        &message.payload[1]
    );
    result.source_id = reinterpret_cast<int32_t const&>(
        source_id_raw
    );
    result.ais_transceiver_information = decode8(
        &message.payload[5]
    ) >> 1;
    result.sequence_number = decode8(
        &message.payload[5]
    ) >> 6;
    auto destination_id_raw = decode32(
        &message.payload[6]
    );
    result.destination_id = reinterpret_cast<int32_t const&>(
        destination_id_raw
    );
    result.retransmit_flag = decode8(
        &message.payload[10]
    ) >> 6;
    auto number_of_bits_in_binary_data_field_raw = decode16(
        &message.payload[11]
    );
    result.number_of_bits_in_binary_data_field = reinterpret_cast<int16_t const&>(
        number_of_bits_in_binary_data_field_raw
    );
    return result;
}
AISAcknowledge AISAcknowledge::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISAcknowledge result;

    result.message_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.repeat_indicator = decode8(
        &message.payload[0]
    ) >> 6;
    result.source_id = decode32(
        &message.payload[1]
    ) >> 0;
    result.ais_transceiver_information = decode8(
        &message.payload[5]
    ) >> 1;
    result.destination_id_number1 = decode32(
        &message.payload[6]
    ) >> 0;
    return result;
}
AISBinaryBroadcastMessage AISBinaryBroadcastMessage::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISBinaryBroadcastMessage result;

    result.message_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.repeat_indicator = decode8(
        &message.payload[0]
    ) >> 6;
    result.source_id = decode32(
        &message.payload[1]
    ) >> 0;
    result.ais_transceiver_information = decode8(
        &message.payload[5]
    ) >> 1;
    result.number_of_bits_in_binary_data_field = decode16(
        &message.payload[6]
    ) >> 0;
    return result;
}
AISSARAircraftPositionReport AISSARAircraftPositionReport::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISSARAircraftPositionReport result;

    result.message_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.repeat_indicator = decode8(
        &message.payload[0]
    ) >> 6;
    auto user_id_raw = decode32(
        &message.payload[1]
    );
    result.user_id = reinterpret_cast<int32_t const&>(
        user_id_raw
    );
    auto longitude_raw = decode32(
        &message.payload[5]
    );
    result.longitude = reinterpret_cast<float const&>(
        longitude_raw
    );
    auto latitude_raw = decode32(
        &message.payload[9]
    );
    result.latitude = reinterpret_cast<float const&>(
        latitude_raw
    );
    result.position_accuracy = decode8(
        &message.payload[13]
    ) >> 0;
    result.raim = decode8(
        &message.payload[13]
    ) >> 1;
    result.time_stamp = decode8(
        &message.payload[13]
    ) >> 2;
    result.cog = decode16(
        &message.payload[14]
    ) >> 0;
    result.sog = decode16(
        &message.payload[16]
    ) >> 0;
    result.ais_transceiver_information = decode8(
        &message.payload[20]
    ) >> 3;
    auto altitude_raw = decode64(
        &message.payload[21]
    );
    result.altitude = reinterpret_cast<float const&>(
        altitude_raw
    );
    result.reserved_for_regional_applications = decode8(
        &message.payload[29]
    ) >> 0;
    result.dte = decode8(
        &message.payload[30]
    ) >> 0;
    return result;
}
RadioFrequencyModePower RadioFrequencyModePower::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RadioFrequencyModePower result;

    auto rx_frequency_raw = decode32(
        &message.payload[0]
    );
    result.rx_frequency = reinterpret_cast<float const&>(
        rx_frequency_raw
    );
    auto tx_frequency_raw = decode32(
        &message.payload[4]
    );
    result.tx_frequency = reinterpret_cast<float const&>(
        tx_frequency_raw
    );
    result.radio_channel = decode8(
        &message.payload[8]
    ) >> 0;
    result.tx_power = decode8(
        &message.payload[9]
    ) >> 0;
    result.mode = decode8(
        &message.payload[10]
    ) >> 0;
    result.channel_bandwidth = decode8(
        &message.payload[11]
    ) >> 0;
    return result;
}
AISUTCDateInquiry AISUTCDateInquiry::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISUTCDateInquiry result;

    result.message_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.repeat_indicator = decode8(
        &message.payload[0]
    ) >> 6;
    result.source_id = decode32(
        &message.payload[1]
    ) >> 0;
    result.ais_transceiver_information = decode8(
        &message.payload[5]
    ) >> 0;
    result.destination_id = decode32(
        &message.payload[6]
    ) >> 0;
    return result;
}
AISAddressedSafetyRelatedMessage AISAddressedSafetyRelatedMessage::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISAddressedSafetyRelatedMessage result;

    result.message_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.repeat_indicator = decode8(
        &message.payload[0]
    ) >> 6;
    result.source_id = decode32(
        &message.payload[1]
    ) >> 0;
    result.ais_transceiver_information = decode8(
        &message.payload[5]
    ) >> 1;
    result.sequence_number = decode8(
        &message.payload[5]
    ) >> 6;
    result.destination_id = decode32(
        &message.payload[6]
    ) >> 0;
    result.retransmit_flag = decode8(
        &message.payload[10]
    ) >> 6;
    return result;
}
AISSafetyRelatedBroadcastMessage AISSafetyRelatedBroadcastMessage::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISSafetyRelatedBroadcastMessage result;

    result.message_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.repeat_indicator = decode8(
        &message.payload[0]
    ) >> 6;
    result.ais_transceiver_information = decode8(
        &message.payload[5]
    ) >> 0;
    return result;
}
AISInterrogation AISInterrogation::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISInterrogation result;

    result.message_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.repeat_indicator = decode8(
        &message.payload[0]
    ) >> 6;
    result.ais_transceiver_information = decode8(
        &message.payload[5]
    ) >> 0;
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
AISAssignmentModeCommand AISAssignmentModeCommand::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISAssignmentModeCommand result;

    result.message_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.repeat_indicator = decode8(
        &message.payload[0]
    ) >> 6;
    auto source_id_raw = decode32(
        &message.payload[1]
    );
    result.source_id = reinterpret_cast<int32_t const&>(
        source_id_raw
    );
    result.ais_transceiver_information = decode8(
        &message.payload[5]
    ) >> 1;
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
AISDataLinkManagementMessage AISDataLinkManagementMessage::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISDataLinkManagementMessage result;

    result.message_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.repeat_indicator = decode8(
        &message.payload[0]
    ) >> 6;
    result.ais_transceiver_information = decode8(
        &message.payload[5]
    ) >> 0;
    return result;
}
AISChannelManagement AISChannelManagement::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISChannelManagement result;

    result.message_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.repeat_indicator = decode8(
        &message.payload[0]
    ) >> 6;
    result.ais_transceiver_information = decode8(
        &message.payload[5]
    ) >> 0;
    result.channel_a = decode8(
        &message.payload[6]
    ) >> 0;
    result.channel_b = decode8(
        &message.payload[6]
    ) >> 7;
    result.power = decode8(
        &message.payload[8]
    ) >> 0;
    auto tx_rx_mode_raw = decode8(
        &message.payload[9]
    );
    result.tx_rx_mode = reinterpret_cast<int8_t const&>(
        tx_rx_mode_raw
    );
    auto north_east_longitude_corner_1_raw = decode32(
        &message.payload[10]
    );
    result.north_east_longitude_corner_1 = reinterpret_cast<float const&>(
        north_east_longitude_corner_1_raw
    );
    auto north_east_latitude_corner_1_raw = decode32(
        &message.payload[14]
    );
    result.north_east_latitude_corner_1 = reinterpret_cast<float const&>(
        north_east_latitude_corner_1_raw
    );
    auto south_west_longitude_corner_1_raw = decode32(
        &message.payload[18]
    );
    result.south_west_longitude_corner_1 = reinterpret_cast<float const&>(
        south_west_longitude_corner_1_raw
    );
    auto south_west_latitude_corner_2_raw = decode32(
        &message.payload[22]
    );
    result.south_west_latitude_corner_2 = reinterpret_cast<float const&>(
        south_west_latitude_corner_2_raw
    );
    result.addressed_or_broadcast_message_indicator = decode8(
        &message.payload[26]
    ) >> 6;
    result.transitional_zone_size = decode8(
        &message.payload[29]
    ) >> 0;
    return result;
}
AISClassBGroupAssignment AISClassBGroupAssignment::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISClassBGroupAssignment result;

    result.message_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.repeat_indicator = decode8(
        &message.payload[0]
    ) >> 6;
    auto north_east_longitude_corner_1_raw = decode32(
        &message.payload[6]
    );
    result.north_east_longitude_corner_1 = reinterpret_cast<float const&>(
        north_east_longitude_corner_1_raw
    );
    auto north_east_latitude_corner_1_raw = decode32(
        &message.payload[10]
    );
    result.north_east_latitude_corner_1 = reinterpret_cast<float const&>(
        north_east_latitude_corner_1_raw
    );
    auto south_west_longitude_corner_1_raw = decode32(
        &message.payload[14]
    );
    result.south_west_longitude_corner_1 = reinterpret_cast<float const&>(
        south_west_longitude_corner_1_raw
    );
    auto south_west_latitude_corner_2_raw = decode32(
        &message.payload[18]
    );
    result.south_west_latitude_corner_2 = reinterpret_cast<float const&>(
        south_west_latitude_corner_2_raw
    );
    result.station_type = decode8(
        &message.payload[22]
    ) >> 0;
    result.ship_and_cargo_filter = decode8(
        &message.payload[23]
    ) >> 2;
    result.reporting_interval = decode16(
        &message.payload[24]
    ) >> 2;
    result.quiet_time = decode16(
        &message.payload[26]
    ) >> 2;
    return result;
}
DSCCallInformation DSCCallInformation::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    DSCCallInformation result;

    result.dsc_format_symbol = decode8(
        &message.payload[0]
    ) >> 0;
    result.dsc_category_symbol = decode8(
        &message.payload[1]
    ) >> 0;
    result.dsc_message_address = decode8(
        &message.payload[2]
    ) >> 0;
    result.nature_of_distress_or_1st_telecommand = decode8(
        &message.payload[3]
    ) >> 0;
    result.subsequent_communication_mode_or_2nd_telecommand = decode8(
        &message.payload[4]
    ) >> 0;
    result.proposed_rx_frequency_channel = decode8(
        &message.payload[5]
    ) >> 0;
    result.proposed_tx_frequency_channel = decode8(
        &message.payload[6]
    ) >> 0;
    result.telephone_number = decode8(
        &message.payload[7]
    ) >> 0;
    auto latitude_of_vessel_reported_raw = decode32(
        &message.payload[8]
    );
    result.latitude_of_vessel_reported = reinterpret_cast<float const&>(
        latitude_of_vessel_reported_raw
    );
    auto longitude_of_vessel_reported_raw = decode32(
        &message.payload[12]
    );
    result.longitude_of_vessel_reported = reinterpret_cast<float const&>(
        longitude_of_vessel_reported_raw
    );
    result.time_of_position = decode32(
        &message.payload[16]
    ) >> 0;
    auto user_id_of_ship_in_distress_raw = decode32(
        &message.payload[20]
    );
    result.user_id_of_ship_in_distress = reinterpret_cast<int32_t const&>(
        user_id_of_ship_in_distress_raw
    );
    result.dsc_eos_symbol = decode8(
        &message.payload[24]
    ) >> 0;
    result.expansion_enabled = decode8(
        &message.payload[25]
    ) >> 0;
    result.calling_rx_frequency_channel = decode8(
        &message.payload[26]
    ) >> 0;
    result.calling_tx_frequency_channel = decode8(
        &message.payload[27]
    ) >> 0;
    result.time_of_receipt = decode32(
        &message.payload[28]
    ) >> 0;
    result.date_of_receipt = decode16(
        &message.payload[32]
    ) >> 0;
    result.dsc_equipment_assigned_message_id = decode8(
        &message.payload[34]
    ) >> 0;
    result.dsc_expansion_field_symbol = decode8(
        &message.payload[35]
    ) >> 0;
    result.dsc_expansion_field_data = decode8(
        &message.payload[36]
    ) >> 0;
    return result;
}
AISClassBStaticDataMsg24PartA AISClassBStaticDataMsg24PartA::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISClassBStaticDataMsg24PartA result;

    result.message_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.repeat_indicator = decode8(
        &message.payload[0]
    ) >> 6;
    auto user_id_raw = decode32(
        &message.payload[1]
    );
    result.user_id = reinterpret_cast<int32_t const&>(
        user_id_raw
    );
    return result;
}
AISClassBStaticDataMsg24PartB AISClassBStaticDataMsg24PartB::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AISClassBStaticDataMsg24PartB result;

    result.message_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.repeat_indicator = decode8(
        &message.payload[0]
    ) >> 6;
    auto user_id_raw = decode32(
        &message.payload[1]
    );
    result.user_id = reinterpret_cast<int32_t const&>(
        user_id_raw
    );
    result.type_of_ship = decode8(
        &message.payload[5]
    ) >> 0;
    auto length_raw = decode16(
        &message.payload[20]
    );
    result.length = reinterpret_cast<float const&>(
        length_raw
    );
    auto beam_raw = decode16(
        &message.payload[22]
    );
    result.beam = reinterpret_cast<float const&>(
        beam_raw
    );
    auto position_reference_from_starboard_raw = decode16(
        &message.payload[24]
    );
    result.position_reference_from_starboard = reinterpret_cast<float const&>(
        position_reference_from_starboard_raw
    );
    auto position_reference_from_bow_raw = decode16(
        &message.payload[26]
    );
    result.position_reference_from_bow = reinterpret_cast<float const&>(
        position_reference_from_bow_raw
    );
    auto mothership_user_id_raw = decode32(
        &message.payload[28]
    );
    result.mothership_user_id = reinterpret_cast<int32_t const&>(
        mothership_user_id_raw
    );
    return result;
}
RouteAndWPServiceDatabaseList RouteAndWPServiceDatabaseList::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RouteAndWPServiceDatabaseList result;

    result.start_database_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.nitems = decode8(
        &message.payload[1]
    ) >> 0;
    result.number_of_databases_available = decode8(
        &message.payload[2]
    ) >> 0;
    result.database_id = decode8(
        &message.payload[3]
    ) >> 0;
    result.database_timestamp = decode32(
        &message.payload[12]
    ) >> 0;
    result.database_datestamp = decode16(
        &message.payload[16]
    ) >> 0;
    result.wp_position_resolution = decode8(
        &message.payload[18]
    ) >> 0;
    result.number_of_routes_in_database = decode16(
        &message.payload[19]
    ) >> 0;
    result.number_of_wps_in_database = decode16(
        &message.payload[21]
    ) >> 0;
    result.number_of_bytes_in_database = decode16(
        &message.payload[23]
    ) >> 0;
    return result;
}
RouteAndWPServiceRouteList RouteAndWPServiceRouteList::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RouteAndWPServiceRouteList result;

    result.start_route_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.nitems = decode8(
        &message.payload[1]
    ) >> 0;
    result.number_of_routes_in_database = decode8(
        &message.payload[2]
    ) >> 0;
    result.database_id = decode8(
        &message.payload[3]
    ) >> 0;
    result.route_id = decode8(
        &message.payload[4]
    ) >> 0;
    result.wp_identification_method = decode8(
        &message.payload[13]
    ) >> 4;
    result.route_status = decode8(
        &message.payload[13]
    ) >> 6;
    return result;
}
RouteAndWPServiceRouteWPListAttributes RouteAndWPServiceRouteWPListAttributes::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RouteAndWPServiceRouteWPListAttributes result;

    result.database_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.route_id = decode8(
        &message.payload[1]
    ) >> 0;
    result.route_wp_list_timestamp = decode32(
        &message.payload[10]
    ) >> 0;
    result.route_wp_list_datestamp = decode16(
        &message.payload[14]
    ) >> 0;
    result.change_at_last_timestamp = decode8(
        &message.payload[16]
    ) >> 0;
    result.number_of_wps_in_the_route_wp_list = decode16(
        &message.payload[17]
    ) >> 0;
    result.critical_supplementary_parameters = decode8(
        &message.payload[19]
    ) >> 0;
    result.navigation_method = decode8(
        &message.payload[20]
    ) >> 0;
    result.wp_identification_method = decode8(
        &message.payload[20]
    ) >> 2;
    result.route_status = decode8(
        &message.payload[20]
    ) >> 4;
    result.xte_limit_for_the_route = decode16(
        &message.payload[20]
    ) >> 6;
    return result;
}
RouteAndWPServiceRouteWPNamePosition RouteAndWPServiceRouteWPNamePosition::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RouteAndWPServiceRouteWPNamePosition result;

    result.start_rpsnumber = decode8(
        &message.payload[0]
    ) >> 0;
    result.nitems = decode8(
        &message.payload[1]
    ) >> 0;
    result.number_of_wps_in_the_route_wp_list = decode16(
        &message.payload[2]
    ) >> 0;
    result.database_id = decode8(
        &message.payload[4]
    ) >> 0;
    result.route_id = decode8(
        &message.payload[5]
    ) >> 0;
    result.wp_id = decode8(
        &message.payload[6]
    ) >> 0;
    auto wp_latitude_raw = decode32(
        &message.payload[15]
    );
    result.wp_latitude = reinterpret_cast<float const&>(
        wp_latitude_raw
    );
    auto wp_longitude_raw = decode32(
        &message.payload[19]
    );
    result.wp_longitude = reinterpret_cast<float const&>(
        wp_longitude_raw
    );
    return result;
}
RouteAndWPServiceRouteWPName RouteAndWPServiceRouteWPName::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RouteAndWPServiceRouteWPName result;

    result.start_rpsnumber = decode8(
        &message.payload[0]
    ) >> 0;
    result.nitems = decode8(
        &message.payload[1]
    ) >> 0;
    result.number_of_wps_in_the_route_wp_list = decode16(
        &message.payload[2]
    ) >> 0;
    result.database_id = decode8(
        &message.payload[4]
    ) >> 0;
    result.route_id = decode8(
        &message.payload[5]
    ) >> 0;
    result.wp_id = decode8(
        &message.payload[6]
    ) >> 0;
    return result;
}
RouteAndWPServiceXTELimitNavigationMethod RouteAndWPServiceXTELimitNavigationMethod::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RouteAndWPServiceXTELimitNavigationMethod result;

    result.start_rpsnumber = decode8(
        &message.payload[0]
    ) >> 0;
    result.nitems = decode8(
        &message.payload[1]
    ) >> 0;
    result.number_of_wps_with_a_specific_xte_limit_or_nav_method = decode16(
        &message.payload[2]
    ) >> 0;
    result.database_id = decode8(
        &message.payload[4]
    ) >> 0;
    result.route_id = decode8(
        &message.payload[5]
    ) >> 0;
    result.rpsnumber = decode8(
        &message.payload[6]
    ) >> 0;
    result.xte_limit_in_the_leg_after_wp = decode16(
        &message.payload[7]
    ) >> 0;
    result.nav_method_in_the_leg_after_wp = decode8(
        &message.payload[9]
    ) >> 0;
    return result;
}
RouteAndWPServiceWPComment RouteAndWPServiceWPComment::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RouteAndWPServiceWPComment result;

    result.start_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.nitems = decode8(
        &message.payload[1]
    ) >> 0;
    result.number_of_wps_with_comments = decode16(
        &message.payload[2]
    ) >> 0;
    result.database_id = decode8(
        &message.payload[4]
    ) >> 0;
    result.route_id = decode8(
        &message.payload[5]
    ) >> 0;
    result.wp_id_rpsnumber = decode8(
        &message.payload[6]
    ) >> 0;
    return result;
}
RouteAndWPServiceRouteComment RouteAndWPServiceRouteComment::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RouteAndWPServiceRouteComment result;

    result.start_route_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.nitems = decode8(
        &message.payload[1]
    ) >> 0;
    result.number_of_routes_with_comments = decode16(
        &message.payload[2]
    ) >> 0;
    result.database_id = decode8(
        &message.payload[4]
    ) >> 0;
    result.route_id = decode8(
        &message.payload[5]
    ) >> 0;
    return result;
}
RouteAndWPServiceDatabaseComment RouteAndWPServiceDatabaseComment::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RouteAndWPServiceDatabaseComment result;

    result.start_database_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.nitems = decode8(
        &message.payload[1]
    ) >> 0;
    result.number_of_databases_with_comments = decode16(
        &message.payload[2]
    ) >> 0;
    result.database_id = decode8(
        &message.payload[4]
    ) >> 0;
    return result;
}
RouteAndWPServiceRadiusOfTurn RouteAndWPServiceRadiusOfTurn::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RouteAndWPServiceRadiusOfTurn result;

    result.start_rpsnumber = decode8(
        &message.payload[0]
    ) >> 0;
    result.nitems = decode8(
        &message.payload[1]
    ) >> 0;
    result.number_of_wps_with_a_specific_radius_of_turn = decode16(
        &message.payload[2]
    ) >> 0;
    result.database_id = decode8(
        &message.payload[4]
    ) >> 0;
    result.route_id = decode8(
        &message.payload[5]
    ) >> 0;
    result.rpsnumber = decode8(
        &message.payload[6]
    ) >> 0;
    result.radius_of_turn = decode16(
        &message.payload[7]
    ) >> 0;
    return result;
}
RouteAndWPServiceWPListWPNamePosition RouteAndWPServiceWPListWPNamePosition::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    RouteAndWPServiceWPListWPNamePosition result;

    result.start_wp_id = decode8(
        &message.payload[0]
    ) >> 0;
    result.nitems = decode8(
        &message.payload[1]
    ) >> 0;
    result.number_of_valid_wps_in_the_wp_list = decode16(
        &message.payload[2]
    ) >> 0;
    result.database_id = decode8(
        &message.payload[4]
    ) >> 0;
    result.reserved = decode8(
        &message.payload[5]
    ) >> 0;
    result.wp_id = decode8(
        &message.payload[6]
    ) >> 0;
    auto wp_latitude_raw = decode32(
        &message.payload[15]
    );
    result.wp_latitude = reinterpret_cast<float const&>(
        wp_latitude_raw
    );
    auto wp_longitude_raw = decode32(
        &message.payload[19]
    );
    result.wp_longitude = reinterpret_cast<float const&>(
        wp_longitude_raw
    );
    return result;
}
WindData WindData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    WindData result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    auto wind_speed_raw = decode16(
        &message.payload[1]
    );
    result.wind_speed = reinterpret_cast<float const&>(
        wind_speed_raw
    );
    result.wind_angle = decode16(
        &message.payload[3]
    ) >> 0;
    result.reference = decode8(
        &message.payload[5]
    ) >> 0;
    result.reserved = decode32(
        &message.payload[5]
    ) >> 3;
    return result;
}
EnvironmentalParameters EnvironmentalParameters::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    EnvironmentalParameters result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.water_temperature = decode16(
        &message.payload[1]
    ) >> 0;
    result.outside_ambient_air_temperature = decode16(
        &message.payload[3]
    ) >> 0;
    result.atmospheric_pressure = decode16(
        &message.payload[5]
    ) >> 0;
    result.reserved = decode8(
        &message.payload[7]
    ) >> 0;
    return result;
}
EnvironmentalParameters1 EnvironmentalParameters1::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    EnvironmentalParameters1 result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.temperature_instance = decode8(
        &message.payload[1]
    ) >> 0;
    result.humidity_instance = decode8(
        &message.payload[1]
    ) >> 6;
    result.temperature = decode16(
        &message.payload[2]
    ) >> 0;
    auto humidity_raw = decode16(
        &message.payload[4]
    );
    result.humidity = reinterpret_cast<float const&>(
        humidity_raw
    );
    result.atmospheric_pressure = decode16(
        &message.payload[6]
    ) >> 0;
    return result;
}
Temperature Temperature::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    Temperature result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.temperature_source = decode8(
        &message.payload[2]
    ) >> 0;
    result.actual_temperature = decode16(
        &message.payload[3]
    ) >> 0;
    result.set_temperature = decode16(
        &message.payload[5]
    ) >> 0;
    result.reserved = decode8(
        &message.payload[7]
    ) >> 0;
    return result;
}
Humidity Humidity::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    Humidity result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.humidity_source = decode8(
        &message.payload[2]
    ) >> 0;
    result.actual_humidity = decode16(
        &message.payload[3]
    ) >> 0;
    result.set_humidity = decode16(
        &message.payload[5]
    ) >> 0;
    result.reserved = decode8(
        &message.payload[7]
    ) >> 0;
    return result;
}
ActualPressure ActualPressure::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    ActualPressure result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.pressure_source = decode8(
        &message.payload[2]
    ) >> 0;
    result.pressure = decode32(
        &message.payload[3]
    ) >> 0;
    return result;
}
SetPressure SetPressure::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SetPressure result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.pressure_source = decode8(
        &message.payload[2]
    ) >> 0;
    result.set_pressure = decode32(
        &message.payload[3]
    ) >> 0;
    return result;
}
TemperatureExtendedRange TemperatureExtendedRange::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    TemperatureExtendedRange result;

    result.sid = decode8(
        &message.payload[0]
    ) >> 0;
    result.temperature_source = decode8(
        &message.payload[2]
    ) >> 0;
    result.actual_temperature = decode32(
        &message.payload[3]
    ) >> 0;
    result.set_temperature = decode16(
        &message.payload[6]
    ) >> 0;
    return result;
}
TideStationData TideStationData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    TideStationData result;

    result.mode = decode8(
        &message.payload[0]
    ) >> 0;
    result.tide_tendency = decode8(
        &message.payload[0]
    ) >> 4;
    result.measurement_date = decode16(
        &message.payload[1]
    ) >> 0;
    result.measurement_time = decode32(
        &message.payload[3]
    ) >> 0;
    auto station_latitude_raw = decode32(
        &message.payload[7]
    );
    result.station_latitude = reinterpret_cast<float const&>(
        station_latitude_raw
    );
    auto station_longitude_raw = decode32(
        &message.payload[11]
    );
    result.station_longitude = reinterpret_cast<float const&>(
        station_longitude_raw
    );
    auto tide_level_raw = decode16(
        &message.payload[15]
    );
    result.tide_level = reinterpret_cast<float const&>(
        tide_level_raw
    );
    auto tide_level_standard_deviation_raw = decode16(
        &message.payload[17]
    );
    result.tide_level_standard_deviation = reinterpret_cast<float const&>(
        tide_level_standard_deviation_raw
    );
    return result;
}
SalinityStationData SalinityStationData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SalinityStationData result;

    result.mode = decode8(
        &message.payload[0]
    ) >> 0;
    result.measurement_date = decode16(
        &message.payload[1]
    ) >> 0;
    result.measurement_time = decode32(
        &message.payload[3]
    ) >> 0;
    auto station_latitude_raw = decode32(
        &message.payload[7]
    );
    result.station_latitude = reinterpret_cast<float const&>(
        station_latitude_raw
    );
    auto station_longitude_raw = decode32(
        &message.payload[11]
    );
    result.station_longitude = reinterpret_cast<float const&>(
        station_longitude_raw
    );
    auto salinity_raw = decode32(
        &message.payload[15]
    );
    result.salinity = reinterpret_cast<float const&>(
        salinity_raw
    );
    result.water_temperature = decode16(
        &message.payload[19]
    ) >> 0;
    return result;
}
CurrentStationData CurrentStationData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    CurrentStationData result;

    result.mode = decode8(
        &message.payload[0]
    ) >> 0;
    result.measurement_date = decode16(
        &message.payload[1]
    ) >> 0;
    result.measurement_time = decode32(
        &message.payload[3]
    ) >> 0;
    auto station_latitude_raw = decode32(
        &message.payload[7]
    );
    result.station_latitude = reinterpret_cast<float const&>(
        station_latitude_raw
    );
    auto station_longitude_raw = decode32(
        &message.payload[11]
    );
    result.station_longitude = reinterpret_cast<float const&>(
        station_longitude_raw
    );
    auto measurement_depth_raw = decode32(
        &message.payload[15]
    );
    result.measurement_depth = reinterpret_cast<float const&>(
        measurement_depth_raw
    );
    auto current_speed_raw = decode16(
        &message.payload[19]
    );
    result.current_speed = reinterpret_cast<float const&>(
        current_speed_raw
    );
    result.current_flow_direction = decode16(
        &message.payload[21]
    ) >> 0;
    result.water_temperature = decode16(
        &message.payload[23]
    ) >> 0;
    return result;
}
MeteorologicalStationData MeteorologicalStationData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    MeteorologicalStationData result;

    result.mode = decode8(
        &message.payload[0]
    ) >> 0;
    result.measurement_date = decode16(
        &message.payload[1]
    ) >> 0;
    result.measurement_time = decode32(
        &message.payload[3]
    ) >> 0;
    auto station_latitude_raw = decode32(
        &message.payload[7]
    );
    result.station_latitude = reinterpret_cast<float const&>(
        station_latitude_raw
    );
    auto station_longitude_raw = decode32(
        &message.payload[11]
    );
    result.station_longitude = reinterpret_cast<float const&>(
        station_longitude_raw
    );
    auto wind_speed_raw = decode16(
        &message.payload[15]
    );
    result.wind_speed = reinterpret_cast<float const&>(
        wind_speed_raw
    );
    result.wind_direction = decode16(
        &message.payload[17]
    ) >> 0;
    result.wind_reference = decode8(
        &message.payload[19]
    ) >> 0;
    auto wind_gusts_raw = decode16(
        &message.payload[20]
    );
    result.wind_gusts = reinterpret_cast<float const&>(
        wind_gusts_raw
    );
    result.atmospheric_pressure = decode16(
        &message.payload[22]
    ) >> 0;
    result.ambient_temperature = decode16(
        &message.payload[24]
    ) >> 0;
    return result;
}
MooredBuoyStationData MooredBuoyStationData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    MooredBuoyStationData result;

    result.mode = decode8(
        &message.payload[0]
    ) >> 0;
    result.measurement_date = decode16(
        &message.payload[1]
    ) >> 0;
    result.measurement_time = decode32(
        &message.payload[3]
    ) >> 0;
    auto station_latitude_raw = decode32(
        &message.payload[7]
    );
    result.station_latitude = reinterpret_cast<float const&>(
        station_latitude_raw
    );
    auto station_longitude_raw = decode32(
        &message.payload[11]
    );
    result.station_longitude = reinterpret_cast<float const&>(
        station_longitude_raw
    );
    auto wind_speed_raw = decode16(
        &message.payload[15]
    );
    result.wind_speed = reinterpret_cast<float const&>(
        wind_speed_raw
    );
    result.wind_direction = decode16(
        &message.payload[17]
    ) >> 0;
    result.wind_reference = decode8(
        &message.payload[19]
    ) >> 0;
    auto wind_gusts_raw = decode16(
        &message.payload[20]
    );
    result.wind_gusts = reinterpret_cast<float const&>(
        wind_gusts_raw
    );
    result.wave_height = decode16(
        &message.payload[22]
    ) >> 0;
    result.dominant_wave_period = decode16(
        &message.payload[24]
    ) >> 0;
    result.atmospheric_pressure = decode16(
        &message.payload[26]
    ) >> 0;
    result.pressure_tendency_rate = decode16(
        &message.payload[28]
    ) >> 0;
    result.air_temperature = decode16(
        &message.payload[30]
    ) >> 0;
    result.water_temperature = decode16(
        &message.payload[32]
    ) >> 0;
    return result;
}
SmallCraftStatus SmallCraftStatus::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SmallCraftStatus result;

    result.port_trim_tab = decode8(
        &message.payload[0]
    ) >> 0;
    result.starboard_trim_tab = decode8(
        &message.payload[1]
    ) >> 0;
    return result;
}
DirectionData DirectionData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    DirectionData result;

    result.data_mode = decode8(
        &message.payload[0]
    ) >> 0;
    result.cog_reference = decode8(
        &message.payload[0]
    ) >> 4;
    result.sid = decode8(
        &message.payload[1]
    ) >> 0;
    result.cog = decode16(
        &message.payload[2]
    ) >> 0;
    result.sog = decode16(
        &message.payload[4]
    ) >> 0;
    result.heading = decode16(
        &message.payload[6]
    ) >> 0;
    auto speed_through_water_raw = decode16(
        &message.payload[8]
    );
    result.speed_through_water = reinterpret_cast<float const&>(
        speed_through_water_raw
    );
    result.set = decode16(
        &message.payload[10]
    ) >> 0;
    auto drift_raw = decode16(
        &message.payload[12]
    );
    result.drift = reinterpret_cast<float const&>(
        drift_raw
    );
    return result;
}
VesselSpeedComponents VesselSpeedComponents::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    VesselSpeedComponents result;

    auto longitudinal_speed_water_referenced_raw = decode16(
        &message.payload[0]
    );
    result.longitudinal_speed_water_referenced = reinterpret_cast<float const&>(
        longitudinal_speed_water_referenced_raw
    );
    auto transverse_speed_water_referenced_raw = decode16(
        &message.payload[2]
    );
    result.transverse_speed_water_referenced = reinterpret_cast<float const&>(
        transverse_speed_water_referenced_raw
    );
    auto longitudinal_speed_ground_referenced_raw = decode16(
        &message.payload[4]
    );
    result.longitudinal_speed_ground_referenced = reinterpret_cast<float const&>(
        longitudinal_speed_ground_referenced_raw
    );
    auto transverse_speed_ground_referenced_raw = decode16(
        &message.payload[6]
    );
    result.transverse_speed_ground_referenced = reinterpret_cast<float const&>(
        transverse_speed_ground_referenced_raw
    );
    auto stern_speed_water_referenced_raw = decode16(
        &message.payload[8]
    );
    result.stern_speed_water_referenced = reinterpret_cast<float const&>(
        stern_speed_water_referenced_raw
    );
    auto stern_speed_ground_referenced_raw = decode16(
        &message.payload[10]
    );
    result.stern_speed_ground_referenced = reinterpret_cast<float const&>(
        stern_speed_ground_referenced_raw
    );
    return result;
}
SimradTextMessage SimradTextMessage::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimradTextMessage result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    auto product_code_raw = decode16(
        &message.payload[2]
    );
    result.product_code = reinterpret_cast<int16_t const&>(
        product_code_raw
    );
    result.a = decode8(
        &message.payload[4]
    ) >> 0;
    result.b = decode8(
        &message.payload[5]
    ) >> 0;
    result.c = decode8(
        &message.payload[6]
    ) >> 0;
    result.d = decode8(
        &message.payload[7]
    ) >> 0;
    result.sid = decode8(
        &message.payload[8]
    ) >> 0;
    result.prio = decode8(
        &message.payload[9]
    ) >> 0;
    return result;
}
NavicoProductInformation NavicoProductInformation::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    NavicoProductInformation result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    auto product_code_raw = decode16(
        &message.payload[2]
    );
    result.product_code = reinterpret_cast<int16_t const&>(
        product_code_raw
    );
    result.a = decode8(
        &message.payload[36]
    ) >> 0;
    result.b = decode8(
        &message.payload[37]
    ) >> 0;
    result.c = decode8(
        &message.payload[38]
    ) >> 0;
    return result;
}
SimnetReprogramData SimnetReprogramData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetReprogramData result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
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
SimnetRequestReprogram SimnetRequestReprogram::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetRequestReprogram result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    return result;
}
SimnetReprogramStatus1 SimnetReprogramStatus1::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetReprogramStatus1 result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    result.reserved1 = decode8(
        &message.payload[2]
    ) >> 0;
    result.status = decode8(
        &message.payload[3]
    ) >> 0;
    result.reserved2 = decode32(
        &message.payload[4]
    ) >> 0;
    return result;
}
LowranceUnknown LowranceUnknown::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    LowranceUnknown result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    result.a = decode8(
        &message.payload[2]
    ) >> 0;
    result.b = decode8(
        &message.payload[3]
    ) >> 0;
    result.c = decode8(
        &message.payload[4]
    ) >> 0;
    result.d = decode8(
        &message.payload[5]
    ) >> 0;
    result.e = decode16(
        &message.payload[6]
    ) >> 0;
    result.f = decode16(
        &message.payload[8]
    ) >> 0;
    return result;
}
SimnetSetSerialNumber SimnetSetSerialNumber::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetSetSerialNumber result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    return result;
}
SuzukiEngineAndStorageDeviceConfig SuzukiEngineAndStorageDeviceConfig::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SuzukiEngineAndStorageDeviceConfig result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    return result;
}
SimnetFuelUsedHighResolution SimnetFuelUsedHighResolution::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetFuelUsedHighResolution result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    return result;
}
SimnetEngineAndTankConfiguration SimnetEngineAndTankConfiguration::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetEngineAndTankConfiguration result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    return result;
}
SimnetSetEngineAndTankConfiguration SimnetSetEngineAndTankConfiguration::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetSetEngineAndTankConfiguration result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    return result;
}
SimnetFluidLevelSensorConfiguration SimnetFluidLevelSensorConfiguration::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetFluidLevelSensorConfiguration result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    result.c = decode8(
        &message.payload[2]
    ) >> 0;
    auto device_raw = decode8(
        &message.payload[3]
    );
    result.device = reinterpret_cast<int8_t const&>(
        device_raw
    );
    result.f = decode8(
        &message.payload[5]
    ) >> 0;
    result.tank_type = decode8(
        &message.payload[5]
    ) >> 4;
    auto capacity_raw = decode32(
        &message.payload[6]
    );
    result.capacity = reinterpret_cast<float const&>(
        capacity_raw
    );
    result.g = decode8(
        &message.payload[10]
    ) >> 0;
    result.h = decode16(
        &message.payload[11]
    ) >> 0;
    result.i = decode8(
        &message.payload[13]
    ) >> 0;
    return result;
}
SimnetFuelFlowTurbineConfiguration SimnetFuelFlowTurbineConfiguration::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetFuelFlowTurbineConfiguration result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    return result;
}
SimnetFluidLevelWarning SimnetFluidLevelWarning::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetFluidLevelWarning result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    return result;
}
SimnetPressureSensorConfiguration SimnetPressureSensorConfiguration::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetPressureSensorConfiguration result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    return result;
}
SimnetDataUserGroupConfiguration SimnetDataUserGroupConfiguration::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetDataUserGroupConfiguration result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    return result;
}
SimnetAISClassBStaticDataMsg24PartA SimnetAISClassBStaticDataMsg24PartA::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetAISClassBStaticDataMsg24PartA result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    result.message_id = decode8(
        &message.payload[2]
    ) >> 0;
    result.repeat_indicator = decode8(
        &message.payload[2]
    ) >> 6;
    result.d = decode8(
        &message.payload[3]
    ) >> 0;
    result.e = decode8(
        &message.payload[4]
    ) >> 0;
    auto user_id_raw = decode32(
        &message.payload[5]
    );
    result.user_id = reinterpret_cast<int32_t const&>(
        user_id_raw
    );
    return result;
}
SimnetSonarStatusFrequencyAndDSPVoltage SimnetSonarStatusFrequencyAndDSPVoltage::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetSonarStatusFrequencyAndDSPVoltage result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    return result;
}
SimnetParameterHandle SimnetParameterHandle::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetParameterHandle result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    result.message_id = decode8(
        &message.payload[2]
    ) >> 0;
    result.repeat_indicator = decode8(
        &message.payload[2]
    ) >> 6;
    result.d = decode8(
        &message.payload[3]
    ) >> 0;
    result.group = decode8(
        &message.payload[4]
    ) >> 0;
    result.f = decode8(
        &message.payload[5]
    ) >> 0;
    result.g = decode8(
        &message.payload[6]
    ) >> 0;
    result.h = decode8(
        &message.payload[7]
    ) >> 0;
    result.i = decode8(
        &message.payload[8]
    ) >> 0;
    result.j = decode8(
        &message.payload[9]
    ) >> 0;
    result.backlight = decode8(
        &message.payload[10]
    ) >> 0;
    result.l = decode16(
        &message.payload[11]
    ) >> 0;
    return result;
}
SimnetEventCommandUnknown SimnetEventCommandUnknown::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetEventCommandUnknown result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    result.a = decode16(
        &message.payload[2]
    ) >> 0;
    result.b = decode16(
        &message.payload[4]
    ) >> 0;
    result.c = decode16(
        &message.payload[6]
    ) >> 0;
    result.d = decode16(
        &message.payload[8]
    ) >> 0;
    result.e = decode16(
        &message.payload[10]
    ) >> 0;
    return result;
}
SimnetEventReplyAPCommand SimnetEventReplyAPCommand::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetEventReplyAPCommand result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    result.ap_command = decode8(
        &message.payload[2]
    ) >> 0;
    result.b = decode16(
        &message.payload[3]
    ) >> 0;
    result.controlling_device = decode8(
        &message.payload[5]
    ) >> 0;
    result.event = decode16(
        &message.payload[6]
    ) >> 0;
    result.direction = decode8(
        &message.payload[8]
    ) >> 0;
    result.angle = decode16(
        &message.payload[9]
    ) >> 0;
    result.g = decode8(
        &message.payload[11]
    ) >> 0;
    return result;
}
SimnetAlarmMessage SimnetAlarmMessage::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    SimnetAlarmMessage result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    result.message_id = decode16(
        &message.payload[2]
    ) >> 0;
    result.b = decode8(
        &message.payload[4]
    ) >> 0;
    result.c = decode8(
        &message.payload[5]
    ) >> 0;
    return result;
}
AirmarAdditionalWeatherData AirmarAdditionalWeatherData::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AirmarAdditionalWeatherData result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    result.c = decode8(
        &message.payload[2]
    ) >> 0;
    result.apparent_windchill_temperature = decode16(
        &message.payload[3]
    ) >> 0;
    result.true_windchill_temperature = decode16(
        &message.payload[5]
    ) >> 0;
    result.dewpoint = decode16(
        &message.payload[7]
    ) >> 0;
    return result;
}
AirmarHeaterControl AirmarHeaterControl::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AirmarHeaterControl result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    result.c = decode8(
        &message.payload[2]
    ) >> 0;
    result.plate_temperature = decode16(
        &message.payload[3]
    ) >> 0;
    result.air_temperature = decode16(
        &message.payload[5]
    ) >> 0;
    result.dewpoint = decode16(
        &message.payload[7]
    ) >> 0;
    return result;
}
AirmarPOST AirmarPOST::fromMessage(Message const& message) {
    if (message.pgn != ID) {
        throw std::invalid_argument("unexpected PGN ID");
    }
    else if (message.size != BYTE_LENGTH) {
        throw std::invalid_argument("unexpected payload size");
    }

    AirmarPOST result;

    result.reserved = decode8(
        &message.payload[1]
    ) >> 3;
    result.industry_code = decode8(
        &message.payload[1]
    ) >> 5;
    result.control = decode8(
        &message.payload[2]
    ) >> 0;
    result.reserved1 = decode8(
        &message.payload[2]
    ) >> 4;
    result.test_id = decode8(
        &message.payload[4]
    ) >> 3;
    result.test_result = decode8(
        &message.payload[5]
    ) >> 3;
    return result;
}
