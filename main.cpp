#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include "SpaceXLaunches.hpp"

const char *UpcomingLaunchesCmd = "curl --location --request GET 'https://api.spacexdata.com/v3/launches/upcoming'";

//perform api call and return results
std::string exec(const char *cmd)
{
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe)
    {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
    {
        result += buffer.data();
    }
    return result;
}

int main()
{
    std::string launch_json = exec(UpcomingLaunchesCmd);
    auto j = json::parse(launch_json);
    //SpaceX::SpaceXLaunches launches(j);
    SpaceX::SpaceXLaunchesSmartPointer launches(j);
    launches.displayLaunchData();
}
