cmake_minimum_required(VERSION 3.26)
project(aplicatia15)

set(OpenGlLinkers -lglut -lGLU -lGL)

add_executable(aplicatia15 main.cpp )
target_link_libraries(aplicatia15 ${OpenGlLinkers})
