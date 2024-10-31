cmake_minimum_required(VERSION 3.10)

# Project name and language
project(Pong++ LANGUAGES CXX)

add_compile_options(-mmacosx-version-min=10.15)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)

# Set minimum MacOS version
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.15")

# Include SDL2
include_directories(/opt/homebrew/Cellar/sdl2/2.30.8/include/SDL2)
link_directories(/opt/homebrew/Cellar/sdl2/2.30.8/lib)

# Include SDL2_ttf
include_directories(/opt/homebrew/Cellar/sdl2_ttf/2.22.0/include/SDL2)
link_directories(/opt/homebrew/Cellar/sdl2_ttf/2.22.0/lib)

# Include SDL2_image
include_directories(/opt/homebrew/Cellar/sdl2_image/2.8.2_2/include/SDL2)
link_directories(/opt/homebrew/Cellar/sdl2_image/2.8.2_2/lib)

# Find all source files
file(GLOB SOURCES "src/*.cpp")

# Add executable
add_executable(Pong++ ${SOURCES})

# Link SDL2
target_link_libraries(Pong++ SDL2)
