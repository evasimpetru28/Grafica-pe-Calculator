cmake_minimum_required(VERSION 3.26)
project(2D_Clock)

set(OpenGlLinkers -lglut -lGLU -lGL)

add_executable(2D_Clock main.cpp)
target_link_libraries(2D_Clock ${OpenGlLinkers})
