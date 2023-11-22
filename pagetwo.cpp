#include "pagetwo.h"
#include "ui_pagetwo.h"
#include<QUrl>
#include<QString>
#include<QDebug>
#include"utils.h"
#include "Controller/soundcontroller.h"
#include "Controller/hapticcontroller.h"

PageTwo::PageTwo(QStackedWidget *parent) :
    Page(parent, 2),
    ui(new Ui::PageTwo)
{
    ui->setupUi(this);
    ipPosition = ui->ip->pos();
    hasRockCollide = false;
    hasRockInvisibleCollide = false;
    defaultRockPosition = ui->rock->pos();
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
            onRockInvisibleCollision();
        } else {
            onRockInvisibleCollision();
        }

        // Set pos y only of the rock to the pos y of the ip + his height (79)
        ui->rock->move(ui->rock->pos().x(), ui->ip->pos().y() - 79);
    } else {
        if (hasRockInvisibleCollide) {
            hasRockInvisibleCollide = false;
            SoundController::getInstance()->stopSound("ip_force");
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
