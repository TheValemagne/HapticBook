#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include "pageseven.h"
#include "ui_pageseven.h"
#include "utils.h"
#include "Controller/hapticcontroller.h"
#include "Controller/soundcontroller.h"

/*
 * Classe pour la page 7 du livre
 */
PageSeven::PageSeven(QStackedWidget *parent) :
    Page(parent, 7),
    ui(new Ui::PageSeven)
{
    ui->setupUi(this);  // Initialise le design de la page en utilisant le fichier pageseven.ui
    ui->ufo_2->hide();  // Cache l'ovni qui s'en va (affiché à la fin de la page)
}

PageSeven::~PageSeven()
{
    delete ui;
}

/*
 * Fonction appelée lorsque la page est affichée
 */
void PageSeven::showEvent(QShowEvent *event) {
    Page::showEvent(event);
    SoundController::getInstance()->playSound("ufo", true);  // Joue le son de l'ovni
}

/*
 * Lorsque IP est déplassé
 */
void PageSeven::on_ip_labelMove() {
    // S'il touche la sortie (ovni)
    if (Utils::collision(ui->ip,  ui->exit) && !hasCollide){
        hasCollide = true;
        onCollision();
    }

    // S'il touche le rayon tracteur
    if (Utils::collision(ui->ip,  ui->tractorBeam) && !hasCollide) {
        onTractorBeamCollision();
    } else {
        onTractorBeamCollisionReverse();
    }
}

// Lorsque IP est relaché
void PageSeven::on_ip_mouseRelease() {
    if (tractorBeamCollision) {  // Si IP est dans le rayon tracteur
        HapticController::getInstance()->stopEffect("tractor_beam");
    }
}

// On tractor beam collision
void PageSeven::onTractorBeamCollision() {
    tractorBeamCollision = true;
    HapticController::getInstance()->startEffect("tractor_beam");
    SoundController::getInstance()->playSound("tractor_beam", true);
}
void PageSeven::onTractorBeamCollisionReverse() {
    tractorBeamCollision = false;
    HapticController::getInstance()->stopEffect("tractor_beam");
    SoundController::getInstance()->stopSound("tractor_beam");

}

// On inside ufo collision
void PageSeven::onCollision() {
    HapticController::getInstance()->stopEffect("tractor_beam");
    SoundController::getInstance()->stopSound("ufo");
    ui->ufo_2->show();  // Affiche l'ovni qui s'en va
    ui->ufo->hide();  // Cache l'ovni qui est arrivé
    ui->ip->hide();
    ui->ip->setIsLocked(true);  // IP ne peut plus être déplacé

    onTractorBeamDeactivation();  // Démarre l'animation de désactivation du rayon tracteur
}

void PageSeven::onTractorBeamDeactivation() {
    SoundController::getInstance()->stopSound("tractor_beam");
    SoundController::getInstance()->playSound("tractor_beam_off");

    // Créez une QGraphicsOpacityEffect pour contrôler l'opacité
    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(ui->tractorBeam);

    // Appliquez QGraphicsOpacityEffect à la QLabel
    ui->tractorBeam->setGraphicsEffect(opacityEffect);

    // Créez une animation pour la propriété d'opacité de QGraphicsOpacityEffect
    QPropertyAnimation *animation = new QPropertyAnimation(opacityEffect, "opacity");

    // Définir la durée de l'animation (en millisecondes)
    animation->setDuration(3000);

    // Définir la courbe d'interpolation pour un mouvement fluide
    animation->setEasingCurve(QEasingCurve::OutInBounce);

    // Définir la valeur de fin de l'opacité (0 pour rendre l'élément invisible)
    animation->setEndValue(0);

    // Connecte le signal finished à une fonction qui sera appelée lorsque l'animation est terminée
    connect(animation, &QPropertyAnimation::finished, this, &PageSeven::onTractorBeamDeactivationFinished);

    // Commence l'animation
    animation->start();
}

void PageSeven::onTractorBeamDeactivationFinished() {
    // L'animation est terminée
    ui->tractorBeam->hide();

    Utils::delay(2);  // Attend 2 secondes
    startAnimationUFOLeft();
}

/*
 * Animation de l'ovni qui s'en va
 */
void PageSeven::startAnimationUFOLeft() {
    SoundController::getInstance()->playSound("ufo_away");
    QPropertyAnimation *animation = new QPropertyAnimation(ui->ufo_2, "pos");
    animation->setDuration(2000);
    animation->setEasingCurve(QEasingCurve::InBack);
    animation->setEndValue(QPoint(2000, -200));
    connect(animation, &QPropertyAnimation::finished, this, &PageSeven::onAnimationUFOLeftFinished);
    animation->start();
}

void PageSeven::onAnimationUFOLeftFinished() {
    Utils::delay(2); // attend 2 sec
    nextPage();
}
