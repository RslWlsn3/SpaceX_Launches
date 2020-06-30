//SpaceXLaunches.hpp
#pragma once

#include <iostream>
#include <nlohmann/json.hpp>
#include <map>
#include <memory>
#include <stdlib.h>
#include <typeinfo>

namespace spacex
{
    //Holds all usfull spacex launch data
    struct LaunchData //private stucture in class? -put in SpaceXLauches
    {
        int flight_number;
        std::string launch_year;
        std::string launch_date_local;
        LaunchData(int flightNum, std::string launchYear, std::string launchDateLocal); 
    };

    //Base Class
    class SpaceXLauches
    {
    public:        
        virtual ~SpaceXLauches() {} 
        template <typename T>

        //Display all launch data stored to console, works with map containing smart pointer or normal pointer 
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

        //extracts data that is used in displayLaunchData()
        void extractUsefullData();

        //Calls parent class displayLaunchData with map being used
        void display() const override;
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

        //extracts data that is used in displayLaunchData()
        void extractUsefullData();

        //Calls parent class displayLaunchData with map being used
        void display() const override;

        //delete heap allocated LaunchData objs
        ~SpaceXLaunchesOldStyle();
    };
} // namespace spacex