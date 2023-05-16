cmake_minimum_required(VERSION 3.5)

project(gspch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(gspch main.cpp
                     congrRand.cpp
                     xorshift.cpp
                     viborki.cpp)
