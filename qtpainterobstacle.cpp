#include "qtpainterobstacle.h"
#include "obstaclespace.h"

QtPainterObstacle::QtPainterObstacle(QPainter* painter):
    _painter(painter), _widgetHeight(0), _widgetWidth(0)
{

}

void QtPainterObstacle::draw(QWidget *widget)
{
    QPainter painter(widget);
    _widgetHeight = widget->height();
    _widgetWidth = widget->width();
    const auto containerObjects = ObstacleSpace::getInstance().getObstacles();

    drawGrid(painter);
    for(const auto& obj : containerObjects) {
        painter.setPen(QPen(Qt::white, 12, Qt::DashDotLine, Qt::RoundCap));
        if(controlledSpace.verifyX(obj.second.getCoord().x()) && controlledSpace.verifyZ(obj.second.getCoord().z())) {
            painter.drawPoint(getScreenX(obj.second.getCoord().x()), getScreenY(obj.second.getCoord().z()));
        }
    }
}

int QtPainterObstacle::getScreenX(float x)
{
     return (x + 2.5) / 5.0 * static_cast<float>(_widgetWidth);
}

int QtPainterObstacle::getScreenY(float z)
{
    return _widgetHeight - static_cast<int>(z/5.0 * static_cast<float>(_widgetHeight));
}

void QtPainterObstacle::drawGrid(QPainter &qPainter)
{
    int hLineStep = _widgetHeight/5;
    int vLineStep = _widgetWidth/5;
    int xCurr = 0, yCurr = 0;
    QVector<QLine> lines;
    for(int i = 0; i < 5; i++) {
        lines.append(QLine(QPoint( 0, yCurr), QPoint(_widgetWidth, yCurr)));
        yCurr += hLineStep;
    }
    for(int i = 0; i < 5; i++) {
        lines.append(QLine(QPoint( xCurr, 0), QPoint(xCurr, _widgetHeight)));
        xCurr += vLineStep;
    }
    qPainter.setPen(QPen(QColor(0, 255, 0, 128), 1, Qt::DashDotLine, Qt::RoundCap));
    qPainter.drawLines(lines);
}
