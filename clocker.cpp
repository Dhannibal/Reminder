#include "clocker.h"
#include "ui_clocker.h"
#include <QDockWidget>
#include <QDebug>
#include <QPainter>

Clocker::Clocker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Clocker)
{
    this->resize(700, 347);
    this->setFixedSize(this->size());
    ui->setupUi(this);
    //绑定事件
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Clocker::showTime);
    timer->start(1000);
    showTime();

//    this->setAttribute(Qt::WA_TranslucentBackground, true);
}

Clocker::~Clocker()
{
    delete ui;
}
void Clocker::showTime()
{
    QString remaintime = getremaintime();
//    ui->clocktext->setText(remaintime);
    ui->daylabel->setText(remaintime.mid(0, remaintime.indexOf("天"))+"天");
    ui->hourlabel->setText(remaintime.mid(remaintime.indexOf("天")+1, remaintime.indexOf("时")-remaintime.indexOf("天")-1)+"时");
    ui->minuslabel->setText(remaintime.mid(remaintime.indexOf("时")+1, remaintime.indexOf("分")-remaintime.indexOf("时")-1)+"分");
    ui->seconedminuslabel->setText(remaintime.mid(remaintime.indexOf("分")+1, remaintime.indexOf("秒")-remaintime.indexOf("分")-1)+"秒");
}

QString Clocker::getremaintime() {
    QDateTime curtime = QDateTime::currentDateTime();
    QString finaltimestr = getfinalyear()+"-"+getfinalmonth()+"-"+getfinalday()+" "+getfinalhour()+":"+getfinalminute()+":"+getfinalseconed();
    QDateTime finaltime = QDateTime::fromString(finaltimestr, "yyyy-MM-dd hh:mm:ss");
    qDebug()<<finaltime.time().hour();
    qDebug()<<finaltimestr;
    int t = curtime.secsTo(finaltime);
    int days = t/(60*60*24);
    int hours =  t%(60*60*24)/(60*60);
    int minutes = t%(60*60)/60;
    int seconeds = t%60;
    if(t < 0) {
        days = 0;
        hours = 0;
        minutes = 0;
        seconeds = 0;
    }
    qDebug()<<days<<" "<<hours<<" "<< minutes<<" "<<seconeds;
    QString res = QString::number(days) + "天" + QString::number(hours) + "时" + QString::number(minutes)+"分"+QString::number(seconeds)+"秒";
    qDebug()<<res;
    return res;
}
QString Clocker::getfinalyear() {
    QString res = QString("%1").arg(year, 4, 10, QChar('0'));
    return res;
}
QString Clocker::getfinalmonth() {
    QString res = QString("%1").arg(month, 2, 10, QChar('0'));
    return res;
}
QString Clocker::getfinalday() {
    QString res = QString("%1").arg(day, 2, 10, QChar('0'));
    return res;
}
QString Clocker::getfinalhour() {
    QString res = QString("%1").arg(hour, 2, 10, QChar('0'));
    return res;
}
QString Clocker::getfinalminute() {
    QString res = QString("%1").arg(minute, 2, 10, QChar('0'));
    return res;
}
QString Clocker::getfinalseconed() {
    QString res = QString("%1").arg(seconed, 2, 10, QChar('0'));
    return res;
}

void Clocker::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        {
            m_bDrag = true;
            //获得鼠标的初始位置
            mouseStartPoint = event->globalPos();
            //mouseStartPoint = event->pos();
            //获得窗口的初始位置
            windowTopLeftPoint = this->frameGeometry().topLeft();
        }
}
void Clocker::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bDrag)
        {
            //获得鼠标移动的距离
            QPoint distance = event->globalPos() - mouseStartPoint;
            //QPoint distance = event->pos() - mouseStartPoint;
            //改变窗口的位置
            this->move(windowTopLeftPoint + distance);
        }
}
void Clocker::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        {
            m_bDrag = false;
        }
}
