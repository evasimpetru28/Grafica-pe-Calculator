cmake_minimum_required(VERSION 3.26)
project(aplicatie_propusa)

set(OpenGlLinkers -lglut -lGLU -lGL)

add_executable(aplicatie_propusa main.cpp )
target_link_libraries(aplicatie_propusa ${OpenGlLinkers})
