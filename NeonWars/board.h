#ifndef BOARD_H
#define BOARD_H


#include <QGraphicsObject>
#include <QMultiMap>
#include <QPaintEvent>
#include <QPainter>
#include "settings.h"
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

private:
    Ship* _map[Settings::COLUMN_COUNT][Settings::ROW_COUNT];
    int _rows[Settings::COLUMN_COUNT];

public:
    Board();

    Ship* getShip(const int &x, const int &y, Neighbour::Type);
    Ship* getShip(const int &x, const int &y);
    bool hasShip(const int &x, const int &y);
    bool hasShip(const int &x, const int &y, Neighbour::Type);
    bool add(Ship::Type, int columnIndex);
    void remove(const int &x, const int &y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int getWidth() const;
    int getHeight() const;
    int getCellSize() const;

signals:

public slots:

private:

    int transformIndexX(const int&, Neighbour::Type);
    int transformIndexY(const int&, Neighbour::Type);
    bool validIndex(const int&, const int&) const;
    bool validIndexX(const int&) const;
    bool validIndexY(const int&) const;
};

#endif // BOARD_H
