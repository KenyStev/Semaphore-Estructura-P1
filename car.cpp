#include "car.h"

Car::Car(Type_Car t,bool pr,int bl,QString n,const QString& path, QGraphicsItem* parent) : MyItem(path,parent)
{
    type = t;
    priority = pr;
    blocks = bl;
    name = n;
    next = NULL;
    moving = false;
    checked = false;
    //1.3 a esta velocidad cruza en 1 seg
    //0.13 a esta velocidad cruza en 10 seg
    v = 1.3;
    vxy=0;
}

void Car::setWay(WAY w)
{
    way=w;
    switch (type) {
    case TURISNO:
        switch (w) {
        case IZQ:
            setImage(new QPixmap(":Turismo_izq.png"));
            break;
        case DER:
            setImage(new QPixmap(":Turismo_der.png"));
            break;
        case DOWN:
            setImage(new QPixmap(":Turismo_down.png"));
            break;
        case UP:
            setImage(new QPixmap(":Turismo_up.png"));
            break;
        }
        break;
    case AMBULANCIA:
        switch (w) {
        case IZQ:
            setImage(new QPixmap(":Ambulancia_izq.png"));
            break;
        case DER:
            setImage(new QPixmap(":Ambulancia_der.png"));
            break;
        case DOWN:
            setImage(new QPixmap(":Ambulancia_down.png"));
            break;
        case UP:
            setImage(new QPixmap(":Ambulancia_up.png"));
            break;
        }
        break;
    case CHECPO:
        switch (w) {
        case IZQ:
            setImage(new QPixmap(":Chepo_izq.png"));
            break;
        case DER:
            setImage(new QPixmap(":Chepo_der.png"));
            break;
        case DOWN:
            setImage(new QPixmap(":Chepo_down.png"));
            break;
        case UP:
            setImage(new QPixmap(":Chepo_up.png"));
            break;
        }
        break;
    case BUS:
        switch (w) {
        case IZQ:
            setImage(new QPixmap(":Bus_izq.png"));
            break;
        case DER:
            setImage(new QPixmap(":Bus_der.png"));
            break;
        case DOWN:
            setImage(new QPixmap(":Bus_down.png"));
            break;
        case UP:
            setImage(new QPixmap(":Bus_up.png"));
            break;
        }
        break;
    case FURGON:
        switch (w) {
        case IZQ:
            setImage(new QPixmap(":Furgon_izq.png"));
            break;
        case DER:
            setImage(new QPixmap(":Furgon_der.png"));
            break;
        case DOWN:
            setImage(new QPixmap(":Furgon_down.png"));
            break;
        case UP:
            setImage(new QPixmap(":Furgon_up.png"));
            break;
        }
        break;
    }
}

void Car::movingON()
{
    moving=true;
}

void Car::movingOFF()
{
    moving = false;
}

void Car::setVXY(int s)
{
    vxy = v/s;
}

void Car::logica()
{
    if(moving)
    {
        float x = position().x();
        float y = position().y();
        switch (way) {
        case IZQ:
            x-=vxy;
            setPosition(QPointF(x,y));
            break;
        case DER:
            x+=vxy;
            setPosition(QPointF(x,y));
            break;
        case DOWN:
            y+=vxy;
            setPosition(QPointF(x,y));
            break;
        case UP:
            y-=vxy;
            setPosition(QPointF(x,y));
            break;
        }
    }
}

/**
 * Turismo*/

Turismo::Turismo() : Car(Type_Car::TURISNO,false,1,"Turismo",":Turismo.png")
{

}

Turismo::Turismo(WAY w) : Turismo()
{
    setWay(w);
}

int Turismo::setMoving()
{
    //srand(time(NULL));

    int t = rand()%3 + 3;
    vxy = v/t;
    return t;
//    moving=true;
}

/**
 * Ambulancia*/


Ambulancia::Ambulancia() : Car(Type_Car::AMBULANCIA,true,1,"Ambulancia",":Ambulancia.png")
{

}

Ambulancia::Ambulancia(WAY w) : Ambulancia()
{
    setWay(w);
}

//void Ambulancia::logica()
//{

//}

int Ambulancia::setMoving()
{
    //srand(time(NULL));

    int t = rand()%3 + 2;
    vxy = v/t;
    return t;
//    moving=true;
}

/**
  *Chepo*/


Chepo::Chepo() : Car(Type_Car::CHECPO,true,1,"Chepo",":Chepo.png")
{

}

Chepo::Chepo(WAY w) : Chepo()
{
    setWay(w);
}

//void Chepo::logica()
//{

//}

int Chepo::setMoving()
{
    //srand(time(NULL));

    int t = rand()%3 + 2;
    vxy = v/t;
    return t;
//    moving=true;
}

/**
  *Bus*/


Bus::Bus() : Car(Type_Car::BUS,false,2,"Bus",":Bus.png")
{

}

Bus::Bus(WAY w) : Bus()
{
    setWay(w);
}

//void Bus::logica()
//{

//}

int Bus::setMoving()
{
    //srand(time(NULL));

    int t = rand()%3 + 1;
    vxy = v/t;
    return t;
//    moving=true;
}

/**
  *Furgon*/



Furgon::Furgon() : Car(Type_Car::FURGON,false,3,"Furgon",":Furgon.png")
{

}

Furgon::Furgon(WAY w) : Furgon()
{
    setWay(w);
}

//void Furgon::logica()
//{

//}

int Furgon::setMoving()
{
    //srand(time(NULL));

    int t = rand()%2 + 4;
    vxy = v/t;
    return t;
//    moving=true;
}
