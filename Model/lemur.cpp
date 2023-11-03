#include "lemur.h"
#include "Controller/hapticcontroller.h"

Lemur::Lemur(const QString& src,
                         const QPoint &position,
                         Page *parent) :
Element(src, position, parent)
{
   setMouseTracking(true); // permet de capter les mouvements audessus du widget sans devoir cliquer sur le widget
}

void Lemur::enterEvent(QEvent *event)
{
    Element::enterEvent(event);

    if (!page->isCurrentPage()){ // avec mouse tracking, l'événement est capter même lorsque la page n'est pas affiché à l'écran
        return;
    }
    qDebug() << "LOG[Lemur] enter event";
    HapticController::getInstance()->startEffect("fur");
}

void Lemur::leaveEvent(QEvent *event)
{
    Element::leaveEvent(event);

    qDebug() << "LOG[Lemur] leave event";
    HapticController::getInstance()->stopEffect("fur");
}

void Lemur::mouseMoveEvent(QMouseEvent *event)
{
    Element::mouseMoveEvent(event);

    if (!page->isCurrentPage()){ // avec mouse tracking, l'événement est capter même lorsque la page n'est pas affiché à l'écran
        return;
    }
    this->page->onMouseMove();
}
