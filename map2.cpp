<<<<<<< HEAD
#include "map2.h"
#include "ui_map2.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
MAP2::MAP2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MAP2)
{
    ui->setupUi(this);
    QFile file ("C:/Users/fatim/OneDrive/Documents/CSPROJECT/MAP2.txt");
    if (!file.open(QFile::ReadOnly|QFile::Text))
        QMessageBox::information(this,"title","file is not open");
    QTextStream in (&file);
    QString text = in.readAll();
    file.close();
}

MAP2::~MAP2()
{
    delete ui;
=======
#include "Map2.h"
#include "tiles.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include<QLayout>

Map2::Map2(QWidget *parent)
    : QDialog(parent)
{


    scene = new QGraphicsScene();


    setupScene();
}


void Map2::setupScene()
{

    loadmapfromfile(":/text/map1.txt");
    QGraphicsView* view = new QGraphicsView(scene);
    view->setFixedSize(scene->width(), scene->height());
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setSceneRect(scene->sceneRect());


    view->show();

}


void Map2::loadmapfromfile(const QString &filename)
{

    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this, "Error", "File is not open");
        return;
    }
    QTextStream in(&file);

    int posX = 0; // Initial position X
    int posY = 0; // Initial position Y
    int pixelWidth = 100; // Width of each pixel
    int pixelHeight = 100; // Height of each pixel

    while (!in.atEnd()) {
        Tiles tileMap2;
        QString line = in.readLine();
        QStringList characters = line.split(",", Qt::SkipEmptyParts);
        for (const QString& character : characters) {
            if (character == "0") {
                QGraphicsPixmapItem *image1 = new QGraphicsPixmapItem(tileMap2.map2land.scaled(pixelWidth, pixelHeight));
                image1->setPos(posX, posY);
                scene->addItem(image1);
            } else if (character == "1") {
                QGraphicsPixmapItem *image2 = new QGraphicsPixmapItem(tileMap2.map2Castle.scaled(pixelWidth, pixelHeight));
                image2->setPos(posX, posY);
                scene->addItem(image2);
            } else if (character == "2") {
                QGraphicsPixmapItem *image3 = new QGraphicsPixmapItem(tileMap2.map2Canon.scaled(pixelWidth, pixelHeight));
                image3->setPos(posX, posY);
                scene->addItem(image3);
            } else if (character == "3") {
                QGraphicsPixmapItem *image4 = new QGraphicsPixmapItem(tileMap2.map2Fence.scaled(pixelWidth, pixelHeight));
                image4->setPos(posX, posY);
                scene->addItem(image4);
            }
            posX += pixelWidth; // Move to the next position on X-axis
        }
        posX = 0; // Reset position X
        posY += pixelHeight; // Move to the next position on Y-axis
    }

    file.close();
>>>>>>> 03ae53d56e40e85bd84ec031a80cbf56a2614d5a
}
