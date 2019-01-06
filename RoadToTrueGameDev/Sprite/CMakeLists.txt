cmake_minimum_required(VERSION 3.12)
project(Sprite)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(Sprite main.cpp)
target_link_libraries(Sprite sfml-graphics sfml-audio)
