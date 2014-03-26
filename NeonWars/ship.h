#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsObject>
#include <behavior.h>

class Board;

namespace Player {

    enum Type {
        NONE,PLAYER1,PLAYER2
    };

}

class Ship : public QObject

{
    Q_OBJECT
public:

    enum Type {
        NONE ,  // EMPTY FIELD TYPE
        NORMAL, // Does nothing
        LASER,  // Kills all Ships beneath it
        BOMB,   //Kills all neighbour Ships
        ROCKET, // Kills all neighbour enemy Ships
        PHASER  // Kills all Ships in diagonal
    };

    Ship();
    ~Ship();
    void setType(Ship::Type);
    void paint(const int&, const int&, const int&, QPainter*);
    void triggerBehavior(Board*, const int&, const int&);

    Ship::Type getType() const;
    Player::Type getPlayer() const;

signals:

public slots:

private:

    void setBehavior(Behavior*);

    Player::Type player;
    Ship::Type type;
    QImage image;
    Behavior *behavior;
};


#endif // SHIP_H
