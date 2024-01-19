cmake_minimum_required(VERSION 3.26)
project(Interactive_Dot_Grid)

set(OpenGlLinkers -lglut -lGLU -lGL)

add_executable(Interactive_Dot_Grid main.cpp)
target_link_libraries(Interactive_Dot_Grid ${OpenGlLinkers})
