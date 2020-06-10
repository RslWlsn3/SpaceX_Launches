set(THIS SpaceXLaunch_unit_tests)

set(Sources
SpaceXLuanch-unit-tests.cpp
)

include_directories(
    ../src
    ../src/SpaceXLaunch
)

add_executable(${THIS} ${Sources})
target_link_libraries(${THIS} PUBLIC
    gtest_main
    SpaceXLaunch    
)

add_test(
    NAME ${THIS}
    COMMAND ${THIS}
)