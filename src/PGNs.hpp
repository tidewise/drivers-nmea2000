#ifndef NMEA2000_PGNS_HPP
#define NMEA2000_PGNS_HPP

#include <nmea2000/Message.hpp>

namespace nmea2000 {
    namespace pgns {
        struct ISOAcknowledgement {
            static const int BYTE_LENGTH = 8;
            static const int ID = 59392;

            static ISOAcknowledgement fromMessage(Message const& message);

            uint8_t control;
            uint8_t group_function;
            uint32_t reserved;
            uint32_t pgn;
        };
        struct ISORequest {
            static const int BYTE_LENGTH = 3;
            static const int ID = 59904;

            static ISORequest fromMessage(Message const& message);

            uint32_t pgn;
        };
        struct ISOAddressClaim {
            static const int BYTE_LENGTH = 8;
            static const int ID = 60928;

            static ISOAddressClaim fromMessage(Message const& message);

            uint8_t device_function;
            uint8_t device_class;
            uint8_t industry_group;
            uint8_t iso_self_configurable;
        };
        struct ISOCommandedAddress {
            static const int BYTE_LENGTH = 10;
            static const int ID = 65240;

            static ISOCommandedAddress fromMessage(Message const& message);

            uint16_t manufacturer_code;
            uint8_t device_function;
            uint8_t reserved;
            uint8_t device_class;
            uint8_t industry_code;
            uint8_t iso_self_configurable;
            uint8_t new_source_address;
        };
        struct LowranceTemperature {
            static const int BYTE_LENGTH = 5;
            static const int ID = 65285;

            static LowranceTemperature fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
            uint8_t temperature_source;
            float actual_temperature;
        };
        struct AirmarBootStateRequest {
            static const int BYTE_LENGTH = 2;
            static const int ID = 65286;

            static AirmarBootStateRequest fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
        };
        struct AirmarAccessLevel {
            static const int BYTE_LENGTH = 7;
            static const int ID = 65287;

            static AirmarAccessLevel fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
            uint8_t format_code;
            uint8_t access_level;
            uint8_t reserved1;
            int32_t access_seed_key;
        };
        struct SimnetTrimTabSensorCalibration {
            static const int BYTE_LENGTH = 2;
            static const int ID = 65289;

            static SimnetTrimTabSensorCalibration fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
        };
        struct SimnetPaddleWheelSpeedConfiguration {
            static const int BYTE_LENGTH = 2;
            static const int ID = 65290;

            static SimnetPaddleWheelSpeedConfiguration fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
        };
        struct SimnetClearFluidLevelWarnings {
            static const int BYTE_LENGTH = 2;
            static const int ID = 65292;

            static SimnetClearFluidLevelWarnings fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
        };
        struct SimnetLGC2000Configuration {
            static const int BYTE_LENGTH = 2;
            static const int ID = 65293;

            static SimnetLGC2000Configuration fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
        };
        struct SimnetReprogramStatus {
            static const int BYTE_LENGTH = 2;
            static const int ID = 65325;

            static SimnetReprogramStatus fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
        };
        struct SimnetAutopilotMode {
            static const int BYTE_LENGTH = 2;
            static const int ID = 65341;

            static SimnetAutopilotMode fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
        };
        struct AirmarDepthQualityFactor {
            static const int BYTE_LENGTH = 4;
            static const int ID = 65408;

            static AirmarDepthQualityFactor fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
            uint8_t sid;
            uint8_t depth_quality_factor;
        };
        struct AirmarDeviceInformation {
            static const int BYTE_LENGTH = 8;
            static const int ID = 65410;

            static AirmarDeviceInformation fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
            uint8_t sid;
            float internal_device_temperature;
            float supply_voltage;
            uint8_t reserved1;
        };
        struct SimnetAutopilotMode1 {
            static const int BYTE_LENGTH = 2;
            static const int ID = 65480;

            static SimnetAutopilotMode1 fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
        };
        struct NMEAAcknowledgeGroupFunction {
            static const int BYTE_LENGTH = 7;
            static const int ID = 126208;

            static NMEAAcknowledgeGroupFunction fromMessage(Message const& message);

            int8_t function_code;
            uint32_t pgn;
            uint8_t pgn_error_code;
            uint8_t transmission_interval_priority_error_code;
            uint8_t number_of_commanded_parameters;
            int8_t parameter_error;
        };
        struct MaretronSlaveResponse {
            static const int BYTE_LENGTH = 8;
            static const int ID = 126270;

            static MaretronSlaveResponse fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
            uint16_t product_code;
            uint16_t software_code;
            uint8_t command;
            uint8_t status;
        };
        struct PGNListTransmitAndReceive {
            static const int BYTE_LENGTH = 4;
            static const int ID = 126464;

            static PGNListTransmitAndReceive fromMessage(Message const& message);

            uint8_t function_code;
            uint32_t pgn;
        };
        struct AirmarAddressableMultiFrame {
            static const int BYTE_LENGTH = 3;
            static const int ID = 126720;

            static AirmarAddressableMultiFrame fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
            int8_t proprietary_id;
        };
        struct SystemTime {
            static const int BYTE_LENGTH = 8;
            static const int ID = 126992;

            static SystemTime fromMessage(Message const& message);

            uint8_t sid;
            uint8_t source;
            uint16_t date;
            float time;
        };
        struct Heartbeat {
            static const int BYTE_LENGTH = 8;
            static const int ID = 126993;

            static Heartbeat fromMessage(Message const& message);

            float interval;
            uint8_t status;
        };
        struct ProductInformation {
            static const int BYTE_LENGTH = 134;
            static const int ID = 126996;

            static ProductInformation fromMessage(Message const& message);

            uint16_t nmea_2000_version;
            uint16_t product_code;
            uint8_t certification_level;
            uint8_t load_equivalency;
        };
        struct ConfigurationInformation {
            static const int BYTE_LENGTH = 0;
            static const int ID = 126998;

            static ConfigurationInformation fromMessage(Message const& message);

        };
        struct HeadingTrackControl {
            static const int BYTE_LENGTH = 21;
            static const int ID = 127237;

            static HeadingTrackControl fromMessage(Message const& message);

            uint8_t rudder_limit_exceeded;
            uint8_t off_heading_limit_exceeded;
            uint8_t off_track_limit_exceeded;
            uint8_t override;
            uint8_t steering_mode;
            uint8_t turn_mode;
            uint8_t heading_reference;
            uint8_t reserved;
            uint8_t commanded_rudder_direction;
            float commanded_rudder_angle;
            float heading_to_steer_course_;
            float track;
            float rudder_limit;
            float off_heading_limit;
            float radius_of_turn_order;
            float rate_of_turn_order;
            uint16_t off_track_limit;
            float vessel_heading;
        };
        struct Rudder {
            static const int BYTE_LENGTH = 6;
            static const int ID = 127245;

            static Rudder fromMessage(Message const& message);

            uint8_t direction_order;
            float angle_order;
            float position;
            uint16_t reserved;
        };
        struct VesselHeading {
            static const int BYTE_LENGTH = 8;
            static const int ID = 127250;

            static VesselHeading fromMessage(Message const& message);

            uint8_t sid;
            float heading;
            float deviation;
            float variation;
            uint8_t reference;
            uint8_t reserved;
        };
        struct RateOfTurn {
            static const int BYTE_LENGTH = 5;
            static const int ID = 127251;

            static RateOfTurn fromMessage(Message const& message);

            uint8_t sid;
            float rate;
        };
        struct Attitude {
            static const int BYTE_LENGTH = 7;
            static const int ID = 127257;

            static Attitude fromMessage(Message const& message);

            uint8_t sid;
            float yaw;
            float pitch;
            float roll;
        };
        struct MagneticVariation {
            static const int BYTE_LENGTH = 6;
            static const int ID = 127258;

            static MagneticVariation fromMessage(Message const& message);

            uint8_t sid;
            uint8_t source;
            uint16_t age_of_service;
            float variation;
        };
        struct EngineParametersRapidUpdate {
            static const int BYTE_LENGTH = 8;
            static const int ID = 127488;

            static EngineParametersRapidUpdate fromMessage(Message const& message);

            float engine_speed;
            uint16_t engine_boost_pressure;
            int8_t engine_tilt_trim;
            uint16_t reserved;
        };
        struct EngineParametersDynamic {
            static const int BYTE_LENGTH = 26;
            static const int ID = 127489;

            static EngineParametersDynamic fromMessage(Message const& message);

            uint16_t oil_pressure;
            float oil_temperature;
            float temperature;
            float alternator_potential;
            float fuel_rate;
            uint32_t total_engine_hours;
            uint16_t coolant_pressure;
            uint16_t fuel_pressure;
            uint8_t reserved;
            int16_t discrete_status_1;
            int16_t discrete_status_2;
            int8_t percent_engine_load;
            int8_t percent_engine_torque;
        };
        struct TransmissionParametersDynamic {
            static const int BYTE_LENGTH = 7;
            static const int ID = 127493;

            static TransmissionParametersDynamic fromMessage(Message const& message);

            uint8_t transmission_gear;
            uint8_t reserved;
            uint16_t oil_pressure;
            float oil_temperature;
            int8_t discrete_status_1;
        };
        struct TripParametersVessel {
            static const int BYTE_LENGTH = 14;
            static const int ID = 127496;

            static TripParametersVessel fromMessage(Message const& message);

            float time_to_empty;
            float distance_to_empty;
            uint16_t estimated_fuel_remaining;
            float trip_run_time;
        };
        struct TripParametersEngine {
            static const int BYTE_LENGTH = 9;
            static const int ID = 127497;

            static TripParametersEngine fromMessage(Message const& message);

            uint16_t trip_fuel_used;
            float fuel_rate_average;
            float fuel_rate_economy;
            float instantaneous_fuel_economy;
        };
        struct EngineParametersStatic {
            static const int BYTE_LENGTH = 6;
            static const int ID = 127498;

            static EngineParametersStatic fromMessage(Message const& message);

            uint16_t rated_engine_speed;
            uint8_t vin;
            uint16_t software_id;
        };
        struct BinarySwitchBankStatus {
            static const int BYTE_LENGTH = 2;
            static const int ID = 127501;

            static BinarySwitchBankStatus fromMessage(Message const& message);

            uint8_t indicator;
        };
        struct SwitchBankControl {
            static const int BYTE_LENGTH = 2;
            static const int ID = 127502;

            static SwitchBankControl fromMessage(Message const& message);

            uint8_t switch_state;
        };
        struct ACInputStatus {
            static const int BYTE_LENGTH = 20;
            static const int ID = 127503;

            static ACInputStatus fromMessage(Message const& message);

            uint8_t number_of_lines;
            uint8_t line;
            uint8_t acceptability;
            uint8_t reserved;
            float voltage;
            float current;
            float frequency;
            float breaker_size;
            int32_t real_power;
            int32_t reactive_power;
            float power_factor;
        };
        struct ACOutputStatus {
            static const int BYTE_LENGTH = 20;
            static const int ID = 127504;

            static ACOutputStatus fromMessage(Message const& message);

            uint8_t number_of_lines;
            uint8_t line;
            uint8_t waveform;
            uint8_t reserved;
            float voltage;
            float current;
            float frequency;
            float breaker_size;
            int32_t real_power;
            int32_t reactive_power;
            float power_factor;
        };
        struct FluidLevel {
            static const int BYTE_LENGTH = 8;
            static const int ID = 127505;

            static FluidLevel fromMessage(Message const& message);

            uint8_t type;
            float level;
            float capacity;
            uint8_t reserved;
        };
        struct DCDetailedStatus {
            static const int BYTE_LENGTH = 9;
            static const int ID = 127506;

            static DCDetailedStatus fromMessage(Message const& message);

            uint8_t sid;
            uint8_t dc_type;
            uint8_t state_of_charge;
            uint8_t state_of_health;
            uint16_t time_remaining;
            float ripple_voltage;
        };
        struct ChargerStatus {
            static const int BYTE_LENGTH = 7;
            static const int ID = 127507;

            static ChargerStatus fromMessage(Message const& message);

            uint8_t operating_state;
            uint8_t charge_mode;
            uint8_t charger_enable_disable;
            uint8_t equalization_pending;
            uint8_t reserved;
            uint16_t equalization_time_remaining;
        };
        struct BatteryStatus {
            static const int BYTE_LENGTH = 8;
            static const int ID = 127508;

            static BatteryStatus fromMessage(Message const& message);

            float voltage;
            float current;
            float temperature;
            uint8_t sid;
        };
        struct InverterStatus {
            static const int BYTE_LENGTH = 4;
            static const int ID = 127509;

            static InverterStatus fromMessage(Message const& message);

            uint8_t operating_state;
            uint8_t inverter;
        };
        struct ChargerConfigurationStatus {
            static const int BYTE_LENGTH = 12;
            static const int ID = 127510;

            static ChargerConfigurationStatus fromMessage(Message const& message);

            uint8_t charger_enable_disable;
            uint8_t reserved;
            float charge_current_limit;
            uint8_t charging_algorithm;
            uint8_t charger_mode;
            float estimated_temperature;
            uint8_t equalize_one_time_enable_disable;
            uint8_t over_charge_enable_disable;
            uint16_t equalize_time;
        };
        struct InverterConfigurationStatus {
            static const int BYTE_LENGTH = 8;
            static const int ID = 127511;

            static InverterConfigurationStatus fromMessage(Message const& message);

            uint8_t inverter_enable_disable;
            uint8_t inverter_mode;
            uint8_t load_sense_enable_disable;
            uint8_t load_sense_power_threshold;
            uint8_t load_sense_interval;
        };
        struct AGSConfigurationStatus {
            static const int BYTE_LENGTH = 3;
            static const int ID = 127512;

            static AGSConfigurationStatus fromMessage(Message const& message);

            uint8_t ags_mode;
        };
        struct BatteryConfigurationStatus {
            static const int BYTE_LENGTH = 8;
            static const int ID = 127513;

            static BatteryConfigurationStatus fromMessage(Message const& message);

            uint8_t battery_type;
            uint8_t supports_equalization;
            uint8_t reserved;
            uint8_t nominal_voltage;
            uint8_t chemistry;
            uint16_t capacity;
            uint8_t temperature_coefficient;
            uint8_t peukert_exponent;
            uint8_t charge_efficiency_factor;
        };
        struct AGSStatus {
            static const int BYTE_LENGTH = 6;
            static const int ID = 127514;

            static AGSStatus fromMessage(Message const& message);

            uint8_t ags_operating_state;
            uint8_t generator_state;
            uint8_t generator_on_reason;
            uint8_t generator_off_reason;
        };
        struct Speed {
            static const int BYTE_LENGTH = 6;
            static const int ID = 128259;

            static Speed fromMessage(Message const& message);

            uint8_t sid;
            float speed_water_referenced;
            float speed_ground_referenced;
            uint8_t speed_water_referenced_type;
            uint16_t reserved;
        };
        struct WaterDepth {
            static const int BYTE_LENGTH = 8;
            static const int ID = 128267;

            static WaterDepth fromMessage(Message const& message);

            uint8_t sid;
            float depth;
            float offset;
            float offset1;
        };
        struct DistanceLog {
            static const int BYTE_LENGTH = 14;
            static const int ID = 128275;

            static DistanceLog fromMessage(Message const& message);

            uint16_t date;
            float time;
            uint32_t log;
            uint32_t trip_log;
        };
        struct TrackedTargetData {
            static const int BYTE_LENGTH = 280;
            static const int ID = 128520;

            static TrackedTargetData fromMessage(Message const& message);

            uint8_t sid;
            uint8_t target_id_number;
            uint8_t track_status;
            uint8_t reported_target;
            uint8_t target_acquisition;
            uint8_t bearing_reference;
            uint8_t reserved;
            float bearing;
            float distance;
            float course;
            float speed;
            float cpa;
            float tcpa;
            float utc_of_fix;
        };
        struct PositionRapidUpdate {
            static const int BYTE_LENGTH = 8;
            static const int ID = 129025;

            static PositionRapidUpdate fromMessage(Message const& message);

            float latitude;
            float longitude;
        };
        struct COGSOGRapidUpdate {
            static const int BYTE_LENGTH = 8;
            static const int ID = 129026;

            static COGSOGRapidUpdate fromMessage(Message const& message);

            uint8_t sid;
            uint8_t cog_reference;
            float cog;
            float sog;
        };
        struct PositionDeltaRapidUpdate {
            static const int BYTE_LENGTH = 7;
            static const int ID = 129027;

            static PositionDeltaRapidUpdate fromMessage(Message const& message);

            uint8_t sid;
            uint16_t time_delta;
            uint16_t latitude_delta;
            uint16_t longitude_delta;
        };
        struct AltitudeDeltaRapidUpdate {
            static const int BYTE_LENGTH = 10;
            static const int ID = 129028;

            static AltitudeDeltaRapidUpdate fromMessage(Message const& message);

            uint8_t sid;
            uint16_t time_delta;
            uint8_t gnss_quality;
            uint8_t direction;
            float course_over_ground;
            uint16_t altitude_delta;
        };
        struct GNSSPositionData {
            static const int BYTE_LENGTH = 45;
            static const int ID = 129029;

            static GNSSPositionData fromMessage(Message const& message);

            uint8_t sid;
            uint16_t date;
            float time;
            float latitude;
            float longitude;
            float altitude;
            uint8_t gnss_type;
            uint8_t method;
            uint8_t integrity;
            uint8_t number_of_svs;
            float hdop;
            float pdop;
            float geoidal_separation;
            uint8_t reference_stations;
            uint8_t reference_station_type;
            uint16_t reference_station_id;
            float age_of_dgnss_corrections;
        };
        struct TimeDate {
            static const int BYTE_LENGTH = 8;
            static const int ID = 129033;

            static TimeDate fromMessage(Message const& message);

            uint16_t date;
            float time;
            int16_t local_offset;
        };
        struct AISClassAPositionReport {
            static const int BYTE_LENGTH = 28;
            static const int ID = 129038;

            static AISClassAPositionReport fromMessage(Message const& message);

            uint8_t message_id;
            uint8_t repeat_indicator;
            int32_t user_id;
            float longitude;
            float latitude;
            uint8_t position_accuracy;
            uint8_t raim;
            uint8_t time_stamp;
            float cog;
            float sog;
            uint8_t ais_transceiver_information;
            float heading;
            float rate_of_turn;
            uint8_t nav_status;
            uint8_t reserved_for_regional_applications;
            uint8_t spare;
        };
        struct AISClassBPositionReport {
            static const int BYTE_LENGTH = 26;
            static const int ID = 129039;

            static AISClassBPositionReport fromMessage(Message const& message);

            uint8_t message_id;
            uint8_t repeat_indicator;
            int32_t user_id;
            float longitude;
            float latitude;
            uint8_t position_accuracy;
            uint8_t raim;
            uint8_t time_stamp;
            float cog;
            float sog;
            uint8_t ais_transceiver_information;
            float heading;
            uint8_t regional_application;
            uint8_t regional_application1;
            uint8_t unit_type;
            uint8_t integrated_display;
            uint8_t dsc;
            uint8_t band;
            uint8_t can_handle_msg_22;
            uint8_t ais_mode;
            uint8_t ais_communication_state;
        };
        struct AISClassBExtendedPositionReport {
            static const int BYTE_LENGTH = 54;
            static const int ID = 129040;

            static AISClassBExtendedPositionReport fromMessage(Message const& message);

            uint8_t message_id;
            uint8_t repeat_indicator;
            int32_t user_id;
            float longitude;
            float latitude;
            uint8_t position_accuracy;
            uint8_t ais_raim_flag;
            uint8_t time_stamp;
            float cog;
            float sog;
            uint8_t regional_application;
            uint8_t regional_application1;
            uint8_t type_of_ship;
            float true_heading;
            uint8_t gnss_type;
            float length;
            float beam;
            float position_reference_from_starboard;
            float position_reference_from_bow;
            uint8_t dte;
            uint8_t ais_mode;
            uint8_t ais_transceiver_information;
        };
        struct Datum {
            static const int BYTE_LENGTH = 20;
            static const int ID = 129044;

            static Datum fromMessage(Message const& message);

            float delta_latitude;
            float delta_longitude;
            float delta_altitude;
        };
        struct UserDatum {
            static const int BYTE_LENGTH = 40;
            static const int ID = 129045;

            static UserDatum fromMessage(Message const& message);

            float delta_x;
            float delta_y;
            float delta_z;
            float rotation_in_x;
            float rotation_in_y;
            float rotation_in_z;
            float scale;
            float ellipsoid_semi_major_axis;
            float ellipsoid_flattening_inverse;
        };
        struct CrossTrackError {
            static const int BYTE_LENGTH = 6;
            static const int ID = 129283;

            static CrossTrackError fromMessage(Message const& message);

            uint8_t sid;
            uint8_t xte_mode;
            uint8_t navigation_terminated;
            float xte;
        };
        struct NavigationData {
            static const int BYTE_LENGTH = 34;
            static const int ID = 129284;

            static NavigationData fromMessage(Message const& message);

            uint8_t sid;
            float distance_to_waypoint;
            uint8_t course_bearing_reference;
            uint8_t perpendicular_crossed;
            uint8_t arrival_circle_entered;
            uint8_t calculation_type;
            float eta_time;
            uint16_t eta_date;
            float bearing_origin_to_destination_waypoint;
            float bearing_position_to_destination_waypoint;
            uint32_t origin_waypoint_number;
            uint32_t destination_waypoint_number;
            float destination_latitude;
            float destination_longitude;
            float waypoint_closing_velocity;
        };
        struct NavigationRouteWPInformation {
            static const int BYTE_LENGTH = 530;
            static const int ID = 129285;

            static NavigationRouteWPInformation fromMessage(Message const& message);

            uint16_t start_rpsnumber;
            uint16_t nitems;
            uint16_t database_id;
            uint16_t route_id;
            uint8_t navigation_direction_in_route;
            uint8_t supplementary_route_wp_data_available;
            uint16_t wp_id;
            float wp_latitude;
            float wp_longitude;
        };
        struct SetDriftRapidUpdate {
            static const int BYTE_LENGTH = 6;
            static const int ID = 129291;

            static SetDriftRapidUpdate fromMessage(Message const& message);

            uint8_t sid;
            uint8_t set_reference;
            float set;
            float drift;
        };
        struct NavigationRouteTimeToFromMark {
            static const int BYTE_LENGTH = 10;
            static const int ID = 129301;

            static NavigationRouteTimeToFromMark fromMessage(Message const& message);

            uint8_t sid;
            float time_to_mark;
            uint8_t mark_type;
            uint32_t mark_id;
        };
        struct BearingAndDistanceBetweenTwoMarks {
            static const int BYTE_LENGTH = 17;
            static const int ID = 129302;

            static BearingAndDistanceBetweenTwoMarks fromMessage(Message const& message);

            uint8_t sid;
            uint8_t bearing_reference;
            uint8_t calculation_type;
            float bearing_origin_to_destination;
            float distance;
            uint8_t origin_mark_type;
            uint8_t destination_mark_type;
            uint32_t origin_mark_id;
            uint32_t destination_mark_id;
        };
        struct GNSSControlStatus {
            static const int BYTE_LENGTH = 14;
            static const int ID = 129538;

            static GNSSControlStatus fromMessage(Message const& message);

            uint16_t sv_elevation_mask;
            float pdop_mask;
            float pdop_switch;
            float snr_mask;
            uint8_t gnss_mode_desired_;
            uint8_t dgnss_mode_desired_;
            uint8_t position_velocity_filter;
            uint16_t max_correction_age;
            float antenna_altitude_for_2d_mode;
            uint8_t use_antenna_altitude_for_2d_mode;
        };
        struct GNSSDOPs {
            static const int BYTE_LENGTH = 8;
            static const int ID = 129539;

            static GNSSDOPs fromMessage(Message const& message);

            uint8_t sid;
            uint8_t desired_mode;
            uint8_t actual_mode;
            float hdop;
            float vdop;
            float tdop;
        };
        struct GNSSSatsInView {
            static const int BYTE_LENGTH = 219;
            static const int ID = 129540;

            static GNSSSatsInView fromMessage(Message const& message);

            uint8_t sid;
            uint8_t mode;
            uint8_t sats_in_view;
            uint8_t sat_number;
            float elevation;
            float azimuth;
            float snr;
            uint32_t range_residuals;
            uint8_t status;
            uint8_t sat_number1;
            float elevation1;
            float azimuth1;
            float snr1;
            uint32_t range_residuals1;
            uint8_t status1;
            uint8_t sat_number2;
            float elevation2;
            float azimuth2;
            float snr2;
            uint32_t range_residuals2;
            uint8_t status2;
            uint8_t sat_number3;
            float elevation3;
            float azimuth3;
            float snr3;
            uint32_t range_residuals3;
            uint8_t status3;
            uint8_t sat_number4;
            float elevation4;
            float azimuth4;
            float snr4;
            uint32_t range_residuals4;
            uint8_t status4;
            uint8_t sat_number5;
            float elevation5;
            float azimuth5;
            float snr5;
            uint32_t range_residuals5;
            uint8_t status5;
            uint8_t sat_number6;
            float elevation6;
            float azimuth6;
            float snr6;
            uint32_t range_residuals6;
            uint8_t status6;
            uint8_t sat_number7;
            float elevation7;
            float azimuth7;
            float snr7;
            uint32_t range_residuals7;
            uint8_t status7;
            uint8_t sat_number8;
            float elevation8;
            float azimuth8;
            float snr8;
            uint32_t range_residuals8;
            uint8_t status8;
            uint8_t sat_number9;
            float elevation9;
            float azimuth9;
            float snr9;
            uint32_t range_residuals9;
            uint8_t status9;
            uint8_t sat_number10;
            float elevation10;
            float azimuth10;
            float snr10;
            uint32_t range_residuals10;
            uint8_t status10;
            uint8_t sat_number11;
            float elevation11;
            float azimuth11;
            float snr11;
            uint32_t range_residuals11;
            uint8_t status11;
            uint8_t sat_number12;
            float elevation12;
            float azimuth12;
            float snr12;
            uint32_t range_residuals12;
            uint8_t status12;
            uint8_t sat_number13;
            float elevation13;
            float azimuth13;
            float snr13;
            uint32_t range_residuals13;
            uint8_t status13;
            uint8_t sat_number14;
            float elevation14;
            float azimuth14;
            float snr14;
            uint32_t range_residuals14;
            uint8_t status14;
            uint8_t sat_number15;
            float elevation15;
            float azimuth15;
            float snr15;
            uint32_t range_residuals15;
            uint8_t status15;
            uint8_t sat_number16;
            float elevation16;
            float azimuth16;
            float snr16;
            uint32_t range_residuals16;
            uint8_t status16;
            uint8_t sat_number17;
            float elevation17;
            float azimuth17;
            float snr17;
            uint32_t range_residuals17;
            uint8_t status17;
        };
        struct GPSAlmanacData {
            static const int BYTE_LENGTH = 13;
            static const int ID = 129541;

            static GPSAlmanacData fromMessage(Message const& message);

            uint8_t prn;
            uint8_t gps_week_number;
            uint8_t sv_health_bits;
            uint8_t eccentricity;
            uint8_t almanac_reference_time;
            uint8_t inclination_angle;
            uint8_t right_of_right_ascension;
            uint8_t root_of_semi_major_axis;
            uint8_t argument_of_perigee;
            uint8_t longitude_of_ascension_node;
            uint8_t mean_anomaly;
            uint8_t clock_parameter_1;
            uint8_t clock_parameter_2;
        };
        struct GNSSPseudorangeNoiseStatistics {
            static const int BYTE_LENGTH = 9;
            static const int ID = 129542;

            static GNSSPseudorangeNoiseStatistics fromMessage(Message const& message);

            uint8_t sid;
            uint16_t rms_of_position_uncertainty;
            uint8_t std_of_major_axis;
            uint8_t std_of_minor_axis;
            uint8_t orientation_of_major_axis;
            uint8_t std_of_lat_error;
            uint8_t std_of_lon_error;
            uint8_t std_of_alt_error;
        };
        struct GNSSRAIMOutput {
            static const int BYTE_LENGTH = 9;
            static const int ID = 129545;

            static GNSSRAIMOutput fromMessage(Message const& message);

            uint8_t sid;
            uint8_t integrity_flag;
            uint8_t latitude_expected_error;
            uint8_t longitude_expected_error;
            uint8_t altitude_expected_error;
            uint8_t sv_id_of_most_likely_failed_sat;
            uint8_t probability_of_missed_detection;
            uint8_t estimate_of_pseudorange_bias;
            uint8_t std_deviation_of_bias;
        };
        struct GNSSRAIMSettings {
            static const int BYTE_LENGTH = 4;
            static const int ID = 129546;

            static GNSSRAIMSettings fromMessage(Message const& message);

            uint8_t radial_position_error_maximum_threshold;
            uint8_t probability_of_false_alarm;
            uint8_t probability_of_missed_detection;
            uint8_t pseudorange_residual_filtering_time_constant;
        };
        struct GNSSPseudorangeErrorStatistics {
            static const int BYTE_LENGTH = 9;
            static const int ID = 129547;

            static GNSSPseudorangeErrorStatistics fromMessage(Message const& message);

            uint8_t sid;
            uint16_t rms_std_dev_of_range_inputs;
            uint8_t std_dev_of_major_error_ellipse;
            uint8_t std_dev_of_minor_error_ellipse;
            uint8_t orientation_of_error_ellipse;
            uint8_t std_dev_lat_error;
            uint8_t std_dev_lon_error;
            uint8_t std_dev_alt_error;
        };
        struct DGNSSCorrections {
            static const int BYTE_LENGTH = 13;
            static const int ID = 129549;

            static DGNSSCorrections fromMessage(Message const& message);

            uint8_t sid;
            uint16_t reference_station_id;
            uint16_t reference_station_type;
            uint8_t time_of_corrections;
            uint8_t station_health;
            uint8_t reserved_bits;
            uint8_t satellite_id;
            uint8_t prc;
            uint8_t rrc;
            uint8_t udre;
            uint8_t iod;
        };
        struct GNSSDifferentialCorrectionReceiverInterface {
            static const int BYTE_LENGTH = 6;
            static const int ID = 129550;

            static GNSSDifferentialCorrectionReceiverInterface fromMessage(Message const& message);

            uint8_t channel;
            uint8_t frequency;
            uint8_t serial_interface_bit_rate;
            uint8_t serial_interface_detection_mode;
            uint8_t differential_source;
            uint8_t differential_operation_mode;
        };
        struct GNSSDifferentialCorrectionReceiverSignal {
            static const int BYTE_LENGTH = 14;
            static const int ID = 129551;

            static GNSSDifferentialCorrectionReceiverSignal fromMessage(Message const& message);

            uint8_t sid;
            uint8_t channel;
            uint8_t signal_strength;
            uint8_t signal_snr;
            uint8_t frequency;
            uint8_t station_type;
            uint8_t station_id;
            uint8_t differential_signal_bit_rate;
            uint8_t differential_signal_detection_mode;
            uint8_t used_as_correction_source;
            uint8_t reserved;
            uint8_t differential_source;
            uint8_t time_since_last_sat_differential_sync;
            uint8_t satellite_service_id_no_;
        };
        struct GLONASSAlmanacData {
            static const int BYTE_LENGTH = 13;
            static const int ID = 129556;

            static GLONASSAlmanacData fromMessage(Message const& message);

            uint8_t prn;
            uint8_t na;
            uint8_t cna;
            uint8_t hna;
            uint8_t _epsilon_na;
            uint8_t _deltatna_dot;
            uint8_t _omega_na;
            uint8_t _delta_tna;
            uint8_t tna;
            uint8_t _lambda_na;
            uint8_t _delta_ina;
            uint8_t tca;
            uint8_t tna1;
        };
        struct AISDGNSSBroadcastBinaryMessage {
            static const int BYTE_LENGTH = 19;
            static const int ID = 129792;

            static AISDGNSSBroadcastBinaryMessage fromMessage(Message const& message);

            uint8_t message_id;
            uint8_t repeat_indicator;
            uint8_t source_id;
            uint8_t nmea_2000_reserved;
            uint8_t ais_tranceiver_information;
            uint8_t spare;
            uint8_t longitude;
            uint8_t latitude;
            uint8_t nmea_2000_reserved1;
            uint8_t spare1;
            uint8_t number_of_bits_in_binary_data_field;
        };
        struct AISUTCAndDateReport {
            static const int BYTE_LENGTH = 25;
            static const int ID = 129793;

            static AISUTCAndDateReport fromMessage(Message const& message);

            uint8_t message_id;
            uint8_t repeat_indicator;
            int32_t user_id;
            float longitude;
            float latitude;
            uint8_t position_accuracy;
            uint8_t raim;
            float position_time;
            uint8_t ais_transceiver_information;
            uint16_t position_date;
            uint8_t gnss_type;
        };
        struct AISClassAStaticAndVoyageRelatedData {
            static const int BYTE_LENGTH = 75;
            static const int ID = 129794;

            static AISClassAStaticAndVoyageRelatedData fromMessage(Message const& message);

            uint8_t message_id;
            uint8_t repeat_indicator;
            int32_t user_id;
            int32_t imo_number;
            uint8_t type_of_ship;
            float length;
            float beam;
            float position_reference_from_starboard;
            float position_reference_from_bow;
            uint16_t eta_date;
            float eta_time;
            float draft;
            uint8_t ais_version_indicator;
            uint8_t gnss_type;
            uint8_t dte;
            uint8_t ais_transceiver_information;
        };
        struct AISAddressedBinaryMessage {
            static const int BYTE_LENGTH = 21;
            static const int ID = 129795;

            static AISAddressedBinaryMessage fromMessage(Message const& message);

            uint8_t message_id;
            uint8_t repeat_indicator;
            int32_t source_id;
            uint8_t ais_transceiver_information;
            uint8_t sequence_number;
            int32_t destination_id;
            uint8_t retransmit_flag;
            int16_t number_of_bits_in_binary_data_field;
        };
        struct AISAcknowledge {
            static const int BYTE_LENGTH = 12;
            static const int ID = 129796;

            static AISAcknowledge fromMessage(Message const& message);

            uint8_t message_id;
            uint8_t repeat_indicator;
            uint32_t source_id;
            uint8_t ais_transceiver_information;
            uint32_t destination_id_number1;
        };
        struct AISBinaryBroadcastMessage {
            static const int BYTE_LENGTH = 263;
            static const int ID = 129797;

            static AISBinaryBroadcastMessage fromMessage(Message const& message);

            uint8_t message_id;
            uint8_t repeat_indicator;
            uint32_t source_id;
            uint8_t ais_transceiver_information;
            uint16_t number_of_bits_in_binary_data_field;
        };
        struct AISSARAircraftPositionReport {
            static const int BYTE_LENGTH = 31;
            static const int ID = 129798;

            static AISSARAircraftPositionReport fromMessage(Message const& message);

            uint8_t message_id;
            uint8_t repeat_indicator;
            int32_t user_id;
            float longitude;
            float latitude;
            uint8_t position_accuracy;
            uint8_t raim;
            uint8_t time_stamp;
            float cog;
            float sog;
            uint8_t ais_transceiver_information;
            float altitude;
            uint8_t reserved_for_regional_applications;
            uint8_t dte;
        };
        struct RadioFrequencyModePower {
            static const int BYTE_LENGTH = 12;
            static const int ID = 129799;

            static RadioFrequencyModePower fromMessage(Message const& message);

            float rx_frequency;
            float tx_frequency;
            uint8_t radio_channel;
            uint8_t tx_power;
            uint8_t mode;
            uint8_t channel_bandwidth;
        };
        struct AISUTCDateInquiry {
            static const int BYTE_LENGTH = 10;
            static const int ID = 129800;

            static AISUTCDateInquiry fromMessage(Message const& message);

            uint8_t message_id;
            uint8_t repeat_indicator;
            uint32_t source_id;
            uint8_t ais_transceiver_information;
            uint32_t destination_id;
        };
        struct AISAddressedSafetyRelatedMessage {
            static const int BYTE_LENGTH = 266;
            static const int ID = 129801;

            static AISAddressedSafetyRelatedMessage fromMessage(Message const& message);

            uint8_t message_id;
            uint8_t repeat_indicator;
            uint32_t source_id;
            uint8_t ais_transceiver_information;
            uint8_t sequence_number;
            uint32_t destination_id;
            uint8_t retransmit_flag;
        };
        struct AISSafetyRelatedBroadcastMessage {
            static const int BYTE_LENGTH = 42;
            static const int ID = 129802;

            static AISSafetyRelatedBroadcastMessage fromMessage(Message const& message);

            uint8_t message_id;
            uint8_t repeat_indicator;
            uint8_t ais_transceiver_information;
        };
        struct AISInterrogation {
            static const int BYTE_LENGTH = 16;
            static const int ID = 129803;

            static AISInterrogation fromMessage(Message const& message);

            uint8_t message_id;
            uint8_t repeat_indicator;
            uint8_t ais_transceiver_information;
            int8_t message_id_a;
            int8_t message_id_b;
        };
        struct AISAssignmentModeCommand {
            static const int BYTE_LENGTH = 14;
            static const int ID = 129804;

            static AISAssignmentModeCommand fromMessage(Message const& message);

            uint8_t message_id;
            uint8_t repeat_indicator;
            int32_t source_id;
            uint8_t ais_transceiver_information;
            int32_t destination_id;
            int16_t offset;
            int16_t increment;
        };
        struct AISDataLinkManagementMessage {
            static const int BYTE_LENGTH = 11;
            static const int ID = 129805;

            static AISDataLinkManagementMessage fromMessage(Message const& message);

            uint8_t message_id;
            uint8_t repeat_indicator;
            uint8_t ais_transceiver_information;
        };
        struct AISChannelManagement {
            static const int BYTE_LENGTH = 30;
            static const int ID = 129806;

            static AISChannelManagement fromMessage(Message const& message);

            uint8_t message_id;
            uint8_t repeat_indicator;
            uint8_t ais_transceiver_information;
            uint8_t channel_a;
            uint8_t channel_b;
            uint8_t power;
            int8_t tx_rx_mode;
            float north_east_longitude_corner_1;
            float north_east_latitude_corner_1;
            float south_west_longitude_corner_1;
            float south_west_latitude_corner_2;
            uint8_t addressed_or_broadcast_message_indicator;
            uint8_t transitional_zone_size;
        };
        struct AISClassBGroupAssignment {
            static const int BYTE_LENGTH = 29;
            static const int ID = 129807;

            static AISClassBGroupAssignment fromMessage(Message const& message);

            uint8_t message_id;
            uint8_t repeat_indicator;
            float north_east_longitude_corner_1;
            float north_east_latitude_corner_1;
            float south_west_longitude_corner_1;
            float south_west_latitude_corner_2;
            uint8_t station_type;
            uint8_t ship_and_cargo_filter;
            uint16_t reporting_interval;
            uint16_t quiet_time;
        };
        struct DSCCallInformation {
            static const int BYTE_LENGTH = 37;
            static const int ID = 129808;

            static DSCCallInformation fromMessage(Message const& message);

            uint8_t dsc_format_symbol;
            uint8_t dsc_category_symbol;
            uint8_t dsc_message_address;
            uint8_t nature_of_distress_or_1st_telecommand;
            uint8_t subsequent_communication_mode_or_2nd_telecommand;
            uint8_t proposed_rx_frequency_channel;
            uint8_t proposed_tx_frequency_channel;
            uint8_t telephone_number;
            float latitude_of_vessel_reported;
            float longitude_of_vessel_reported;
            float time_of_position;
            int32_t user_id_of_ship_in_distress;
            uint8_t dsc_eos_symbol;
            uint8_t expansion_enabled;
            uint8_t calling_rx_frequency_channel;
            uint8_t calling_tx_frequency_channel;
            float time_of_receipt;
            uint16_t date_of_receipt;
            uint8_t dsc_equipment_assigned_message_id;
            uint8_t dsc_expansion_field_symbol;
            uint8_t dsc_expansion_field_data;
        };
        struct AISClassBStaticDataMsg24PartA {
            static const int BYTE_LENGTH = 25;
            static const int ID = 129809;

            static AISClassBStaticDataMsg24PartA fromMessage(Message const& message);

            uint8_t message_id;
            uint8_t repeat_indicator;
            int32_t user_id;
        };
        struct AISClassBStaticDataMsg24PartB {
            static const int BYTE_LENGTH = 33;
            static const int ID = 129810;

            static AISClassBStaticDataMsg24PartB fromMessage(Message const& message);

            uint8_t message_id;
            uint8_t repeat_indicator;
            int32_t user_id;
            uint8_t type_of_ship;
            float length;
            float beam;
            float position_reference_from_starboard;
            float position_reference_from_bow;
            int32_t mothership_user_id;
        };
        struct RouteAndWPServiceDatabaseList {
            static const int BYTE_LENGTH = 25;
            static const int ID = 130064;

            static RouteAndWPServiceDatabaseList fromMessage(Message const& message);

            uint8_t start_database_id;
            uint8_t nitems;
            uint8_t number_of_databases_available;
            uint8_t database_id;
            float database_timestamp;
            uint16_t database_datestamp;
            uint8_t wp_position_resolution;
            uint16_t number_of_routes_in_database;
            uint16_t number_of_wps_in_database;
            uint16_t number_of_bytes_in_database;
        };
        struct RouteAndWPServiceRouteList {
            static const int BYTE_LENGTH = 14;
            static const int ID = 130065;

            static RouteAndWPServiceRouteList fromMessage(Message const& message);

            uint8_t start_route_id;
            uint8_t nitems;
            uint8_t number_of_routes_in_database;
            uint8_t database_id;
            uint8_t route_id;
            uint8_t wp_identification_method;
            uint8_t route_status;
        };
        struct RouteAndWPServiceRouteWPListAttributes {
            static const int BYTE_LENGTH = 23;
            static const int ID = 130066;

            static RouteAndWPServiceRouteWPListAttributes fromMessage(Message const& message);

            uint8_t database_id;
            uint8_t route_id;
            float route_wp_list_timestamp;
            uint16_t route_wp_list_datestamp;
            uint8_t change_at_last_timestamp;
            uint16_t number_of_wps_in_the_route_wp_list;
            uint8_t critical_supplementary_parameters;
            uint8_t navigation_method;
            uint8_t wp_identification_method;
            uint8_t route_status;
            uint16_t xte_limit_for_the_route;
        };
        struct RouteAndWPServiceRouteWPNamePosition {
            static const int BYTE_LENGTH = 23;
            static const int ID = 130067;

            static RouteAndWPServiceRouteWPNamePosition fromMessage(Message const& message);

            uint8_t start_rpsnumber;
            uint8_t nitems;
            uint16_t number_of_wps_in_the_route_wp_list;
            uint8_t database_id;
            uint8_t route_id;
            uint8_t wp_id;
            float wp_latitude;
            float wp_longitude;
        };
        struct RouteAndWPServiceRouteWPName {
            static const int BYTE_LENGTH = 15;
            static const int ID = 130068;

            static RouteAndWPServiceRouteWPName fromMessage(Message const& message);

            uint8_t start_rpsnumber;
            uint8_t nitems;
            uint16_t number_of_wps_in_the_route_wp_list;
            uint8_t database_id;
            uint8_t route_id;
            uint8_t wp_id;
        };
        struct RouteAndWPServiceXTELimitNavigationMethod {
            static const int BYTE_LENGTH = 10;
            static const int ID = 130069;

            static RouteAndWPServiceXTELimitNavigationMethod fromMessage(Message const& message);

            uint8_t start_rpsnumber;
            uint8_t nitems;
            uint16_t number_of_wps_with_a_specific_xte_limit_or_nav_method;
            uint8_t database_id;
            uint8_t route_id;
            uint8_t rpsnumber;
            uint16_t xte_limit_in_the_leg_after_wp;
            uint8_t nav_method_in_the_leg_after_wp;
        };
        struct RouteAndWPServiceWPComment {
            static const int BYTE_LENGTH = 15;
            static const int ID = 130070;

            static RouteAndWPServiceWPComment fromMessage(Message const& message);

            uint8_t start_id;
            uint8_t nitems;
            uint16_t number_of_wps_with_comments;
            uint8_t database_id;
            uint8_t route_id;
            uint8_t wp_id_rpsnumber;
        };
        struct RouteAndWPServiceRouteComment {
            static const int BYTE_LENGTH = 14;
            static const int ID = 130071;

            static RouteAndWPServiceRouteComment fromMessage(Message const& message);

            uint8_t start_route_id;
            uint8_t nitems;
            uint16_t number_of_routes_with_comments;
            uint8_t database_id;
            uint8_t route_id;
        };
        struct RouteAndWPServiceDatabaseComment {
            static const int BYTE_LENGTH = 13;
            static const int ID = 130072;

            static RouteAndWPServiceDatabaseComment fromMessage(Message const& message);

            uint8_t start_database_id;
            uint8_t nitems;
            uint16_t number_of_databases_with_comments;
            uint8_t database_id;
        };
        struct RouteAndWPServiceRadiusOfTurn {
            static const int BYTE_LENGTH = 9;
            static const int ID = 130073;

            static RouteAndWPServiceRadiusOfTurn fromMessage(Message const& message);

            uint8_t start_rpsnumber;
            uint8_t nitems;
            uint16_t number_of_wps_with_a_specific_radius_of_turn;
            uint8_t database_id;
            uint8_t route_id;
            uint8_t rpsnumber;
            uint16_t radius_of_turn;
        };
        struct RouteAndWPServiceWPListWPNamePosition {
            static const int BYTE_LENGTH = 23;
            static const int ID = 130074;

            static RouteAndWPServiceWPListWPNamePosition fromMessage(Message const& message);

            uint8_t start_wp_id;
            uint8_t nitems;
            uint16_t number_of_valid_wps_in_the_wp_list;
            uint8_t database_id;
            uint8_t reserved;
            uint8_t wp_id;
            float wp_latitude;
            float wp_longitude;
        };
        struct WindData {
            static const int BYTE_LENGTH = 6;
            static const int ID = 130306;

            static WindData fromMessage(Message const& message);

            uint8_t sid;
            float wind_speed;
            float wind_angle;
            uint8_t reference;
            uint32_t reserved;
        };
        struct EnvironmentalParameters {
            static const int BYTE_LENGTH = 7;
            static const int ID = 130310;

            static EnvironmentalParameters fromMessage(Message const& message);

            uint8_t sid;
            float water_temperature;
            float outside_ambient_air_temperature;
            uint16_t atmospheric_pressure;
            uint8_t reserved;
        };
        struct EnvironmentalParameters1 {
            static const int BYTE_LENGTH = 8;
            static const int ID = 130311;

            static EnvironmentalParameters1 fromMessage(Message const& message);

            uint8_t sid;
            uint8_t temperature_instance;
            uint8_t humidity_instance;
            float temperature;
            float humidity;
            uint16_t atmospheric_pressure;
        };
        struct Temperature {
            static const int BYTE_LENGTH = 8;
            static const int ID = 130312;

            static Temperature fromMessage(Message const& message);

            uint8_t sid;
            uint8_t temperature_source;
            float actual_temperature;
            float set_temperature;
            uint8_t reserved;
        };
        struct Humidity {
            static const int BYTE_LENGTH = 8;
            static const int ID = 130313;

            static Humidity fromMessage(Message const& message);

            uint8_t sid;
            uint8_t humidity_source;
            uint16_t actual_humidity;
            uint16_t set_humidity;
            uint8_t reserved;
        };
        struct ActualPressure {
            static const int BYTE_LENGTH = 8;
            static const int ID = 130314;

            static ActualPressure fromMessage(Message const& message);

            uint8_t sid;
            uint8_t pressure_source;
            float pressure;
        };
        struct SetPressure {
            static const int BYTE_LENGTH = 8;
            static const int ID = 130315;

            static SetPressure fromMessage(Message const& message);

            uint8_t sid;
            uint8_t pressure_source;
            uint32_t set_pressure;
        };
        struct TemperatureExtendedRange {
            static const int BYTE_LENGTH = 8;
            static const int ID = 130316;

            static TemperatureExtendedRange fromMessage(Message const& message);

            uint8_t sid;
            uint8_t temperature_source;
            float actual_temperature;
            float set_temperature;
        };
        struct TideStationData {
            static const int BYTE_LENGTH = 23;
            static const int ID = 130320;

            static TideStationData fromMessage(Message const& message);

            uint8_t mode;
            uint8_t tide_tendency;
            uint16_t measurement_date;
            float measurement_time;
            float station_latitude;
            float station_longitude;
            float tide_level;
            float tide_level_standard_deviation;
        };
        struct SalinityStationData {
            static const int BYTE_LENGTH = 25;
            static const int ID = 130321;

            static SalinityStationData fromMessage(Message const& message);

            uint8_t mode;
            uint16_t measurement_date;
            float measurement_time;
            float station_latitude;
            float station_longitude;
            float salinity;
            float water_temperature;
        };
        struct CurrentStationData {
            static const int BYTE_LENGTH = 29;
            static const int ID = 130322;

            static CurrentStationData fromMessage(Message const& message);

            uint8_t mode;
            uint16_t measurement_date;
            float measurement_time;
            float station_latitude;
            float station_longitude;
            float measurement_depth;
            float current_speed;
            float current_flow_direction;
            float water_temperature;
        };
        struct MeteorologicalStationData {
            static const int BYTE_LENGTH = 30;
            static const int ID = 130323;

            static MeteorologicalStationData fromMessage(Message const& message);

            uint8_t mode;
            uint16_t measurement_date;
            float measurement_time;
            float station_latitude;
            float station_longitude;
            float wind_speed;
            float wind_direction;
            uint8_t wind_reference;
            float wind_gusts;
            uint16_t atmospheric_pressure;
            float ambient_temperature;
        };
        struct MooredBuoyStationData {
            static const int BYTE_LENGTH = 42;
            static const int ID = 130324;

            static MooredBuoyStationData fromMessage(Message const& message);

            uint8_t mode;
            uint16_t measurement_date;
            float measurement_time;
            float station_latitude;
            float station_longitude;
            float wind_speed;
            float wind_direction;
            uint8_t wind_reference;
            float wind_gusts;
            uint16_t wave_height;
            uint16_t dominant_wave_period;
            uint16_t atmospheric_pressure;
            uint16_t pressure_tendency_rate;
            float air_temperature;
            float water_temperature;
        };
        struct SmallCraftStatus {
            static const int BYTE_LENGTH = 2;
            static const int ID = 130576;

            static SmallCraftStatus fromMessage(Message const& message);

            uint8_t port_trim_tab;
            uint8_t starboard_trim_tab;
        };
        struct DirectionData {
            static const int BYTE_LENGTH = 14;
            static const int ID = 130577;

            static DirectionData fromMessage(Message const& message);

            uint8_t data_mode;
            uint8_t cog_reference;
            uint8_t sid;
            float cog;
            float sog;
            float heading;
            float speed_through_water;
            float set;
            float drift;
        };
        struct VesselSpeedComponents {
            static const int BYTE_LENGTH = 12;
            static const int ID = 130578;

            static VesselSpeedComponents fromMessage(Message const& message);

            float longitudinal_speed_water_referenced;
            float transverse_speed_water_referenced;
            float longitudinal_speed_ground_referenced;
            float transverse_speed_ground_referenced;
            float stern_speed_water_referenced;
            float stern_speed_ground_referenced;
        };
        struct SimradTextMessage {
            static const int BYTE_LENGTH = 42;
            static const int ID = 130816;

            static SimradTextMessage fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
            int16_t product_code;
            uint8_t a;
            uint8_t b;
            uint8_t c;
            uint8_t d;
            uint8_t sid;
            uint8_t prio;
        };
        struct NavicoProductInformation {
            static const int BYTE_LENGTH = 113;
            static const int ID = 130817;

            static NavicoProductInformation fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
            int16_t product_code;
            uint8_t a;
            uint8_t b;
            uint8_t c;
        };
        struct SimnetReprogramData {
            static const int BYTE_LENGTH = 261;
            static const int ID = 130818;

            static SimnetReprogramData fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
            int16_t version;
            int16_t sequence;
        };
        struct SimnetRequestReprogram {
            static const int BYTE_LENGTH = 2;
            static const int ID = 130819;

            static SimnetRequestReprogram fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
        };
        struct SimnetReprogramStatus1 {
            static const int BYTE_LENGTH = 7;
            static const int ID = 130820;

            static SimnetReprogramStatus1 fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
            uint8_t reserved1;
            uint8_t status;
            uint32_t reserved2;
        };
        struct LowranceUnknown {
            static const int BYTE_LENGTH = 10;
            static const int ID = 130827;

            static LowranceUnknown fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
            uint8_t a;
            uint8_t b;
            uint8_t c;
            uint8_t d;
            uint16_t e;
            uint16_t f;
        };
        struct SimnetSetSerialNumber {
            static const int BYTE_LENGTH = 2;
            static const int ID = 130828;

            static SimnetSetSerialNumber fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
        };
        struct SuzukiEngineAndStorageDeviceConfig {
            static const int BYTE_LENGTH = 2;
            static const int ID = 130831;

            static SuzukiEngineAndStorageDeviceConfig fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
        };
        struct SimnetFuelUsedHighResolution {
            static const int BYTE_LENGTH = 2;
            static const int ID = 130832;

            static SimnetFuelUsedHighResolution fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
        };
        struct SimnetEngineAndTankConfiguration {
            static const int BYTE_LENGTH = 2;
            static const int ID = 130834;

            static SimnetEngineAndTankConfiguration fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
        };
        struct SimnetSetEngineAndTankConfiguration {
            static const int BYTE_LENGTH = 2;
            static const int ID = 130835;

            static SimnetSetEngineAndTankConfiguration fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
        };
        struct SimnetFluidLevelSensorConfiguration {
            static const int BYTE_LENGTH = 14;
            static const int ID = 130836;

            static SimnetFluidLevelSensorConfiguration fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
            uint8_t c;
            int8_t device;
            uint8_t f;
            uint8_t tank_type;
            float capacity;
            uint8_t g;
            uint16_t h;
            uint8_t i;
        };
        struct SimnetFuelFlowTurbineConfiguration {
            static const int BYTE_LENGTH = 2;
            static const int ID = 130837;

            static SimnetFuelFlowTurbineConfiguration fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
        };
        struct SimnetFluidLevelWarning {
            static const int BYTE_LENGTH = 2;
            static const int ID = 130838;

            static SimnetFluidLevelWarning fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
        };
        struct SimnetPressureSensorConfiguration {
            static const int BYTE_LENGTH = 2;
            static const int ID = 130839;

            static SimnetPressureSensorConfiguration fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
        };
        struct SimnetDataUserGroupConfiguration {
            static const int BYTE_LENGTH = 2;
            static const int ID = 130840;

            static SimnetDataUserGroupConfiguration fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
        };
        struct SimnetAISClassBStaticDataMsg24PartA {
            static const int BYTE_LENGTH = 29;
            static const int ID = 130842;

            static SimnetAISClassBStaticDataMsg24PartA fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
            uint8_t message_id;
            uint8_t repeat_indicator;
            uint8_t d;
            uint8_t e;
            int32_t user_id;
        };
        struct SimnetSonarStatusFrequencyAndDSPVoltage {
            static const int BYTE_LENGTH = 2;
            static const int ID = 130843;

            static SimnetSonarStatusFrequencyAndDSPVoltage fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
        };
        struct SimnetParameterHandle {
            static const int BYTE_LENGTH = 13;
            static const int ID = 130845;

            static SimnetParameterHandle fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
            uint8_t message_id;
            uint8_t repeat_indicator;
            uint8_t d;
            uint8_t group;
            uint8_t f;
            uint8_t g;
            uint8_t h;
            uint8_t i;
            uint8_t j;
            uint8_t backlight;
            uint16_t l;
        };
        struct SimnetEventCommandUnknown {
            static const int BYTE_LENGTH = 12;
            static const int ID = 130850;

            static SimnetEventCommandUnknown fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
            uint16_t a;
            uint16_t b;
            uint16_t c;
            uint16_t d;
            uint16_t e;
        };
        struct SimnetEventReplyAPCommand {
            static const int BYTE_LENGTH = 12;
            static const int ID = 130851;

            static SimnetEventReplyAPCommand fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
            uint8_t ap_command;
            uint16_t b;
            uint8_t controlling_device;
            uint16_t event;
            uint8_t direction;
            float angle;
            uint8_t g;
        };
        struct SimnetAlarmMessage {
            static const int BYTE_LENGTH = 261;
            static const int ID = 130856;

            static SimnetAlarmMessage fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
            uint16_t message_id;
            uint8_t b;
            uint8_t c;
        };
        struct AirmarAdditionalWeatherData {
            static const int BYTE_LENGTH = 9;
            static const int ID = 130880;

            static AirmarAdditionalWeatherData fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
            uint8_t c;
            float apparent_windchill_temperature;
            float true_windchill_temperature;
            float dewpoint;
        };
        struct AirmarHeaterControl {
            static const int BYTE_LENGTH = 9;
            static const int ID = 130881;

            static AirmarHeaterControl fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
            uint8_t c;
            float plate_temperature;
            float air_temperature;
            float dewpoint;
        };
        struct AirmarPOST {
            static const int BYTE_LENGTH = 7;
            static const int ID = 130944;

            static AirmarPOST fromMessage(Message const& message);

            uint8_t reserved;
            uint8_t industry_code;
            uint8_t control;
            uint8_t reserved1;
            uint8_t test_id;
            uint8_t test_result;
        };
    }
}

#endif
