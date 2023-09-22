cmake_minimum_required(VERSION 3.12)
project(${CMAKE_PROJECT_NAME}.common)

find_package(spdlog CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

add_library(${PROJECT_NAME} STATIC
    include/common/operation.h
    include/common/setup.h
    include/common/type.h
    src/setup.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
    PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_link_libraries(${PROJECT_NAME} PRIVATE
    spdlog::spdlog
    fmt::fmt)

## Module tests
add_subdirectory(test)
