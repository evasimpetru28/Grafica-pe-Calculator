cmake_minimum_required(VERSION 3.26)
project(Tic_Tac_Toe)

set(OpenGlLinkers -lglut -lGLU -lGL)

add_executable(Tic_Tac_Toe main.cpp)
target_link_libraries(Tic_Tac_Toe ${OpenGlLinkers})
