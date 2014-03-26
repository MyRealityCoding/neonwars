#include "board.h"
#include "settings.h"

#include <QBrush>
#include <iostream>

Board::Board(int rows, int columns)
{
    for (int x = 0;  x < Settings::COLUMN_COUNT; ++x)
    {
        for (int y = 0; y < Settings::ROW_COUNT; ++y)
        {
            Ship *ship = new Ship();
            map[x][y] = ship;
        }
    }
}

void Board::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setOpacity(0.7);
    painter->fillRect(QRect(Settings::GLOBAL_PADDING, Settings::WINDOW_HEIGHT - getHeight() - Settings::GLOBAL_PADDING, getWidth(), getHeight()), Qt::SolidPattern);

    for (int x = 0;  x < Settings::COLUMN_COUNT; ++x)
    {
        for (int y = 0; y < Settings::ROW_COUNT; ++y)
        {
            painter->setOpacity(1.0);

            int cellX = Settings::GLOBAL_PADDING + x * getCellSize() + Settings::CELL_PADDING;
            int cellY = Settings::WINDOW_HEIGHT - getHeight() - Settings::GLOBAL_PADDING + y * getCellSize() + Settings::CELL_PADDING;
            int cellSize = getCellSize() - Settings::CELL_PADDING * 2;

            painter->fillRect(QRect(cellX,
                                    cellY,
                                    cellSize,
                                    cellSize),
                              Qt::Dense1Pattern);

            Ship *ship = getShip(x, y);

            if (ship != NULL)
            {
                ship->paint(cellX, cellY, cellSize, painter);
            }
        }
    }
}

QRectF Board::boundingRect() const
{
    return QRectF(QPoint(this->x() + Settings::GLOBAL_PADDING,this->y() + Settings::GLOBAL_PADDING),QPoint(this->x() + getWidth(),this->y()+ getHeight()));
}

int Board::getCellSize() const
{
    return (Settings::WINDOW_WIDTH - Settings::GLOBAL_PADDING * 2) / Settings::COLUMN_COUNT;
}

int Board::getWidth() const
{
    return getCellSize() * Settings::COLUMN_COUNT;
}

int Board::getHeight() const
{
    return getCellSize() * Settings::ROW_COUNT;
}

Ship* Board::getShip(const int &x, const int &y, Neighbour::Type type)
{
    int indexX = transformIndexX(x, type);
    int indexY = transformIndexY(y, type);

    if (indexX >= 0 && indexX < Settings::COLUMN_COUNT &&
        indexY >= 0 && indexY < Settings::ROW_COUNT)
    {
        return map[indexX][indexY];
    }
    else
    {
        return NULL;
    }
}

Ship* Board::getShip(const int &x, const int &y)
{
    return getShip(x, y, Neighbour::NONE);
}

bool Board::hasShip(const int &x, const int &y)
{
    return hasShip(x, y, Neighbour::NONE);
}

bool Board::hasShip(const int &x, const int &y, Neighbour::Type type)
{
    return getShip(x, y, type)->getType() != Ship::NONE;
}

void Board::add(Ship::Type, int columnIndex)
{

}

void Board::remove(const int &x, const int &y)
{

}


int Board::transformIndexX(const int &x, Neighbour::Type type)
{
    return x;
}

int Board::transformIndexY(const int &y, Neighbour::Type type)
{
    return y;
}
