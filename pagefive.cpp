#include "pagefive.h"
#include "ui_pagefive.h"
#include "Controller/hapticcontroller.h"
#include "utils.h"

PageFive::PageFive(QStackedWidget *parent) :
    Page(parent, 5),
    ui(new Ui::PageFive)
{
    ui->setupUi(this);

    changeCurcor(":images/ips_hand.png", 64, 65);
    showEmergencyTransmitter(false);

    this->show();
}

PageFive::~PageFive()
{
    delete ui;
}

void PageFive::onMouseMove()
{
    qDebug() << "LOG[PageFive] : onMouseMove()";
}

 void PageFive::showEmergencyTransmitter(bool isVisible)
 {
     ui->emergencyTransmitter->setHidden(!isVisible);
     ui->sosButton->setHidden(!isVisible);

     if (isVisible) {
         ui->emergencyTransmitter->raise();
         ui->sosButton->raise();
     }
 }

void PageFive::on_smallEmergencyTransmitter_clicked()
{
    ui->smallEmergencyTransmitter->setHidden(true);
    showEmergencyTransmitter(true);
}

void PageFive::on_sosButton_clicked()
{
    if (!hasCollide){
        hasCollide = true;
        HapticController::getInstance()->startEffect("pulse");
        Utils::delay(0.5);
        nextPage();
    }
}

void PageFive::on_treeTrunk1_labelMove()
{
    if (ui->treeTrunk1->isMovable && !ui->treeTrunk1->isEffectActive){
        HapticController::getInstance()->startEffect("heavy_load");
        ui->treeTrunk1->isEffectActive = true;
    }
}

void PageFive::on_treeTrunk1_mouseRelease()
{
    HapticController::getInstance()->stopEffect("heavy_load");
    ui->treeTrunk1->isEffectActive = false;
}

void PageFive::on_treeTrunk2_labelMove()
{
    if (ui->treeTrunk2->isMovable && !ui->treeTrunk2->isEffectActive){
        HapticController::getInstance()->startEffect("heavy_load");
        ui->treeTrunk2->isEffectActive = true;
    }
}

void PageFive::on_treeTrunk2_mouseRelease()
{
    HapticController::getInstance()->stopEffect("heavy_load");
    ui->treeTrunk2->isEffectActive = false;
}
