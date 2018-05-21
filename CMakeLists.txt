cmake_minimum_required(VERSION 3.9)
project(RoboAuto_geometry)

set(CMAKE_CXX_STANDARD 17)

add_executable(RoboAuto_geometry main.cpp Lib/GeometricEntity.cpp Lib/GeometricEntity.h Lib/Point.cpp Lib/Point.h Lib/Line.cpp Lib/Line.h Lib/Vector.cpp Lib/Vector.h)