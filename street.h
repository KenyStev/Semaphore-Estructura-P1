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
#include <QMutex>
#include <time.h>

using namespace std;

//Car* cars[] = {new Turismo(), new Ambulancia(), new Chepo(), new Bus(), new Furgon()};

class Street : public MyItem
{
public:
    Street(WAY,int);

    Queue *cola1,*cola2;
    Stack<Car*> *pila1,*pila2;
    bool draw;
    QMutex *mutex;
//    Car *crossing_1,*crossing_2;

    Car*getNewCar();
    void logica();
//    void draw(Car*,Car*);
    void setSemaphore(WAY);
    void setPoints(WAY);
    void changeSemaphore(int);
    bool empty();
    void turnOff();
//    void cross_cars();

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
