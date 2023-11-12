
cmake_minimum_required(VERSION 3.26)
project(aplicatie_triangle_fan)

set(OpenGlLinkers -lglut -lGLU -lGL)

add_executable(aplicatie_triangle_fan main.cpp )
target_link_libraries(aplicatie_triangle_fan ${OpenGlLinkers})
