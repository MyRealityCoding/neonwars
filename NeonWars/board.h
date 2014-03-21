#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsObject>

class Board : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit Board();

signals:

public slots:

private:
    QMultiMap<int, QPair<int, Ship*> > map;

};

#endif // BOARD_H
