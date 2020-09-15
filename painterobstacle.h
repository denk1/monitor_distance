#ifndef PAINTEROBSTACLE_H
#define PAINTEROBSTACLE_H

#include "obstaclespace.h"
#include <QPainter>
#include <QWidget>

class PainterObstacle
{
public:
    PainterObstacle();
    virtual void draw(QWidget* widget) = 0;


protected:


private:

};

#endif // PAINTEROBSTACLE_H
