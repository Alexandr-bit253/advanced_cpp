cmake_minimum_required(VERSION 3.16)
project(IniParser)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_library(ini_parser
    src/IniParser.cpp
    src/IniFileReader.cpp
    src/IniSyntaxValidator.cpp
)

target_include_directories(ini_parser PUBLIC include)

add_executable(ini_parser_main src/main.cpp)
target_link_libraries(ini_parser_main ini_parser)

add_subdirectory(tests)