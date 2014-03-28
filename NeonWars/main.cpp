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

    Board board;

    scene.addItem(&board);

    Preview previewPlayer1(Player::PLAYER1), previewPlayer2(Player::PLAYER2);

    scene.addItem(&previewPlayer1);
    scene.addItem(&previewPlayer2);


    board.add(previewPlayer1.fetch(), 1);
    board.add(previewPlayer2.fetch(), 1);
    board.add(previewPlayer1.fetch(), 1);
    board.add(previewPlayer2.fetch(), 1);
    board.add(previewPlayer1.fetch(), 3);
    board.add(previewPlayer2.fetch(), 3);
    board.add(previewPlayer2.fetch(), 0);
    //view.setStyleSheet(":STYLESHEET");
    view.show();
    return a.exec();
}
