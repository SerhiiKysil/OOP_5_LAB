#ifndef ISNAKEMOVEMENTSTRATEGY_H
#define ISNAKEMOVEMENTSTRATEGY_H

class ISnakeMovementStrategy {
public:
    virtual ~ISnakeMovementStrategy() = default;
    virtual void move(int &x, int &y) = 0;
};

#endif // ISNAKEMOVEMENTSTRATEGY_H
