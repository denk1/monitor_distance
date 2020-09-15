#include <QVBoxLayout>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "screenwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVBoxLayout* layout = new QVBoxLayout(ui->widgetMonitor);
    ScreenWidget* screenWidget = new ScreenWidget();
    layout->addWidget(screenWidget);
    QSizePolicy sizePolicy;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *pEvent)
{

}

