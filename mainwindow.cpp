#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clocker = new Clocker();
//    clocker->setWindowFlags(Qt::FramelessWindowHint);
    clocker->setWindowTitle("研究生考试倒计时");
    clocker->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
