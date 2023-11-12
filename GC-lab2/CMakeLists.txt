cmake_minimum_required(VERSION 3.26) # common to every CLion project
project(GC_lab2) # project name


set(OpenGlLinkers -lglut -lGLU -lGL) # setting all the Glut libraries as one variable.


################################################

add_executable(GC_lab2 main.cpp ) #common to all clion project
target_link_libraries(GC_lab2 ${OpenGlLinkers}) # linking opengl libraries to the project

#################################################