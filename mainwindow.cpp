#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPixmap>
#include<QMediaPlayer>
#include<QAudioOutput>
#include <QUrl>
#include"maps.h"
#include"settings.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    intromusic( new QMediaPlayer(this)),
    click(new QMediaPlayer(this))
{

    ui->setupUi(this);
    QPixmap background (":/Back/5dcf59a8d44ba57f29414c411.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    backgroundMusic = new QMediaPlayer();
    QAudioOutput* Backgroundmusic= new QAudioOutput();
    Backgroundmusic = new QAudioOutput();
    backgroundMusic->setSource(QUrl::fromLocalFile("C:/Users/ASUS/Documents/TRIALCLASHOFCLANS/backgroundmusic.mp3"));
    Backgroundmusic->setVolume(100);
    backgroundMusic->setAudioOutput(Backgroundmusic);


    QMediaPlayer* click=new QMediaPlayer();
    QAudioOutput* Click= new QAudioOutput();
    click->setSource(QUrl::fromLocalFile("C:/Users/ASUS/Documents/TRIALCLASHOFCLANS/click.mp3"));
    Click->setVolume(100);
    click->setAudioOutput(Click);

    intromusic->setSource(QUrl::fromLocalFile("C:/Users/ASUS/Documents/TRIALCLASHOFCLANS/intro.mp3"));
    QAudioOutput *Intromusic =new QAudioOutput();
    Intromusic->setVolume(100);
    intromusic->setAudioOutput(Intromusic);
    intromusic->play();




}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonStart_clicked()
{

    intromusic->stop();
    click->play();
    backgroundMusic->stop();
    hide();
    Maps* map= new Maps();
    map->show();
}


void MainWindow::on_pushButtonSettings_clicked()
{

    intromusic->stop();
    click->play();

    hide();
    Settings* settings=new Settings();
    settings->show();
}

