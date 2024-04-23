#include "mainwindow.h"
#include "ui_mainwindow.h"
<<<<<<< HEAD
#include "map.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

=======
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
    backgroundMusic(new QMediaPlayer(this)),
    intromusic(new QMediaPlayer(this)),
    click(new QMediaPlayer(this)),
    war(new QMediaPlayer(this))
{

    ui->setupUi(this);

    QPixmap background (":/Back/5dcf59a8d44ba57f29414c411.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    QAudioOutput* Backgroundmusic= new QAudioOutput();
    backgroundMusic->setSource(QUrl("qrc:/sounds/backgroundmusic.mp3"));
    Backgroundmusic->setVolume(1);
    backgroundMusic->setAudioOutput(Backgroundmusic);
    backgroundMusic->play();

    QAudioOutput* Click= new QAudioOutput();
    click->setSource(QUrl("qrc:/sounds/click.mp3"));
    Click->setVolume(1);
    click->setAudioOutput(Click);

    intromusic->setSource(QUrl("qrc:/sounds/intro.mp3"));
    QAudioOutput *Intromusic =new QAudioOutput();
    Intromusic->setVolume(1);
    intromusic->setAudioOutput(Intromusic);
    intromusic->play();

    war->setSource(QUrl("qrc:/sounds/war.mp3"));
    QAudioOutput *War =new QAudioOutput();
    War->setVolume(1);
    war->setAudioOutput(War);
}


>>>>>>> 03ae53d56e40e85bd84ec031a80cbf56a2614d5a
MainWindow::~MainWindow()
{
    delete ui;
}

<<<<<<< HEAD
void MainWindow::on_StartPB_clicked()
{
    hide();
    Map* map = new Map();
    map->show();
}

=======

void MainWindow::on_pushButtonStart_clicked()
{
    intromusic->stop();
    click->play();
    backgroundMusic->stop();
    war->play();
    hide();
    Maps* map= new Maps(this);
    map->show();
}

void MainWindow::setSoundVolume(float value)
{
    this->click->audioOutput()->setVolume(value);
}

void MainWindow::setMusicVolume(float value)
{
    this->backgroundMusic->audioOutput()->setVolume(value);
    this->intromusic->audioOutput()->setVolume(value);
    this->war->audioOutput()->setVolume(value);
}

void MainWindow::on_pushButtonSettings_clicked()
{

    intromusic->stop();
    click->play();

    hide();
    Settings* settings = new Settings(this, click, this->click->audioOutput()->volume(), this->backgroundMusic->audioOutput()->volume());
    settings->show();
}

>>>>>>> 03ae53d56e40e85bd84ec031a80cbf56a2614d5a
