#ifndef LOG
#define LOG

#include <QString>
#include <car.h>

class Log
{
public:
    QString log;
    Log *next;

    Log(Car* who,Car* with,QString street)
    {
        log = "Car: " + who->name + " crached with: " + with->name + " at street: " + street;
    }
};

#endif // LOG

