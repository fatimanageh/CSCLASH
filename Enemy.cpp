#include "enemy.h"
#include <QMessageBox>

float dotProduct(QPointF a, QPointF b)
{
    return a.x() * b.x() + a.y() * b.y();
}

QPointF lerp(QPointF a, QPointF b, float t)
{
    return (1-t) * a + t * b;
}

float inverseLerp(QPointF a, QPointF b, QPointF v)
{
    QPointF ab = b - a;
    QPointF av = v - a;

    float nominator = dotProduct(ab, av);
    float denominator = dotProduct(ab, ab);

    return (nominator / denominator); // Or you can do it by components (i.e ab.y / av.y
    //but I like this because it looks more elegant
}

Enemy::Enemy(QPoint coords, QPixmap pixMap) : QGraphicsPixmapItem(nullptr), QObject(nullptr)
{
    setPixmap(pixMap);
    this->coords = coords;
}
void Enemy::processPath(QList<Node*> path, bool isCastlePath)
{
    this->currentNodeOnPath = 0;
    this->currentPath = path;
    this->isCastlePath = isCastlePath;
    currentTimer = new QTimer();
    connect(currentTimer, SIGNAL(timeout()), this, SLOT (moveOnPath()));
    currentTimer->start(15);
}

void Enemy::moveOnPath()
{
    if (currentNodeOnPath == currentPath.count() - 1 && !isCastlePath)
    {
        emit needNewPath();
        delete currentTimer;
    }


    Node* currentNode = currentPath[currentNodeOnPath];
    Node* nextNode = currentPath[currentNodeOnPath + 1];

    float currentValue = inverseLerp(QPointF(currentNode->coords) * 100, QPointF(nextNode->coords) * 100, pos());


    QPointF newPoint = lerp(QPointF(currentNode->coords) * 100, QPointF(nextNode->coords) * 100, currentValue + 0.005);

    setPos(newPoint);

    if (currentValue >= 1)
    {
        QMessageBox::information(nullptr, "changing", "changing");
        currentNodeOnPath++;
    }
}

