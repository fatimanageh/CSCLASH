#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPoint>
#include <QTimer>
#include "node.h"

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    QTimer* currentTimer;


    QList<Node*> currentPath;

    bool isCastlePath = false;


    int currentNodeOnPath = 0;

public:

    QPoint coords;
    Enemy(QPoint, QPixmap);
public slots:
    void processPath(QList<Node*>, bool);
    void moveOnPath();
signals:
    void needNewPath();
};

#endif // ENEMY_H
