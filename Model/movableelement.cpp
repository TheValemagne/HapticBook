#include "movableelement.h"
#include <QDebug>

MovableElement::MovableElement(const QString& src, QWidget *parent) :
    Element(src, parent)
{
    isMovable = false;
}

void MovableElement::mousePressEvent(QMouseEvent *event){
    isMovable = true;
     qDebug()<<"LOG[MovableElement] : click " << isMovable;
}

void MovableElement::mouseReleaseEvent(QMouseEvent *event){
    isMovable = false;
    position = new QPoint(event->x(), this->y())
    qDebug()<<"LOG[MovableElement] : release " << isMovable;
}

void MovableElement::mouseMoveEvent(QMouseEvent *event){
    if (!isMovable){
        return;
    }

    this->move(event->x(), event->y());
}

