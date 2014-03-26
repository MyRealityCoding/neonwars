#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsObject>

namespace Player {

    enum Type {
        NONE,PLAYER1,PLAYER2
    };

}

class Ship : public QGraphicsObject

{
    Q_OBJECT
public:

    enum Type {
        EMPTY , // EMPTY FIELD TYPE
        NORMAL, // Does nothing
        LASER, // Kills all Ships beneath it
        BOMB, //Kills all neighbour Ships
        ROCKET, // Kills all neighbour enemy Ships
        PHASER// Kills all Ships in diagonal
    };

    explicit Ship();
    QRectF boundingRect() const ;
    void setType(Ship::Type);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


signals:

public slots:
private:
    Player::Type player;
    Ship::Type type;
    QImage image;
};


#endif // SHIP_H
