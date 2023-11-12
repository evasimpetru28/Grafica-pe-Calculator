
cmake_minimum_required(VERSION 3.26)
project(rotatie)

set(OpenGlLinkers -lglut -lGLU -lGL)

add_executable(rotatie main.cpp )
target_link_libraries(rotatie ${OpenGlLinkers})
