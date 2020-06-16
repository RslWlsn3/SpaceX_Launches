//SpaceXLaunches.hpp
#pragma once

#include <iostream>
#include <nlohmann/json.hpp>
#include <map>
#include <memory>
#include <stdlib.h>

namespace spacex
{
    //Holds all usfull spacex launch data
    struct LaunchData
    {
        int flight_number;
        std::string launch_year;
        std::string launch_date_local;
        LaunchData(int fn, std::string yr, std::string ldl);
    };

    //Base Class
    class SpaceXLauches
    {
    public:
        SpaceXLauches() {}
        virtual ~SpaceXLauches() {}
        template <typename T>

        //Display all launch data stored to console
        void displayLaunchData(const T &t) const;

        virtual void display() const = 0;
    };

    //Utilizes smart pointers for LaunchData objs
    class SpaceXLaunchesSmartPointer : public SpaceXLauches
    {
    private:
        std::map<std::string, std::shared_ptr<LaunchData>> launchMapSmartPointer;
        const nlohmann::json jsonData;

    public:
        //takes in parsed json data from api call and poplulates a std::map.
        SpaceXLaunchesSmartPointer(const nlohmann::json &j);

        //extracts data that it used in displayLaunchData()
        void extractUsefullData();

        //Calls parent class displayLaunchData with map being used
        void display() const;
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

        //Calls parent class displayLaunchData with map being used
        void display() const;

        //delete heap allocated LaunchData objs
        ~SpaceXLaunchesOldStyle();
    };
} // namespace spacex