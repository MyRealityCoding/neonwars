#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsObject>

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
    void add(Ship*);
    void remove(Ship *);
    void paintEvent(QPaintEvent * q);
signals:

public slots:

private:
    QMultiMap<int, QPair<int, Ship*> > map;

    void move(Ship*, const QPoint&);
};

#endif // BOARD_H
