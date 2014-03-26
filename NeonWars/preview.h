#ifndef PREVIEW_H
#define PREVIEW_H

#include "ship.h"

class Preview : public QGraphicsObject

{
    Q_OBJECT
public:
    Preview(Player::Type);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


signals:

public slots:

private:
    Player::Type _playerType;
};

#endif // PREVIEW_H
