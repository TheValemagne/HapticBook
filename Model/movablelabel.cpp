#include "movablelabel.h"

MovableLabel::MovableLabel(QWidget* parent, Qt::WindowFlags f) :
    QLabel(parent, f)
{
    isMovable = false;
    isLocked = false;

    openHandCursor = QCursor(Qt::OpenHandCursor);
    closedHandCursor = QCursor(Qt::ClosedHandCursor);
}

void MovableLabel::mousePressEvent(QMouseEvent *event){
    if(!isLocked){
        setCursor(closedHandCursor);
    }

    isMovable = true;
    mousePos = event->pos();
    emit mousePress();
}

void MovableLabel::mouseReleaseEvent(QMouseEvent *event){
    Q_UNUSED(event);

    if(!isLocked){
        setCursor(openHandCursor);
    }

    isMovable = false;
    emit mouseRelease();
}

void MovableLabel::mouseMoveEvent(QMouseEvent *event){
    if (!isMovable || isLocked) {
        return;
    }

   QPoint newPos = this->mapToGlobal(event->pos());
   QPoint movement = newPos - mousePos;
   this->move(movement);
   emit labelMove();
}

void MovableLabel::enterEvent(QEvent *event)
{
    Q_UNUSED(event);

    if(!isLocked){
        setCursor(openHandCursor);
    }
}

}

void MovableLabel::setIsLocked(bool isLocked) {
    this->isLocked = isLocked;
}
