#include "preview.h"

Preview::Preview(Player::Type type)
    : _playerType(type)
{

}

QRectF Preview::boundingRect() const
{
    return QRect(0, 0, 0, 0);
}

void Preview::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}
