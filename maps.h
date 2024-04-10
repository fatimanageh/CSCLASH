#ifndef MAPS_H
#define MAPS_H
#include<QMediaPlayer>
#include <QDialog>

namespace Ui {
class Maps;
}

class Maps : public QDialog
{
    Q_OBJECT

public:
    explicit Maps(QWidget *parent = nullptr);
    QMediaPlayer* click;
    QMediaPlayer* war;
    QAudioOutput* War;
    QMediaPlayer* backgroundm;
    QAudioOutput* Backgroundm;

    ~Maps();

private slots:
    void on_pushButtonmap1_clicked();

    void on_pushButtonmap2_clicked();

    void on_pushButtonmap3_clicked();
signals:
    void stopBackgroundMusicRequested();


private:
    Ui::Maps *ui;

};

#endif // MAPS_H
