cmake_minimum_required(VERSION 3.26)
project(teapot)

set(OpenGlLinkers -lglut -lGLU -lGL)

add_executable(teapot main.cpp )
target_link_libraries(teapot ${OpenGlLinkers})
