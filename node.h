
#ifndef NODE_H
#define NODE_H

#include <QPoint>

class Node
{
public:
    Node(QPoint);
    QPoint coords; //In int

    int gCost = 0;
    int hCost = INT32_MAX;
    Node* connectedTo;


    bool isWalkable;
    bool isVisited;
    int getfCost()
    {
        return gCost + hCost;
    }
};

#endif // NODE_H
