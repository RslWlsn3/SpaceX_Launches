//SpaceXLaunches.cpp

#include "SpaceXLaunches.hpp"

namespace spacex
{
    LaunchData::LaunchData(int flightNum, std::string launchYear, std::string launchDateLocal) : flight_number(flightNum), launch_year(launchYear), launch_date_local(launchDateLocal)
    {
    }

/////////////////SpaceXLauches/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <typename T>
    void SpaceXLauches::displayLaunchData(const T &launchMap) const 
    {   
        for (const auto &iter : launchMap) 
        {            
            std::cout << "mission_name: " << iter.first << std::endl;
            auto launchData = iter.second; 
            std::cout << "  -  flight_number: " << launchData->flight_number << std::endl;
            std::cout << "  -  launch_year: " << launchData->launch_year << std::endl;
            std::cout << "  -  launch_date_local: " << launchData->launch_date_local << std::endl;
            std::cout << "------------------------------\n";
        }
    }

/////////////////SpaceXLaunchesSmartPointer/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    SpaceXLaunchesSmartPointer::SpaceXLaunchesSmartPointer(const nlohmann::json &jsn) : jsonData(jsn)
    {
        extractUsefullData();
    }

    void SpaceXLaunchesSmartPointer::extractUsefullData()
    {
        if (jsonData.is_array())
        {
            for (auto &element : jsonData)
            {
                std::shared_ptr<LaunchData> ld = std::make_shared<LaunchData>(element["flight_number"], element["launch_year"], element["launch_date_local"]); 
                launchMapSmartPointer[element["mission_name"]] = ld;
            }
        }
        else if (jsonData.is_object())
        {
            std::shared_ptr<LaunchData> ld = std::make_shared<LaunchData>(jsonData.at("flight_number"), jsonData.at("launch_year"), jsonData.at("launch_date_local"));
            launchMapSmartPointer[jsonData.at("mission_name")] = ld;
        }
        else
        {
            std::cout << "Error: json data must be an array or object\n";
            exit(EXIT_FAILURE);
        }
    }

    void SpaceXLaunchesSmartPointer::display() const
    {
        SpaceXLauches::displayLaunchData(launchMapSmartPointer);
    }

/////////////////SpaceXLaunchesOldStyle/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    SpaceXLaunchesOldStyle::SpaceXLaunchesOldStyle(const nlohmann::json &jsn) : jsonData(jsn)
    {
        extractUsefullData();
    }

    void SpaceXLaunchesOldStyle::extractUsefullData()
    {
        if (jsonData.is_array())
        {
            for (auto &element : jsonData)
            {
                LaunchData *ld = new LaunchData(element["flight_number"], element["launch_year"], element["launch_date_local"]);
                launchesMap[element["mission_name"]] = ld;
            }
        }
        else if (jsonData.is_object())
        {
            LaunchData *ld = new LaunchData(jsonData.at("flight_number"), jsonData.at("launch_year"), jsonData.at("launch_date_local"));
            launchesMap[jsonData.at("mission_name")] = ld;
        }
        else
        {
            std::cout << "Error: json data must be an array or object\n";
            exit(EXIT_FAILURE);
        }
    }

    void SpaceXLaunchesOldStyle::display() const
    {
        SpaceXLauches::displayLaunchData(launchesMap);
    }

    SpaceXLaunchesOldStyle::~SpaceXLaunchesOldStyle()
    {
        for (std::map<std::string, LaunchData *>::iterator iter = launchesMap.begin(); iter != launchesMap.end(); iter++)
        {
            LaunchData *ld = iter->second;
            delete ld;
        }
    }
} // namespace spacex