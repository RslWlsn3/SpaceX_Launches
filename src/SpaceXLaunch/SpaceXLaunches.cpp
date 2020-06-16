//SpaceXLaunches.cpp

#include "SpaceXLaunches.hpp"

namespace SpaceX
{
    LaunchData::LaunchData(int fn, std::string yr, std::string ldl) : flight_number(fn), launch_year(yr), launch_date_local(ldl)
    {
    }

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
                launchMapSmart[element["mission_name"]] = ld;
            }
        }
        else if (jsonData.is_object())
        {
            std::shared_ptr<LaunchData> ld = std::make_shared<LaunchData>(jsonData.at("flight_number"), jsonData.at("launch_year"), jsonData.at("launch_date_local"));
            launchMapSmart[jsonData.at("mission_name")] = ld;
        }
        else
        {
            std::cout << "Error: json data must be an array or object\n";
            exit(EXIT_FAILURE);
        }
    }
    
    void SpaceXLaunchesSmartPointer::displayLaunchData() const
    {
        for (const auto &iter : launchMapSmart)
        {
            std::cout << "mission_name: " << iter.first << std::endl;
            const std::shared_ptr<SpaceX::LaunchData> ld = iter.second;
            std::cout << "  -  flight_number: " << ld->flight_number << std::endl;
            std::cout << "  -  launch_year: " << ld->launch_year << std::endl;
            std::cout << "  -  launch_date_local: " << ld->launch_date_local << std::endl;
            std::cout << "------------------------------\n";
        }
    }
    
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
  
    void SpaceXLaunchesOldStyle::displayLaunchData() const
    {
        for (const auto &iter : launchesMap)
        {
            std::cout << "mission_name: " << iter.first << std::endl;
            LaunchData *ld = iter.second;
            std::cout << "  -  flight_number: " << ld->flight_number << std::endl;
            std::cout << "  -  launch_year: " << ld->launch_year << std::endl;
            std::cout << "  -  launch_date_local: " << ld->launch_date_local << std::endl;
            std::cout << "------------------------------\n";
        }
    }

    SpaceXLaunchesOldStyle::~SpaceXLaunchesOldStyle()
    {
        for (std::map<std::string, LaunchData *>::iterator iter = launchesMap.begin(); iter != launchesMap.end(); iter++)
        {
            LaunchData *ld = iter->second;
            delete ld;
        }
    }
} // namespace SpaceX