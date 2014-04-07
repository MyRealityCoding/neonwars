#ifndef ARROW_H
#define ARROW_H

#include <QPainter>
#include <QImage>

#include "ship.h"

class Board;

class Arrow {
private:
    QImage *arr;
public:
    int x;
    Arrow() : x(0)
    {
        arr = new QImage(":ARROW");
    }
    void draw(QPainter* painter, Board*);
};

#endif // ARROW_H
