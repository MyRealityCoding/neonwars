#include "board.h"

Board::Board()
{

}

void Board::paintEvent(QPaintEvent * q)
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
