cmake_minimum_required(VERSION 3.11)
project(routing_json)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(external)
add_subdirectory(lib)

add_subdirectory(test)
