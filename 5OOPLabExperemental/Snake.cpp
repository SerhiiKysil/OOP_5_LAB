#include "Snake.h"

Snake::Snake() {
    x.resize(3);
    y.resize(3);

    for (std::size_t i = 0; i < x.size(); ++i) {
        x[i] = 50 - static_cast<int>(i) * 10;
        y[i] = 50;
    }

    direction = Direction::Right;
}

void Snake::move() {
    for (std::size_t i = x.size() - 1; i > 0; --i) {
        x[i] = x[i - 1];
        y[i] = y[i - 1];
    }

    switch (direction) {
    case Direction::Left:
        x[0] -= 10;
        break;
    case Direction::Right:
        x[0] += 10;
        break;
    case Direction::Up:
        y[0] -= 10;
        break;
    case Direction::Down:
        y[0] += 10;
        break;
    }
}

void Snake::grow() {
    x.push_back(x.back());
    y.push_back(y.back());
}

bool Snake::isColliding() const {
    for (std::size_t i = 1; i < x.size(); ++i) {
        if (x[0] == x[i] && y[0] == y[i]) {
            return true;
        }
    }
    return false;
}

int Snake::headX() const {
    return x[0];
}

int Snake::headY() const {
    return y[0];
}

int Snake::length() const {
    return static_cast<int>(x.size());
}

int Snake::getX(int index) const {
    return x[static_cast<std::size_t>(index)];
}

int Snake::getY(int index) const {
    return y[static_cast<std::size_t>(index)];
}

void Snake::setDirection(Direction dir) {
    direction = dir;
}

bool Snake::isMovingLeft() const {
    return direction == Direction::Left;
}

bool Snake::isMovingRight() const {
    return direction == Direction::Right;
}

bool Snake::isMovingUp() const {
    return direction == Direction::Up;
}

bool Snake::isMovingDown() const {
    return direction == Direction::Down;
}
