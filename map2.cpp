#include "map2.h"
#include "ui_map2.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
MAP2::MAP2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MAP2)
{
    ui->setupUi(this);
    QFile file ("C:/Users/fatim/OneDrive/Documents/CSPROJECT/MAP2.txt");
    if (!file.open(QFile::ReadOnly|QFile::Text))
        QMessageBox::information(this,"title","file is not open");
    QTextStream in (&file);
    QString text = in.readAll();
    file.close();
}

MAP2::~MAP2()
{
    delete ui;
}
