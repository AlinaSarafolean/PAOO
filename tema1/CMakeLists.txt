cmake_minimum_required(VERSION 3.2)

project(tema1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
   
include_directories(src)

add_executable(tema1 src/main.cpp src/Resource.cpp) 


