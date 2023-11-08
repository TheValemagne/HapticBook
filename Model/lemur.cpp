#include "lemur.h"

Lemur::Lemur(QWidget* parent, Qt::WindowFlags f) :
        QLabel(parent, f)
{
   setMouseTracking(true); // permet de capter les mouvements audessus du widget sans devoir cliquer sur le widget
}

void Lemur::enterEvent(QEvent *event)
{
    emit enterEvent();
}

void Lemur::leaveEvent(QEvent *event)
{
    emit leaveEvent();
}

void Lemur::mouseMoveEvent(QMouseEvent *event)
{
    emit mouseMove();
}
