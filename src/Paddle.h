// Paddle.h - Header file for Paddle class

#ifndef PADDLE_H
#define PADDLE_H

#include "Types.h"

#include <unordered_map>

class Paddle
{
private:
    PaddleType paddle_type;
    Vec2<int> position;
    Vec2<unsigned int> size;
    Colour colour;
    Direction direction;

public:
    Paddle(const PaddleType paddle_type = Player1, const Vec2<int> position = (Vec2<int>) {0, 0}, const Vec2<unsigned int> size = (Vec2<unsigned int>) {50, 50}, const Colour colour = (Colour) {0, 0, 0, 255});
    void init(const PaddleType paddle_type = Player1, const Vec2<int> position = (Vec2<int>) {0, 0}, const Vec2<unsigned int> size = (Vec2<unsigned int>) {50, 50}, const Colour colour = (Colour) {0, 0, 0, 255});

    PaddleType getPaddleType();
    void setPaddleType(const PaddleType paddle_type);

    Vec2<int> getPosition();
    void setPosition(const Vec2<int> position);

    Vec2<unsigned int> getSize();
    void setSize(const Vec2<unsigned int> size);

    Colour getColour();
    void setColour(const Colour colour);

    Direction getDirection();
    void setDirection(const Direction direction);

    void move(const Vec2<int> displacement);
    void processInput(const std::unordered_map<SDL_KeyCode, bool> keyboard_state);
    void update();
    void render(const float interpolation);
};

#endif // PADDLE_H