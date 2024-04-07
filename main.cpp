
 #include "mainwindow.h"

#include <QApplication>
#include<QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QGraphicsView view;
    view.setFixedSize(1000,1000);
    QGraphicsScene *scene= new QGraphicsScene();
    scene->setSceneRect(0,0,1000,1000);
    view.setScene(scene);
    view.show();
    return a.exec();
}

