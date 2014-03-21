#include "board.h"

Board::Board(int rows, int columns)
    : rows(rows), columns(columns)
{
    for (int x = 0;  x < columns; ++x)
    {
        for (int y = 0; y < rows; ++y)
        {
            Ship *ship = new Ship(NONE, EMPTY);
            map.insert(x, QPair<int, Ship*>(y, ship));
        }
    }
}

void Board::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // TODO
}

Ship* Board::getShip(const QPoint &point, NeighbourType type)
{
    // TODO
    return NULL;
}

Ship* Board::getShip(const QPoint &point)
{
    return NULL;
}

bool Board::hasShip(const QPoint &point)
{
    // TODO
    return false;
}

bool Board::hasShip(const QPoint &point, NeighbourType type)
{
    // TODO
    return false;
}

void Board::add(ShipType, int columnIndex)
{
    // TODO
}

void Board::remove(const QPoint&)
{
    // TODO
}
