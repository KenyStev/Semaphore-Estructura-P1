#ifndef STAR_H
#define STAR_H
#include "myitem.h"
#include <QPointF>

class Background : public MyItem
{
public:
    Background(const QString&, QGraphicsItem* parent = nullptr);

    void logica();
};

#endif // STAR_H
