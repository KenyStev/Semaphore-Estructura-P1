#ifndef CROSS_H
#define CROSS_H
#include "myscene.h"
#include "street.h"
#include "background.h"
#include "mythread.h"
#include <QMutex>
#define MSEC 10

class Cross : public MyScene
{
public:
    Cross(QObject *parent);
    Cross(QObject *parent, MyThread *thread);

    void onUpdate();
    void update_semaphore();

private:
    Street *north,*south,*east,*west;
    Background *back;

    Car *cross_n_1,*cross_n_2;
    Car *cross_s_1,*cross_s_2;
    Car *cross_e_1,*cross_e_2;
    Car *cross_w_1,*cross_w_2;

    int frame;
    int change_semaphore;
    bool activo,crossing;

    MyThread *thread;
    QMutex *mutex;

    void cross_cars();
};

#endif // CROSS_H
