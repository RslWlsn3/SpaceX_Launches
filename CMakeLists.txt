cmake_minimum_required(VERSION 3.0.2)
project(SpaceX CXX)

add_subdirectory(src)

add_executable(SpaceX main.cpp)

target_link_libraries(SpaceX PRIVATE SpaceXLaunch)


