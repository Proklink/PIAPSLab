#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QWidget>
#include <QPen>
#include <QPainter>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>
#include <QGraphicsView>
#include <QPaintEngine>

#include "proxyimage.h"

class Rectangle : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Rectangle(QObject *parent = 0);
    ~Rectangle();


private:
    QSize rectSize;
    int x = -30;
    int y = -30;

    AbstractImage *image;

    bool imageflag = false;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // RECTANGLE_H
