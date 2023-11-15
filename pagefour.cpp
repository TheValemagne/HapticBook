#include "pagefour.h"
#include "ui_pagefour.h"

PageFour::PageFour(QStackedWidget *parent) :
    Page(parent, 4),
    ui(new Ui::PageFour)
{
    ui->setupUi(this);
}

PageFour::~PageFour()
{
    delete ui;
}


void PageFour::onCollision()
{
    qDebug() << "LOG[PageFour] : rocket over earth";

/*    stopSoundsAndEffects();
    SoundController::getInstance()->playSound("explosion");
    Utils::delay(0.2); // attend 20 ms*/

    //HapticController::getInstance()->startEffect("landing");
    //Utils::delay(2); // attend 2 sec avant de passer à la suite
}



void PageFour::on_wale_labelMove()
{
/*    if (ui->rocket->isMovable) {
        SoundController::getInstance()->playSound("alarm", true);
    }

    if (ui->rocket->isMovable){
        HapticController::getInstance()->startEffect("shaking");
    }*/
}

void PageFour::on_wale_mouseRelease()
{
    /*HapticController::getInstance()->stopEffect("shaking");*/
}
