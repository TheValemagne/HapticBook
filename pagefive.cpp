#include "pagefive.h"
#include "ui_pagefive.h"
#include "Controller/hapticcontroller.h"
#include "utils.h"

PageFive::PageFive(QStackedWidget *parent) :
    Page(parent, 5),
    ui(new Ui::PageFive)
{
    ui->setupUi(this);
    treeTrunkPosition1 = ui->treeTrunk1->pos();
    treeTrunkPosition2 = ui->treeTrunk2->pos();

    changeCurcor(":images/ips_hand.png", 64, 65);
}

PageFive::~PageFive()
{
    delete ui;
}

void PageFive::showEvent(QShowEvent *event)
{
    Page::showEvent(event);
    showEmergencyTransmitter(false);
}

void PageFive::hideEvent(QHideEvent *event)
{
    Page::hideEvent(event);
    ui->smallEmergencyTransmitter->setHidden(false);
    ui->treeTrunk1->move(treeTrunkPosition1);
    ui->treeTrunk2->move(treeTrunkPosition2);
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
        HapticController::getInstance()->startEffect("click");
        Utils::delay(0.5);
        nextPage();
    }
}

void PageFive::on_treeTrunk1_labelMove()
{
    HapticController::getInstance()->startEffect("heavy_load");
}

void PageFive::on_treeTrunk1_mouseRelease()
{
    HapticController::getInstance()->stopEffect("heavy_load");
}

void PageFive::on_treeTrunk2_labelMove()
{
    HapticController::getInstance()->startEffect("heavy_load");
}

void PageFive::on_treeTrunk2_mouseRelease()
{
    HapticController::getInstance()->stopEffect("heavy_load");
}
