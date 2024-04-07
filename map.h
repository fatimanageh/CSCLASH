#ifndef MAP_H
#define MAP_H
#include"map1.h"
#include"map2.h"
#include"map3.h"
#include <QDialog>

namespace Ui {
class Map;
}

class Map : public QDialog
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = nullptr);
    ~Map();

private slots:
    void on_Map1PB_clicked();

    void on_Map2PB_clicked();

    void on_Map3PB_clicked();

private:
    Ui::Map *ui;
};

#endif // MAP_H
