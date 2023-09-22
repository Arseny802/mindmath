cmake_minimum_required(VERSION 3.5)
project(${CMAKE_PROJECT_NAME}.mindmath.test)

find_package(gtest CONFIG REQUIRED)
enable_testing()

add_executable(${PROJECT_NAME} src/generator.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE
    ${CMAKE_PROJECT_NAME}.common
    ${CMAKE_PROJECT_NAME}.mindmath
    gtest::gtest)

add_test(
    NAME ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    COMMAND ${PROJECT_NAME})