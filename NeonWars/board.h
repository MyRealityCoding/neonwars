#ifndef BOARD_H
#define BOARD_H


#include <QGraphicsObject>
#include <QMultiMap>
#include <QPaintEvent>
#include <QPainter>

#include "ship.h"

namespace Neighbour {

    enum Type {
        NONE,
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

    Ship* getShip(const int &x, const int &y, Neighbour::Type);
    Ship* getShip(const int &x, const int &y);
    bool hasShip(const int &x, const int &y);
    bool hasShip(const int &x, const int &y, Neighbour::Type);
    void add(Ship::Type, int columnIndex);
    void remove(const int &x, const int &y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int getWidth() const;
    int getHeight() const;
    int getCellSize() const;
signals:

public slots:

private:
    int rows, columns;
    QMultiMap<int, QPair<int, Ship*> > map;
};

#endif // BOARD_H
