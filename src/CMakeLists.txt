set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(../json $(CMAKE_CURRENT_SOURCE_DIR))

file(GLOB SPACEX_LIB_SRC
    "SpaceXLaunch/*.cpp"
)

add_library(SpaceXLaunch ${SPACEX_LIB_SRC})

#add_library(
#    SpaceXLaunch
#    #${CMAKE_CURRENT_SOURCE_DIR}/SpaceXlaunch/SpaceXLaunches.hpp
#    ./SpaceXlaunch/SpaceXLaunches.cpp
#)

target_link_libraries(SpaceXLaunch PUBLIC nlohmann_json::nlohmann_json)

target_include_directories(SpaceXLaunch PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}) 