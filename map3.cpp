#include "map3.h"
#include "ui_map3.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
MAP3::MAP3(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MAP3)
{
    ui->setupUi(this);
    QFile file ("C:/Users/fatim/OneDrive/Documents/CSPROJECT/MAP3.txt");
    if (!file.open(QFile::ReadOnly|QFile::Text))
        QMessageBox::information(this,"title","file is not open");
    QTextStream in (&file);
    QString text = in.readAll();
    file.close();
}

MAP3::~MAP3()
{
    delete ui;
}
