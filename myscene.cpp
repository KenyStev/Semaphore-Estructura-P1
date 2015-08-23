#include "myscene.h"
#include "myitem.h"

#define XPOS 0.0
#define YPOS 0.0
#define WIDTH 1128.0
#define HEIGHT 600.0

MyScene::MyScene(QObject *parent)
    :QGraphicsScene(XPOS,YPOS,WIDTH,HEIGHT, parent)
{
    addRect(XPOS,YPOS,WIDTH,HEIGHT,QPen(Qt::black));
}

void MyScene::onUpdate()
{
    for(int x=0;x<actores.size();x++){
        if(actores[x])
            actores[x]->logica();
    }

    update();
}

void MyScene::addActor(MyItem *actor){
    actores.push_back(actor);
    addItem(actor);
}

void MyScene::removeActor(MyItem *actor)
{
    for(vector<MyItem*>::iterator i=actores.begin();
        i!=actores.end();i++)
    {
        if(actor==*i)
        {
            actores.erase(i);
            break;
        }
    }
    removeItem(actor);
}

