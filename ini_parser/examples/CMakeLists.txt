add_executable(example example.cpp)

target_link_libraries(example PRIVATE ini_parser)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/example.ini
    ${CMAKE_CURRENT_BINARY_DIR}/example.ini
    COPYONLY
)

install(FILES ${CMAKE_CURRENT_BINARY_DYR}/example.ini DESTINATION examples)