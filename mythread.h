#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread(QObject *parent = nullptr);
    void start(int msec, Priority p);
    inline bool isRunning()const;
    inline int msecs() const;
signals:
    void already();
protected:
    void run();
private:
    bool mRunning;
    int mMsec;
};

bool MyThread::isRunning() const
{
    return mRunning;
}

int MyThread::msecs() const
{
    return mMsec;
}

#endif // MYTHREAD_H
