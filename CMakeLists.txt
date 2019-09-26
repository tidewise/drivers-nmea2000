# CMakeLists.txt has to be located in the project folder and cmake has to be
# executed from 'project/build' with 'cmake ../'.
cmake_minimum_required(VERSION 2.6)
find_package(Rock)
# Ruby is used for code generation
include (RockRuby)

rock_init(nmea2000 0.1)
set(CMAKE_CXX_STANDARD 11)
rock_standard_layout()
add_subdirectory(codegen)

