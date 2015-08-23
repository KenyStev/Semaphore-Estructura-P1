#ifndef QUEUE_H
#define QUEUE_H
#include "car.h"
#include <QString>
#include <QPointF>

class Queue
{
public:
    Queue();
    Queue(WAY);

    Car *First,*Last;
    QString direction;
    WAY way;
    QPointF start;
    int size;

    void push(Car*);
    Car *pop();
    Car *first();
    void draw();
    void setWay(WAY);
    int length();
};

#endif // QUEUE_H
