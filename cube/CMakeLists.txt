cmake_minimum_required(VERSION 3.26)
project(cube)

set(OpenGlLinkers -lglut -lGLU -lGL)

add_executable(cube main.cpp )
target_link_libraries(cube ${OpenGlLinkers})
