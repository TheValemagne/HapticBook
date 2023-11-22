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
}

void PageTwo::on_ip_mouseRelease()
{
//    stopSoundsAndEffects();
}
