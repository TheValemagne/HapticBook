#include "pagesix.h"
#include "ui_pagesix.h"

PageSix::PageSix(QStackedWidget *parent) :
    Page(parent),
    ui(new Ui::PageSix)
{
    ui->setupUi(this);
}

PageSix::~PageSix()
{
    delete ui;
}

void PageSix::onMouseMove() {
    qDebug() << "LOG[PageSix] : onMouseMove()";
}
