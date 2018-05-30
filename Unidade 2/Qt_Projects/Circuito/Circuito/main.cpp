#include "mainwindow.h"
#include "circuito.h"
#include <QApplication>

Circuito C;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
