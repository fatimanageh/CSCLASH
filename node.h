
#ifndef NODE_H
#define NODE_H

#include <QPoint>

class Node
{
public:
    Node(QPoint);
    QPoint coords; //In int

    int gCost = INT32_MAX;
    int hCost = 0;
    Node* connectedTo;


    bool isWalkable;
    int getfCost()
    {
        return gCost + hCost;
    }
};

#endif // NODE_H
