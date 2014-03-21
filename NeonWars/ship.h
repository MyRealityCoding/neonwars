#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsObject>

enum Player { Player1,Player2};

enum ShipType {
    NONE , // EMPTY FIELD TYPE
    NORMAL, // Does nothing
    LASER, // Kills all Ships beneath it
    BOMB, //Kills all neighbour Ships
    ROCKET, // Kills all neighbour enemy Ships
    PHASER// Kills all Ships in diagonal
};

class Ship : public QGraphicsObjects

{
    Q_OBJECT
public:
    explicit Ship(QWidget *parent = 0);
    void setType(ShipType);
signals:

public slots:
private:
    Player player;
    ShipType type;
    QPixmap image;


};


#endif // SHIP_H
