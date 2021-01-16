#ifndef CLOCKER_H
#define CLOCKER_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QDateTime>
#include <QMouseEvent>
#include "dateimp.h"
namespace Ui {
class Clocker;
}

class Clocker : public QWidget
{
    Q_OBJECT

public:
    explicit Clocker(QWidget *parent = nullptr);
    void showTime();
    QString getremaintime();
    QString getfinalyear();
    QString getfinalmonth();
    QString getfinalday();
    QString getfinalhour();
    QString getfinalminute();
    QString getfinalseconed();
    ~Clocker();

private:
    Ui::Clocker *ui;
    Dateimp dateimp;
    const int year = 2020;
    const int month = 12;
    const int day = 26;
    const int hour = 8;
    const int minute = 30;
    const int seconed = 0;
    bool m_bDrag;
    QPoint mouseStartPoint;
    QPoint windowTopLeftPoint;
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // CLOCKER_H
