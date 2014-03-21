#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <ship.h>

class board : public QWidget
{
    Q_OBJECT
public:
    explicit board(QWidget *parent = 0);

signals:

public slots:

private:
    Ship board[6][7] ;

};

#endif // BOARD_H
