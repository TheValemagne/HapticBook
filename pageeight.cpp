#include <QApplication>
#include "pageeight.h"
#include "ui_pageeight.h"
#include "mainwindow.h"
#include "Controller/soundcontroller.h"

PageEight::PageEight(QStackedWidget *parent) :
    Page(parent, 8),
    ui(new Ui::PageEight)
{
    ui->setupUi(this);
    ui->closeButton->setCursor(QCursor(Qt::PointingHandCursor));
}

PageEight::~PageEight()
{
    delete ui;
}

void PageEight::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    SoundController::getInstance()->playSound("main_theme", true);
}

void PageEight::on_closeButton_clicked()
{
    QApplication::quit();
}

void PageEight::on_closeButton_pressed()
{
    ui->closeButton->setCursor(Qt::ClosedHandCursor);
}

void PageEight::on_closeButton_released()
{
    ui->closeButton->setCursor(Qt::PointingHandCursor);
}
