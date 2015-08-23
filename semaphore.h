#ifndef SEMAPHORE_H
#define SEMAPHORE_H
#include "myitem.h"
#include <vector>
#include <iostream>
#include "car.h"
using namespace std;

class Semaphore : public MyItem
{
public:
    Semaphore();

    void logica();
    void turnOff();
    void change(int);

    void setEstados(WAY);

    bool isActivo(){return activo;}

private:
    int time;
    int estado;
    bool activo;
    vector<QPixmap*> estados;
};

#endif // SEMAPHORE_H
