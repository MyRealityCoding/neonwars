#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <stdio.h>

#include "settings.h"
#include "board.h"
#include "preview.h"

int main(int argc, char *argv[])
{\
    srand(time(NULL));
    QApplication a(argc, argv);

    QGraphicsScene scene;
    scene.setSceneRect(QRect(0, 0, Settings::WINDOW_WIDTH, Settings::WINDOW_HEIGHT));

    QGraphicsView view(&scene);
    view.setWindowTitle(Settings::APP_TITLE + " v. " + Settings::APP_VERSION);

    QPixmap map(":BACKGROUND");

    // Scale the background properly
    map = map.scaledToHeight(Settings::WINDOW_HEIGHT);
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(map);

    scene.addItem(item);

    Preview previewPlayer1(Player::PLAYER1), previewPlayer2(Player::PLAYER2);
    Board board(&previewPlayer1, &previewPlayer2);

    scene.addItem(&board);

    scene.addItem(&previewPlayer1);
    scene.addItem(&previewPlayer2);

    //view.setStyleSheet(":STYLESHEET");
    view.show();
    return a.exec();
}
