//SpaceXLaunches.hpp
#pragma once

#include <iostream>
#include <nlohmann/json.hpp>
#include <map>
#include <memory>
#include <stdlib.h>

namespace SpaceX
{
    //Holds all usfull SpaceX launch data
    struct LaunchData
    {
        int flight_number;
        std::string launch_year;
        std::string launch_date_local;
        LaunchData(int fn, std::string yr, std::string ldl);
    };

    //Interface 
    class SpaceXLauches
    {
    public:
        SpaceXLauches() {}
        virtual ~SpaceXLauches() {}
        virtual void displayLaunchData() const = 0;
    };

    //Utilizes new/delete to create LaunchData objs on heap
    class SpaceXLaunchesOldStyle : public SpaceXLauches
    {
    private:
        const nlohmann::json jsonData;
        std::map<std::string, LaunchData *> launchesMap;

    public:
        //takes in parsed json data from api call and poplulates a std::map.
        SpaceXLaunchesOldStyle(const nlohmann::json &j);

        //extracts data that it used in displayLaunchData()
        void extractUsefullData();

        //Display stored launch data
        void displayLaunchData() const;

        //delete heap allocated LaunchData objs
        ~SpaceXLaunchesOldStyle();
    };

    //Utilizes smart pointers for LaunchData objs
    class SpaceXLaunchesSmartPointer : public SpaceXLauches
    {
    private:
        std::map<std::string, std::shared_ptr<LaunchData>> launchMapSmart;
        const nlohmann::json jsonData;

    public:
        //takes in parsed json data from api call and poplulates a std::map.
        SpaceXLaunchesSmartPointer(const nlohmann::json &j);

        //extracts data that it used in displayLaunchData()
        void extractUsefullData();

        //Display stored launch data
        void displayLaunchData() const;
    };
} // namespace SpaceX