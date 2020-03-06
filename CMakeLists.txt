cmake_minimum_required(VERSION 3.13)
project(untitled17 LANGUAGES CXX)

INCLUDE(CMakeForceCompiler)
CMAKE_FORCE_C_COMPILER(gcc GNU)
CMAKE_FORCE_CXX_COMPILER(g++ GNU)
set(CMAKE_INCLUDE_CURRENT_DIR ON)



#LINK_DIRECTORIES(C:\\Users\\rasah_s2z0ncs\\Downloads\\WiringPi-master\\wiringPi)
set(CMAKE_CXX_STANDARD 14)


set(CMAKE_CXX_FLAGS "-lwiringPi -pthread" )


add_executable(untitled17 main.cpp)