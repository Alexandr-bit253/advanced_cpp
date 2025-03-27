include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(ini_parser_test test_ini_parser.cpp)
target_link_libraries(ini_parser_tests PRIVATE ini_parser gtest gtest_main)

include(GoogleTest)
gtest_discover_test(ini_parser_tests)