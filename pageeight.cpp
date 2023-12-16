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
    // lancement du son d'ambiance
    SoundController::getInstance()->playSound("main_theme", true);
}

void PageEight::on_closeButton_clicked()
{
    // fermer le livre
    QApplication::quit();
}

void PageEight::on_closeButton_pressed()
{
    // le curseur indique le clique sur l'objet
    ui->closeButton->setCursor(Qt::ClosedHandCursor); 
}

void PageEight::on_closeButton_released()
{
    // le curseur indique le relachement du clique
    ui->closeButton->setCursor(Qt::PointingHandCursor);
}
