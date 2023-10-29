#include "treetrunk.h"
#include "Controller/HapticController.h"

TreeTrunk::TreeTrunk(const QString& src,
                       const QPoint &position,
                       Page *parent) :
    MovableElement(src, position, parent)
{

}

void TreeTrunk::mouseReleaseEvent(QMouseEvent *event){
    MovableElement::mouseReleaseEvent(event);
    HapticController::getInstance()->stopEffect("heavy_load");
}

void TreeTrunk::mousePressEvent(QMouseEvent *event){
    MovableElement::mousePressEvent(event);
    HapticController::getInstance()->startEffect("heavy_load");
}
