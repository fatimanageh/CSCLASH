#ifndef TILES_H
#define TILES_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QMap>
#include<QPixmap>
class Tiles
{

public:
    Tiles();
    void settilemap1();
    QPixmap map1land;
    QPixmap map1Castle;
    QPixmap map1Canon;
    QPixmap map1fence;
    QPixmap map2land;
    QPixmap map2Castle;
    QPixmap map2Fence;
    QPixmap map2Canon;
    QPixmap map3land;
    QPixmap map3Castle;
    QPixmap map3Fence;
    QPixmap map3Canon;
    QMap<QString, QPixmap> fences1;
    int index;


};

#endif // TILES_H
