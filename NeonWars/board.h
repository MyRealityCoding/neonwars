#ifndef BOARD_H
#define BOARD_H


#include <QGraphicsObject>
#include <QMultiMap>
#include <QPaintEvent>

#include <ship.h>

enum NeighbourType
{
    UP,
    UP_LEFT,
    UP_RIGHT,
    BELOW,
    BELOW_LEFT,
    BELOW_RIGHT
};

class Board : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit Board(int rows, int columns);

    Ship* getShip(const QPoint&, NeighbourType);
    Ship* getShip(const QPoint&);
    bool hasShip(const QPoint&);
    bool hasShip(const QPoint&, NeighbourType);
    void add(ShipType, int columnIndex);
    void remove(const QPoint&);

signals:

public slots:

private:
    int rows, columns;
    QMultiMap<int, QPair<int, Ship*> > map;
};

#endif // BOARD_H
