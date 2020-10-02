#include "obstacle.h"

Obstacle::Obstacle(): _position(),
                     _classObject(0),
                     _width(0),
                     _height(0),
                     _visability(0)
{
    _statusObstacle = StatusObstacle::SEEN;
}

Obstacle::Obstacle( int cl, QVector3D position, float width, float height, bool visible):
                    _position(position),
                    _classObject(cl),
                    _width(width),
                    _height(height),
                    _visability(visible)
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

int Obstacle::getClassOfObject() const
{
    return _classObject;
}

const bool Obstacle::getVisability() const
{
    return _visability;
}
