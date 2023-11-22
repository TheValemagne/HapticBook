#include "movablelabel.h"

MovableLabel::MovableLabel(QWidget* parent, Qt::WindowFlags f) :
    QLabel(parent, f)
{
    isMovable = false;
    isLocked = false;
}

void MovableLabel::mousePressEvent(QMouseEvent *event){
    isMovable = true;
    mousePos = event->pos();
    emit mousePress(); // peut-être inutile
}

void MovableLabel::mouseReleaseEvent(QMouseEvent *event){
    isMovable = false;
    emit mouseRelease(); // arrêt effect haptique (et son si nécessaire)
}

void MovableLabel::mouseMoveEvent(QMouseEvent *event){
    if (!isMovable || isLocked) {
        return;
    }

   QPoint newPos = this->mapToGlobal(event->pos());
   QPoint movement = newPos - mousePos;
   this->move(movement);
   emit labelMove(); // effect haptique + sons
}

void MovableLabel::setIsLocked(bool isLocked) {
    this->isLocked = isLocked;
}
