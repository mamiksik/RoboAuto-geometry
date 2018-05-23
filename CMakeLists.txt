cmake_minimum_required(VERSION 3.9)
project(RoboAuto_geometry)

find_package(Qt5Core)
find_package(Qt5Charts)

set(CMAKE_CXX_STANDARD 17)

add_executable(RoboAuto_geometry main.cpp Lib/Vector.h Lib/Line.h Lib/Polygon.h Lib/Drawer.h Lib/Drawable.h)
target_link_libraries(RoboAuto_geometry Qt5::Widgets Qt5::Charts)