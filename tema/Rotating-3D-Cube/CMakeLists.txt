cmake_minimum_required(VERSION 3.26)
project(Rotating_3D_Cube)

set(OpenGlLinkers -lglut -lGLU -lGL)

add_executable(Rotating_3D_Cube main.cpp)
target_link_libraries(Rotating_3D_Cube ${OpenGlLinkers})
