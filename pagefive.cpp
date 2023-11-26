#include <QPixmap>
#include "pagefive.h"
#include "ui_pagefive.h"
#include "Controller/hapticcontroller.h"
#include "Controller/soundcontroller.h"
#include "utils.h"

PageFive::PageFive(QStackedWidget *parent) :
    Page(parent, 5),
    ui(new Ui::PageFive)
{
    ui->setupUi(this);
    setCursors();

    treeTrunkPosition1 = ui->treeTrunk1->pos();
    treeTrunkPosition2 = ui->treeTrunk2->pos();
}

PageFive::~PageFive()
{
    delete ui;
}

void PageFive::setCursors()
{
    ui->sosButton->setCursor(Qt::PointingHandCursor);

    QCursor openHandCurcor = QCursor(QPixmap(":images/ips_hand.png"), 48, 45);
    QCursor closedHandCursor = QCursor(QPixmap(":images/ips_closedhand.png"));

    ui->treeTrunk1->openHandCursor = openHandCurcor;
    ui->treeTrunk1->closedHandCursor = closedHandCursor;

    ui->treeTrunk2->openHandCursor = openHandCurcor;
    ui->treeTrunk2->closedHandCursor = closedHandCursor;
}

void PageFive::showEvent(QShowEvent *event)
{
    Page::showEvent(event);
    showEmergencyTransmitter(false);
    SoundController::getInstance()->playSound("rainforest", true);
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

        HapticController::getInstance()->stopAllEffects();
        nextPage(false);
    }
}

void PageFive::on_sosButton_pressed()
{
    ui->sosButton->setCursor(Qt::ClosedHandCursor);
}

void PageFive::on_sosButton_released()
{
    ui->sosButton->setCursor(Qt::PointingHandCursor);
}

void PageFive::onTreeTrunkMove()
{
    HapticController::getInstance()->startEffect("heavy_load");
    SoundController::getInstance()->playSound("ip_force", true);
}

void PageFive::onTreeTrunkRelease()
{
    HapticController::getInstance()->stopEffect("heavy_load");
    SoundController::getInstance()->stopSound("ip_force");
}

void PageFive::on_treeTrunk1_labelMove()
{
   onTreeTrunkMove();
}

void PageFive::on_treeTrunk1_mouseRelease()
{
    onTreeTrunkRelease();
}

void PageFive::on_treeTrunk2_labelMove()
{
    onTreeTrunkMove();
}

void PageFive::on_treeTrunk2_mouseRelease()
{
    onTreeTrunkRelease();
}
