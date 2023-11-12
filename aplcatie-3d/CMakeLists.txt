
cmake_minimum_required(VERSION 3.26)
project(aplcatie_3d)

set(OpenGlLinkers -lglut -lGLU -lGL)

add_executable(aplcatie_3d main.cpp )
target_link_libraries(aplcatie_3d ${OpenGlLinkers})
