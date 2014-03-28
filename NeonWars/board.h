#ifndef BOARD_H
#define BOARD_H


#include <QGraphicsObject>
#include <QMultiMap>
#include <QPaintEvent>
#include <QPainter>
#include "settings.h"
#include "ship.h"
#include <vector>
#include "preview.h"

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
    Preview *previewA, *previewB;
    Player::Type currentPlayer;
public:
    Board(Preview*, Preview*);

    Ship* getShip(const int &x, const int &y, Neighbour::Type);
    Ship* getShip(const int &x, const int &y);
    bool hasShip(const int &x, const int &y);
    bool hasShip(const int &x, const int &y, Neighbour::Type);
    bool add(Ship*, int columnIndex);
    bool remove(const int&, const int&);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int getWidth() const;
    int getHeight() const;
    int getCellSize() const;
    std::vector<QPoint> getNeighbours(const int&, const int&);

    /* Returns all positions in the given range.
     *
     * Example:
     *
     * std::vector<QPoint> diagonal1 = getShips(1, 1, Neighbour::UPPER_LEFT, Neighbour::LOWER_RIGHT);
     * std::vector<QPoint> diagonal2 = getShips(1, 1, Neighbour::LOWER_LEFT, Neighbour::UPPER_RIGHT);
     * std::vector<QPoint> vertical = getShips(1, 1, Neighbour::UPPER, Neighbour::LOWER);
     * std::vector<QPoint> horizontal = getShips(1, 1, Neighbour::LEFT, Neighbour::RIGHT);
     *
     * RETURNS only LEFT and UPPER_LEFT:
     * std::vector<QPoint> crap = getShips(1, 1, Neighbour::LEFT, Neighbour::UPPER_LEFT);
     *
     * RETURNS only UPPER and RIGHT:
     * std::vector<QPoint> crap = getShips(1, 1, Neighbour::UPPER, Neighbour::RIGHT);
     *
     * etc.
     */
    std::vector<QPoint> getShips(const int&, const int&, Neighbour::Type from, Neighbour::Type to);

signals:

public slots:

private:

    int transformIndexX(const int&, Neighbour::Type);
    int transformIndexY(const int&, Neighbour::Type);
    bool validIndex(const int&, const int&) const;
    bool validIndexX(const int&) const;
    bool validIndexY(const int&) const;
    bool removeByColumn(const int&);
};

#endif // BOARD_H
