#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <stdio.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene scene;
    scene.setSceneRect(QRect(0, 0, 200, 200));
    QGraphicsView view(&scene);
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap(":BACKGROUND"));

    scene.addItem(item);
    view.show();
    return a.exec();
}
