add_custom_command(
    COMMAND ${RUBY_EXECUTABLE} -I${PROJECT_SOURCE_DIR}/codegen/lib
            ${PROJECT_SOURCE_DIR}/codegen/codegen
            ${PROJECT_SOURCE_DIR}/pgns.xml
            ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS ${PROJECT_SOURCE_DIR}/pgns.xml
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/PGNs.hpp ${CMAKE_CURRENT_BINARY_DIR}/PGNs.cpp
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

rock_library(nmea2000
    SOURCES Receiver.cpp Message.cpp PGNLibrary.cpp PGNInfo.cpp
            ${CMAKE_CURRENT_BINARY_DIR}/PGNs.cpp
    HEADERS Receiver.hpp Message.hpp PGNLibrary.hpp PGNInfo.hpp
            ${CMAKE_CURRENT_BINARY_DIR}/PGNs.hpp
    DEPS_PKGCONFIG canbus base-types)

rock_executable(nmea2000_bin Main.cpp
    DEPS nmea2000)

