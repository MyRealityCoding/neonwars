#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <stdio.h>
#include <QMediaPlayer>
#include <QMediaPlaylist>

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
    previewPlayer1.setBoard(&board);
    previewPlayer2.setBoard(&board);
    scene.addItem(&board);

    scene.addItem(&previewPlayer1);
    scene.addItem(&previewPlayer2);

    a.installEventFilter(&board);

    QMediaPlayer *p = new QMediaPlayer;

    p->setMedia(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + "/Resources/theme.mp3"));
    p->setVolume(50);
    p->play();
    view.show();
    return a.exec();
}
