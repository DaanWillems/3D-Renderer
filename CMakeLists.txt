cmake_minimum_required(VERSION 3.12)
project(RDAlgebra2)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
set(SDL2_PATH "C:/SDL2")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(RDAlgebra2 main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} ${SDL2_LIBRARY})
