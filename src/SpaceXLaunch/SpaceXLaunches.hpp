//SpaceXLaunches.hpp
#pragma once

#include <iostream>
#include <nlohmann/json.hpp>
#include <map>
#include <memory>
#include <stdlib.h>

using json = nlohmann::json;

namespace SpaceX
{
    struct LaunchData
    {
        int flight_number;
        std::string launch_year;
        std::string launch_date_local;
        LaunchData(int fn, std::string yr, std::string ldl);
    };

    class SpaceXLaunches
    {
    private:
        std::map<std::string, LaunchData *> launchMap;

    public:
        //takes in parsed json data from api call and poplulates a std::map.
        SpaceXLaunches(const json &j);

        //Display stored launch data
        void displayLaunchData();

        //delete heap allocated LaunchData objs
        ~SpaceXLaunches();
    };

    class SpaceXLaunchesSmartPointer
    {
    private:
        std::map<std::string, std::shared_ptr<LaunchData>> launchMapSmart;

    public:
        //takes in parsed json data from api call and poplulates a std::map.
        SpaceXLaunchesSmartPointer(const json &j);

        //Display stored launch data
        void displayLaunchData();
    };
} // namespace SpaceX