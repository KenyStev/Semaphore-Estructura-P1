#include "street.h"

Street::Street(WAY w,int s) : MyItem("")
{
    way = w;

    setPoints(w);

    semaphore = new Semaphore();
    setSemaphore(w);

    cola1 = new Queue(w);
    cola2 = new Queue(w);
//    cola1->push(new Turismo(IZQ));
//    cola1->push(new Turismo(IZQ));
//    cola1->push(new Furgon());
//    cola1->push(new Turismo(IZQ));

    pila1 = new Stack<Car*>(w);
    pila2 = new Stack<Car*>(w);

//    pila1->push(new Turismo(IZQ));
//    pila2->push(new Turismo(IZQ));
//    pila1->push(new Turismo(DER));
//    pila2->push(new Turismo(DER));

//    crossing_1 = NULL;
//    crossing_2 = NULL;

    frame = 0;
    secuence=s;
    draw = true;
}

Car *Street::getNewCar()
{
    srand(time(NULL));
    if(frame!=0 && frame%secuence==0)
    {
        int which_cola = rand()%2 + 1;
        int which_car =  rand()%5;
        switch (which_cola) {
        case 1:
            switch (which_car) {
            case 0:
                cola1->push(new Turismo(way));

//                pila1->push(new Turismo(way));
                break;
            case 1:
                cola1->push(new Ambulancia(way));

//                pila1->push(new Ambulancia(way));
                break;
            case 2:
                cola1->push(new Chepo(way));

//                pila1->push(new Chepo(way));
                break;
            case 3:
                cola1->push(new Bus(way));

//                pila1->push(new Bus(way));
                break;
            case 4:
                cola1->push(new Furgon(way));

//                pila1->push(new Furgon(way));
                break;
            }
            break;
        case 2:
            switch (which_car) {
            case 0:
                cola2->push(new Turismo(way));

//                pila2->push(new Turismo(way));
                break;
            case 1:
                cola2->push(new Ambulancia(way));

//                pila2->push(new Ambulancia(way));
                break;
            case 2:
                cola2->push(new Chepo(way));

//                pila2->push(new Chepo(way));
                break;
            case 3:
                cola2->push(new Bus(way));

//                pila2->push(new Bus(way));
                break;
            case 4:
                cola2->push(new Furgon(way));

//                pila2->push(new Furgon(way));
                break;
            }
            break;
        }
    }
}

void Street::logica()
{
    getNewCar();
    //draw(cola1->first(),NULL);

    semaphore->logica();
//    cross_cars();

//    if(cola1->first())
//    {
//        cola1->first()->logica();
//    }
//    if(cola2->first())
//        cola2->first()->logica();

    frame++;
}

//void Street::draw(Car*q,Car*p)
//{

//}

void Street::setSemaphore(WAY w)
{
    semaphore->setEstados(w);
    QPointF*pos;
    switch (w) {
    case IZQ:
        pos = new QPointF(*posColas[0]);
        pos->operator +=(QPointF(0,-40));
        semaphore->setPosition(*pos);
        break;
    case DER:
        pos = new QPointF(*posColas[0]);
        pos->operator +=(QPointF(-semaphore->imagen->width(),50));
        semaphore->setPosition(*pos);
        break;
    case DOWN:
        pos = new QPointF(*posColas[0]);
        pos->operator +=(QPointF(-45,-70));
        semaphore->setPosition(*pos);
        break;
    case UP:
        pos = new QPointF(*posColas[0]);
        pos->operator +=(QPointF(50,0));
        semaphore->setPosition(*pos);
        break;
    }
}

void Street::setPoints(WAY w)
{
    posColas.clear();
    posPilas.clear();
    switch (w) {
    case IZQ:
        posColas.push_back(new QPointF(696.851,200.923));
        posColas.push_back(new QPointF(696.851,240.923));

        posPilas.push_back(new QPointF(430.107,200.923));
        posPilas.push_back(new QPointF(430.107,240.923));
        break;
    case DER:
        posColas.push_back(new QPointF(430.107,360.487));
        posColas.push_back(new QPointF(430.107,300.487));

        posPilas.push_back(new QPointF(696.851,360.487));
        posPilas.push_back(new QPointF(696.851,300.487));
        break;
    case DOWN:
        posColas.push_back(new QPointF(474.499,171.706));
        posColas.push_back(new QPointF(525.511,171.706));

        posPilas.push_back(new QPointF(474.499,433.849));
        posPilas.push_back(new QPointF(525.511,433.849));
        break;
    case UP:
        posColas.push_back(new QPointF(619.797,433.849));
        posColas.push_back(new QPointF(565.784,433.849));

        posPilas.push_back(new QPointF(619.797,171.706));
        posPilas.push_back(new QPointF(565.784,171.706));
        break;
    }
}

void Street::changeSemaphore(int frecuence)
{
    if(!semaphore->isActivo())
    {
        semaphore->change(frecuence);
    }
}

bool Street::empty()
{
    return (cola1->length() + cola2->length()) == 0;
}

void Street::turnOff()
{
    semaphore->turnOff();
}

//void Street::cross_cars()
//{
//    if(semaphore->isActivo())
//    {
//        if(crossing_1)
//        {
//            if(crossing_1->moving)
//            {
//                crossing_1->logica();
//            }
//        }else{
////            crossing_1 = cola1->pop();
//            if(crossing_1)
//            {
//                crossing_1->setMoving();
//                crossing_1->moving=true;
//            }
//        }

//        if(crossing_2)
//        {

//        }else{
//            crossing_2 = cola2->pop();
//        }
//    }
//}

void Street::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    mutex->lock();
    float x = 0;
    float y = 0;

    if(draw){
        //dibujando cola de carros
        Car*tmp = cola1->first();
        for(int i=0;i<2;i++)
        {
            if(i)
                tmp = cola2->first();

            x = posColas[i]->x();
            y = posColas[i]->y();

            while(tmp){
                switch (way) {
                case IZQ:
                    tmp->setPosition(QPointF(x,y));
                    tmp->paint(painter,option,widget);
                    x += tmp->imagen->size().width();
                    break;
                case DER:
                    x -= tmp->imagen->size().width();
                    tmp->setPosition(QPointF(x,y));
                    tmp->paint(painter,option,widget);
                    break;
                case DOWN:
                    y -= tmp->imagen->size().height();
                    tmp->setPosition(QPointF(x,y));
                    tmp->paint(painter,option,widget);
                    break;
                case UP:
                    tmp->setPosition(QPointF(x,y));
                    y += tmp->imagen->size().height();
                    tmp->paint(painter,option,widget);
                    break;
                }
                tmp = tmp->next;
            }
        }

        //dibujando pila de carros
        tmp = pila1->top();
        for(int i=0;i<2;i++)
        {
            if(i)
                tmp = pila2->top();

            //posPilas no llena
            x = posPilas[i]->x();
            y = posPilas[i]->y();

            while(tmp)
            {
                switch (way) {
                case IZQ:
                    x -= tmp->imagen->size().width();
                    tmp->setPosition(QPointF(x,y));
                    tmp->paint(painter,option,widget);
                    break;
                case DER:
                    tmp->setPosition(QPointF(x,y));
                    tmp->paint(painter,option,widget);
                    x += tmp->imagen->size().width();
                    break;
                case DOWN:

                    tmp->setPosition(QPointF(x,y));
                    tmp->paint(painter,option,widget);
                    y += tmp->imagen->size().height();
                    break;
                case UP:
                    y -= tmp->imagen->size().height();
                    tmp->setPosition(QPointF(x,y));
                    tmp->paint(painter,option,widget);
                    break;
                }
                tmp = tmp->next;
            }
        }
    }

//    if(crossing_1)
//        crossing_1->paint(painter,option,widget);
//    if(crossing_2)
//        crossing_2->paint(painter,option,widget);

    semaphore->paint(painter,option,widget);
//    mutex->unlock();
}
