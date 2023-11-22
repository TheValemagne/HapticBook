#include "clickablelabel.h"

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent) {

}

ClickableLabel::~ClickableLabel() {}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    Q_UNUSED(event);

    setCursor(QCursor(Qt::ClosedHandCursor));
    emit clicked();
}

void ClickableLabel::enterEvent(QEvent *event)
{
    Q_UNUSED(event);

    setCursor(QCursor(Qt::PointingHandCursor));
}
