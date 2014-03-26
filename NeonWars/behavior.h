#ifndef BEHAVIOR_H
#define BEHAVIOR_H

class Board;
class Ship;

class Behavior
{
public:
    virtual void trigger(Board *board, const int&, const int&) = 0;
};

class SimpleBehavior : public Behavior
{
public:
    void trigger(Board *board, const int&, const int&);
};

#endif // BEHAVIOR_H
