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
    HapticController::getInstance()->startEffect("page2_wall");
}

PageTwo::~PageTwo()
{
    delete ui;
}


void PageTwo::onCollision()
{
//    HapticController::getInstance()->stopEffect("water");
    SoundController::getInstance()->playSound("bubbles");
    ui->ip->setIsLocked(true);
    Utils::delay(3);
    nextPage(false);
}

void PageTwo::on_ip_labelMove()
{
    SoundController::getInstance()->playSound("swim", true);
//    HapticController::getInstance()->startEffect("water");

    if (Utils::collision(ui->ip,  ui->exit) && !hasCollide){
        hasCollide = true;
        onCollision();
    }


    if (Utils::collision(ui->ip,  ui->rock_invisible)) {
        if (!hasRockInvisibleCollide) {
            hasRockInvisibleCollide = true;
        }
        onRockInvisibleCollision();

        // Set pos y only of the rock to the pos y of the ip + his height (79)
       if (!hasMarkerCollide) {
           ui->rock->move(defaultRockPosition.x() + (defaultRockPosition.y() - ui->ip->pos().y() + 110), ui->ip->pos().y() - 110);

           if (Utils::collision(ui->ip, ui->marker)) {
               onMarkerCollision();
           }
       }
    } else {
        if (hasRockInvisibleCollide && !hasMarkerCollide) {
            hasRockInvisibleCollide = false;
            // SoundController::getInstance()->stopSound("ip_force"); should auto stop
            HapticController::getInstance()->stopEffect("push_up");
            ui->rock->move(defaultRockPosition);
        }
    }
}

void PageTwo::onRockCollision()
{
    SoundController::getInstance()->playSound("ip_force");
    HapticController::getInstance()->startEffect("push_up");
}

void PageTwo::on_ip_mouseRelease()
{
//    stopSoundsAndEffects();
}

void PageTwo::onRockInvisibleCollision() {
    SoundController::getInstance()->playSound("ip_force");
    HapticController::getInstance()->startEffect("push_up");
}

void PageTwo::onMarkerCollision() {
    if (!hasMarkerCollide) {
        hasMarkerCollide = true;
        // Stop ip
        ui->ip->setIsLocked(true);

        SoundController::getInstance()->playSound("sliding_rock");

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
    }
}

void PageTwo::onRockAnimationFinished() {
    // Animation is complete, you can perform any additional actions here
    ui->ip->setIsLocked(false);
}
