#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <nlohmann/json.hpp>
#include <map>

using json = nlohmann::json;

const char* upcomingLaunchesCmd = "curl --location --request GET 'https://api.spacexdata.com/v3/launches/upcoming'";

//perform api call and return results
std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

//Store launch data from SpaceX api 
struct LaunchData{
    int flight_number;
    std::string launch_year;
    std::string launch_date_local;
    LaunchData(int fn, std::string yr, std::string ldl): flight_number(fn), launch_year(yr), launch_date_local(ldl)
    {        
    }    
};

class SpaceXLaunches{
    private:
        std::map<std::string, LaunchData*> launchMap;
    public:
        //takes in parsed json data from api call and poplulates a std::map. 
        SpaceXLaunches(const json &j) {
            for (auto& element : j) {  
                auto el = element["tentative_max_precision"];            
                LaunchData* l = new LaunchData(element["flight_number"],element["launch_year"],element["launch_date_local"]);          
                launchMap[element["mission_name"]] = l;
                }            
        }

        //Display stored launch data
        void displayLaunchData(){
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
        ~SpaceXLaunches(){
            for (std::map<std::string, LaunchData*>::iterator it = launchMap.begin();it != launchMap.end();it++)
                {
                    LaunchData* L = it->second;
                    delete L;
                }
        } 
};

int main(){
  std::string launch_json = exec(upcomingLaunchesCmd);  
  auto j = json::parse(launch_json); 
  SpaceXLaunches spaceX(j);
  spaceX.displayLaunchData();
}
