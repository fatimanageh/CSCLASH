<<<<<<< HEAD
#ifndef MAP2_H
#define MAP2_H

#include <QDialog>

namespace Ui {
class MAP2;
}

class MAP2 : public QDialog
{
    Q_OBJECT

public:
    explicit MAP2(QWidget *parent = nullptr);
    ~MAP2();

private:
    Ui::MAP2 *ui;
};

#endif // MAP2_H
=======
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
>>>>>>> 03ae53d56e40e85bd84ec031a80cbf56a2614d5a
