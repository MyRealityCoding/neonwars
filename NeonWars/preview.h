#ifndef PREVIEW_H
#define PREVIEW_H

#include "ship.h"
#include <QGraphicsObject>
#include <QLinkedList>

class Board;

class Preview : public QGraphicsObject

{
    Q_OBJECT
public:
    Preview(Player::Type);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Ship* top();
    Ship* fetch();
    void reset();
    void setBoard(Board*);
signals:

public slots:

private:
    Board *board;
    Player::Type _playerType;
    QLinkedList<Ship*> elements;

    Ship* provideNext();
};

#endif // PREVIEW_H
