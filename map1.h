
 #ifndef MAP1_H
#define MAP1_H

#include <QDialog>

namespace Ui {
class MAP1;
}

class MAP1 : public QDialog
{
    Q_OBJECT

public:
    explicit MAP1(QWidget *parent = nullptr);
    ~MAP1();

private:
    Ui::MAP1 *ui;
};

#endif // MAP1_H

