#include "ship.h"
#include <QPainter>
#include <iostream>
#include "board.h"

Ship::Ship()
    : player(Player::NONE), type(Ship::NONE), behavior(NULL)
{
    image = QImage(":NORMAL");
    setBehavior(new SimpleBehavior);
}

Ship::~Ship()
{
    setBehavior(NULL);
}

void Ship::setType(Ship::Type type){

    switch (type){
        case Ship::NONE:
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
    if(type != Ship::NONE)
    {
       painter->drawImage(QRect(x, y, size, size),image);
    }
}

void Ship::triggerBehavior(Board *board)
{
    if (behavior != NULL)
    {
        behavior->trigger(board, this);
    }
}

Ship::Type  Ship::getType() const
{
    return type;
}

Player::Type Ship::getPlayer() const
{
    return player;
}

void Ship::setBehavior(Behavior *newBehavior)
{
    if (behavior != NULL)
    {
        delete behavior;
    }

    behavior = newBehavior;
}
