#ifndef MAINWINDOW_H
#define MAINWINDOW_H
<<<<<<< HEAD

#include <QMainWindow>

=======
#include <QMainWindow>
#include"maps.h"
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QPixmap>
#include<QMediaPlayer>
#include<QAudioOutput>
>>>>>>> 03ae53d56e40e85bd84ec031a80cbf56a2614d5a
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
<<<<<<< HEAD

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_StartPB_clicked();

private:
    Ui::MainWindow *ui;
=======
public:

    QMediaPlayer* war;
    QMediaPlayer* intromusic;
    QMediaPlayer* click;
    QMediaPlayer* backgroundMusic;
    QObject* selectedMap;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setSoundVolume(float);
    void setMusicVolume(float);

private slots:

    void on_pushButtonStart_clicked();
    void on_pushButtonSettings_clicked();

private:
    Ui::MainWindow* ui;

>>>>>>> 03ae53d56e40e85bd84ec031a80cbf56a2614d5a
};
#endif // MAINWINDOW_H
