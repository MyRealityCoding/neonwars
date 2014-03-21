#include "ship.h"


void Ship::setType(ShipType type){
    switch (type){
        case NONE :;
        case NORMAL : image = QImage(":NORMAL") ;
        case ROCKET : image = QImage(":ROCKET");
        case BOMB : image = QImage(":BOMB");;
        case LASER : image = QImage(":LASER");;
        case PHASER: image = QImage(":PHASER");;
        image = image.scaled(QSize(50,50));
    }
    this->update(this->x(),this->y(),this->boundingRect().width(),this->boundingRect().height());

}
QRectF Ship::boundingRect() const{
   return QRectF(QPoint(this->x(),this->y()),QPoint(this->x()+51,this->y()+51));
}
