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
    Vec2<int> default_position;
    Vec2<unsigned int> size;
    Colour colour;
    unsigned int speed;
    Vec2<int> velocity;
    bool is_frozen;
    std::function<void()> outOfBoundsCallback;

public:
    void init(const Vec2<int> position = (Vec2<int>) {0, 0}, const Vec2<unsigned int> size = (Vec2<unsigned int>) {24, 24}, const Colour colour = (Colour) {255, 255, 255}, const Vec2<int> default_position = (Vec2<int>) {SCREEN_WIDTH / 2 - 12, SCREEN_HEIGHT / 2 - 12}, const unsigned int speed = 5);
    
    Vec2<int> getPosition();
    void setPosition(const Vec2<int> position);

    Vec2<int> getDefaultPosition();
    void setDefaultPosition(const Vec2<int> position);

    Vec2<unsigned int> getSize();
    void setSize(const Vec2<unsigned int> size);

    Colour getColour();
    void setColour(const Colour colour);

    unsigned int getSpeed();
    void setSpeed(const unsigned int speed);

    Vec2<int> getVelocity();
    void setVelocity(const Vec2<int> velocity);

    bool isFrozen();
    void freeze();
    void unfreeze();

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