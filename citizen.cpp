#include "citizen.h"
#include <QTimer>

Citizen::Citizen(QList<QPoint> positions)
{
    this->positions = positions;

    QPixmap map(":/map1/Castle.png");
    setPixmap(map.scaled(50, 50));
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(MoveToNextPostion()));
    timer->start();
}
void Citizen::MoveToNextPostion()
{
    QPoint currentPosition = positions[currentIndex];
    QPoint nextPosition = positions[currentIndex + direction];

    QPointF directionVector = nextPosition - currentPosition;

    setPos(pos() + directionVector  * 0.005);

    QPoint currentPoint(x(), y());

    if (currentPoint == nextPosition && currentIndex != this->positions.count() - 1)
    {
        currentIndex += direction;
    }

    if (currentIndex == positions.count() - 1)
    {
        direction = -1;
    }

    if (currentIndex == 0)
    {
        direction = 1;
    }
}
