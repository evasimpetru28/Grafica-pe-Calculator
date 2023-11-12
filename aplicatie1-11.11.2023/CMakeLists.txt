
cmake_minimum_required(VERSION 3.26)
project(aplicatie1_11_11_2023)

set(OpenGlLinkers -lglut -lGLU -lGL)

add_executable(aplicatie1_11_11_2023 main.cpp )
target_link_libraries(aplicatie1_11_11_2023 ${OpenGlLinkers})
