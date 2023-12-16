#include "clickablelabel.h"

/**
 * Classe pour créer un QLable cliquable et afficher les bons curseurs
 *
 * @param parent le widget parent
 * @param f flag du widget
 */
ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent, f) {

}

ClickableLabel::~ClickableLabel() {}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    Q_UNUSED(event);

    // le curseur indique le clique sur l'objet
    setCursor(Qt::ClosedHandCursor);
    emit clicked();
}

void ClickableLabel::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    // le curseur indique le relachement du clique
    setCursor(Qt::PointingHandCursor);
}

void ClickableLabel::enterEvent(QEvent *event)
{
    Q_UNUSED(event);

    // curseur pour indiquer que l'objet est cliquable
    setCursor(Qt::PointingHandCursor);
}
