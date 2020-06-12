//SpaceXLaunches.hpp
#pragma once

#include <iostream>
#include <nlohmann/json.hpp>
#include <map>
#include <memory>
#include <stdlib.h>

namespace SpaceX
{
    struct LaunchData
    {
        int flight_number;
        std::string launch_year;
        std::string launch_date_local;
        LaunchData(int fn, std::string yr, std::string ldl);
    };

    class SpaceXLauches
    {
    public:
        SpaceXLauches() {}
        virtual ~SpaceXLauches() {}
        virtual void displayLaunchData() const = 0;
    };

    class SpaceXLaunchesOldStyle : public SpaceXLauches
    {
    private:
        std::map<std::string, LaunchData *> launchMap;

    public:
        //takes in parsed json data from api call and poplulates a std::map.
        SpaceXLaunchesOldStyle(const nlohmann::json &j);

        //Display stored launch data
        void displayLaunchData() const;

        //delete heap allocated LaunchData objs
        ~SpaceXLaunchesOldStyle();
    };

    class SpaceXLaunchesSmartPointer : public SpaceXLauches
    {
    private:
        std::map<std::string, std::shared_ptr<LaunchData>> launchMapSmart;

    public:
        //takes in parsed json data from api call and poplulates a std::map.
        SpaceXLaunchesSmartPointer(const nlohmann::json &j);

        //Display stored launch data
        void displayLaunchData() const;
    };
} // namespace SpaceX