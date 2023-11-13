cmake_minimum_required(VERSION 3.16)
project(Trip_From_Start)

set(CMAKE_CXX_STANDARD 17)

add_executable(Trip_From_Start mainOld.cpp Trip.h Date.h Date.cpp Trip.cpp ManagementTrips.cpp ManagementTrips.h)