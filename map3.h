<<<<<<< HEAD
#ifndef MAP3_H
#define MAP3_H

#include <QDialog>

namespace Ui {
class MAP3;
}

class MAP3 : public QDialog
{
    Q_OBJECT

public:
    explicit MAP3(QWidget *parent = nullptr);
    ~MAP3();

private:
    Ui::MAP3 *ui;
};

#endif // MAP3_H
=======
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
>>>>>>> 03ae53d56e40e85bd84ec031a80cbf56a2614d5a
