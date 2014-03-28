#include "preview.h"
#include "settings.h"

#include <iostream>
#include <QPainter>

Preview::Preview(Player::Type type)
    : _playerType(type)
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

Ship* Preview::fetch()
{
    update();
    Ship* result = elements.takeLast();
    elements.append(provideNext());
    return result;
}

void Preview::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF bounds = boundingRect();
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setOpacity(Settings::PANEL_OPACITY);
    painter->fillRect(bounds, Qt::SolidPattern);
    QLinkedList<Ship*>::iterator it = elements.begin();
    for (int i = 0; i < Settings::PREVIEW_COUNT; ++i)
    {
        int size = Settings::PREVIEW_SIZE - Settings::CELL_PADDING * 2;
        int x = bounds.x() + Settings::CELL_PADDING + i * Settings::PREVIEW_SIZE;
        int y = bounds.y() + Settings::CELL_PADDING;
        painter->setOpacity(1.0);
        painter->fillRect(QRect(x, y, size, size),
                          Qt::Dense1Pattern);

        if (it != elements.begin())
            painter->setOpacity(0.2);
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
