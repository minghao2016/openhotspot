cmake_minimum_required (VERSION 2.6)
project (OpenHotSpot)
set(hotspot src/main.cpp src/hotspot.cpp)
add_executable(hotspot ${PROJECT_SOURCE_DIR}/test.cpp)
