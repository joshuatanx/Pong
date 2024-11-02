# Pong++
A recreation of _Pong_ in C++, using the SDL2 framework.

This game incorporates the defining elements of _Pong_ while introducing an additional game mode with multiple balls.
## Setup
### 1) Cloning the repository
```
git clone https://github.com/joshuatanx/Pong.git
cd Pong
```

### 2) Installing SDL2
For the program to work on your device, you will have to install the SDL2 library. Once you have done so, edit the "includePath" in `c_cpp_properties.json` with the path of the SDL header file on your device, then edit "args" in `tasks.json` and update the include and library paths.

## 3) Building executable
```
cd build
cmake ..
cmake --build .
```

4) ## Running the executable
```
./Pong++
```

## Note
These instructions only apply for MacOS. Additionally, this program has only been tested on MacOS 14.1.
