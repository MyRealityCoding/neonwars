#include "board.h"
#include "settings.h"

#include <QBrush>
#include <iostream>
#include <cmath>

Board::Board(Preview *a, Preview *b)
    : previewA(a), previewB(b), currentPlayer(Player::PLAYER1)
{
    for (int x = 0;  x < Settings::COLUMN_COUNT; ++x)
    {
        for (int y = 0; y < Settings::ROW_COUNT; ++y)
        {
            Ship *ship = new Ship();

            if (validIndex(x, y))
            {
                _map[x][y] = ship;
            }
        }

        _rows[x] = 0;
    }
}

void Board::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setOpacity(Settings::PANEL_OPACITY);
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
    return QRectF(Settings::GLOBAL_PADDING, Settings::WINDOW_HEIGHT - getHeight() - Settings::GLOBAL_PADDING, getWidth(), getHeight());
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

void Board::reset()
{
    for (int y = 0; y < Settings::ROW_COUNT; ++y)
    {
        for (int x = 0; x < Settings::COLUMN_COUNT; ++x)
        {
            if (hasShip(x, y))
            {
                remove(x, y);
            }
        }
    }

    previewA->reset();
    previewB->reset();
}

std::vector<QPoint> Board::getShips(const int &x, const int &y, const QVector2D &dir)
{
    QVector2D normalized = dir;
    std::vector<QPoint> points;

    if (normalized.x() <= -1.f)
    {
        normalized.setX(-1.0f);
    }
    else if (normalized.x() >= 1.f)
    {
        normalized.setX(1.f);
    }
    else
    {
        normalized.setX(0);
    }

    if (normalized.y() <= -1.f)
    {
        normalized.setY(-1.0f);
    }
    else if (normalized.y() >= 1.f)
    {
        normalized.setY(1.f);
    }
    else
    {
        normalized.setY(0);
    }

    if (normalized.length() == 0)
    {
        return points;
    }

    // Direction 1
    int localX = x, localY = y;

    while ((localX - 1) >= 0 && (localX + 1) < Settings::COLUMN_COUNT &&
           (localY - 1) >= 0 && (localY + 1) < Settings::ROW_COUNT)
    {
        localX += normalized.x();
        localY += normalized.y();

        if (hasShip(localX, localY))
        {
            points.push_back(QPoint(localX, localY));
        }
    }

    // Direction 2
    localX = x, localY = y;

    while ((localX - 1) >= 0 && (localX + 1) < Settings::COLUMN_COUNT &&
           (localY - 1) >= 0 && (localY + 1) < Settings::ROW_COUNT)
    {
        localX -= normalized.x();
        localY -= normalized.y();
        if (hasShip(localX, localY))
        {
            points.push_back(QPoint(localX, localY));
        }
    }

    return points;
}

Ship* Board::getShip(const int &x, const int &y, Neighbour::Type type)
{
    int indexX = transformIndexX(x, type);
    int indexY = transformIndexY(y, type);

    if (validIndex(indexX, indexY))
    {
        return _map[indexX][indexY];
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

bool Board::canAdd(const int &columnIndex) const
{
    if (validIndexX(columnIndex))
    {
        int indexY = Settings::ROW_COUNT - _rows[columnIndex] - 1;

        if (validIndexY(indexY))
        {
            return true;
        }
    }

    return false;
}

bool Board::add(Ship *ship, int indexX)
{
    if (validIndexX(indexX))
    {
        int indexY = Settings::ROW_COUNT - _rows[indexX] - 1;

        if (validIndexY(indexY))
        {
            _rows[indexX]++;
            _map[indexX][indexY] = ship;
            _map[indexX][indexY]->triggerBehavior(this, indexX, indexY);
            update();
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}

bool Board::remove(const int &indexX, const int &indexY)
{
    // Validate index
    if (!validIndex(indexX, indexY))
    {
        return false;
    }

    // Check if it's the top element, otherwise iterate
    if (indexY == 0 || getShip(indexX, indexY, Neighbour::UPPER)->getType() == Ship::NONE)
    {
        removeByColumn(indexX);
        update();
        return true;
    }
    else
    {
        // Remove the current element
        _rows[indexX]--;

        int localIndexY = indexY;
        int startY = indexY;

        // Swap everything 1 row down. Reason: Gravity :)
        while (localIndexY >= 0 && _map[indexX][localIndexY]->getType() != Ship::NONE)
        {
            if (localIndexY == startY)
            {
                _map[indexX][localIndexY]->setType(Ship::NONE);
            }
            else
            {
                _map[indexX][localIndexY + 1]->setType(_map[indexX][localIndexY]->getType());
                _map[indexX][localIndexY]->setType(Ship::NONE);
            }

            localIndexY--;
        }

        update();

        return true;
    }

    return false;
}


int Board::transformIndexX(const int &x, Neighbour::Type type)
{
    if (type == Neighbour::LEFT || type == Neighbour::LOWER_LEFT || type == Neighbour::UPPER_LEFT)
    {
        return x - 1;
    }
    else if (type == Neighbour::RIGHT || type == Neighbour::LOWER_RIGHT || type == Neighbour::UPPER_RIGHT)
    {
        return x + 1;
    }

    return x;
}

int Board::transformIndexY(const int &y, Neighbour::Type type)
{
    if (type == Neighbour::UPPER || type == Neighbour::UPPER_LEFT || type == Neighbour::UPPER_RIGHT)
    {
        return y - 1;
    }
    else if (type == Neighbour::LOWER || type == Neighbour::LOWER_LEFT || type == Neighbour::LOWER_RIGHT)
    {
        return y + 1;
    }

    return y;
}

bool Board::validIndex(const int &indexX, const int &indexY) const
{
    return validIndexX(indexX) && validIndexY(indexY);
}

bool Board::validIndexX(const int &indexX) const
{
    return indexX >= 0 && indexX < Settings::COLUMN_COUNT;
}

bool Board::validIndexY(const int &indexY) const
{
    return indexY >= 0 && indexY < Settings::ROW_COUNT;
}

bool Board::removeByColumn(const int &indexX)
{
    if (validIndexX(indexX))
    {
        int indexY = Settings::ROW_COUNT - _rows[indexX];

        if (validIndexY(indexY))
        {
            _rows[indexX]--;
            _map[indexX][indexY]->setType(Ship::NONE);
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}
std::vector<QPoint> Board::getNeighbours(const int& x, const int& y)
{
    std::vector<QPoint> result;

    // Provide bounds
    const int startX = (x - 1) >= 0 ? x - 1 : 0;
    const int startY = (y - 1) >= 0 ? y - 1 : 0;
    const int endX   = (x + 1) < Settings::COLUMN_COUNT ? x + 1 : Settings::COLUMN_COUNT - 1;
    const int endY   = (y + 1) < Settings::ROW_COUNT ? y + 1 : Settings::ROW_COUNT - 1;

    // Build neigbour bounds
    for (int localY = startY; localY <= endY; localY++)
    {
        for (int localX = startX; localX <= endX; localX++)
        {
            if (hasShip(localX, localY) && (localX != x || localY != y))
            {
                std::cout << "Found Neighbour!" << std::endl;
                result.push_back(QPoint(localX, localY));
            }
        }
    }

    return result;
}

void Board::mousePressEvent(QGraphicsSceneMouseEvent * Event)
{
    float column = (Event->pos().x()-Settings::GLOBAL_PADDING)/ ( float(this->getCellSize()));
    Preview * prev;
    if(this->currentPlayer == Player::PLAYER1)
    {
        prev = previewA;
    }
    else
    {
        prev =previewB;
    }
    if(this->canAdd(column))
    {
        this->add(prev->fetch(), column);
        if(this->currentPlayer == Player::PLAYER1){
            currentPlayer = Player::PLAYER2;
        }
        else
        {
            currentPlayer = Player::PLAYER1;
        }
    }

}

