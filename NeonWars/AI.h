#ifndef AI_H
#define AI_H

#include <QPoint>

class Board;
class Preview;

class AI
{
public:
    virtual void handle(Board*, Preview*) = 0;
};

class SimpleAI : public AI
{
public:
    void handle(Board*, Preview*);
private:
    /* Finds a good position to insert for
     *
     * @param board current board
     * @param preview preview of this AI
     * @param last Last found point, maybe find a better one?
     */
    QPoint findPosition(Board *board, Preview *preview, const QPoint &last);
};

#endif // AI_H
