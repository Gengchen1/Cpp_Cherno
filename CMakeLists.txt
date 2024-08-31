cmake_minimum_required(VERSION 3.5)

project(LearnCpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")
# set (CMAKE_BUILD_TYPE Debug)
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

include_directories(${CMAKE_SOURCE_DIR}/include)

file (GLOB source_files "${source_dir}/*.cpp")

add_executable (LearnCpp ${source_files})
