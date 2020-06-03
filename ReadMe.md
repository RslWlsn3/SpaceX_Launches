## SpaceX Launches Mini-Project

# Goals
 - https://docs.spacexdata.com/?version=latest

 - Explore hitting the API using Postman

 - Look specifically at the launches resource

 - Call the launches API to get all the launches

 - Parse the data to build an instance of a Launch object for each record, and store in a container.

 - Use a std::map<std::string, LaunchData*>

 - Iterate over the collection and output some basic information for each launch to std::cout

# Error
/home/cmote/spacexlaunches/main.cpp:25:13: error: ‘json’ has not been declared
   25 |   auto j3 = json::parse(launch_json);