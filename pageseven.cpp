#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include "pageseven.h"
#include "ui_pageseven.h"
#include "utils.h"
#include "Controller/hapticcontroller.h"
#include "Controller/soundcontroller.h"

PageSeven::PageSeven(QStackedWidget *parent) :
    Page(parent, 7),
    ui(new Ui::PageSeven)
{
    ui->setupUi(this);
    ui->ufo_2->setHidden(true);
}

PageSeven::~PageSeven()
{
    delete ui;
}

void PageSeven::showEvent(QShowEvent *event) {
    Page::showEvent(event);
    SoundController::getInstance()->playSound("ufo", true);
}

void PageSeven::on_ip_labelMove() {
    if (Utils::collision(ui->ip,  ui->exit) && !hasCollide){
        hasCollide = true;
        onCollision();
    }

    if (Utils::collision(ui->ip,  ui->tractorBeam) && !hasCollide) {
        onTractorBeamCollision();
    } else {
        onTractorBeamCollisionReverse();
    }
}

void PageSeven::on_ip_mouseRelease() {
    if (tractorBeamCollision) {
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
    ui->ufo_2->setHidden(false);
    ui->ufo->setHidden(true);
    ui->ip->setHidden(true);
    ui->ip->setIsLocked(true);

    onTractorBeamDeactivation();
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

    // Définissez la durée de l'animation (en millisecondes)
    animation->setDuration(3000);

    // Définissez la courbe d'interpolation pour un mouvement fluide
    animation->setEasingCurve(QEasingCurve::OutInBounce);

    // Définissez la valeur de fin de l'opacité (0 pour rendre l'élément invisible)
    animation->setEndValue(0);

    // Connectez le signal finished à une fonction qui sera appelée lorsque l'animation est terminée
    connect(animation, &QPropertyAnimation::finished, this, &PageSeven::onTractorBeamDeactivationFinished);

    // Commencez l'animation
    animation->start();
}

void PageSeven::onTractorBeamDeactivationFinished() {
    // L'animation est terminée, vous pouvez effectuer des actions supplémentaires ici
    // Par exemple, masquer l'élément ou effectuer d'autres actions nécessaires après la désactivation
    ui->tractorBeam->hide();
    startAnimationUFOLeft();
}

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
    Utils::delay(1);
    nextPage();
}
