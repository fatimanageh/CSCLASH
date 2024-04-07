#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "map.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_StartPB_clicked()
{
    hide();
    Map* map = new Map();
    map->show();
}

