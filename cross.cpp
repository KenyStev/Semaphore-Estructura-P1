#include "cross.h"

Cross::Cross(QObject *parent) : MyScene(parent)
{
    mutex = new QMutex();
    back = new Background(":street.png");

//    north = new Street(UP,7000);
//    south = new Street(DOWN,8000);
//    east = new Street(IZQ,1500);
//    west = new Street(DER,1000);

    north = new Street(UP,400);
    south = new Street(DOWN,300);
    east = new Street(IZQ,200);
    west = new Street(DER,100);
    east->mutex = mutex;

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

    frame=0;
    change_semaphore = 100*10;
    activo=true;
    crossing=false;

//    north->changeSemaphore(change_semaphore);
    //    south->changeSemaphore(change_semaphore);
}

Cross::Cross(QObject *parent, MyThread *thread) : Cross(parent)
{
    this->thread=thread;
}

void Cross::onUpdate()
{
    MyScene::onUpdate();
    frame++;

    update_semaphore();
    cross_cars();
}

void Cross::update_semaphore()
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

void Cross::cross_cars()
{
//    mutex->lock();
    if(east->semaphore->isActivo())
    {
        // east - west
        if(cross_e_1)
        {
            cross_e_1->logica();
            float x = cross_e_1->position().x();
            float xf = east->posPilas[0]->x();
            if(xf>x)
            {
                removeActor(cross_e_1);
                cross_e_1->moving=false;
                east->pila1->push(cross_e_1);
                cross_e_1=NULL;
            }
        }else{
//            east->draw=false;
//            thread->wait();
//            thread->sleep(500);
            cross_e_1 = east->cola1->pop();
            if(cross_e_1){
                cross_e_1->setMoving();
                addActor(cross_e_1);
//                east->draw=true;
//                thread->sleep(500);
            }
        }

    }else{
        //north - south
    }
//    mutex->unlock();
}

