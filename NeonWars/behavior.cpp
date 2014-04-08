#include <QCoreApplication>

#include "behavior.h"
#include "ship.h"
#include "board.h"

Behavior::Behavior()
    : mediaPlayer(NULL)
{
    mediaPlayer = new QMediaPlayer;
}


void NormalBehavior::trigger(Board *board, const int &x, const int &y)
{
    // DO NOTHING!
}

void  LaserBehavior::trigger(Board *board, const int &x, const int &y)
{
    std::vector<QPoint> vector = board->getShips(x,y, QVector2D(0, 1));
    foreach (QPoint var, vector) {
         board->remove(var.x(),var.y());
    }
    board->remove(x,y);

    if (Settings::SOUNDS)
    {
        mediaPlayer->setMedia(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + "/Resources/explosion.mp3"));
        mediaPlayer->play();
    }
}

void BombBehavior::trigger(Board *board, const int &x, const int &y)
{
    std::vector<QPoint> vector = board->getNeighbours(x,y);

    for (unsigned int i = 0; i < vector.size(); ++i)
    {
         QPoint var = vector[i];
         board->remove(var.x(),var.y());
    }
    board->remove(x,y);

    if (Settings::SOUNDS)
    {
        mediaPlayer->setMedia(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + "/Resources/explosion.mp3"));
        mediaPlayer->play();
    }
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
    board->remove(x,y);

    if (Settings::SOUNDS)
    {
        mediaPlayer->setMedia(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + "/Resources/explosion.mp3"));
        mediaPlayer->play();
    }
}

void PhaserBehavior::trigger(Board *board, const int &x, const int &y)
{
    Player::Type player(board->getShip(x,y)->getPlayer());
    //Get Diagonal 1
    std::vector<QPoint> vector1 = board->getShips(x,y, QVector2D(1, 1));
    foreach (QPoint var, vector1) {
        if(board->getShip(var.x(),var.y())->getPlayer() == !player){
            board->remove(var.x(),var.y());
        }
    }
    // Get Diagonal 2

    std::vector<QPoint> vector2 = board->getShips(x,y, QVector2D(1, -1));
    foreach (QPoint var, vector2) {
        if(board->getShip(var.x(),var.y())->getPlayer() == !player){
            board->remove(var.x(),var.y());
        }
    }

    board->remove(x,y);

    if (Settings::SOUNDS)
    {
        mediaPlayer->setMedia(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + "/Resources/explosion.mp3"));
        mediaPlayer->play();
    }
}
