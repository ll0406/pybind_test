cmake_minimum_required(VERSION 2.8.12)
project(first_bind)

add_subdirectory(pybind11)
pybind11_add_module(first_bind src/main.cpp)
