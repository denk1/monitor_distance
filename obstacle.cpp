#include "obstacle.h"

Obstacle::Obstacle(): _position()
{
    _statusObstacle = StatusObstacle::SEEN;
}

Obstacle::Obstacle(QVector3D position): _position(position)
{
    _statusObstacle = StatusObstacle::SEEN;
}

void Obstacle::setStatus(StatusObstacle status)
{
    _statusObstacle = status;

}

const QVector3D &Obstacle::getCoord() const
{
    return _position;
}
