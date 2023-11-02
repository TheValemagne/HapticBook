#include "pagefive.h"
#include "ui_pagefive.h"
#include "Model/treetrunk.h"
#include "utils.h"

PageFive::PageFive(QStackedWidget *parent) :
    Page(parent),
    ui(new Ui::PageFive)
{
    ui->setupUi(this);

    changeCurcor(":images/ips_hand.png", 64, 65);
    showEmergencyTransmitter(false);

    Element *treeTrunk1 = new TreeTrunk(
                QString(":/images/tree_trunk_1.png"),
                QPoint(403, 538), this);
    Element *treeTrunk2 = new TreeTrunk(
                QString(":/images/tree_trunk_2.png"),
                QPoint(385, 573), this);

    addElement("treeTrunk1", treeTrunk1);
    addElement("treeTrunk2", treeTrunk2);

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
        Utils::delay(1);
        nextPage();
    }
}
