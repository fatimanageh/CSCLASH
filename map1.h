#ifndef MAP1_H
#define MAP1_H

#include<QDialog>
#include<QHash>
#include<QObject>
#include<QGraphicsScene>
#include"tiles.h"
#include"mainwindow.h"

class Map1 : public QObject , public Tiles
{

public:
    explicit Map1(QWidget *parent = nullptr);
    QGraphicsScene* scene;

private:
    void setupScene();
    void loadmapfromfile(const QString &file);
    Tiles tilemap1;
    MainWindow* mainWindow;
};

#endif // MAP1_H
