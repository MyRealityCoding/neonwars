#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsObject>
#include <QMultiMap>

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
    explicit Board();

    Ship* getShip(const QPoint&, NeighbourType);
    Ship* getShip(const QPoint&);
    bool hasShip(const QPoint&);
    bool hasShip(const QPoint&, NeighbourType);
    void add(Ship*, int columnIndex);
    void remove(const QPoint&);
    void paintEvent(QPaintEvent * q);
signals:

public slots:

private:
    QMultiMap<int, QPair<int, Ship*> > map;
};

#endif // BOARD_H
