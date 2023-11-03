#include "rocket.h"
#include "Controller/hapticcontroller.h"
#include "Controller/soundcontroller.h"

Rocket::Rocket(const QString& src,
                          const QPoint &position,
                          Page *parent) :
    MovableElement(src, position, parent)
{
    isEffectActive = false;
    isSoundPlaying = false;
}

void Rocket::mouseReleaseEvent(QMouseEvent *event){
    MovableElement::mouseReleaseEvent(event);
    HapticController::getInstance()->stopEffect("shaking");
    isEffectActive = false;
}

void Rocket::mouseMoveEvent(QMouseEvent *event){
    MovableElement::mouseMoveEvent(event);
    if (isMovable && !isSoundPlaying) {
        SoundController::getInstance()->playSound("alarm", true);
        isSoundPlaying = true;
    }

    if (isMovable && !isEffectActive){
        HapticController::getInstance()->startEffect("shaking");
        isEffectActive = true;
    }
}
