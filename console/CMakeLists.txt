cmake_minimum_required(VERSION 3.12)
project(${CMAKE_PROJECT_NAME}.console)

find_package(spdlog CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

#########################################
## Static library (to test functionality)

add_library(${PROJECT_NAME}.internal STATIC
    src/game.cpp
    src/printer.cpp)

target_include_directories(${PROJECT_NAME}.internal
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
    PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_link_libraries(${PROJECT_NAME}.internal PRIVATE
    ${CMAKE_PROJECT_NAME}.common
    ${CMAKE_PROJECT_NAME}.mindmath
    spdlog::spdlog
    fmt::fmt)

## Module tests
add_subdirectory(test)

##########################
## Executor of application

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE
    ${CMAKE_PROJECT_NAME}.common
    ${CMAKE_PROJECT_NAME}.mindmath
    ${PROJECT_NAME}.internal
    spdlog::spdlog
    fmt::fmt)
