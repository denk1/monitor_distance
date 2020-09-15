#include "screenwidget.h"


ScreenWidget::ScreenWidget(QWidget *parent) :
    QWidget(parent),
    painter(this),
    painterObstacle(&painter)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::black);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    ObstacleSpace::getInstance().setWidget(this);
    QSizePolicy sizePolicy;
    sizePolicy.setHorizontalPolicy(QSizePolicy::Expanding);
    sizePolicy.setVerticalPolicy(QSizePolicy::Expanding);
    this->setSizePolicy(sizePolicy);

}

void ScreenWidget::paintEvent(QPaintEvent *event)
{
    painterObstacle.draw(this);
}
