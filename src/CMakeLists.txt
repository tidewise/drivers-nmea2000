rock_library(nmea2000
    SOURCES Dummy.cpp
    HEADERS Dummy.hpp)

rock_executable(nmea2000_bin Main.cpp
    DEPS nmea2000)

