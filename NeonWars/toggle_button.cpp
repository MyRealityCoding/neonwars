#include <QPainter>

#include "toggle_button.h"
#include "settings.h"
#include "board.h"

#include <iostream>

ToggleButton::ToggleButton(Board *board)
    : board(board), image(NULL)
{

}

QRectF ToggleButton::boundingRect() const
{
    return QRect(Settings::WINDOW_WIDTH / 2 - board->getCellSize() / 2, Settings::GLOBAL_PADDING, board->getCellSize(), board->getCellSize());
}

void ToggleButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    reloadImage();

    QRectF rect = boundingRect();

    if (image != NULL)
    {
        painter->drawImage(rect, *image);
    }
}

void ToggleButton::mousePressEvent(QGraphicsSceneMouseEvent * Event)
{
    board->toggleKIMode();
    update();
}


void ToggleButton::reloadImage()
{
    if (board->isAIMode())
    {
        image = new QImage(":BTN_AI");
    }
    else
    {
        image = new QImage(":BTN_PVP");
    }
}
