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
        int id = obj["ID"].toInt();
        int cl = obj["CL"].toInt();
        float x = obj["X"].toDouble();
        float y = obj["Y"].toDouble();
        float z = obj["Z"].toDouble();
        float height = obj["H"].toDouble();
        float width = obj["W"].toDouble();
        bool visible = obj["V"].toInt();

        mObstacles[id] = Obstacle(cl, QVector3D(x, y, z), width, height, visible);
    }
    if(ptrWidget != nullptr)
        ptrWidget->update();
}

void ObstacleSpace::setWidget(QWidget *widget)
{
    ptrWidget = widget;
}
