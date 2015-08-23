#ifndef MYSCENE_H
#define MYSCENE_H
#include<QGraphicsScene>
#include <vector>
#include<iostream>
#include"myitem.h"

using namespace std;
class MyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    MyScene(QObject* parent = nullptr);
    void addActor(MyItem* actor);
    void removeActor(MyItem* actor);
public slots:
    void onUpdate();
private:
    vector<MyItem*>actores;
};

#endif // MYSCENE_H
