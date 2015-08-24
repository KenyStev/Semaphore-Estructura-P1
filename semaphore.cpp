#include "semaphore.h"

Semaphore::Semaphore() : MyItem(":redstate.png")
{
    estado=0;
    time=0;
    fullTime=2000;
    range=500;
    estados.push_back(new QPixmap(":redstate.png"));
    estados.push_back(new QPixmap(":greenstate.png"));
    estados.push_back(new QPixmap(":yellowstate.png"));
}

void Semaphore::logica()
{
//    switch (time) {
//    case 200 ... 1000:
//        estado=1;
//        break;
//    case 1 ... 199:
//        estado=2;
//        activo=false;
//        break;
//    default:
//        turnOff();
//    }

    if(time>=range && time<=fullTime)
    {
        estado=1;
    }else if(time>0 && time<range)
    {
        estado=2;
        activo=false;
    }else{
        turnOff();
    }

    setImage(estados[estado]);
    if(time<0)time=0;
    time--;
}

void Semaphore::turnOff()
{
    time = 0;
    estado=0;
//    fullTime=0;
    activo=false;
}

void Semaphore::change(int segs)
{
    time = segs;
//    fullTime=segs*100;
//    range = fullTime/9;
    activo=true;
}

void Semaphore::setEstados(WAY w)
{
    estados.clear();
    switch (w) {
    case IZQ:
        estados.push_back(new QPixmap(":redstate_izq.png"));
        estados.push_back(new QPixmap(":greenstate_izq.png"));
        estados.push_back(new QPixmap(":yellowstate_izq.png"));
        break;
    case DER:
        estados.push_back(new QPixmap(":redstate_der.png"));
        estados.push_back(new QPixmap(":greenstate_der.png"));
        estados.push_back(new QPixmap(":yellowstate_der.png"));
        break;
    case DOWN:
        estados.push_back(new QPixmap(":redstate_down.png"));
        estados.push_back(new QPixmap(":greenstate_down.png"));
        estados.push_back(new QPixmap(":yellowstate_down.png"));
        break;
    case UP:
        estados.push_back(new QPixmap(":redstate_up.png"));
        estados.push_back(new QPixmap(":greenstate_up.png"));
        estados.push_back(new QPixmap(":yellowstate_up.png"));
        break;
    }
}

bool Semaphore::ableToCross(int segs)
{
    return segs*100 >= range;
}

