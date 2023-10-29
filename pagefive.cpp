#include "pagefive.h"
#include "ui_pagefive.h"
#include "Model/treetrunk.h"

PageFive::PageFive(QStackedWidget *parent) :
    Page(parent),
    ui(new Ui::PageFive)
{
    ui->setupUi(this);

    changeCurcor(":images/ips_hand.png", 64, 65);
    hideEmergencyTransmitter(true);

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

 void PageFive::hideEmergencyTransmitter(bool shouldHide)
 {
     ui->emergencyTransmitter->setHidden(shouldHide);
     ui->sosButton->setHidden(shouldHide);

     if (!shouldHide) {
         ui->emergencyTransmitter->raise();
         ui->sosButton->raise();
     }
 }

void PageFive::on_smallEmergencyTransmitter_clicked()
{
    ui->smallEmergencyTransmitter->setHidden(true);
    hideEmergencyTransmitter(false);
}

void PageFive::on_sosButton_clicked()
{
    nextPage();
}
