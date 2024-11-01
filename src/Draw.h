// Draw.h - header file for Draw class

#ifndef DRAW_H
#define DRAW_H

#include "Types.h"

class Draw
{
public:
    static void line(const Vec2<int> head, const Vec2<int> tail, const Colour colour);
    static void rectangle(const int x, const int y, const int width, const int height, const Colour colour = (Colour) {255, 255, 255, 255}, const bool fill = true);
    static void rectangle(const Vec2<int> position, const Vec2<int> size, const Colour colour = (Colour) {255, 255, 255, 255}, const bool fill = true);
    static void stripedRectangle(const int x, const int y, const int width, const int height, const Colour colour = (Colour) {255, 255, 255, 255}, const bool fill = true, const Direction stripe_direction = Right, const int divisions = 2, const int gap = 15);
};

#endif