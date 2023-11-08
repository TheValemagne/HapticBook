#include "pagethree.h"
#include "ui_pagethree.h"
#include<QUrl>
#include<QString>
#include<QDebug>
#include"utils.h"

PageThree::PageThree(QStackedWidget *parent) :
    Page(parent, 6),
    ui(new Ui::PageThree)
{
    ui->setupUi(this);
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
