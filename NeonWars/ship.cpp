#include "ship.h"
#include <QPainter>


void Ship::setType(ShipType type){
    switch (type){
        case EMPTY :;
        case NORMAL : image = QImage(":NORMAL");
        case ROCKET : image = QImage(":ROCKET");
        case BOMB : image = QImage(":BOMB");
        case LASER : image = QImage(":LASER");
        case PHASER: image = QImage(":PHASER");
        image = image.scaled(QSize(50,50));
    }
    this->update(this->x(),this->y(),this->boundingRect().width(),this->boundingRect().height());

}
QRectF Ship::boundingRect() const{
   return QRectF(QPoint(this->x(),this->y()),QPoint(this->x()+51,this->y()+51));
}

void Ship::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    if(type == EMPTY){
        painter->drawRect(QRect(QPoint(this->x(),this->y()),QSize(50,50)));
    }
    else{
    painter->drawImage(QPoint(this->x(),this->y()),image);
    }
}
