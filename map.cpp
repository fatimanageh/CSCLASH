#include "map.h"
#include "ui_map.h"
#include<QFile>
#include"map1.h"
#include"map2.h"
#include"map3.h"
#include<QTextStream>
#include<QMessageBox>
Map::Map(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Map)
{
    ui->setupUi(this);
}

Map::~Map()
{
    delete ui;
}

void Map::on_Map1PB_clicked()
{

    hide();
    MAP1* map1 = new MAP1();
    map1->show();

}

void Map::on_Map2PB_clicked()
{
    hide();
    MAP2* map2 = new MAP2();
    map2->show();

}


void Map::on_Map3PB_clicked()
{
    hide();
    MAP3* map3 = new MAP3();
    map3->show();

}

