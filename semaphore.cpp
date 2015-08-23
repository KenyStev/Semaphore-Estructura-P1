#include "semaphore.h"

Semaphore::Semaphore() : MyItem(":redstate.png")
{
    estado=0;
    time=0;
    estados.push_back(new QPixmap(":redstate.png"));
    estados.push_back(new QPixmap(":greenstate.png"));
    estados.push_back(new QPixmap(":yellowstate.png"));
}

void Semaphore::logica()
{
    switch (time) {
    case 200 ... 1000:
        estado=1;
        break;
    case 1 ... 199:
        estado=2;
        break;
    default:
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
    activo=false;
}

void Semaphore::change(int segs)
{
    time = segs;
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

