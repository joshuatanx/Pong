cmake_minimum_required(VERSION 3.28)
project(Pong)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

# Find and include SDL2 headers
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Find and include SDL2_image headers
# find_package(SDL2_image REQUIRED)
# include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
include_directories("/opt/homebrew/Cellar/sdl2_image/2.8.1/include/SDL2") # non-standard path that CMake can't find smh

# Group .cpp files
set(SOURCE_FILES_MAIN
    Source/main.cpp
    Source/Game.cpp
)

set(SOURCE_FILES_GRAPHICS
#    Source/Graphics/RenderSystem.cpp
#    Source/Graphics/Draw.cpp
#    Source/Graphics/TextureManager.cpp
)

set(SOURCE_FILES_ALL
    ${SOURCE_FILES_MAIN}
    ${SOURCE_FILES_GRAPHICS}
)

# Add all source files
add_executable(Pong ${SOURCE_FILES_ALL})

# Link SDL2 and SDL2_image libraries
target_link_libraries(Pong ${SDL2_LIBRARIES} "/opt/homebrew/Cellar/sdl2_image/2.8.1/lib/libSDL2_image.dylib")

# Recursive copy of the assets directory to the build directory
file(GLOB_RECURSE ASSETS_FILES ${CMAKE_SOURCE_DIR}/Assets/*)
foreach(ASSET ${ASSETS_FILES})
    configure_file(${ASSET} ${CMAKE_BINARY_DIR}/Assets COPYONLY)
endforeach()