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
    Utils::delay(0.2); // attend 20 ms
}

PageThree::~PageThree()
{
    delete ui;
}

void PageThree::onCollision()
{
    qDebug() << "LOG[PageThree] : wale over IP";

    stopSoundsAndEffects();
    ui->ip->setHidden(true);
    SoundController::getInstance()->playSound("bite");
    for (int i = 2; i < 8; ++i) {
        QString path = QString(":/images/wale%1.png").arg(QString::number(i));
        qDebug() << "LOG[PageThree] : wale animation" << path;
        QPixmap image = QPixmap(path);
        ui->wale->setPixmap(image);
        ui->wale->setFixedSize(image.size());
        Utils::delay(0.01);
    }
    Utils::delay(0.2); // attend 20 ms

    //HapticController::getInstance()->startEffect("landing");
    Utils::delay(2); // attend 2 sec avant de passer à la suite
}

void PageThree::on_wale_labelMove()
{
    if (ui->wale->isMovable) {
        SoundController::getInstance()->playSound("wale_cry");
    }

    if (ui->wale->isMovable){
            Utils::delay(0.05); // attend 20 ms
        HapticController::getInstance()->startEffect("wale");
    }

    if (Utils::collision(ui->wale,  ui->ip) && !hasCollide){
        hasCollide = true;
        //ui->wale->setHidden(true);
        onCollision();
        nextPage(true);
        ui->wale->setHidden(true);
    }
}

void PageThree::on_wale_mouseRelease()
{
    HapticController::getInstance()->stopEffect("shaking");
}
