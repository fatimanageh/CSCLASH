#ifndef BUILDING_H
#define BUILDING_H

#include <QPoint>
#include <QGraphicsPixmapItem>

class Building : public QGraphicsPixmapItem
{
    int currentHitpoint;
    int maximumHitpoints = 5;
    bool isDestroyed = false; //For later usage;
public:

    QPoint coords;

    Building(QPoint, QPixmap);
};

#endif // BUILDING_H
