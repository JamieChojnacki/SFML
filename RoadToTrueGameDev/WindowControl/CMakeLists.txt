cmake_minimum_required(VERSION 3.12)
project(WindowControl)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(WindowControl Window.cpp Window.h main.cpp)
target_link_libraries(WindowControl sfml-graphics sfml-audio)