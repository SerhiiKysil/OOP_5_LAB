#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "Direction.h"

class Snake {
public:
    Snake();
    void move();
    void grow();
    bool isColliding() const;

    int headX() const;
    int headY() const;
    int length() const;
    int getX(int index) const;
    int getY(int index) const;

    void setDirection(Direction dir);
    bool isMovingLeft() const;
    bool isMovingRight() const;
    bool isMovingUp() const;
    bool isMovingDown() const;

private:
    std::vector<int> x;
    std::vector<int> y;
    Direction direction;
};

#endif // SNAKE_H
