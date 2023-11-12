cmake_minimum_required(VERSION 3.26)
project(GC_lab1)

set(OpenGlLinkers -lglut -lGLU -lGL)

add_executable(GC_lab1 main.cpp )
target_link_libraries(GC_lab1 ${OpenGlLinkers})

