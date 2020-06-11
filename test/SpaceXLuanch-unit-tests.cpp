#include <gtest/gtest.h>
#include "SpaceXLaunches.hpp"
#include <string>
#include <fstream>

const nlohmann::json jsonTestData = nlohmann::json::object({{"mission_name", "Connor test"},
                                        {"flight_number", 21},
                                        {"launch_year", "2020"},
                                        {"launch_date_local", "1/1/1"}});

bool TestConnection()
{
    const char *cmd = "curl --location --request GET 'https://api.spacexdata.com/v3/launches/upcoming'";
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe)
    {
        return 0;
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
    {
        result += buffer.data();
    }
    if (result.size() == 0)
    {
        return 0;
    }
    return 1;
}

TEST(SpaceXLaunch_unit_tests, connection)
{
    bool connectionWorks = TestConnection();
    ASSERT_TRUE(connectionWorks);
}

TEST(SpaceXLaunch_unit_tests, output)
{
    SpaceX::SpaceXLaunches launches(jsonTestData);
    testing::internal::CaptureStdout();
    launches.displayLaunchData();
    std::string output = testing::internal::GetCapturedStdout();
    std::string expectedOutput = "mission_name: Connor test\n  -  flight_number: 21\n  -  launch_year: 2020\n  -  launch_date_local: 1/1/1\n------------------------------\n";

    ASSERT_EQ(output, expectedOutput);
}

TEST(SpaceXLaunch_unit_tests, outputSmart)
{
    SpaceX::SpaceXLaunchesSmartPointer launches(jsonTestData);
    testing::internal::CaptureStdout();
    launches.displayLaunchData();
    std::string output = testing::internal::GetCapturedStdout();
    std::string expectedOutput = "mission_name: Connor test\n  -  flight_number: 21\n  -  launch_year: 2020\n  -  launch_date_local: 1/1/1\n------------------------------\n";

    ASSERT_EQ(output, expectedOutput);
}