#ifndef MYITEM_H
#define MYITEM_H
#include <QGraphicsItem>
#include<QPointF>
#include <QSizeF>

class MyItem : public QGraphicsItem
{
public:
    MyItem(const QString &Filename,QGraphicsItem *parent=nullptr);
    inline void setPosition(const QPointF &pos);
    inline void setVelocity(const QPointF &vel);
    inline void setSize(const QSizeF &size);
    inline QPointF position() const;
    inline QPointF velocity() const;
    inline QSizeF size() const;
    inline QString filename() const;
    virtual void logica()=0;
    void setImage(QPixmap*);
    QPixmap *imagen;
//protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget =0);
private:
    QPointF mPos;
    QPointF mVel;
    QSizeF mSize;
    QString mFilename;
//    QPixmap *imagen;
};

void MyItem::setPosition(const QPointF &pos)
{
    mPos = pos;
}

void MyItem::setVelocity(const QPointF &vel)
{
    mVel = vel;
}

void MyItem::setSize(const QSizeF &size)
{
    mSize = size;
}

QPointF MyItem::position() const
{
    return mPos;
}

QPointF MyItem::velocity() const
{
    return mVel;
}

QSizeF MyItem::size() const
{
    return mSize;
}

QString MyItem::filename() const
{
    return mFilename;
}

#endif // MYITEM_H
