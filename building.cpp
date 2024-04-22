#include "building.h"

Building::Building(QPoint coords, QPixmap map)
{
    setPixmap(map);
    this->coords = coords;
}
