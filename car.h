#ifndef CAR_H
#define CAR_H
#include "type_car.h"
#include <QString>
#include "myitem.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

enum WAY {
    NONE = 0,
    IZQ = 1,
    DOWN = 2,
    DER = 3,
    UP = 4
};

using namespace std;

class Car : public MyItem
{
public:
    Car(Type_Car,bool,int,QString,const QString&, QGraphicsItem* parent = nullptr);

    bool priority;
    int blocks;
    Type_Car type;
    QString name;
    WAY way;
    bool moving;

    float v;

    Car *next;

    void setWay(WAY);
    virtual void setMoving()=0;

    void logica();
};

class Turismo : public Car
{
public:
    Turismo();
    Turismo(WAY);
//    void logica();
    void setMoving();
};

class Ambulancia : public Car
{
public:
    Ambulancia();
    Ambulancia(WAY);
//    void logica();
    void setMoving();
};

class Chepo : public Car
{
public:
    Chepo();
    Chepo(WAY);
//    void logica();
    void setMoving();
};

class Bus : public Car
{
public:
    Bus();
    Bus(WAY);
//    void logica();
    void setMoving();
};

class Furgon : public Car
{
public:
    Furgon();
    Furgon(WAY);
//    void logica();
    void setMoving();
};

#endif // CAR_H
