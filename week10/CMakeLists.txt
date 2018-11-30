cmake_minimum_required(VERSION 3.9)
project(week10)

set(CMAKE_CXX_STANDARD 11)

add_executable(week10
        Customer.cpp
        Customer.hpp
        Product.cpp
        Product.hpp
        Store.cpp
        Store.hpp)
