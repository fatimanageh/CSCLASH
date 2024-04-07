#ifndef MAP2_H
#define MAP2_H

#include <QDialog>

namespace Ui {
class MAP2;
}

class MAP2 : public QDialog
{
    Q_OBJECT

public:
    explicit MAP2(QWidget *parent = nullptr);
    ~MAP2();

private:
    Ui::MAP2 *ui;
};

#endif // MAP2_H
