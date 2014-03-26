#ifndef BEHAVIOR_H
#define BEHAVIOR_H

class Board;
class Ship;

class Behavior
{
public:
    virtual void trigger(Board *board, Ship *target) = 0;
};

class SimpleBehavior : public Behavior
{
public:
    void trigger(Board *board, Ship *target);
};

#endif // BEHAVIOR_H
