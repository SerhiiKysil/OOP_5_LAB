#include "Apple.h"
#include <cstdlib>

Apple::Apple(int x, int y) : x(x), y(y) {}

int Apple::getX() const {
    return x;
}

int Apple::getY() const {
    return y;
}

void Apple::relocate(int maxX, int maxY) {
    x = (rand() % maxX) * 10;
    y = (rand() % maxY) * 10;
}
