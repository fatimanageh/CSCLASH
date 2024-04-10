#include "map1.h"
#include "tiles.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include<QLayout>

MAP1::MAP1(QWidget *parent)
    : QDialog(parent)
{


    scene = new QGraphicsScene();


    setupScene();
}


    void MAP1::setupScene()
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


    void MAP1::loadmapfromfile(const QString &filename)
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
        Tiles tilemap1;
        QString line = in.readLine();
        QStringList characters = line.split(",", Qt::SkipEmptyParts);
        for (const QString& character : characters) {
            if (character == "0") {
                QGraphicsPixmapItem *image1 = new QGraphicsPixmapItem(tilemap1.map1land.scaled(pixelWidth, pixelHeight));
                image1->setPos(posX, posY);
                scene->addItem(image1);
            } else if (character == "1") {
                QGraphicsPixmapItem *image2 = new QGraphicsPixmapItem(tilemap1.map1Castle.scaled(pixelWidth, pixelHeight));
                image2->setPos(posX, posY);
                scene->addItem(image2);
            } else if (character == "2") {
                QGraphicsPixmapItem *image3 = new QGraphicsPixmapItem(tilemap1.map1Canon.scaled(pixelWidth, pixelHeight));
                image3->setPos(posX, posY);
                scene->addItem(image3);
            } else if (character == "3") {
                QGraphicsPixmapItem *image4 = new QGraphicsPixmapItem(tilemap1.map1Fence.scaled(pixelWidth, pixelHeight));
                image4->setPos(posX, posY);
                scene->addItem(image4);
            }
            posX += pixelWidth; // Move to the next position on X-axis
        }
        posX = 0; // Reset position X
        posY += pixelHeight; // Move to the next position on Y-axis
    }

    file.close();
    }
