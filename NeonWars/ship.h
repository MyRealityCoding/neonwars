#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsObject>

enum Player {NONE,PLAYER1,PLAYER2};

enum ShipType {
    NONE , // EMPTY FIELD TYPE
    NORMAL, // Does nothing
    LASER, // Kills all Ships beneath it
    BOMB, //Kills all neighbour Ships
    ROCKET, // Kills all neighbour enemy Ships
    PHASER// Kills all Ships in diagonal
};

class Ship : public QGraphicsObject

{
    Q_OBJECT
public:
    explicit Ship(Player p, ShipType t):player(p),type(t){
        setType(type);
    }
    QRectF boundingRect() const ;
    void setType(ShipType);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
signals:

public slots:
private:
    Player player;
    ShipType type;
    QImage image;
};


#endif // SHIP_H
