
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

    file.close();

}

MAP1::~MAP1()
{
    delete ui;
}

