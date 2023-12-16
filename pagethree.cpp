#include "pagethree.h"
#include "ui_pagethree.h"
#include<QString>
#include<QDebug>
#include"utils.h"
#include "Controller/hapticcontroller.h"
#include "Controller/soundcontroller.h"

PageThree::PageThree(QStackedWidget *parent) :
    Page(parent, 3),
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

    SoundController::getInstance()->playSound("bite");
    Utils::delay(0.01);
    HapticController::getInstance()->startEffect("waleback");

    for (int i = 2; i < 8; ++i) { // animation la baleine mange l'extraterrestre
        QString path = QString(":/images/wale%1.png").arg(QString::number(i));
        qDebug() << "LOG[PageThree] : wale animation" << path;
        QPixmap image = QPixmap(path);
        ui->wale->setPixmap(image);
        ui->wale->setFixedSize(image.size());
        if(i == 4) ui->ip->setHidden(true);
        Utils::delay(0.01);
    }

    Utils::delay(1.2); // attend 1.2 sec avant de passer à la suite
}

void PageThree::on_wale_labelMove()
{
    if (Utils::collision(ui->wale,  ui->ip) && !hasCollide){
        hasCollide = true;
        onCollision();
        nextPage(true);
        ui->wale->hide();
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
