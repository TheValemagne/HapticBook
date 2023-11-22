#include "clickablelabel.h"

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent, f) {

}

ClickableLabel::~ClickableLabel() {}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    Q_UNUSED(event);

    setCursor(Qt::ClosedHandCursor);
    emit clicked();
}

void ClickableLabel::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    setCursor(Qt::PointingHandCursor);
}

void ClickableLabel::enterEvent(QEvent *event)
{
    Q_UNUSED(event);

    setCursor(Qt::PointingHandCursor); // curseur pour indiquer que l'objet est cliquable
}
