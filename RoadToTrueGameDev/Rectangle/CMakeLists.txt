cmake_minimum_required(VERSION 3.12)
project(Rectangle)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(Rectangle main.cpp)
target_link_libraries(Rectangle sfml-graphics sfml-audio)