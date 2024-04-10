#include "settings.h"
#include "ui_settings.h"
#include<QMediaPlayer>
#include"mainwindow.h"
#include<QDebug>
Settings::Settings(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Settings),
    backgroundm(new QMediaPlayer(this)),
    click(new QMediaPlayer(this)),
    Click (new QAudioOutput(this)),
    Backgroundm (new QAudioOutput(this))
{
    ui->setupUi(this);
    QPixmap background (":/Back/Background.jpeg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    ui->MusicButton->setChecked(Qt::Checked);
    ui->SoundButton->setChecked(Qt::Checked);

    ui->MusicGlider->setValue(100);
    ui->SoundGlider->setValue(100);

    backgroundm->setSource(QUrl::fromLocalFile("C:/Users/ASUS/Documents/TRIALCLASHOFCLANS/backgroundmusic.mp3"));
    Backgroundm->setVolume(100);
    backgroundm->setAudioOutput(Backgroundm);
    backgroundm->play();

    click->setSource(QUrl::fromLocalFile("C:/Users/ASUS/Documents/TRIALCLASHOFCLANS/click.mp3"));
    Click->setVolume(100);
    click->setAudioOutput(Click);


}

Settings::~Settings()
{
    delete ui;
    delete backgroundm;
}

void Settings::on_Back_clicked()
{
    backgroundm->stop();
    click->play();
    hide();
    MainWindow* mainwindow=new MainWindow();
    mainwindow->show();

}


void Settings::on_MusicButton_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
    {
        Backgroundm->setVolume(100);
    }
    else
    {
        Backgroundm->setVolume(0);
    }
}


void Settings::on_SoundButton_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
    {
        Click->setVolume(100);

    }
    else
    {
        Click->setVolume(0);
    }
}


void Settings::on_MusicGlider_valueChanged(int value)
{

 Backgroundm->setVolume(value);
}


void Settings::on_SoundGlider_valueChanged(int value)
{
    Click->setVolume(value);
}

