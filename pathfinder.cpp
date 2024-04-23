#include "pathfinder.h"
#include "math.h"
#include <QList>
#include <QPoint>


PathFinder::PathFinder(QPoint start, QPoint end, QHash<QPoint, Node*> grid)
{
    int minX = 0;
    int minY = 0;
    int maxX = 9;
    int maxY = 10;



    for (int i = minX; i < maxX; i++)
    {
        for (int j = minY; j < minY; j++)
        {
            grid[QPoint(i, j)]->connectedTo = nullptr;
            grid[QPoint(i, j)]->gCost = INT32_MAX;
        }
    }

    QPoint min = QPoint(minX, minY);
    QPoint max = QPoint(maxX, maxY);
    QList<Node*> openList;
    QList<Node*> closedList;
    Node* startNode = new Node(start);
    startNode->gCost = 0;
    startNode->hCost = CalculateDistance(start, end);

    openList.push_back(startNode);

    while(openList.count() > 0)
    {
        Node* lowestfCostNode = GetLowestfCostNode(openList);
        for (int i = 0; i < openList.count(); i++)
        {
            if (lowestfCostNode == openList.at(i))
            {
                openList.removeAt(i);
            }
        }
        closedList.push_back(lowestfCostNode);

        if (lowestfCostNode->coords.x() == end.x() && lowestfCostNode->coords.y() == end.y())
        {
            ConstructPath(lowestfCostNode);
            return;
        }

        foreach(Node* neighbour, GetNeighbours(lowestfCostNode, min, max, grid))
        {
            if(closedList.contains(neighbour) || !neighbour->isWalkable) continue;

            int tentativegCost = lowestfCostNode->gCost + CalculateDistance(start, neighbour->coords);

            if (tentativegCost < neighbour->gCost)
            {
                neighbour->gCost = tentativegCost;
                neighbour->hCost = CalculateDistance(neighbour->coords, end);
                neighbour->connectedTo = lowestfCostNode;

                if (!openList.contains(neighbour)) openList.push_back(neighbour);
            }
        }
    }
}

int PathFinder::CalculateDistance(QPoint a, QPoint b)
{
    int x = abs(a.x() - b.x());
    int y = abs(a.y() - b.y());

    return fmin(x, y) * 14 + 10 * abs(x - y);
}

Node* PathFinder::GetLowestfCostNode(QList<Node*> list)
{
    Node* leastfCostNode = list.at(0);
    for (int i = 1; i < list.count(); i++)
    {
        Node* currentNode = list.at(i);
        if (currentNode->getfCost() < leastfCostNode->getfCost() || currentNode->getfCost() == leastfCostNode->getfCost() && currentNode->hCost < leastfCostNode->hCost)
        {
            leastfCostNode = currentNode;
        }
    }

    return leastfCostNode;
}

void PathFinder::ConstructPath(Node* end)
{
    QList<QPoint> pathReversed;
    pathReversed.push_back(end->coords);

    Node* currentNode = end;
    while(currentNode->connectedTo != nullptr)
    {
        pathReversed.push_back(currentNode->connectedTo->coords);
        currentNode = currentNode->connectedTo;
    }

    for (int i = pathReversed.count() - 1; i >= 0; i--)
    {
        path.push_back(pathReversed.at(i));
    }
}

QList<Node*> PathFinder::GetNeighbours(Node* node, QPoint min, QPoint max, QHash<QPoint, Node*> grid)
{
    QList<Node*> neighbours;
    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0) continue;
            QPoint neighbourCoords = node->coords + QPoint(i, j);
            if (neighbourCoords.x() >= min.x() && neighbourCoords.y() >= min.y() && neighbourCoords.x() <= max.x() && neighbourCoords.y() <= max.y())
            {
                Node* neighbour = grid[neighbourCoords];
                neighbours.push_back(neighbour);
            }
        }
    }

    return neighbours;
}
