#ifndef WIDGET_H
#define WIDGET_H
#include "mythread.h"
#include "myscene.h"
#include <QMainWindow>
#include <QWidget>
#include"background.h"
#include "cross.h"

namespace Ui {
class widget;
}

class widget : public QMainWindow
{
    Q_OBJECT

public:
    explicit widget(QMainWindow *parent = 0);
    ~widget();

private:
    Ui::widget *ui;
//    Background* back;
//    Street *east;
//    Street *west;
//    Street *south;
//    Street *north;

    MyThread *thread;
//    MyScene *cross;
    Cross *cross;

signals:
    void update();
private slots:

    void on_actionLogs_triggered();
};

#endif // WIDGET_H
