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
}

Ship* Board::getShip(const QPoint &point)
{
    // TODO
}

bool Board::hasShip(const QPoint &point)
{
    // TODO
}

bool Board::hasShip(const QPoint &point, NeighbourType type)
{
    // TODO
}

void Board::add(Ship *ship)
{
    // TODO
}

void Board::remove(Ship *ship)
{
    // TODO
}

void move(Ship *ship, const QPoint &point)
{
    // TODO
}
