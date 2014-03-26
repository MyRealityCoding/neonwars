#ifndef BOARD_H
#define BOARD_H


#include <QGraphicsObject>
#include <QMultiMap>
#include <QPaintEvent>

#include "ship.h"

namespace Neighbour {

    enum Type {
        UPPER,
        LOWER,
        LEFT,
        RIGHT,
        UPPER_LEFT,
        UPPER_RIGHT,
        LOWER_LEFT,
        LOWER_RIGHT
    };
}

class Board : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit Board(int rows, int columns);

    Ship* getShip(const QPoint&, Neighbour::Type);
    Ship* getShip(const QPoint&);
    bool hasShip(const QPoint&);
    bool hasShip(const QPoint&, Neighbour::Type);
    void add(Ship::Type, int columnIndex);
    void remove(const QPoint&);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
signals:

public slots:

private:
    int rows, columns;
    QMultiMap<int, QPair<int, Ship*> > map;
};

#endif // BOARD_H
