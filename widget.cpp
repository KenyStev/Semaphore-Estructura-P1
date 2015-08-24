#include "widget.h"
#include "ui_widget.h"
#include "car.h"
#include "log.h"
#include "semaphore.h"
#include "street.h"
#include <iostream>
//#define MSEC 10

using namespace std;

widget::widget(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);
    showFullScreen();
    thread = new MyThread(this);
//    scene = new MyScene(this);
//    s = new Background(":street.png");
//    s->setPosition(QPointF(0,0));
//    s->setVelocity(QPointF(1,0));
//    s->setSize(QSizeF(1128,600));

//    Semaphore *sema = new Semaphore();
//    sema->change(1000);

//    Street *calle = new Street(IZQ,1000);
//    Street *calle2 = new Street(DER,1500);
//    Street *calle3 = new Street(DOWN,8000);
//    Street *calle4 = new Street(UP,7000);
//    back = new Background(":street.png");

//    north = new Street(UP,5161);
//    south = new Street(DOWN,7416);
//    east = new Street(IZQ,65613);
//    west = new Street(DER,95630);

//    cross->addActor(back);

//    cross->addActor(north);
//    cross->addActor(south);
//    cross->addActor(east);
//    cross->addActor(west);
//    calle->posColas.push_back(new QPointF(696.851,210.923));

//    Car*car = new Turismo();
//    car->setPos(QPointF(696.851,234.923));

//    scene->addActor(s);
    //scene->addActor(sema);
//    scene->addActor(calle);
//    scene->addActor(calle2);
//    scene->addActor(calle3);
//    scene->addActor(calle4);
//    scene->addActor(car);
//    ui->graphicsView->setScene(scene);

//    layout()->setMargin(0);

//    connect(thread, &MyThread::already, [&](){emit update();});
//    connect(this,&widget::update, scene,&MyScene::onUpdate);
//    thread->start(MSEC,QThread::HighestPriority);

    cross = new Cross(this);
    ui->graphicsView->setScene(cross);

    layout()->setMargin(0);

    connect(thread, &MyThread::already, [&](){emit update();});
    connect(this,&widget::update, cross,&Cross::onUpdate);
    thread->start(MSEC,QThread::HighestPriority);

}

widget::~widget()
{
    delete ui;
}

void widget::on_actionLogs_triggered()
{
    //llamar logs widget
}
