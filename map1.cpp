#include "map1.h"
#include "tiles.h"
#include "node.h"
#include "pathfinder.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include<QLayout>
#include "Player.h"

Map1::Map1(QWidget *parent)
    : QObject(parent)
{
    scene = new QGraphicsScene();
    this->mainWindow = static_cast<MainWindow*>(parent);
    setupScene();

    //added
    Player* player= new Player;
    scene->addItem(player);
    player->setPos(800,-800);

}


void Map1::setupScene()
{


    loadmapfromfile(":/text/map1.txt");
    QGraphicsView* view = new QGraphicsView(scene);
    view->setFixedSize(scene->width(), scene->height());
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
}


void Map1::loadmapfromfile(const QString &filename)
{

    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this->mainWindow, "Error", "File is not open");
        return;
    }
    QTextStream in(&file);

    int posX = 0; // Initial position X
    int posY = 0; // Initial position Y
    int pixelWidth = 100; // Width of each pixel
    int pixelHeight = 100; // Height of each pixel

    int i = 0;
    QList<QString> lines;

    while (!in.atEnd()) {
        Tiles tilemap1;
        lines.append(in.readLine());
    }

    QHash<QPoint, Node*> grid;

    for (int i = 0; i < lines.count(); i++)
    {
        QString line = lines[i];
        for (int j = 0; j < line.length() / 2; j++)
        {
            Node* node = new Node(QPoint(i, j));
            QChar character = line[j * 2];
            if (character == '0') {
                node->isWalkable = true;
                QGraphicsPixmapItem *image1 = new QGraphicsPixmapItem(tilemap1.map1land.scaled(pixelWidth, pixelHeight));
                image1->setPos(posX, posY);
                scene->addItem(image1);
            } else if (character == '1') {
                node->isWalkable = false;
                QGraphicsPixmapItem *image2 = new QGraphicsPixmapItem(tilemap1.map1Castle.scaled(pixelWidth, pixelHeight));
                image2->setPos(posX, posY);
                scene->addItem(image2);
            } else if (character == '2') {
                node->isWalkable = false;
                QGraphicsPixmapItem *image3 = new QGraphicsPixmapItem(tilemap1.map1Canon.scaled(pixelWidth, pixelHeight));
                image3->setPos(posX, posY);
                scene->addItem(image3);
            } else if (character == '3') {
                node->isWalkable = false;
                QGraphicsPixmapItem *image1 = new QGraphicsPixmapItem(tilemap1.map1fence.scaled(pixelWidth, pixelHeight));
                image1->setPos(posX, posY);
                scene->addItem(image1);
                /*QChar charLeft = (j != 0) ? line[j - 1] : 'N';
                QChar charRight = (j != (line.length() - 1)) ? line[j + 1] : 'N';
                QChar charUp = (i != 0) ? lines[i - 1][j] : 'N';
                QChar charDown = (i != (lines.count() - 1)) ? lines[i + 1][j] : 'N';

                // Check neighboring nodes if they are fences to determine the correct fence picture
                QString corner = "3";
                if (charLeft == '3' && charUp == '3' && charRight == '3' && charDown == '3') {
                    corner = "center";
                } else if (charLeft == '3' && charUp == '3') {
                    corner = "topLeft";
                } else if (charRight == '3' && charUp == '3') {
                    corner = "topRight";
                } else if (charLeft == '3' && charDown == '3') {
                    corner = "bottomLeft";
                } else if (charRight == '3' && charDown == '3') {
                    corner = "bottomRight";
                } else if (charLeft == '3' && charRight == '3') {
                    corner = "horozintal";
                } else {
                    corner = "vertical";
                }


                QGraphicsPixmapItem* fence = new QGraphicsPixmapItem(tilemap1.fences1[corner].scaled(pixelWidth, pixelHeight));

                fence->setPos(posX, posY);
                scene->addItem(fence);*/

            }
            grid[node->coords] = node;
            posX += pixelWidth;
        }
        posX = 0;
        posY += pixelHeight;
    }

    QMessageBox::information(this->mainWindow, "Error", QString::number(grid.count()));
    PathFinder path(QPoint(0,0), QPoint(9,9), grid);


    file.close();

}
