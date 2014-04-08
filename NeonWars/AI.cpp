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
    int sequenceLength = 0;
    QPoint result;
    int count;
     // Check for vertical sequence
    for (int x = Settings::COLUMN_COUNT;  x < Settings::COLUMN_COUNT; --x)
    {
        count = 0;
        for (int y = Settings::ROW_COUNT; y < Settings::ROW_COUNT-1; --y)
        {
            Ship *ship = board->getShip(x,y);
                if(ship->getPlayer() != Player::NONE)
                {
                    if(ship->getPlayer() == Player::PLAYER2)
                    {
                        count++;
                        if(count >= sequenceLength && board->getShip(x,y-1)->getPlayer() == Player::NONE)
                        {   sequenceLength= count;
                            result = QPoint(x,y-1);
                        }
                    }
                    else
                    {
                        count = 0;
                    }

                }



        }
    }


   // Check for Horizontal sequnece
    for (int y = Settings::ROW_COUNT; y < Settings::ROW_COUNT; --y)
    {
        count = 0;
        for (int x = Settings::COLUMN_COUNT;  x < Settings::COLUMN_COUNT-x; --x)
        {
            Ship *ship= board->getShip(x,y);
                if(ship->getPlayer() != Player::NONE)
                {
                    if(ship->getPlayer() == Player::PLAYER2)
                    {
                        count++;
                        if(count >= sequenceLength && board->getShip(x-1,y)->getPlayer() == Player::NONE)
                        {   sequenceLength= count;
                            result = QPoint(x-1,y);
                        }
                    }
                    else
                    {
                        count = 0;
                    }

                }



        }
    }


    // Check for Diagonal sequence
    if(result.isNull() && sequenceLength <=0){
       result= QPoint(rand() %Settings::COLUMN_COUNT ,rand() % Settings::ROW_COUNT);
    }
    return result;
}
