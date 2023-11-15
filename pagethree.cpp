#include "pagethree.h"
#include "ui_pagethree.h"
#include<QUrl>
#include<QString>
#include<QDebug>
#include"utils.h"
#include "Controller/hapticcontroller.h"
#include "Controller/soundcontroller.h"
#include "utils.h"

PageThree::PageThree(QStackedWidget *parent) :
    Page(parent, 6),
    ui(new Ui::PageThree)
{
    ui->setupUi(this);
    this->show();
}

PageThree::~PageThree()
{
    delete ui;
}

void PageThree::onCollision()
{
    qDebug() << "LOG[PageThree] : wale over IP";

    stopSoundsAndEffects();
    SoundController::getInstance()->playSound("explosion");
    Utils::delay(0.2); // attend 20 ms

    //HapticController::getInstance()->startEffect("landing");
    Utils::delay(2); // attend 2 sec avant de passer à la suite
}

void PageThree::onMouseMove()
{
    qDebug() << "LOG[PageThree] : onMouseMove()";

    if (Utils::collision(ui->wale,  ui->ip) && !hasCollide){
        hasCollide = true;
        //ui->wale->setHidden(true);
        onCollision();
        nextPage();
    }
}

void PageThree::on_wale_labelMove()
{
    if (ui->wale->isMovable) {
        SoundController::getInstance()->playSound("alarm", true);
    }

    if (ui->wale->isMovable){
        HapticController::getInstance()->startEffect("shaking");
    }

    onMouseMove();
}

void PageThree::on_wale_mouseRelease()
{
    HapticController::getInstance()->stopEffect("shaking");
}
