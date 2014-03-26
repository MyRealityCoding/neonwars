#include "ship.h"
#include <QPainter>
#include <iostream>

Ship::Ship()
    : player(Player::NONE), type(Ship::EMPTY)
{
    image = QImage(":NORMAL");

    std::cout << image.isNull() << std::endl;
}

void Ship::setType(Ship::Type type){

    switch (type){
        case Ship::EMPTY:
            break;
        case Ship::NORMAL:
            image = QImage(":NORMAL");
            break;
        case Ship::ROCKET:
            image = QImage(":ROCKET");
            break;
        case Ship::BOMB:
            image = QImage(":BOMB");
            break;
        case Ship::LASER:
            image = QImage(":LASER");
            break;
        case Ship::PHASER:
            image = QImage(":PHASER");
            break;
    }

    this->type = type;
}

void Ship::paint(const int &x, const int &y, const int &size, QPainter *painter)
{
    //if(type != Ship::EMPTY)
    //{
       //std::cout << (painter) << std::endl;
       //painter->drawImage(QRect(x, y, size, size),image);
    //}
}
