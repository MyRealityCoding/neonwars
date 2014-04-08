#include "AI.h"
#include "board.h"
#include "preview.h"
#include "settings.h"

void SimpleAI::handle(Board *board, Preview *preview)
{
    QPoint point;

    for (int i = 0; i < Settings::AI_ITERATIONS; ++i)
    {
        point = findPosition(board, preview, point);
    }

    board->add(preview->fetch(), point.x());
}

QPoint SimpleAI::findPosition(Board *board, Preview *preview, const QPoint &last)
{
    // TODO AI
}
