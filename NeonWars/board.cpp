#include "board.h"
#include "settings.h"

#include <QBrush>
#include <iostream>

Board::Board(int rows, int columns)
    : rows(rows), columns(columns)
{
    for (int x = 0;  x < columns; ++x)
    {
        for (int y = 0; y < rows; ++y)
        {
            Ship *ship = new Ship();
            map.insert(x, QPair<int, Ship*>(y, ship));
        }
    }
}

void Board::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setOpacity(0.7);
    painter->fillRect(QRect(Settings::GLOBAL_PADDING, Settings::WINDOW_HEIGHT - getHeight() - Settings::GLOBAL_PADDING, getWidth(), getHeight()), Qt::SolidPattern);

    for (int x = 0;  x < columns; ++x)
    {
        for (int y = 0; y < rows; ++y)
        {
            painter->setOpacity(1.0);

            int cellX = x * getCellSize() + Settings::CELL_PADDING;
            int cellY = y * getCellSize() + Settings::CELL_PADDING;
            int cellSize = getCellSize() - Settings::CELL_PADDING * 2;
            painter->fillRect(QRect(Settings::GLOBAL_PADDING + cellX,
                                    Settings::WINDOW_HEIGHT - getHeight() - Settings::GLOBAL_PADDING + cellY,
                                    cellSize,
                                    cellSize),
                              Qt::Dense1Pattern);

            Ship *ship = getShip(x, y);
            ship->paint(cellX, cellY, cellSize, painter);
        }
    }
}

QRectF Board::boundingRect() const
{
    return QRectF(QPoint(this->x() + Settings::GLOBAL_PADDING,this->y() + Settings::GLOBAL_PADDING),QPoint(this->x() + getWidth(),this->y()+ getHeight()));
}

int Board::getCellSize() const
{
    return (Settings::WINDOW_WIDTH - Settings::GLOBAL_PADDING * 2) / columns;
}

int Board::getWidth() const
{
    return getCellSize() * columns;
}

int Board::getHeight() const
{
    return getCellSize() * rows;
}

Ship* Board::getShip(const int &x, const int &y, Neighbour::Type type)
{
    // TODO
    return NULL;
}

Ship* Board::getShip(const int &x, const int &y)
{
    return NULL;
}

bool Board::hasShip(const int &x, const int &y)
{
    // TODO
    return false;
}

bool Board::hasShip(const int &x, const int &y, Neighbour::Type type)
{
    // TODO
    return false;
}

void Board::add(Ship::Type, int columnIndex)
{
    // TODO
}

void Board::remove(const int &x, const int &y)
{
    // TODO
}
