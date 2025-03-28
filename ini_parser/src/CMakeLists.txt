add_library(ini_parser STATIC
    IniParser.cpp
    Exceptions.cpp
    StdFileReader.cpp
)

target_include_directories(ini_parser
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(ini_parser PUBLIC cxx_std_23)

if(MSVC)
    target_compile_options(ini_parser PRIVATE /utf-8 /W4 /WX)
    add_compile_options(/source-charset:utf-8 /execution-charset:utf-8)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8 /EHsc /W4")
else()
    target_compile_options(ini_parser PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()