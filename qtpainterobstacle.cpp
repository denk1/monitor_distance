#include <QStringLiteral>
#include "qtpainterobstacle.h"
#include "obstaclespace.h"

using namespace std;


QtPainterObstacle::QtPainterObstacle(QPainter* painter):
    _painter(painter), _widgetHeight(0), _widgetWidth(0),
    acc( tag::rolling_window::window_size = 1500)
{
    _prev_time_point = chrono::system_clock::now();
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
            painter.drawText(getScreenX(obj.second.getCoord().x()) + SHIFT_TITILE,
                             getScreenY(obj.second.getCoord().z()) + SHIFT_TITILE,
                             QString::fromStdString(controlledSpace.getObjectName(obj.first)));
        }
    }
    setFPS(painter);
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

void QtPainterObstacle::setFPS(QPainter &painter)
{
    auto time_point_now = chrono::system_clock::now();
    int duration =  std::chrono::duration_cast<std::chrono::microseconds>(time_point_now - _prev_time_point).count();
    int fps = 1000000 / duration;
    acc(double(fps));
    QFont font = painter.font();
    font.setPointSize(font.pointSize() * 2);
    painter.setPen(QPen(Qt::blue, 125, Qt::DashDotLine, Qt::RoundCap));
    painter.setFont(font);
    fps = static_cast<int>(rolling_mean(acc));
    QString strFps = QStringLiteral("%1 FPS").arg(fps);
    painter.drawText(QPoint(15, 35), strFps);
    _prev_time_point = time_point_now;
}
