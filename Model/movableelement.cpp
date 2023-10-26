#include "movableelement.h"
#include <QDebug>

MovableElement::MovableElement(const QString& src,
                               const QPoint &position,
                               QWidget *parent) :
    Element(src, position, parent)
{
    isMovable = false;
}

void MovableElement::mousePressEvent(QMouseEvent *event){
    isMovable = true;
    mousePos = event->pos();
     qDebug()<<"LOG[MovableElement] : click " << isMovable;
}

void MovableElement::mouseReleaseEvent(QMouseEvent *event){
    isMovable = false;
    qDebug()<<"LOG[MovableElement] : release " << isMovable;
}

void MovableElement::mouseMoveEvent(QMouseEvent *event){
    if (!isMovable){
        return;
    }

   QPoint newPos = this->mapToGlobal(event->pos());
   QPoint movement = newPos - mousePos;
   this->move(movement);
}

