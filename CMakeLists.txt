# TODO: add gtest

cmake_minimum_required(VERSION 3.0)
project(Graper)

# graper static lib
add_library(graper-sl STATIC
            src/graper.cpp)
