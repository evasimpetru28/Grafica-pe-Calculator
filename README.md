# Grafica-pe-Calculator


## Specifications
**OS**: Ubuntu 23.04

**IDE**: JetBrains CLion


> **Note**
> See version by running ```cat /etc/lsb-release``` in terminal.
> 

## Installation
```
sudo apt-get install freeglut3-dev
```

## Configuration CLion

For <project_name>/cmake-build-debug/CMakeLists.txt file:
```
cmake_minimum_required(VERSION 3.26)
project(<project_name>)

set(OpenGlLinkers -lglut -lGLU -lGL)

add_executable(<project_name> main.cpp )
target_link_libraries(<project_name> ${OpenGlLinkers})
```
then load CMake changes.
