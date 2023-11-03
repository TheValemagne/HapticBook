#include "pagethree.h"
#include "ui_pagethree.h"
#include"Model/MovableElement.h"
#include<QUrl>
#include<QString>
#include<QDebug>
#include"utils.h"

PageThree::PageThree(QStackedWidget *parent) :
    Page(parent, 6),
    ui(new Ui::PageThree)
{
    ui->setupUi(this);

    QString qs = QString(":/images/wale.png");
    Element *rocket = new MovableElement(qs, QPoint(593, 7), this); // Remplacez "parentWidget" par le parent approprié
    addElement("rocket", rocket);

    // Ajoutez l'objet Element à votre interface utilisateur, par exemple, à un layout ou à un widget
    this->show();
}

PageThree::~PageThree()
{
    delete ui;
}

void PageThree::onMouseMove()
{
    qDebug() << "LOG[PageThree] : onMouseMove()";
}
