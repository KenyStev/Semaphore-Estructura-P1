#include "mythread.h"

MyThread::MyThread(QObject *parent): QThread(parent)
{
    mRunning=false;
    mMsec=0;
}

void MyThread::start(int msec, QThread::Priority p)
{
    mMsec = msec;
    mRunning = true;
    QThread::start(p);
}

void MyThread::run(){
    while(mRunning){
        emit already();
        msleep(mMsec);
    }
}
