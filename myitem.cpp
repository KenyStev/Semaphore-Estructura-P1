#include "myitem.h"
#include<QPainter>
MyItem::MyItem(const QString &Filename,QGraphicsItem *parent): QGraphicsItem(parent)
{
    mFilename = Filename;
    imagen = new QPixmap(mFilename);
}

void MyItem::setImage(QPixmap *i)
{
    imagen = i;
}

QRectF MyItem::boundingRect() const
{
    return QRectF(mPos.x(),mPos.y(),mSize.width(),mSize.height());
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
                   QWidget *)
{
    painter->drawPixmap(mPos.x(), mPos.y(), mSize.width(),mSize.height(),
                        *imagen);
}

