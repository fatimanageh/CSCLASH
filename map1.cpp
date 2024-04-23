<<<<<<< HEAD

 #include "map1.h"
#include "ui_map1.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QGraphicsPixmapItem>
#include<QGraphicsScene>


MAP1::MAP1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MAP1)
{
    ui->setupUi(this);


    //scene modification
    QGraphicsScene *scene = dynamic_cast<QGraphicsScene*>(parent->parent());
    if (!scene) {
        QMessageBox::information(this, "Error", "Unable to access QGraphicsScene");
        return;
    }



    QFile file (":/new/prefix1/Map1Trial");
    if (!file.open(QFile::ReadOnly|QFile::Text))
        QMessageBox::information(this,"title","file is not open");
    QTextStream in (&file);



   // Creating a land image object
    QPixmap land(":/Map/green land.jpg");
    land=land.scaledToWidth(100);
    land=land.scaledToHeight(100);
    QGraphicsPixmapItem * image1 = new QGraphicsPixmapItem();
    image1->setPixmap(land);
    image1->setPos(x(),y());
    scene->addItem(image1);


    //Creating an archery tower image object
    QPixmap archery_tower(":/Map/archery tower.png");
    archery_tower=archery_tower.scaledToWidth(100);
    archery_tower=archery_tower.scaledToHeight(100);
    QGraphicsPixmapItem * image2 = new QGraphicsPixmapItem;
    image2->setPixmap(archery_tower);
    image2->setPos(x(),y());
    scene->addItem(image2);

    //Creating a castle object
    QPixmap Castle(":/Map/canon.png");
    Castle=Castle.scaledToWidth(100);
    Castle=Castle.scaledToHeight(100);
    QGraphicsPixmapItem * image3 = new QGraphicsPixmapItem;
    image3->setPixmap(Castle);
    image3->setPos(x(),y());
    scene->addItem(image3);

    //Creating a fence object
    QPixmap fence(":/Map/fence.png");
    fence=fence.scaledToWidth(100);
    fence=fence.scaledToHeight(100);
    QGraphicsPixmapItem * image4 = new QGraphicsPixmapItem;
    image4->setPixmap(fence);
    image4->setPos(x(),y());
    scene->addItem(image4);


    //added

    while(!in.atEnd()){
        for (int ctrx=0; ctrx<10; ctrx++)
        {
            for (int ctry=0;ctry<10;ctry++)
            {
        QString character = in.read(1);
        if(character=='0')
        {
            //create empty land
            QPixmap land(":/Map/green land.jpg");
            land=land.scaledToWidth(100);
            land=land.scaledToHeight(100);
            QGraphicsPixmapItem * image1 = new QGraphicsPixmapItem();
            image1->setPixmap(land);
            image1->setPos(100*ctrx,100*ctry);
            scene->addItem(image1);

        }
        else if (character=='1'){
            //Creating a castle object
            QPixmap Castle(":/Map/canon.png");
            Castle=Castle.scaledToWidth(100);
            Castle=Castle.scaledToHeight(100);
            QGraphicsPixmapItem * image3 = new QGraphicsPixmapItem;
            image3->setPixmap(Castle);
            image3->setPos(100*ctrx,100*ctry);
            scene->addItem(image3);
        }
        else if (character=='2'){

            //Creating an archery tower image object
            QPixmap archery_tower(":/Map/archery tower.png");
            archery_tower=archery_tower.scaledToWidth(100);
            archery_tower=archery_tower.scaledToHeight(100);
            QGraphicsPixmapItem * image2 = new QGraphicsPixmapItem;
            image2->setPixmap(archery_tower);
            image2->setPos(100*ctrx,100*ctry);
            scene->addItem(image2);

        }
        else if (character=='3'){
            //Creating a fence object
            QPixmap fence(":/Map/fence.png");
            fence=fence.scaledToWidth(100);
            fence=fence.scaledToHeight(100);
            QGraphicsPixmapItem * image4 = new QGraphicsPixmapItem;
            image4->setPixmap(fence);
            image4->setPos(100*ctrx,100*ctry);
            scene->addItem(image4);
        }
        else{

        }
            }
        }

    }

   // QString text = in.readAll();
=======
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

>>>>>>> 03ae53d56e40e85bd84ec031a80cbf56a2614d5a

    file.close();

}
<<<<<<< HEAD

MAP1::~MAP1()
{
    delete ui;
}

=======
>>>>>>> 03ae53d56e40e85bd84ec031a80cbf56a2614d5a
