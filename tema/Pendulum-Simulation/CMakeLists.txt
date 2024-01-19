cmake_minimum_required(VERSION 3.26)
project(Pendulum_Simulation)

set(OpenGlLinkers -lglut -lGLU -lGL)

add_executable(Pendulum_Simulation main.cpp)
target_link_libraries(Pendulum_Simulation ${OpenGlLinkers})
