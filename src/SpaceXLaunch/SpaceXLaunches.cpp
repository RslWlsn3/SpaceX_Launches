//SpaceXLaunches.cpp

#include "SpaceXLaunches.hpp"
#include <stdlib.h> 

namespace SpaceX
{
    LaunchData::LaunchData(int fn, std::string yr, std::string ldl): flight_number(fn), launch_year(yr), launch_date_local(ldl)
    {        
    }    

    //takes in parsed json data from api call and poplulates a std::map. 
    SpaceXLaunches::SpaceXLaunches(const json &j) { 
        if (j.is_array()){
            for (auto& element : j) {                  
                auto el1 = element["mission_name"];          
                LaunchData* ld = new LaunchData(element["flight_number"],element["launch_year"],element["launch_date_local"]);          
                launchMap[element["mission_name"]] = ld;
            }      
        }     
        else if (j.is_object()){
            LaunchData* ld = new LaunchData(j.at("flight_number"),j.at("launch_year"),j.at("launch_date_local"));          
            launchMap[j.at("mission_name")] = ld;
        } 
        else {
            std::cout<<"Error processing json obj\n";
            exit (EXIT_FAILURE);
        } 
           
    }

    //Display stored launch data
    void SpaceXLaunches::displayLaunchData(){
        for (std::map<std::string, LaunchData*>::iterator it = launchMap.begin();it != launchMap.end();it++)
            {
                std::cout<< "mission_name: " << it->first<<std::endl;
                LaunchData* L = it->second;
                std::cout<<"  -  flight_number: " << (*L).flight_number<<std::endl;
                std::cout<<"  -  launch_year: " << (*L).launch_year<<std::endl;
                std::cout<<"  -  launch_date_local: " << (*L).launch_date_local<<std::endl;
                std::cout<<"------------------------------\n";
            }
    }

    //delete heap allocated LaunchData objs
    SpaceXLaunches::~SpaceXLaunches(){
        for (std::map<std::string, LaunchData*>::iterator it = launchMap.begin();it != launchMap.end();it++)
            {
                LaunchData* L = it->second;
                delete L;
            }
    } 
}