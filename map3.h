#ifndef MAP3_H
#define MAP3_H

#include <QDialog>

namespace Ui {
class MAP3;
}

class MAP3 : public QDialog
{
    Q_OBJECT

public:
    explicit MAP3(QWidget *parent = nullptr);
    ~MAP3();

private:
    Ui::MAP3 *ui;
};

#endif // MAP3_H
