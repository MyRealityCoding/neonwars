#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <stdio.h>

#include "settings.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene scene;
    scene.setSceneRect(QRect(0, 0, Settings::WINDOW_WIDTH, Settings::WINDOW_HEIGHT));

    QGraphicsView view(&scene);
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap(":BACKGROUND"));

    scene.addItem(item);
    view.setStyleSheet(":/Resources/style.qss");
    view.show();
    return a.exec();
}
