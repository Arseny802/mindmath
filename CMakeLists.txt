cmake_minimum_required(VERSION 3.23)
project(mindmath VERSION 0.0.1)
set(VENDOR "Arseny802")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_GENERATOR_PLATFORM})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_DOC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/docs")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")

add_subdirectory(common)
add_subdirectory(config)
add_subdirectory(console)
add_subdirectory(mindmath)

include(install_and_pack.cmake)
