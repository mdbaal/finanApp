# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (finanApp)

add_executable(
src/main.cpp
src/input.cpp
src/input.h
src/output.cpp
src/output.h
src/commands.h
src/summary.cpp
src/summary.h
)
