#include "cross.h"

Cross::Cross(QObject *parent) : MyScene(parent)
{
    back = new Background(":street.png");

//    north = new Street(UP,7000);
//    south = new Street(DOWN,8000);
//    east = new Street(IZQ,1500);
//    west = new Street(DER,1000);

    north = new Street(UP,400);
    south = new Street(DOWN,300);
    east = new Street(IZQ,250);
    west = new Street(DER,200);

    logs = new Stack<Log*>();

    addActor(back);

    addActor(north);
    addActor(south);
    addActor(east);
    addActor(west);

    cross_n_1 = NULL;
    cross_n_2 = NULL;
    cross_s_1 = NULL;
    cross_s_2 = NULL;
    cross_e_1 = NULL;
    cross_e_2 = NULL;
    cross_w_1 = NULL;
    cross_w_2 = NULL;

    n1=false;
    n2=false;
    s1=false;
    s2=false;
    e1=false;
    e2=false;
    w1=false;
    w2=false;

    frame=0;
    change_semaphore = 100*20;
    time_accident = 0;
    activo=true;
    crossing=false;
    accident = false;
    quit_time=1000;
}

void Cross::onUpdate()
{
    MyScene::onUpdate();
    frame++;

    update_semaphore();
    cross_cars();
//    east->cola1->push(new Bus(IZQ));
//    east->cola2->push(new Bus(IZQ));
//    west->cola1->push(new Bus(DER));
//    west->cola2->push(new Bus(DER));

//    north->cola1->push(new Bus(UP));
//    north->cola2->push(new Bus(UP));
//    south->cola1->push(new Bus(DOWN));
//    south->cola2->push(new Bus(DOWN));
}

void Cross::update_semaphore()
{
    if(!accident)
    {
        if(frame%change_semaphore==0)
        {
            if(activo)
            {
                north->changeSemaphore(change_semaphore);
                south->changeSemaphore(change_semaphore);
                east->turnOff();
                west->turnOff();

            }else{
                east->changeSemaphore(change_semaphore);
                west->changeSemaphore(change_semaphore);
                north->turnOff();
                south->turnOff();
            }
            activo=!activo;
        }else{
            if(!crossing)
            {
                if(north->empty() && south->empty())
                {
                    east->changeSemaphore(change_semaphore);
                    west->changeSemaphore(change_semaphore);
                    north->turnOff();
                    south->turnOff();
                    activo=true;
                }else if(east->empty() && west->empty()){
                    north->changeSemaphore(change_semaphore);
                    south->changeSemaphore(change_semaphore);
                    east->turnOff();
                    west->turnOff();
                    activo=false;
                }
            }
        }
    }else{
        north->turnOff();
        south->turnOff();
        east->turnOff();
        west->turnOff();

        if(time_accident<0)
        {
            time_accident=0;
            accident=false;

            if(n1)
            {
                removeActor(cross_n_1);
                cross_n_1=NULL;
                n1=false;
            }
            if(n2)
            {
                removeActor(cross_n_2);
                cross_n_2=NULL;
                n2=false;
            }

            if(s1)
            {
                removeActor(cross_s_1);
                cross_s_1=NULL;
                s1=false;
            }
            if(s2)
            {
                removeActor(cross_s_2);
                cross_s_2=NULL;
                s2=false;
            }

            if(e1)
            {
                removeActor(cross_e_1);
                cross_e_1=NULL;
                e1=false;
            }
            if(e2)
            {
                removeActor(cross_e_2);
                cross_e_2=NULL;
                e2=false;
            }

            if(w1)
            {
                removeActor(cross_w_1);
                cross_w_1=NULL;
                w1=false;
            }
            if(w2)
            {
                removeActor(cross_w_2);
                cross_w_2=NULL;
                w2=false;
            }
            east->changeSemaphore(change_semaphore);
            west->changeSemaphore(change_semaphore);
            north->turnOff();
            south->turnOff();
            activo=true;
        }
        time_accident--;
    }
}

void Cross::cross_cars()
{
    if(!accident)
    {
        int segs;
        if(east->semaphore->isActivo())
        {
            // west - east
            if(!cross_e_1)
            {
                cross_e_1 = east->cola1->pop();
                if(cross_e_1){
                    segs = cross_e_1->setMoving();
                    cout<<"Segs: "<<segs<<endl;
                    if(!east->ableToCross(segs))cross_e_1->setVXY(segs-1);
                    addActor(cross_e_1);
                    cross_e_1->movingON();
                }
            }

            if(!cross_e_2)
            {
                cross_e_2 = east->cola2->pop();
                if(cross_e_2){
                    segs = cross_e_2->setMoving();
                    cout<<"Segs: "<<segs<<endl;
                    if(!east->ableToCross(segs))cross_e_2->setVXY(segs-1);
                    addActor(cross_e_2);
                    cross_e_2->movingON();
                }
            }

            //east - west
            if(!cross_w_1)
            {
                cross_w_1 = west->cola1->pop();
                if(cross_w_1){
                    segs = cross_w_1->setMoving();
                    cout<<"Segs: "<<segs<<endl;
                    if(!west->ableToCross(segs))cross_w_1->setVXY(segs-1);
                    addActor(cross_w_1);
                    cross_w_1->movingON();

                }
            }

            if(!cross_w_2)
            {
                cross_w_2 = west->cola2->pop();
                if(cross_w_2){
                    segs = cross_w_2->setMoving();
                    cout<<"Segs: "<<segs<<endl;
                    if(!west->ableToCross(segs))cross_w_2->setVXY(segs-1);
                    addActor(cross_w_2);
                    cross_w_2->movingON();
                }
            }
        }else{
            //Bus puede cruzar en rojo
            int can_Cross;
            //east
            if(!cross_e_1)
            {
                cross_e_1 = east->cola1->first();
                if(cross_e_1!=NULL && cross_e_1->type == BUS &&
                        !cross_e_1->checked)
                {
                    cross_e_1->checked=true;
                    srand(time(NULL));
                    can_Cross = rand()%11;
                    cout<<"puede cruzar: "<<crossInRed[can_Cross]<<endl;
                    if(crossInRed[can_Cross])
                    {
                        cross_e_1 = east->cola1->pop();
                        segs = cross_e_1->setMoving();
                        cout<<"Segs: "<<segs<<endl;
                        addActor(cross_e_1);
                        cross_e_1->movingON();

                        checkColisions(cross_e_1,&e1,cross_n_1,&n1,cross_n_2,&n2,cross_s_1,&s1,cross_s_2,&s2);
                    }else{
                        cross_e_1 = NULL;
                    }
                }else{
                    cross_e_1 = NULL;
                }
            }else{
                if(cross_e_1->type == BUS)
                    checkColisions(cross_e_1,&e1,cross_n_1,&n1,cross_n_2,&n2,cross_s_1,&s1,cross_s_2,&s2);
            }
            if(!cross_e_2)
            {
                cross_e_2 = east->cola2->first();
                if(cross_e_2!=NULL && cross_e_2->type == BUS &&
                        !cross_e_2->checked)
                {
                    cross_e_2->checked=true;
                    srand(time(NULL));
                    can_Cross = rand()%11;
                    cout<<"puede cruzar: "<<crossInRed[can_Cross]<<endl;
                    if(crossInRed[can_Cross])
                    {
                        cross_e_2 = east->cola2->pop();
                        segs = cross_e_2->setMoving();
                        cout<<"Segs: "<<segs<<endl;
                        addActor(cross_e_2);
                        cross_e_2->movingON();

                        checkColisions(cross_e_2,&e2,cross_n_1,&n1,cross_n_2,&n2,cross_s_1,&s1,cross_s_2,&s2);
                    }else{
                        cross_e_2 = NULL;
                    }
                }else{
                    cross_e_2 = NULL;
                }
            }else{
                if(cross_e_2->type == BUS)
                    checkColisions(cross_e_2,&e2,cross_n_1,&n1,cross_n_2,&n2,cross_s_1,&s1,cross_s_2,&s2);
            }

            //west
            if(!cross_w_1)
            {
                cross_w_1 = west->cola1->first();
                if(cross_w_1!=NULL && cross_w_1->type == BUS &&
                        !cross_w_1->checked)
                {
                    cross_w_1->checked=true;
                    srand(time(NULL));
                    can_Cross = rand()%11;
                    cout<<"puede cruzar: "<<crossInRed[can_Cross]<<endl;
                    if(crossInRed[can_Cross])
                    {
                        cross_w_1 = west->cola1->pop();
                        segs = cross_w_1->setMoving();
                        cout<<"Segs: "<<segs<<endl;
                        addActor(cross_w_1);
                        cross_w_1->movingON();

                        checkColisions(cross_w_1,&w1,cross_n_1,&n1,cross_n_2,&n2,cross_s_1,&s1,cross_s_2,&s2);
                    }else{
                        cross_w_1 = NULL;
                    }
                }else{
                    cross_w_1 = NULL;
                }
            }else{
                if(cross_w_1->type == BUS)
                    checkColisions(cross_w_1,&w1,cross_n_1,&n1,cross_n_2,&n2,cross_s_1,&s1,cross_s_2,&s2);
            }
            if(!cross_w_2)
            {
                cross_w_2 = west->cola2->first();
                if(cross_w_2!=NULL && cross_w_2->type == BUS &&
                        !cross_w_2->checked)
                {
                    cross_w_2->checked=true;
                    srand(time(NULL));
                    can_Cross = rand()%11;
                    cout<<"puede cruzar: "<<crossInRed[can_Cross]<<endl;
                    if(crossInRed[can_Cross])
                    {
                        cross_w_2 = west->cola2->pop();
                        segs = cross_w_2->setMoving();
                        cout<<"Segs: "<<segs<<endl;
                        addActor(cross_w_2);
                        cross_w_2->movingON();

                        checkColisions(cross_w_2,&w2,cross_n_1,&n1,cross_n_2,&n2,cross_s_1,&s1,cross_s_2,&s2);
                    }else{
                        cross_w_2 = NULL;
                    }
                }else{
                    cross_w_2 = NULL;
                }
            }else{
                if(cross_w_2->type == BUS)
                    checkColisions(cross_w_2,&w2,cross_n_1,&n1,cross_n_2,&n2,cross_s_1,&s1,cross_s_2,&s2);
            }
        }

        if(north->semaphore->isActivo()){
            //south - north
            if(!cross_n_1)
            {
                cross_n_1 = north->cola1->pop();
                if(cross_n_1){
                    segs = cross_n_1->setMoving();
                    cout<<"Segs: "<<segs<<endl;
                    if(!north->ableToCross(segs))cross_n_1->setVXY(segs-1);
                    addActor(cross_n_1);
                    cross_n_1->movingON();
                }
            }

            if(!cross_n_2)
            {
                cross_n_2 = north->cola2->pop();
                if(cross_n_2){
                    segs = cross_n_2->setMoving();
                    cout<<"Segs: "<<segs<<endl;
                    if(!north->ableToCross(segs))cross_n_2->setVXY(segs-1);
                    addActor(cross_n_2);
                    cross_n_2->movingON();
                }
            }

            //north - south
            if(!cross_s_1)
            {
                cross_s_1 = south->cola1->pop();
                if(cross_s_1){
                    segs = cross_s_1->setMoving();
                    cout<<"Segs: "<<segs<<endl;
                    if(!south->ableToCross(segs))cross_s_1->setVXY(segs-1);
                    addActor(cross_s_1);
                    cross_s_1->movingON();
                }
            }

            if(!cross_s_2)
            {
                cross_s_2 = south->cola2->pop();
                if(cross_s_2){
                    segs = cross_s_2->setMoving();
                    cout<<"Segs: "<<segs<<endl;
                    if(!south->ableToCross(segs))cross_s_2->setVXY(segs-1);
                    addActor(cross_s_2);
                    cross_s_2->movingON();
                }
            }
        }else{
            //Bus puede cruzar en rojo 2
            int can_Cross;
            //north
            if(!cross_n_1)
            {
                cross_n_1 = north->cola1->first();
                if(cross_n_1!=NULL && cross_n_1->type == BUS &&
                        !cross_n_1->checked)
                {
                    cross_n_1->checked=true;
                    srand(time(NULL));
                    can_Cross = rand()%11;
                    cout<<"puede cruzar: "<<crossInRed[can_Cross]<<endl;
                    if(crossInRed[can_Cross])
                    {
                        cross_n_1 = north->cola1->pop();
                        segs = cross_n_1->setMoving();
                        cout<<"Segs: "<<segs<<endl;
                        addActor(cross_n_1);
                        cross_n_1->movingON();

                        checkColisions(cross_n_1,&n1,cross_e_1,&e1,cross_e_2,&e2,cross_w_1,&w1,cross_w_2,&w2);
                    }else{
                        cross_n_1 = NULL;
                    }
                }else{
                    cross_n_1 = NULL;
                }
            }else{
                if(cross_n_1->type == BUS)
                    checkColisions(cross_n_1,&n1,cross_e_1,&e1,cross_e_2,&e2,cross_w_1,&w1,cross_w_2,&w2);
            }
            if(!cross_n_2)
            {
                cross_n_2 = north->cola2->first();
                if(cross_n_2!=NULL && cross_n_2->type == BUS &&
                        !cross_n_2->checked)
                {
                    cross_n_2->checked=true;
                    srand(time(NULL));
                    can_Cross = rand()%11;
                    cout<<"puede cruzar: "<<crossInRed[can_Cross]<<endl;
                    if(crossInRed[can_Cross])
                    {
                        cross_n_2 = north->cola2->pop();
                        segs = cross_n_2->setMoving();
                        cout<<"Segs: "<<segs<<endl;
                        addActor(cross_n_2);
                        cross_n_2->movingON();

                        checkColisions(cross_n_2,&n2,cross_e_1,&e1,cross_e_2,&e2,cross_w_1,&w1,cross_w_2,&w2);
                    }else{
                        cross_n_2 = NULL;
                    }
                }else{
                    cross_n_2 = NULL;
                }
            }else{
                if(cross_n_2->type == BUS)
                    checkColisions(cross_n_2,&n2,cross_e_1,&e1,cross_e_2,&e2,cross_w_1,&w1,cross_w_2,&w2);
            }

            //south
            if(!cross_s_1)
            {
                cross_s_1 = south->cola1->first();
                if(cross_s_1!=NULL && cross_s_1->type == BUS &&
                        !cross_s_1->checked)
                {
                    cross_s_1->checked=true;
                    srand(time(NULL));
                    can_Cross = rand()%11;
                    cout<<"puede cruzar: "<<crossInRed[can_Cross]<<endl;
                    if(crossInRed[can_Cross])
                    {
                        cross_s_1 = south->cola1->pop();
                        segs = cross_s_1->setMoving();
                        cout<<"Segs: "<<segs<<endl;
                        addActor(cross_s_1);
                        cross_s_1->movingON();

                        checkColisions(cross_s_1,&s1,cross_e_1,&e1,cross_e_2,&e2,cross_w_1,&w1,cross_w_2,&w2);
                    }else{
                        cross_s_1 = NULL;
                    }
                }else{
                    cross_s_1 = NULL;
                }
            }else{
                if(cross_s_1->type == BUS)
                    checkColisions(cross_s_1,&s1,cross_e_1,&e1,cross_e_2,&e2,cross_w_1,&w1,cross_w_2,&w2);
            }
            if(!cross_s_2)
            {
                cross_s_2 = south->cola2->first();
                if(cross_s_2!=NULL && cross_s_2->type == BUS &&
                        !cross_s_2->checked)
                {
                    cross_s_2->checked=true;
                    srand(time(NULL));
                    can_Cross = rand()%11;
                    cout<<"puede cruzar: "<<crossInRed[can_Cross]<<endl;
                    if(crossInRed[can_Cross])
                    {
                        cross_s_2 = south->cola2->pop();
                        segs = cross_s_2->setMoving();
                        cout<<"Segs: "<<segs<<endl;
                        addActor(cross_s_2);
                        cross_s_2->movingON();

                        checkColisions(cross_s_2,&w2,cross_e_1,&e1,cross_e_2,&e2,cross_w_1,&w1,cross_w_2,&w2);
                    }else{
                        cross_s_2 = NULL;
                    }
                }else{
                    cross_s_2 = NULL;
                }
            }else{
                if(cross_s_2->type == BUS)
                    checkColisions(cross_s_2,&w2,cross_e_1,&e1,cross_e_2,&e2,cross_w_1,&w1,cross_w_2,&w2);
            }
        }
    }
    //east
    if(cross_e_1)
    {
        cross_e_1->logica();
        float x = cross_e_1->position().x();
        float xf = east->posPilas[0]->x();
        if(xf>x)
        {
            removeActor(cross_e_1);
            cross_e_1->movingOFF();
            east->pila1->push(cross_e_1);
            cross_e_1=NULL;
        }
    }
    if(cross_e_2)
    {
        cross_e_2->logica();
        float x = cross_e_2->position().x();
        float xf = east->posPilas[1]->x();
        if(xf>x)
        {
            removeActor(cross_e_2);
            cross_e_2->movingOFF();
            east->pila2->push(cross_e_2);
            cross_e_2=NULL;
        }
    }

    //west
    if(cross_w_1)
    {
        cross_w_1->logica();
        float x = cross_w_1->position().x();
        float xf = west->posPilas[0]->x();
        if(xf<x + cross_w_1->imagen->width())
        {
            removeActor(cross_w_1);
            cross_w_1->movingOFF();
            west->pila1->push(cross_w_1);
            cross_w_1=NULL;
        }
    }
    if(cross_w_2)
    {
        cross_w_2->logica();
        float x = cross_w_2->position().x();
        float xf = west->posPilas[1]->x();
        if(xf<x + cross_w_2->imagen->width())
        {
            removeActor(cross_w_2);
            cross_w_2->movingOFF();
            west->pila2->push(cross_w_2);
            cross_w_2=NULL;
        }
    }

    //north
    if(cross_n_1)
    {
        cross_n_1->logica();
        float y = cross_n_1->position().y();
        float yf = north->posPilas[0]->y();
        if(yf>y)
        {
            removeActor(cross_n_1);
            cross_n_1->movingOFF();
            north->pila1->push(cross_n_1);
            cross_n_1=NULL;
        }
    }
    if(cross_n_2)
    {
        cross_n_2->logica();
        float y = cross_n_2->position().y();
        float yf = north->posPilas[1]->y();
        if(yf>y)
        {
            removeActor(cross_n_2);
            cross_n_2->movingOFF();
            north->pila2->push(cross_n_2);
            cross_n_2=NULL;
        }
    }

    //south
    if(cross_s_1)
    {
        cross_s_1->logica();
        float y = cross_s_1->position().y();
        float yf = south->posPilas[0]->y();
        if(yf<y + cross_s_1->imagen->height())
        {
            removeActor(cross_s_1);
            cross_s_1->movingOFF();
            south->pila1->push(cross_s_1);
            cross_s_1=NULL;
        }
    }
    if(cross_s_2)
    {
        cross_s_2->logica();
        float y = cross_s_2->position().y();
        float yf = south->posPilas[1]->y();
        if(yf<y + cross_s_2->imagen->height())
        {
            removeActor(cross_s_2);
            cross_s_2->movingOFF();
            south->pila2->push(cross_s_2);
            cross_s_2=NULL;
        }
    }

    if(cross_e_1 || cross_e_2 ||
       cross_w_1 || cross_w_2 ||
       cross_n_1 || cross_n_2 ||
       cross_s_1 || cross_s_2)
    {
        crossing=true;
    }else{
        crossing=false;
    }
}

void Cross::checkColisions(Car *&bus, bool *b, Car *&car1, bool *c1, Car *&car2, bool *c2, Car *&car3, bool *c3, Car *&car4, bool *c4)
{
    if(car1)
    {
        accident=true;
        *b=true;
        *c1=true;
        bus->movingOFF();
        car1->movingOFF();
        time_accident = (car1->blocks+bus->blocks)*quit_time;
        cout<<"accident_time: "<<time_accident<<endl;
        cout<<"Hubo accidente con: "<<car1->name.toStdString()<<endl;
    }else if(car2)
    {
        accident=true;
        *b=true;
        *c2=true;
        bus->movingOFF();
        car2->movingOFF();
        time_accident = (car2->blocks+bus->blocks)*quit_time;
        cout<<"accident_time: "<<time_accident<<endl;
        cout<<"Hubo accidente con: "<<car2->name.toStdString()<<endl;
    }else if(car3)
    {
        accident=true;
        *b=true;
        *c3=true;
        bus->movingOFF();
        car3->movingOFF();
        time_accident = (car3->blocks+bus->blocks)*quit_time;
        cout<<"accident_time: "<<time_accident<<endl;
        cout<<"Hubo accidente con: "<<car3->name.toStdString()<<endl;
    }else if(car4)
    {
        accident=true;
        *b=true;
        *c4=true;
        bus->movingOFF();
        car4->movingOFF();
        time_accident = (car4->blocks+bus->blocks)*quit_time;
        cout<<"accident_time: "<<time_accident<<endl;
        cout<<"Hubo accidente con: "<<car4->name.toStdString()<<endl;
    }
}

