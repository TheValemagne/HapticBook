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

    //stopSoundsAndEffects();

     SoundController::getInstance()->playSound("bite");
     Utils::delay(0.05);
    for (int i = 2; i < 8; ++i) {
        QString path = QString(":/images/wale%1.png").arg(QString::number(i));
        qDebug() << "LOG[PageThree] : wale animation" << path;
        QPixmap image = QPixmap(path);
        ui->wale->setPixmap(image);
        ui->wale->setFixedSize(image.size());
        if(i == 5) ui->ip->setHidden(true);
        Utils::delay(0.01);
    }
    //stopSoundsAndEffects();
    Utils::delay(1.2); // attend 2 sec avant de passer à la suite
}

void PageThree::on_wale_labelMove()
{
    if (Utils::collision(ui->wale,  ui->ip) && !hasCollide){
        hasCollide = true;
        onCollision();
        nextPage(true);
        ui->wale->setHidden(true);
    }
}

void PageThree::on_wale_mousePress()
{
        qDebug() << "LOG[PageThree] : mouse press";
        SoundController::getInstance()->playSound("wale_cry");
        HapticController::getInstance()->startEffect("wale");
}

void PageThree::on_wale_mouseRelease()
{
    SoundController::getInstance()->stopSound("wale_cry");
    HapticController::getInstance()->stopEffect("wale");
}
