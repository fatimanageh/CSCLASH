#include"Enemy.h"
#include<QTimer>
#include<QGraphicsScene>
#include <QList>
#include <stdlib.h>


Enemy::Enemy(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent){
    int random_number=rand()%900;
    setPos(random_number, 0);
    setPixmap(QPixmap(":/photos/enemy.png").scaled(100,100));


    QTimer* timer= new QTimer(this);
    connect (timer, SIGNAL(timeout()),this,SLOT(move()) );
    timer->start(50);
}

void Enemy::move(){
    if(pos().x()==500){
    setPos(x(),y()+5);
    }

    else if(pos().x()<500){
        setPos(x()+5,y()+5);
    }
    else {
        setPos(x()-5,y()+5);
    }


}
