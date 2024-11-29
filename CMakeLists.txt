cmake_minimum_required(VERSION 3.29)
project(AAPay)

set(CMAKE_CXX_STANDARD 20)

add_executable(AAPay main.cpp
        ItemData.cpp
        ItemData.h
        OrderData.cpp
        OrderData.h
        LogFile.cpp
        LogFile.h
        Report.h
        Report.cpp
        OrderManager.h
        OrderManager.cpp)
