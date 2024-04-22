#ifndef MAP1_H
#define MAP1_H

#include <QHash>
#include "enemy.h"
#include <QObject>
#include <QGraphicsScene>
#include "tiles.h"
#include "mainwindow.h"
#include "building.h"
#include "node.h"

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
    QHash<QPoint, Node*> grid;
    QHash<QPoint, Node*> gridWithoutObstacles;

    Building* castle;
    QList<Building*> otherBuildings;

    QList<Enemy*> enemies;
public slots:
    void giveNewPath();
};

#endif // MAP1_H
