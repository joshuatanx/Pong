// Ball.h - Header file for ball class

#ifndef BALL_H
#define BALL_H

#include <functional>
#include <iostream>

#include "Paddle.h"
#include "Types.h"

class Ball
{
private:
    Vec2<int> position;
    Vec2<unsigned int> size;
    Colour colour;
    Vec2<int> velocity;
    std::function<void()> outOfBoundsCallback;

public:
    void init(const Vec2<int> position = (Vec2<int>) {0, 0}, const Vec2<unsigned int> size = (Vec2<unsigned int>) {25, 25}, const Colour colour = (Colour) {255, 255, 255});
    
    Vec2<int> getPosition();
    void setPosition(const Vec2<int> position);

    Vec2<unsigned int> getSize();
    void setSize(const Vec2<unsigned int> size);

    Colour getColour();
    void setColour(const Colour colour);

    Vec2<int> getVelocity();
    void setVelocity(const Vec2<int> velocity);

    void setOutOfBoundsCallback(std::function<void()> callback);

    Direction collisionWithPaddle(Paddle paddle);
    Direction collisionWithWall(const int screen_height);
    Direction outOfBounds(const int screen_width);
    void handleCollision();

    bool updateScore();

    void reset();
    void move(const Vec2<int> displacement);
    void update();
    void render(const float interpolation);
};

#endif // BALL_H