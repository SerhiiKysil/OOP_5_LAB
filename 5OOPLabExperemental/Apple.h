#ifndef APPLE_H
#define APPLE_H

class Apple {
public:
    Apple(int x, int y);
    int getX() const;
    int getY() const;
    void relocate(int maxX, int maxY);

private:
    int x;
    int y;
};

#endif // APPLE_H
