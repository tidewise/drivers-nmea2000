rock_library(nmea2000
    SOURCES Receiver.cpp Message.cpp PGNLibrary.cpp PGNInfo.cpp
    HEADERS Receiver.hpp Message.hpp PGNLibrary.hpp PGNInfo.hpp
    DEPS_PKGCONFIG canbus base-types)

rock_executable(nmea2000_bin Main.cpp
    DEPS nmea2000)

