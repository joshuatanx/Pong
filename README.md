# Pong++
A recreation of _Pong_ in C++, using the SDL2 framework.

This game encorporates the defining elements of _Pong_ while introducing additional features like power-ups and different game modes.
## Setup
For the program to work on your device, you will have to install the SDL2 library. Edit the "includePath" in `c_cpp_properties.json` with the path of the SDL header file on your device, then edit "args" in `tasks.json` and update the include and library paths.

## Build (using CMake)
1. Generate build files `cmake -S . -B build`
2. Compile project `cmake --build build`
