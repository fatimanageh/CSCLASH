#ifndef Map2_H
#define Map2_H

#include <QDialog>
#include <QObject>
#include<QGraphicsScene>
#include"tiles.h"
class Map2 : public QDialog , public Tiles
{

public:
    explicit Map2(QWidget *parent = nullptr);

private:
    QGraphicsScene* scene;
    void setupScene();
    void loadmapfromfile(const QString &file);
    Tiles tileMap1;
};

#endif // Map2_H
