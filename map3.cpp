<<<<<<< HEAD
#include "map3.h"
#include "ui_map3.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
MAP3::MAP3(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MAP3)
{
    ui->setupUi(this);
    QFile file ("C:/Users/fatim/OneDrive/Documents/CSPROJECT/MAP3.txt");
    if (!file.open(QFile::ReadOnly|QFile::Text))
        QMessageBox::information(this,"title","file is not open");
    QTextStream in (&file);
    QString text = in.readAll();
    file.close();
}

MAP3::~MAP3()
{
    delete ui;
=======
#include "Map3.h"
#include "tiles.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include<QLayout>

Map3::Map3(QWidget *parent)
    : QDialog(parent)
{


    scene = new QGraphicsScene();


    setupScene();
}


void Map3::setupScene()
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


void Map3::loadmapfromfile(const QString &filename)
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
        Tiles tileMap3;
        QString line = in.readLine();
        QStringList characters = line.split(",", Qt::SkipEmptyParts);
        for (const QString& character : characters) {
            if (character == "0") {
                QGraphicsPixmapItem *image1 = new QGraphicsPixmapItem(tileMap3.map3land.scaled(pixelWidth, pixelHeight));
                image1->setPos(posX, posY);
                scene->addItem(image1);
            } else if (character == "1") {
                QGraphicsPixmapItem *image2 = new QGraphicsPixmapItem(tileMap3.map3Castle.scaled(pixelWidth, pixelHeight));
                image2->setPos(posX, posY);
                scene->addItem(image2);
            } else if (character == "2") {
                QGraphicsPixmapItem *image3 = new QGraphicsPixmapItem(tileMap3.map3Canon.scaled(pixelWidth, pixelHeight));
                image3->setPos(posX, posY);
                scene->addItem(image3);
            } else if (character == "3") {
                QGraphicsPixmapItem *image4 = new QGraphicsPixmapItem(tileMap3.map3Fence.scaled(pixelWidth, pixelHeight));
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
