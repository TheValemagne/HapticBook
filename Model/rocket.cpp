#include "rocket.h"
#include "Controller/HapticController.h"

Rocket::Rocket(const QString& src,
               const QPoint &position,
               Page *parent) :
    MovableElement(src, position, parent)
{

}

void Rocket::mouseReleaseEvent(QMouseEvent *event){
    MovableElement::mouseReleaseEvent(event);
    HapticController::getInstance()->stopEffect("shaking");
}

void Rocket::mousePressEvent(QMouseEvent *event){
    MovableElement::mousePressEvent(event);
    HapticController::getInstance()->startEffect("shaking");
}
