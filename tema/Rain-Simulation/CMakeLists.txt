cmake_minimum_required(VERSION 3.26)
project(Rain_Simulation)

set(OpenGlLinkers -lglut -lGLU -lGL)

add_executable(Rain_Simulation main.cpp)
target_link_libraries(Rain_Simulation ${OpenGlLinkers})
