#include "maps.h"
#include "ui_maps.h"
#include"map1.h"
#include"map2.h"
#include"map3.h"
#include<QMediaplayer>
#include<QAudioOutput>
#include"game.h"

extern Game* game;
Maps::Maps(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Maps),
    click(new QMediaPlayer(this)),
    war(new QMediaPlayer(this)),
    War(new QAudioOutput(this)),
    backgroundm(new QMediaPlayer(this)),
    Backgroundm(new QAudioOutput(this))
{
    ui->setupUi(this);
    QPixmap background (":/Back/Background.jpeg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);
    QPixmap Map1(":/map1/green land.jpg");
    ui->Map1label->setPixmap(Map1);
    QPixmap Map2(":/map2/desert land.png");
    ui->Map2label->setPixmap(Map2);
    QPixmap Map3(":/map3/ice land.png");
    ui->Map3label->setPixmap(Map3);

    backgroundm->setSource(QUrl::fromLocalFile("C:/Users/ASUS/Documents/TRIALCLASHOFCLANS/backgroundmusic.mp3"));
    Backgroundm->setVolume(100);
    backgroundm->setAudioOutput(Backgroundm);
    backgroundm->play();
    click->setSource(QUrl::fromLocalFile("C:/Users/ASUS/Documents/TRIALCLASHOFCLANS/click.mp3"));
    QAudioOutput *Click =new QAudioOutput();
    Click->setVolume(100);
    click->setAudioOutput(Click);



   war->setSource(QUrl::fromLocalFile("C:/Users/ASUS/Documents/TRIALCLASHOFCLANS/war.mp3"));
    War->setVolume(100);
    war->setAudioOutput(War);
}

Maps::~Maps()
{
    delete ui;
}


void Maps::on_pushButtonmap1_clicked()
{

    backgroundm->stop();
    click->play();
    war->play();
    hide();
    MAP1* map1 = new MAP1();
    map1->show();

}


void Maps::on_pushButtonmap2_clicked()
{
    backgroundm->stop();
    click->play();
    war->play();
    hide();
    Map2* map2 = new Map2();
    map2->show();

}


void Maps::on_pushButtonmap3_clicked()
{
    backgroundm->stop();
    click->play();
    war->play();
    hide();
    Map3* map3 = new Map3();
    map3->show();

}

