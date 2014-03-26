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
    Ship* map[Settings::COLUMN_COUNT][Settings::ROW_COUNT];

    int transformIndexX(const int&, Neighbour::Type);
    int transformIndexY(const int&, Neighbour::Type);
};

#endif // BOARD_H
