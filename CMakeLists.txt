cmake_minimum_required(VERSION 3.10)
project(Concurrency)

set(CMAKE_CXX_STANDARD 11)




add_executable(Concurrency main.cpp)
TARGET_LINK_LIBRARIES( Concurrency pthread)