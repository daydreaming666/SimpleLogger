cmake_minimum_required(VERSION 3.19)
project(SimpleLogger)

set(CMAKE_CXX_STANDARD 11)

add_library(SimpleLogger STATIC SimpleLogger.cpp SimpleLogger.hpp)