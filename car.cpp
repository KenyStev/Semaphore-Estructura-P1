#include "car.h"

Car::Car(Type_Car t,bool pr,int bl,QString n,const QString& path, QGraphicsItem* parent) : MyItem(path,parent)
{
    type = t;
    priority = pr;
    blocks = bl;
    name = n;
    next = NULL;
    moving = false;
    v = 0.5;
    //    cout<<"width: "<<imagen->size().width()<<endl;
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

void Car::logica()
{
    if(moving)
    {
        float x = position().x();
        float y = position().y();
        switch (way) {
        case IZQ:
            x-=v;
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
    v = 81.25;
//    setVelocity(QPointF(81.25,81.25));
//    moving=true;
}

//void Turismo::logica()
//{
//    if(moving)
//    {
//        float x = position().x();
//        float y = position().y();
//        switch (way) {
//        case IZQ:
//            x-=v;
//            setPosition(QPointF(x,y));
//            break;
//        }
//    }
//}

void Turismo::setMoving()
{
    srand(time(NULL));

    int t = rand()%3 + 2;
    moving=true;
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

void Ambulancia::setMoving()
{
    srand(time(NULL));

    int t = rand()%3 + 2;
    moving=true;
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

void Chepo::setMoving()
{
    srand(time(NULL));

    int t = rand()%3 + 2;
    moving=true;
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

void Bus::setMoving()
{
    srand(time(NULL));

    int t = rand()%3 + 2;
    moving=true;
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

void Furgon::setMoving()
{
    srand(time(NULL));

    int t = rand()%3 + 2;
    moving=true;
}
