// Paddle.h - Header file for Paddle class

#ifndef PADDLE_H
#define PADDLE_H

#include "Types.h"

class Paddle
{
private:
    Vec2<int> position;
    Vec2<int> size;
    Colour colour;

public:
    Paddle(const Vec2<int> position = (Vec2<int>) {0, 0}, const Vec2<int> size = (Vec2<int>) {50, 50}, const Colour = (Colour) {0, 0, 0, 255});

    Vec2<int> getPosition();
    void setPosition(const Vec2<int> position);

    Vec2<int> getSize();
    void setSize(const Vec2<int> size);

    Colour getColour();
    void setColour(const Colour colour);

    void render(const float interpolation);
};

#endif // PADDLE_H