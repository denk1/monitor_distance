#ifndef QTPAINTEROBSTACLE_H
#define QTPAINTEROBSTACLE_H

#include <QPainter>
#include <QWidget>
#include "painterobstacle.h"
#include "obstaclespace.h"
#include "controlledspace.h"

class QtPainterObstacle : public PainterObstacle
{
public:
    QtPainterObstacle(QPainter* painter);
    void draw(QWidget* widget ) override;


private:
    int getScreenX(float x);
    int getScreenY(float y);
    void drawGrid(QPainter& qPainter);

    QPainter* _painter;
    ControlledSpace controlledSpace;
    QWidget* _ptrWidget;
    int _widgetHeight;
    int _widgetWidth;

};

#endif // QTPAINTEROBSTACLE_H
