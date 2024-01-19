cmake_minimum_required(VERSION 3.26)
project(Rotating_Fan)

set(OpenGlLinkers -lglut -lGLU -lGL)

add_executable(Rotating_Fan main.cpp)
target_link_libraries(Rotating_Fan ${OpenGlLinkers})
