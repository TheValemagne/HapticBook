#include "movablelabel.h"

/**
 * Classe définissant un QLabel déplacable lors de sa saisie par la sourie
 *
 * @param parent le widget parent
 * @param f flag du widget
 */
MovableLabel::MovableLabel(QWidget* parent, Qt::WindowFlags f) :
    QLabel(parent, f)
{
    isMovable = false; // si le label est déplacable
    isLocked = false; // si le label est verrouillé

    // les curseurs par défaux
    openHandCursor = Qt::OpenHandCursor;
    closedHandCursor = Qt::ClosedHandCursor;
}

void MovableLabel::mousePressEvent(QMouseEvent *event){
    if(!isLocked){
        setCursor(closedHandCursor);
    }

    isMovable = true; // label déplacable à la saisie avec la souris
    mousePos = event->pos(); // enregistrement de la dernière position du label
    emit mousePress();
}

void MovableLabel::mouseReleaseEvent(QMouseEvent *event){
    Q_UNUSED(event);

    if(!isLocked){ // le label est verrouillé, afficher le curseur normal
        setCursor(openHandCursor);
    }

    isMovable = false; // label non déplacable au relachement de la souris
    emit mouseRelease();
}

void MovableLabel::mouseMoveEvent(QMouseEvent *event){
    if (!isMovable || isLocked) { // vérification si l'objet n'est pas déplacable ou verrouillé 
        return;
    }

   QPoint newPos = this->mapToGlobal(event->pos());
   QPoint movement = newPos - mousePos; // calcul du déplacement à effectuer
   this->move(movement); // réalisation du déplacement de l'objet
   emit labelMove();
}

void MovableLabel::enterEvent(QEvent *event)
{
    Q_UNUSED(event);

    if(!isLocked){ // afficher le retour "saisie possible de l'objet" au survol de la souris
        setCursor(openHandCursor);
    } else { // lorsque l'objet n'est pas déplacable, afficher le curseur classique
        unsetCursor(); // par défaux la flèche
    }
}

/**
 * Verrouille le label pour empêcher tous déplacements
 *
 * @param isLocked, vrai si le label doit être verrouillé, sinon faux
 */
void MovableLabel::setLocked(bool isLocked) {
    this->isLocked = isLocked;

    if(!isLocked){
        setCursor(openHandCursor);
    } else {
        unsetCursor();
    }
}
