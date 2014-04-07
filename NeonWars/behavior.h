#ifndef BEHAVIOR_H
#define BEHAVIOR_H

class Board;
class Ship;
class QMediaPlayer;

class Behavior
{
protected:


    QMediaPlayer *mediaPlayer;
public:
    Behavior();
    virtual void trigger(Board *board, const int&, const int&) = 0;
};

class NormalBehavior : public Behavior
{
public:
    void trigger(Board *board, const int&, const int&);
};

class LaserBehavior: public Behavior {
    void trigger(Board *board, const int&, const int&);
};

class BombBehavior: public Behavior {
    void trigger(Board *board, const int&, const int&);
};
class RocketBehavior: public Behavior {
    void trigger(Board *board, const int&, const int&);
};
class PhaserBehavior: public Behavior {
    void trigger(Board *board, const int&, const int&);
};




//        NONE ,  // EMPTY FIELD TYPE
//        NORMAL, // Does nothing
//        LASER,  // Kills all Ships beneath it
//        BOMB,   //Kills all neighbour Ships
//        ROCKET, // Kills all neighbour enemy Ships
//        PHASER

#endif // BEHAVIOR_H
