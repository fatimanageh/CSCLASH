#include "game.h"
#include <QUrl>

Game::Game(QObject *parent) : QObject(parent)
{
    mainWindow = new MainWindow();
    maps = new Maps();
    settings = new Settings();
    mainWindow->show();


}





Game::~Game() {
    delete mainWindow;
    delete maps;
    delete settings;

}
