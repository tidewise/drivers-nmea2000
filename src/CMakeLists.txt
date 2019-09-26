add_custom_target(regen-pgns
    COMMAND ${RUBY_EXECUTABLE} -I${PROJECT_SOURCE_DIR}/codegen/lib
            ${PROJECT_SOURCE_DIR}/codegen/codegen
            ${PROJECT_SOURCE_DIR}/pgns.xml
            ${CMAKE_CURRENT_SOURCE_DIR}
)

rock_library(nmea2000
    SOURCES Receiver.cpp Message.cpp PGNLibrary.cpp PGNInfo.cpp PGNs.cpp
            ActisenseDriver.cpp
    HEADERS Receiver.hpp Message.hpp PGNLibrary.hpp PGNInfo.hpp PGNs.hpp
            ActisenseDriver.hpp
    DEPS_PKGCONFIG canbus base-types)

rock_executable(nmea2000_bin Main.cpp
    DEPS nmea2000)

