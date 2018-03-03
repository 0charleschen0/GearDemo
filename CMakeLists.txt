# cmake_minimum_required(VERSION <specify CMake version here>)
project(gearDemo_c__)

set(CMAKE_CXX_STANDARD 11)

add_executable(gearDemo_c__ main.cpp Gear.cpp Gear.h FullDepth.cpp Stub.cpp UserDefine.cpp FullDepth.h Stub.h UserDefine.h)