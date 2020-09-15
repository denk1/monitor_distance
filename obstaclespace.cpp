#include "obstaclespace.h"



ObstacleSpace::ObstacleSpace()
{
    //mObstacles[1] = Obstacle(QVector3D(10, 0, 10));
    //mObstacles[2] = Obstacle(QVector3D(250, 0, 250));
    //mObstacles[3] = Obstacle(QVector3D(250, 0, 200));
}

const ObstacleSpace::ObstacleContainer ObstacleSpace::getObstacles()
{
    std::lock_guard<std::mutex> lockObstacleSpace(mutexObstacleSpace);
    return mObstacles;
}

void ObstacleSpace::setObstacles(const QJsonObject qJsonObjectsObstacles)
{
    std::lock_guard<std::mutex> lockObstacleSpace(mutexObstacleSpace);
    mObstacles.clear();
    const QJsonArray jsonArray = qJsonObjectsObstacles["list_objects"].toArray();
    for(const auto& obj : jsonArray) {
        int id = obj["id"].toInt();
        float x = obj["x"].toDouble();
        float y = obj["y"].toDouble();
        float z = obj["z"].toDouble();
        mObstacles[id] = Obstacle(QVector3D(x, y, z));
    }
    if(ptrWidget != nullptr)
        ptrWidget->update();
}

void ObstacleSpace::setWidget(QWidget *widget)
{
    ptrWidget = widget;
}
