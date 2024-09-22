// Types.h - Header file for type declarations

#ifndef TYPES_H
#define TYPES_H

#include <cstddef>
#include <cstdint>
#include <SDL.h>

// Vectors
template <typename T>
struct Vec2
{
    T x;
    T y;
};

template <typename T>
struct Vec3
{
    T x;
    T y;
    T z;
};

template <typename T>
struct Vec4
{
    T x;
    T y;
    T z;
    T w;
};

// Graphics
struct Colour
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};

// Movement
enum Direction
{
    None,
    Up,
    Down,
    Left,
    Right
};

// Paddles
enum PaddleType
{
    Player1,
    Player2,
    CPU1,
    CPU2
};

// Screen info
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const Vec2<int> SCREEN_SIZE = {SCREEN_WIDTH, SCREEN_HEIGHT};

// Game loop
const int TICKS_PER_SECOND = 60;
const int TICK_DELAY = 1000 / TICKS_PER_SECOND;
const int MAX_FRAME_SKIP = 5;

#endif // TYPES_H