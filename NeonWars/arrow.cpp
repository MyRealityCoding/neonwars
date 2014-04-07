#include "arrow.h"
#include "board.h"
#include "ship.h"
#include <iostream>

void Arrow::draw(QPainter* painter, Board *b)
{
    int y = 0;

    painter->setOpacity(0.3f);

    int drawX = b->boundingRect().x() + b->getColumn((x + 1) * b->getCellSize()) * b->getCellSize();

    while (y < Settings::ROW_COUNT && !b->hasShip(x, y))
    {
        int drawY = b->boundingRect().y() + y * b->getCellSize();
        painter->drawRect(QRect(drawX, drawY, b->getCellSize(), b->getCellSize()));

        y++;

        if (!(y < Settings::ROW_COUNT && !b->hasShip(x, y)))
        {
            Preview *p = b->getPreview(b->getCurrentPlayer());
            Ship *s = p->top();
            painter->setOpacity(0.6);
            s->paint(drawX + Settings::CELL_PADDING, drawY + Settings::CELL_PADDING, b->getCellSize() - Settings::CELL_PADDING * 2, painter);
        }
    }

    if (y > 1) {
        painter->setOpacity(0.4);
        painter->drawImage(QRect(drawX + Settings::CELL_PADDING, b->boundingRect().y() + Settings::CELL_PADDING,
                                 b->getCellSize() - Settings::CELL_PADDING * 2, b->getCellSize() - Settings::CELL_PADDING * 2), *arr);
    }

}
