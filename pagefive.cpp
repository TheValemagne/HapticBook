#include "pagefive.h"
#include "ui_pagefive.h"

PageFive::PageFive(QStackedWidget *parent) :
    Page(parent),
    ui(new Ui::PageFive)
{
    ui->setupUi(this);
}

PageFive::~PageFive()
{
    delete ui;
}

void PageFive::onMouseMove() {
    qDebug() << "LOG[PageFive] : onMouseMove()";
}
