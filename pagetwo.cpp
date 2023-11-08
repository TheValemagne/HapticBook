#include "pagetwo.h"
#include "ui_pagetwo.h"
#include<QUrl>
#include<QString>
#include<QDebug>
#include"utils.h"
PageTwo::PageTwo(QStackedWidget *parent) :
    Page(parent, 2),
    ui(new Ui::PageTwo)
{
    ui->setupUi(this);
    this->show();
}

PageTwo::~PageTwo()
{
    delete ui;
}

void PageTwo::onMouseMove()
{
    qDebug() << "LOG[PageTwo] : onMouseMove()";
}


