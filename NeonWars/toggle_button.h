#ifndef TOGGLE_BUTTON_H
#define TOGGLE_BUTTON_H

#include <QGraphicsObject>
#include <QImage>

class Board;

class ToggleButton : public QGraphicsObject
{
    Q_OBJECT
private:
    Board *board;
    QImage *image;
signals:

public slots:
public:
    ToggleButton(Board*);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *);
private:
    void reloadImage();
};

#endif // TOGGLE_BUTTON_H
