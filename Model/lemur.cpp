#include "lemur.h"
#include "Controller/HapticController.h"

Lemur::Lemur(const QString& src,
                         const QPoint &position,
                         Page *parent) :
Element(src, position, parent)
{
    setMouseTracking(true); // permet de capter les mouvements audessus du widget sans devoir cliquer sur le widget
}

void Lemur::enterEvent(QEvent *event)
{
    qDebug() << "LOG[Lemur] enter event";
    HapticController::getInstance()->startEffect("fur");
}

void Lemur::leaveEvent(QEvent *event)
{
    qDebug() << "LOG[Lemur] leave event";
    HapticController::getInstance()->stopEffect("fur");
}

void Lemur::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "LOG[Lemur] moving";
    this->page->onMouseMove();
}
