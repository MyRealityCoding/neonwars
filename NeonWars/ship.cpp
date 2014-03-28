#include "ship.h"
#include <QPainter>
#include <QGraphicsEffect>
#include <iostream>
#include "board.h"

Ship::Ship()
    : player(Player::NONE), type(Ship::NONE), behavior(NULL)
{
    image = QImage(":NORMAL");
    setBehavior(new NormalBehavior);
}

Ship::~Ship()
{
    setBehavior(NULL);
}

void Ship::setType(Ship::Type type){

    switch (type){
        case Ship::NONE:
            player = Player::NONE;
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

void Ship::setPlayer(Player::Type type)
{
    player = type;
}

void Ship::paint(const int &x, const int &y, const int &size, QPainter *painter)
{
    if(type != Ship::NONE)
    {
       QColor color(Settings::COLOR_PLAYER_1);

       if (player == Player::PLAYER2)
       {
           color.setNamedColor(Settings::COLOR_PLAYER_2);
       }

       painter->setBrush(color);
       painter->drawRect(QRect(x, y, size, size));

       //image.setColor(0, qRgb(0, 0, 0));

       painter->drawImage(QRect(x, y, size, size), image);
    }
}

void Ship::triggerBehavior(Board *board, const int &x, const int &y)
{
    if (behavior != NULL)
    {
        behavior->trigger(board, x, y);
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
