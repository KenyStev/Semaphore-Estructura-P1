#ifndef CROSS_H
#define CROSS_H
#include "myscene.h"
#include "street.h"
#include "background.h"
#include "mythread.h"
#include "log.h"
#include <QMutex>
#define MSEC 10

class Cross : public MyScene
{
public:
    Cross(QObject *parent);

    void onUpdate();
    void update_semaphore();

private:
    Street *north,*south,*east,*west;
    Background *back;
    Stack<Log*> *logs;

    Car *cross_n_1,*cross_n_2;
    Car *cross_s_1,*cross_s_2;
    Car *cross_e_1,*cross_e_2;
    Car *cross_w_1,*cross_w_2;

    int frame,time_accident,quit_time;
    int change_semaphore;
    bool activo,crossing,accident;
    bool e1,e2,w1,w2,n1,n2,s1,s2;

//    bool crossInRed[11] = {false,true,false,false,false,false,false,false,false,true,false};
//    bool crossInRed[11] = {false,true,false,true,false,true,false,true,false,true,false};
    bool crossInRed[11] = {true,true,true,true,true,true,true,true,true,true,true};

    void cross_cars();
    void checkColisions(Car*&,bool*,Car*&,bool*,Car*&,bool*,Car*&,bool*,Car*&,bool*);
};

#endif // CROSS_H
