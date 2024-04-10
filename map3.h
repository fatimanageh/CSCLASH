#ifndef Map3_H
#define Map3_H

#include <QDialog>
#include <QObject>
#include<QGraphicsScene>
#include"tiles.h"
class Map3 : public QDialog , public Tiles
{

public:
    explicit Map3(QWidget *parent = nullptr);

private:
    QGraphicsScene* scene;
    void setupScene();
    void loadmapfromfile(const QString &file);
    Tiles tileMap3;
};

#endif // Map3_H
