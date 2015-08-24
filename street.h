#ifndef STREET_H
#define STREET_H
#include "car.h"
#include "log.h"
#include "stack.h"
#include "queue.h"
#include "semaphore.h"

#include <iostream>
#include <vector>
#include <QPointF>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Street : public MyItem
{
public:
    Street(WAY,int);

    Queue *cola1,*cola2;
    Stack<Car*> *pila1,*pila2;
    bool draw;

    Car*getNewCar();
    void logica();
    void setSemaphore(WAY);
    void setPoints(WAY);
    void changeSemaphore(int);
    bool empty();
    void turnOff();
    bool ableToCross(int);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget =0);

//private:
    WAY way;

    Semaphore *semaphore;
    int frame,secuence;

    vector<QPointF*> posColas;
    vector<QPointF*> posPilas;
};

#endif // STREET_H
