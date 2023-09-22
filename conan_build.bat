@ECHO OFF

set BASEDIR=%~dp0
PUSHD "%BASEDIR%"
set TOOLCHAIN_FILE=build/generators/conan_toolchain.cmake

set GENERATOR_PLATFORM=x64
set GENERATOR="Visual Studio 17 2022"
set GENERATOR_TOOLSET=v143
set CPP_STANDARD=17

rem Create conan debug info
conan install . --output-folder=cmake-build-debug --build=missing^
 -s build_type=Debug -s compiler.cppstd=%CPP_STANDARD%
cd cmake-build-debug
cmake .. -G %GENERATOR% -DCMAKE_TOOLCHAIN_FILE=%TOOLCHAIN_FILE% -CMAKE_GENERATOR_PLATFORM=%GENERATOR_PLATFORM%^
 -CMAKE_GENERATOR_TOOLSET=%GENERATOR_TOOLSET% -DCMAKE_BUILD_TYPE=Debug
cmake --build . --config Debug
cd ..

rem Create conan release-64 info
conan install . --output-folder=cmake-build-release-%GENERATOR_PLATFORM% --build=missing^
 -s build_type=Release -s compiler.cppstd=%CPP_STANDARD%
cd cmake-build-release-%GENERATOR_PLATFORM%
cmake .. -G %GENERATOR% -DCMAKE_TOOLCHAIN_FILE=%TOOLCHAIN_FILE% -CMAKE_GENERATOR_PLATFORM=%GENERATOR_PLATFORM%^
 -CMAKE_GENERATOR_TOOLSET=%GENERATOR_TOOLSET% -DCMAKE_BUILD_TYPE=Release -A x64
cmake --build . --config Release
cd ..

set GENERATOR_PLATFORM=x86
rem Create conan release-86 info
conan install . --output-folder=cmake-build-release-%GENERATOR_PLATFORM% --build=missing^
 -s build_type=Release -s compiler.cppstd=%CPP_STANDARD% -s arch=x86
cd cmake-build-release-%GENERATOR_PLATFORM%
cmake .. -G %GENERATOR% -DCMAKE_TOOLCHAIN_FILE=%TOOLCHAIN_FILE% -CMAKE_GENERATOR_PLATFORM=%GENERATOR_PLATFORM%^
 -CMAKE_GENERATOR_TOOLSET=%GENERATOR_TOOLSET% -DCMAKE_BUILD_TYPE=Release -A Win32
cmake --build . --config Release
cd ..
