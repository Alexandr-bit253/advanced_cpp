cmake_minimum_required(VERSION 3.24)

file(GLOB TEST_SOURCES "*.cpp")

add_executable(ini_tests ${TEST_SOURCES})

target_link_libraries(ini_tests
    PRIVATE
        ini_parser
        GTest::gtest_main
)

file(COPY test_data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME ini_parser_tests COMMAND ini_tests)

target_include_directories(ini_tests
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)