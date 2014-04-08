#include "preview.h"
#include "settings.h"
#include "board.h"

#include <iostream>
#include <QPainter>

Preview::Preview(Player::Type type)
    : _playerType(type), board(NULL)
{
    for (int i = 0; i < Settings::PREVIEW_COUNT; ++i)
    {
        elements.push_back(provideNext());
    }
}

QRectF Preview::boundingRect() const
{
    int width = Settings::PREVIEW_COUNT * Settings::PREVIEW_SIZE;
    if (_playerType == Player::PLAYER1)
    {
        return QRect(Settings::GLOBAL_PADDING, Settings::GLOBAL_PADDING, width, Settings::PREVIEW_SIZE);
    }
    else
    {
        return QRect(Settings::WINDOW_WIDTH - Settings::GLOBAL_PADDING - width, Settings::GLOBAL_PADDING, width, Settings::PREVIEW_SIZE);
    }
}

 void Preview::reset()
 {
     for (int i = 0; i < Settings::PREVIEW_COUNT; ++i)
     {
         fetch();
     }
 }
Ship* Preview::top()
{
    return *elements.begin();
}

Ship* Preview::fetch()
{
    update();
    Ship* result = elements.takeFirst();
    elements.append(provideNext());
    return result;
}

void Preview::setBoard(Board *b)
{
    board = b;
}

void Preview::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF bounds = boundingRect();
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setOpacity(Settings::PANEL_OPACITY);

    if (board != NULL && board->getCurrentPlayer() == _playerType)
    {
        painter->setOpacity(1.0);
    }
    else
    {
        painter->setOpacity(0.5);
    }

    painter->setBrush(QColor(0, 0, 0));
    painter->fillRect(bounds, Qt::SolidPattern);
    QLinkedList<Ship*>::iterator it = elements.begin();
    for (int i = 0; i < Settings::PREVIEW_COUNT; ++i)
    {
        int size = Settings::PREVIEW_SIZE - Settings::CELL_PADDING * 2;
        int x = bounds.x() + Settings::CELL_PADDING + i * Settings::PREVIEW_SIZE;
        int y = bounds.y() + Settings::CELL_PADDING;

       if (it != elements.begin())
        {
            painter->setOpacity(0.2);
        }
        else if (board != NULL && board->getCurrentPlayer() == _playerType)
        {
            painter->setOpacity(1.0);
        }

        if (_playerType == Player::PLAYER2)
        {
            x = bounds.x() + Settings::CELL_PADDING + (Settings::PREVIEW_COUNT - i - 1) * Settings::PREVIEW_SIZE;
        }

        (*it)->paint(x, y, size, painter);

        it++;
    }
}

int random(int max)
{
    return rand() % max;
}

int randInt(int low, int high)
{
    return random(high) + low;
}

Ship* Preview::provideNext()
{
    Ship *ship = new Ship();
    Ship::Type type = Ship::NORMAL;
    if (randInt(0, 100) < Settings::SPECIAL_FACTOR)
    {
        type = static_cast<Ship::Type>(randInt(2, Ship::MAX - 1));
    }

    ship->setType(type);
    ship->setPlayer(_playerType);

    return ship;
}
