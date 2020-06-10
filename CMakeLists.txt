cmake_minimum_required(VERSION 3.2.2)
project(SpaceX CXX)

enable_testing()

add_subdirectory(src)
add_subdirectory(googletest)

include_directories(
    src
    src/SpaceXLaunch
)

add_executable(SpaceX main.cpp)

target_link_libraries(SpaceX PRIVATE SpaceXLaunch)

add_subdirectory(test)