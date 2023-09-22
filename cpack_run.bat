@echo off

cd bin

echo Packing for Win32
cd Win32
cpack --config CPackConfig.cmake
cpack --config CPackSourceConfig.cmake
cd ..

echo Packing for x64
cd x64
cpack --config CPackConfig.cmake
cpack --config CPackSourceConfig.cmake
cd ..

echo Packing for unix
cd unix
cpack --config CPackConfig.cmake
cpack --config CPackSourceConfig.cmake
cd ..