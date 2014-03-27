#include "behavior.h"
#include "ship.h"
#include "board.h"


void NormalBehavior::trigger(Board *board, const int &x, const int &y)
{

}

void  LaserBehavior::trigger(Board *board, const int &x, const int &y)
{
    std::vector<QPoint> vector = board->getShips(x,y,Neighbour::UPPER, Neighbour::LOWER);
    foreach (QPoint var, vector) {
         board->remove(var.x(),var.y());
    }
}
void BombBehavior::trigger(Board *board, const int &x, const int &y)
{
    std::vector<QPoint> vector = board->getNeighbours(x,y);
    foreach (QPoint var, vector) {
         board->remove(var.x(),var.y());
    }
    board->remove(x,y);

}

void RocketBehavior::trigger(Board *board, const int &x, const int &y)
{
    Player::Type player(board->getShip(x,y)->getPlayer());
    std::vector<QPoint> vector = board->getNeighbours(x,y);
    foreach (QPoint var, vector) {
        if(board->getShip(var.x(),var.y())->getPlayer() == !player){
            board->remove(var.x(),var.y());
        }
    }
}

void PhaserBehavior::trigger(Board *board, const int &x, const int &y)
{
    Player::Type player(board->getShip(x,y)->getPlayer());
    //Get Diagonal 1
    std::vector<QPoint> vector1 = board->getShips(x,y,Neighbour::UPPER_LEFT, Neighbour::LOWER_RIGHT);
    foreach (QPoint var, vector1) {
        if(board->getShip(var.x(),var.y())->getPlayer() == !player){
            board->remove(var.x(),var.y());
        }
    }
    // Get Diagonal 2

    std::vector<QPoint> vector2 = board->getShips(x,y,Neighbour::LOWER_LEFT, Neighbour::UPPER_RIGHT);
    foreach (QPoint var, vector2) {
        if(board->getShip(var.x(),var.y())->getPlayer() == !player){
            board->remove(var.x(),var.y());
        }
    }
}
