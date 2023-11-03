#include "movableelement.h"
#include <QDebug>

MovableElement::MovableElement(const QString& src,
                                                            const QPoint &position,
                                                            Page *parent) :
    Element(src, position, parent)
{
    isMovable = false;
}

void MovableElement::mousePressEvent(QMouseEvent *event){
    Element::mousePressEvent(event);

    isMovable = true;
    mousePos = event->pos();
     qDebug()<<"LOG[MovableElement] : click";
}

void MovableElement::mouseReleaseEvent(QMouseEvent *event){
    Element::mouseReleaseEvent(event);

    isMovable = false;
    qDebug()<<"LOG[MovableElement] : release";
}

void MovableElement::mouseMoveEvent(QMouseEvent *event){
    Element::mouseMoveEvent(event);

    if (!isMovable){
        return;
    }

   QPoint newPos = this->mapToGlobal(event->pos());
   QPoint movement = newPos - mousePos;
   this->move(movement);
   this->page->onMouseMove();
}
