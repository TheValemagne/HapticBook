#include <QApplication>
#include "pageeight.h"
#include "ui_pageeight.h"
#include "mainwindow.h"

PageEight::PageEight(QStackedWidget *parent) :
    Page(parent),
    ui(new Ui::PageEight)
{
    ui->setupUi(this);
}

PageEight::~PageEight()
{
    delete ui;
}

void PageEight::onMouseMove() {
    qDebug() << "LOG[PageEight] : onMouseMove()";
}

void PageEight::on_closeButton_clicked()
{
  qApp->closeAllWindows();
}