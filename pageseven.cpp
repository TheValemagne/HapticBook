#include <QPropertyAnimation>
#include "pageseven.h"
#include "ui_pageseven.h"
#include "utils.h"
#include "Controller/hapticcontroller.h"

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
}

void PageSeven::on_ip_labelMove() {
    if (Utils::collision(ui->ip,  ui->exit) && !hasCollide){
        hasCollide = true;
        onCollision();
    }

    if (Utils::collision(ui->ip,  ui->tractorBeam) && !hasCollide) {
        tractorBeamCollision = true;
        onTractorBeamCollision();
    } else {
        tractorBeamCollision = false;
        HapticController::getInstance()->stopEffect("tractor_beam");
    }
}

// On tractor beam collision
void PageSeven::onTractorBeamCollision() {
    HapticController::getInstance()->startEffect("tractor_beam");
}

// On inside ufo collision
void PageSeven::onCollision() {
//    nextPage();
    HapticController::getInstance()->stopEffect("tractor_beam");
    ui->ufo_2->setHidden(false);
    ui->ufo->setHidden(true);
    ui->ip->setHidden(true);
    ui->ip->setIsLocked(true);

    // TODO : Sound of tractor beam desactivation
    onTractorBeamDeactivation();
}

void PageSeven::onTractorBeamDeactivation() {
    // Créez une animation pour la propriété d'opacité de tractorBeam
    QPropertyAnimation *animation = new QPropertyAnimation(ui->tractorBeam, "opacity");

    // Définissez la durée de l'animation (en millisecondes)
    animation->setDuration(1000);

    // Définissez la courbe d'interpolation pour un mouvement fluide
    animation->setEasingCurve(QEasingCurve::InOutElastic);

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
}
