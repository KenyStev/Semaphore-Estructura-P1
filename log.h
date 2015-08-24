#ifndef LOG
#define LOG

#include <QString>
#include <car.h>

class Log
{
public:
    QString *log;
    Log *next;

    Log(Car* who,Car* with,QString street)
    {
        log = new QString("Car: " + who->name + " crached with: " + with->name + " at street: " + street);
        next=NULL;
    }

    Log(QString who,QString with,QString street)
    {
        log = new QString("Car: " + who + " crached with: " + with + " at street: " + street);
        next=NULL;
    }
};

#endif // LOG

