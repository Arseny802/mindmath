@echo off

cd bin
cpack --config CPackConfig.cmake
cpack --config CPackSourceConfig.cmake
