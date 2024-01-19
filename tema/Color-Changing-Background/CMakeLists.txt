cmake_minimum_required(VERSION 3.26)
project(Color_Changing_Background)

set(OpenGlLinkers -lglut -lGLU -lGL)

add_executable(Color_Changing_Background main.cpp)
target_link_libraries(Color_Changing_Background ${OpenGlLinkers})
