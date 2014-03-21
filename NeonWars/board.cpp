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
    return nullptr;
}

Ship* Board::getShip(const QPoint &point)
{
    return nullptr;
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

void Board::add(Ship *ship)
{
    // TODO
}

void Board::remove(Ship *ship)
{
    // TODO
}
