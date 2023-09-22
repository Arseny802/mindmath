cmake_minimum_required(VERSION 3.20)

set(CMAKE_INSTALL_MFC_LIBRARIES TRUE)
set(CMAKE_INSTALL_UCRT_LIBRARIES TRUE)
set(CMAKE_INSTALL_OPENMP_LIBRARIES TRUE)
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/bin)

include(InstallRequiredSystemLibraries)

install(
    TARGETS ${CMAKE_PROJECT_NAME}.console
    RUNTIME DESTINATION bin
    COMPONENT ${CMAKE_PROJECT_NAME}.console)
if(CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS)
    install(
        PROGRAMS ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS}
        DESTINATION bin COMPONENT runtime_libraries)
endif(CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS)

set(CPACK_PACKAGE_NAME "${CMAKE_PROJECT_NAME}")
set(CPACK_PACKAGE_VENDOR "${VENDOR}")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${VENDOR} math game")
set(CPACK_NSIS_DISPLAY_NAME "${CMAKE_PROJECT_NAME} ${CPACK_PACKAGE_VERSION}")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/Copyright.txt")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/Copyright.txt")

if (VENDOR)
    set(CPACK_PACKAGE_INSTALL_DIRECTORY "${VENDOR}\\\\${CMAKE_PROJECT_NAME}")
else()
    set(CPACK_PACKAGE_INSTALL_DIRECTORY "${CMAKE_PROJECT_NAME}")
endif(VENDOR)

set(CPACK_NSIS_MODIFY_PATH ON)
set(CPACK_ARCHIVE_COMPONENT_INSTALL ON)
set(CPACK_COMPONENTS_ALL ${CMAKE_PROJECT_NAME}.console runtime_libraries)

set(CPACK_PACKAGE_ICON "${CMAKE_CURRENT_SOURCE_DIR}/resource\\\\icon-math-96.bmp")
set(CPACK_NSIS_MUI_ICON "${CMAKE_CURRENT_SOURCE_DIR}/resource/icon-math-96.ico")
set(CPACK_NSIS_MUI_UNIICON "${CMAKE_CURRENT_SOURCE_DIR}/resource/icon-math-96.ico")
set(CPACK_NSIS_INSTALLED_ICON_NAME "${CMAKE_CURRENT_SOURCE_DIR}/resource/icon-math-96.ico")

set(CPACK_SOURCE_IGNORE_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/.git;"
    "${CMAKE_CURRENT_SOURCE_DIR}/.idea;"
    "${CMAKE_CURRENT_SOURCE_DIR}/bin;"
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake-build-debug;"
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake-build-release;"
    "${CMAKE_CURRENT_SOURCE_DIR}/resource;"
    "${CMAKE_CURRENT_SOURCE_DIR}/CMakeUserPresets.json;")
set(CPACK_INSTALL_CMAKE_PROJECTS "${CMAKE_CURRENT_BINARY_DIR};${CMAKE_PROJECT_NAME};ALL;/")
set(CPACK_PACKAGE_EXECUTABLES "bin/Release/${CMAKE_PROJECT_NAME}.console" "${CMAKE_PROJECT_NAME}.console")

FILE(COPY "${CMAKE_CURRENT_SOURCE_DIR}/docs" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
include(CPack)

cpack_add_component_group("Mindmath" EXPANDED
    DESCRIPTION "Mindmath application representations and modules")
cpack_add_component(
    ${CMAKE_PROJECT_NAME}.console
    DISPLAY_NAME "Console"
    DESCRIPTION "Console view of ${CMAKE_PROJECT_NAME} application."
    GROUP ${CMAKE_PROJECT_NAME})

cpack_add_component(
    runtime_libraries
    DISPLAY_NAME "Runtime Libraries"
    DESCRIPTION
    "Runtime libraries for ${CMAKE_PROJECT_NAME} run on your OS. "
    "Uncheck this if you already installed this libs."
    DEPENDS "${CMAKE_PROJECT_NAME}.console;")
