#include "neonwarsgame.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NeonWarsGame w;
    w.show();

    return a.exec();
}
