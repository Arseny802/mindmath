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
    ${CMAKE_PROJECT_NAME}.config
    ${CMAKE_PROJECT_NAME}.mindmath
    spdlog::spdlog
    fmt::fmt)

## Module tests
add_subdirectory(test)

##########################
## Executor of application

if ("${CMAKE_GENERATOR_PLATFORM}" STREQUAL "x64")
    set(ICON_OBJECT_FILE "../resource/icon-math-96.o")
elseif("${CMAKE_GENERATOR_PLATFORM}" STREQUAL "Win32")
    set(ICON_OBJECT_FILE "")  #TODO: create icon for x86 platform
endif()

add_executable(${PROJECT_NAME}
    src/main.cpp ${ICON_OBJECT_FILE})
target_link_libraries(${PROJECT_NAME} PRIVATE
    ${CMAKE_PROJECT_NAME}.common
    ${CMAKE_PROJECT_NAME}.mindmath
    ${PROJECT_NAME}.internal
    spdlog::spdlog
    fmt::fmt)
