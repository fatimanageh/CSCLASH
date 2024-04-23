<<<<<<< HEAD

 #ifndef MAP1_H
#define MAP1_H

#include <QDialog>

namespace Ui {
class MAP1;
}

class MAP1 : public QDialog
{
    Q_OBJECT

public:
    explicit MAP1(QWidget *parent = nullptr);
    ~MAP1();

private:
    Ui::MAP1 *ui;
};

#endif // MAP1_H

=======
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
>>>>>>> 03ae53d56e40e85bd84ec031a80cbf56a2614d5a
