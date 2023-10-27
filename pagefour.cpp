#include "pagefour.h"
#include "ui_pagefour.h"

PageFour::PageFour(QStackedWidget *parent) :
    Page(parent),
    ui(new Ui::PageFour)
{
    ui->setupUi(this);
}

PageFour::~PageFour()
{
    delete ui;
}

void PageFour::onMouseMove() {
    qDebug() << "LOG[PageFour] : onMouseMove()";
}

