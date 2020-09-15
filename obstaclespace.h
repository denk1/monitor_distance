#ifndef OBSTACLESPACE_H
#define OBSTACLESPACE_H
#include <QJsonObject>
#include <QJsonArray>
#include <QWidget>
#include <map>
#include <mutex>
#include "obstacle.h"
#include "datasources.h"

inline std::mutex mutexObstacleSpace;

class ObstacleSpace
{
public:

    typedef std::map<int, Obstacle> ObstacleContainer;
    const ObstacleContainer getObstacles();
    static ObstacleSpace& getInstance() {
        static ObstacleSpace instance;
        return instance;
    }

    void setObstacles(QJsonObject qJsonObjectsObstacles);
    void setWidget(QWidget* widget);


private:
    ObstacleSpace();
    ~ObstacleSpace() = default;
    ObstacleSpace(const ObstacleSpace&) = delete;
    ObstacleSpace& operator=(const ObstacleSpace&) = delete;

    ObstacleContainer mObstacles;
    QWidget* ptrWidget = nullptr;
};

#endif // OBSTACLESPACE_H
