cmake_minimum_required(VERSION 3.10)

# Project name and language
project(Pong++ LANGUAGES CXX)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)

# Include SDL2
include_directories(/opt/homebrew/Cellar/sdl2/2.30.8/include/SDL2)
link_directories(/opt/homebrew/Cellar/sdl2/2.30.8/lib)

# Find all source files
file(GLOB SOURCES "Source/*.cpp")

# Add executable
add_executable(Pong++ ${SOURCES})

# Link SDL2
target_link_libraries(Pong++ SDL2)
