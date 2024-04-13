#ifndef CITIZEN_H
#define CITIZEN_H

#include<QGraphicsItem>
#include<QObject>
#include<QList>

class Citizen : public QObject, public QGraphicsPixmapItem
{
public:
    Citizen(QList<QPoint>);
    QList<QPoint> positions;
    int currentIndex = 0;
    int direction = 1;

public slots:
    void MoveToNextPostion();
};

#endif // CITIZEN_H
