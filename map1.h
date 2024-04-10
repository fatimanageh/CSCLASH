#ifndef MAP1_H
#define MAP1_H

#include <QDialog>
#include <QObject>
#include<QGraphicsScene>
#include"tiles.h"
class MAP1 : public QDialog , public Tiles
{

public:
    explicit MAP1(QWidget *parent = nullptr);

private:
    QGraphicsScene* scene;
    void setupScene();
    void loadmapfromfile(const QString &file);
    Tiles tilemap1;
};

#endif // MAP1_H
