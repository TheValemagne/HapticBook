#include "pageseven.h"
#include "ui_pageseven.h"

PageSeven::PageSeven(QStackedWidget *parent) :
    Page(parent, 7),
    ui(new Ui::PageSeven)
{
    ui->setupUi(this);
}

PageSeven::~PageSeven()
{
    delete ui;
}

void PageSeven::onMouseMove()
{
    qDebug() << "LOG[PageSevent] : onMouseMove()";
}
