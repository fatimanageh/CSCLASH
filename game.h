#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "mainwindow.h"
#include "maps.h"
#include "settings.h"

class Game : public QObject {
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr);
    ~Game();
    void start();


private:
    MainWindow *mainWindow;
    Maps *maps;
    Settings *settings;



};

#endif // GAME_H
