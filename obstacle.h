#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <QVector3D>

enum StatusObstacle {
    SEEN,
    UNSEEN
};

class Obstacle
{
public:
    Obstacle();
    Obstacle(int cl, QVector3D position, float width, float height, bool visible);
    void setCoord( int x, int y, int z);
    void setStatus(StatusObstacle status);
    const QVector3D& getCoord() const;
    int getClassOfObject() const;
    const bool getVisability() const;
private:
    QVector3D _position;
    StatusObstacle _statusObstacle;
    int _classObject;
    float _width;
    float _height;
    bool _visability;
};

#endif // OBSTACLE_H
