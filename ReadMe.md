# SpaceX Launches Mini-Project

## Goals
 - https://docs.spacexdata.com/?version=latest

 - Explore hitting the API using Postman

 - Look specifically at the launches resource

 - Call the launches API to get all the launches

 - Parse the data to build an instance of a Launch object for each record, and store in a container.

 - Use a std::map<std::string, LaunchData*>

 - Iterate over the collection and output some basic information for each launch to std::cout

## Example output
mission_name: ANASIS-II
  -  flight_number: 105
  -  launch_year: 2020
  -  launch_date_local: 2020-06-30T20:00:00-04:00
------------------------------
mission_name: CRS-21
  -  flight_number: 106
  -  launch_year: 2020
  -  launch_date_local: 2020-10-19T20:00:00-04:00
------------------------------
mission_name: GPS III SV03 (Columbus)
  -  flight_number: 98
  -  launch_year: 2020
  -  launch_date_local: 2020-06-30T15:55:00-04:00
------------------------------
ect...