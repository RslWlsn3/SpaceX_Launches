cmake_minimum_required(VERSION 3.7.2)
project(SpaceX CXX)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(json)

add_executable(SpaceX main.cpp)

target_link_libraries(SpaceX PRIVATE nlohmann_json::nlohmann_json)

