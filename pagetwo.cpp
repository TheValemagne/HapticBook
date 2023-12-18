#include "pagetwo.h"
#include "ui_pagetwo.h"
#include<QUrl>
#include<QString>
#include<QDebug>
#include"utils.h"
#include "Controller/soundcontroller.h"
#include "Controller/hapticcontroller.h"
#include <QPropertyAnimation>


PageTwo::PageTwo(QStackedWidget *parent) :
    Page(parent, 2),
    ui(new Ui::PageTwo)
{
    ui->setupUi(this);
    ipPosition = ui->ip->pos();
    hasRockCollide = false;  // Rocher visible (animation)
    hasRockInvisibleCollide = false;  // Rocher invisible (fix sur sa position initial)
    hasMarkerCollide = false;  // Hauteur max du rocher (déclanche l'animation à son contact)
    defaultRockPosition = ui->rock->pos();
}

PageTwo::~PageTwo()
{
    delete ui;
}

void PageTwo::showEvent(QShowEvent *event) {
    Q_UNUSED(event);
    hasCollide = false;
    hasRockCollide = false;
    hasRockInvisibleCollide = false;
    hasMarkerCollide = false;

    ui->ip->show();
    ui->ip->setLocked(false);
    ui->ip->move(ipPosition);
    ui->rock->move(defaultRockPosition);

    HapticController::getInstance()->startEffect("page2_wall");
    SoundController::getInstance()->playSound("swim", true);
}

void PageTwo::onCollision()
{
    SoundController::getInstance()->playSound("bubbles");
    ui->ip->setLocked(true);

    Utils::delay(3);

    nextPage(false);
    HapticController::getInstance()->stopEffect("page2_wall");
    ui->ip->hide();
}

void PageTwo::on_ip_labelMove()
{
    HapticController::getInstance()->startEffect("water");

    // S'il touche la sortie (rocher)
    if (Utils::collision(ui->ip,  ui->exit) && !hasCollide){
        hasCollide = true;
        onCollision();
    }

    // S'il touche le rocher invisible (entrain de pousser le rocher visible)
    if (Utils::collision(ui->ip,  ui->rock_invisible)) {
        if (!hasRockInvisibleCollide) {
            hasRockInvisibleCollide = true;
        }
        onRockInvisibleCollision();

    } else {
        if (hasRockInvisibleCollide && !hasMarkerCollide) {
            hasRockInvisibleCollide = false;
            SoundController::getInstance()->stopSound("ip_force");
            HapticController::getInstance()->stopEffect("rock_push");
            ui->rock->move(defaultRockPosition);
        }
    }
}

void PageTwo::on_ip_mouseRelease()
{
    HapticController::getInstance()->stopEffect("water");
}

void PageTwo::onRockInvisibleCollision() {
    // Set pos y only of the rock to the pos y of the ip + his height (79)
    if (!hasMarkerCollide) {
        HapticController::getInstance()->startEffect("rock_push");
        SoundController::getInstance()->playSound("ip_force");
        // Move the rock when ip is pushing it
        ui->rock->move(defaultRockPosition.x() + (defaultRockPosition.y() - ui->ip->pos().y() + 110), ui->ip->pos().y() - 110);

        if (Utils::collision(ui->ip, ui->marker)) {
            onMarkerCollision();
        }
    }
}

void PageTwo::onMarkerCollision() {
    if (hasMarkerCollide) {
        return;
    }

    hasMarkerCollide = true;
    // Stop ip
    ui->ip->setLocked(true);

    HapticController::getInstance()->stopEffect("rock_push");

    SoundController::getInstance()->playSound("sliding_rock");
    HapticController::getInstance()->startEffect("rock_sliding");

    // Create an animation for the rock
    QPropertyAnimation *animation = new QPropertyAnimation(ui->rock, "pos");

    // Set the duration of the animation (in milliseconds)
    animation->setDuration(3000);

    // Set the easing curve for smooth motion
    animation->setEasingCurve(QEasingCurve::OutBounce);

    // Set the end position of the rock (e.g., slide down and to the right)
    QPointF endPos(570, 307);

    // Set the start and end values for the animation
    animation->setStartValue(ui->rock->pos());
    animation->setEndValue(endPos);

    // Connect the finished signal to a slot that will be called when the animation is complete
    connect(animation, &QPropertyAnimation::finished, this, &PageTwo::onRockAnimationFinished);

    // Start the animation
    animation->start();

    Utils::delay(1.2);
    HapticController::getInstance()->stopEffect("rock_sliding");
}

void PageTwo::onRockAnimationFinished() {
    // Animation is complete
    ui->ip->setLocked(false);
}
