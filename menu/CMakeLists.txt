
cmake_minimum_required(VERSION 3.26)
project(menu)

set(OpenGlLinkers -lglut -lGLU -lGL)

add_executable(menu main.cpp )
target_link_libraries(menu ${OpenGlLinkers})
