#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include"maps.h"
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QPixmap>
#include<QMediaPlayer>
#include<QAudioOutput>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonStart_clicked();

    void on_pushButtonSettings_clicked();




private:
    Ui::MainWindow *ui;
    QMediaPlayer* intromusic;
    QMediaPlayer* click;
    QMediaPlayer* backgroundMusic;
};
#endif // MAINWINDOW_H
