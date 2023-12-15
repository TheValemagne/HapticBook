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
    hasRockCollide = false;
    hasRockInvisibleCollide = false;
    hasMarkerCollide = false;
    defaultRockPosition = ui->rock->pos();
    SoundController::getInstance()->playSound("swim", true);
}

PageTwo::~PageTwo()
{
    delete ui;
}

void PageTwo::showEvent(QShowEvent *event) {
    hasCollide = false;
    hasRockCollide = false;
    hasRockInvisibleCollide = false;
    hasMarkerCollide = false;
    ui->ip->show();
    ui->ip->setIsLocked(false);
    ui->ip->move(ipPosition);
    ui->rock->move(defaultRockPosition);
    HapticController::getInstance()->startEffect("page2_wall");
}

void PageTwo::onCollision()
{
//    HapticController::getInstance()->stopEffect("water");
    SoundController::getInstance()->playSound("bubbles");
    ui->ip->setIsLocked(true);
    Utils::delay(3);
    nextPage(false);
    HapticController::getInstance()->stopEffect("page2_wall");
    ui->ip->hide();
}

void PageTwo::on_ip_labelMove()
{
    HapticController::getInstance()->startEffect("water");

    if (Utils::collision(ui->ip,  ui->exit) && !hasCollide){
        hasCollide = true;
        onCollision();
    }


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
        ui->rock->move(defaultRockPosition.x() + (defaultRockPosition.y() - ui->ip->pos().y() + 110), ui->ip->pos().y() - 110);

        if (Utils::collision(ui->ip, ui->marker)) {
            onMarkerCollision();
        }
    }
}

void PageTwo::onMarkerCollision() {
    if (!hasMarkerCollide) {
        hasMarkerCollide = true;
        // Stop ip
        ui->ip->setIsLocked(true);

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
}

void PageTwo::onRockAnimationFinished() {
    // Animation is complete, you can perform any additional actions here
    ui->ip->setIsLocked(false);
}
