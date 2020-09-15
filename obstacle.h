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
    Obstacle(QVector3D position);
    void setCoord(int x, int y, int z);
    void setStatus(StatusObstacle status);
    const QVector3D& getCoord() const;
private:
    QVector3D _position;
    StatusObstacle _statusObstacle;
};

#endif // OBSTACLE_H
