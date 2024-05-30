#ifndef STANDARDBOVEMENTSTRATEGY_H
#define STANDARDBOVEMENTSTRATEGY_H

#include "ISnakeMovementStrategy.h"

class StandardMovementStrategy : public ISnakeMovementStrategy {
public:
    void move(int &x, int &y) override;
};

#endif // STANDARDBOVEMENTSTRATEGY_H
