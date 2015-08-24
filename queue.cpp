#include "queue.h"

Queue::Queue() : Queue(WAY::NONE)
{

}

Queue::Queue(WAY w)
{
    way = w;
    setWay(w);
    size=0;
    First = NULL;
    Last = NULL;
}

void Queue::push(Car * car)
{
    if(!First)
    {
        First = car;
        Last = car;
    }else{
        if(car->priority)
        {
            if(car->type==BUS)
                car->checked=false;
            car->next = First;
            First = car;
        }else{
            Last->next = car;
            Last = Last->next;
        }
    }
    size++;
}

Car *Queue::pop()
{
    if(!First)return NULL;
    Car*tmp = First;
    First = First->next;
    size--;
    tmp->next=NULL;
    return tmp;
}

Car *Queue::first()
{
    return First;
}

void Queue::setWay(WAY w)
{
    way=w;
    switch (way) {
    case IZQ:
        direction = "der -> izq";
        break;
    case DOWN:
        direction = "up -> down";
        break;
    case DER:
        direction = "izq -> der";
        break;
    case UP:
        direction = "down -> up";
        break;
    default:
        direction="";
        break;
    }
}

int Queue::length()
{
    return size;
}

