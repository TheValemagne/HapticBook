#include "pagefour.h"
#include "ui_pagefour.h"
#include<QString>
#include<QDebug>
#include"utils.h"
#include "Controller/hapticcontroller.h"
#include "Controller/soundcontroller.h"

PageFour::PageFour(QStackedWidget *parent) :
        Page(parent, 4),
        ui(new Ui::PageFour)
{
    ui->setupUi(this);
    Utils::delay(0.2); // attend 20 ms
}

PageFour::~PageFour()
{
    delete ui;
}

void PageFour::showEvent(QShowEvent *event) {
       /* for (int i = 2; i < 6; ++i) {
            QString path = QString(":/images/wale_heart%1.png").arg(QString::number(i));
            qDebug() << "LOG[PageFour] : wale heart animation" << path;
            QPixmap image = QPixmap(path);
            ui->wale->setPixmap(image);
            ui->wale->setFixedSize(image.size());
            //if(i == 4) ui->ip->setHidden(true);
            Utils::delay(0.05);
    }*/
}

void PageFour::onCollision()
{
    qDebug() << "LOG[PageFour] : wale over IP";

    //stopSoundsAndEffects();

   /* SoundController::getInstance()->playSound("bite");
    Utils::delay(0.01);
    HapticController::getInstance()->startEffect("waleback");
    for (int i = 2; i < 8; ++i) {
        QString path = QString(":/images/wale%1.png").arg(QString::number(i));
        qDebug() << "LOG[PageFour] : wale animation" << path;
        QPixmap image = QPixmap(path);
        ui->wale->setPixmap(image);
        ui->wale->setFixedSize(image.size());
        //if(i == 4) ui->ip->setHidden(true);
        Utils::delay(0.01);
    }
    //stopSoundsAndEffects(); */
    Utils::delay(1.2); // attend 2 sec avant de passer à la suite
}

void PageFour::on_wale_labelMove()
{
/*    if (Utils::collision(ui->wale,  ui->ip) && !hasCollide){
        hasCollide = true;
        onCollision();
        nextPage(true);
        ui->wale->setHidden(true);
    }*/
}

void PageFour::on_wale_mousePress()
{
    qDebug() << "LOG[PageFour] : mouse press";
  /*  SoundController::getInstance()->playSound("wale_cry");
    HapticController::getInstance()->startEffect("wale");*/
}

void PageFour::on_wale_mouseRelease()
{
    /*SoundController::getInstance()->stopSound("wale_cry");
    HapticController::getInstance()->stopEffect("wale");*/
}
