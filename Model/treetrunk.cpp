#include "treetrunk.h"
#include "Controller/hapticcontroller.h"

TreeTrunk::TreeTrunk(const QString& src,
                                      const QPoint &position,
                                      Page *parent) :
    MovableElement(src, position, parent)
{
    isEffectActive = false;
}

void TreeTrunk::mouseReleaseEvent(QMouseEvent *event){
    MovableElement::mouseReleaseEvent(event);
    HapticController::getInstance()->stopEffect("heavy_load");
    isEffectActive = false;
}

void TreeTrunk::mouseMoveEvent(QMouseEvent *event){
    MovableElement::mouseMoveEvent(event);
    if (isMovable && !isEffectActive){
        HapticController::getInstance()->startEffect("heavy_load");
        isEffectActive = true;
    }
}
