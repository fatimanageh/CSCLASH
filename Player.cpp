#include"Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Enemy.h"


Player::Player(QGraphicsItem* parent):QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/photos/player.png").scaled(100,100));

}
void::Player::keyPressEvent(QKeyEvent* event){

}

void Player::spawn(){
    Enemy* enemy =new Enemy;
    scene()->addItem(enemy);


}
