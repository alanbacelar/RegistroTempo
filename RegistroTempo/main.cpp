#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    QTime *tempo = new QTime();
//    tempo->start();

//    for(int i = 0; i<10000; ++i)
//    {
//        qDebug() << i;
//    }

//    qDebug() << tempo->toString();
//    tempo->elapsed();

    return a.exec();
}
