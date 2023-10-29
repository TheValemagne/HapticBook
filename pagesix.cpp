#include "pagesix.h"
#include "ui_pagesix.h"

PageSix::PageSix(QStackedWidget *parent) :
    Page(parent),
    ui(new Ui::PageSix)
{
    ui->setupUi(this);
    changeCurcor(":images/ips_hand.png", 43, 43);

    // cacher la notification et le bouton confirmer position
    ui->notification->setHidden(true);
    ui->answerButton->setHidden(true);
}

PageSix::~PageSix()
{
    delete ui;
}

void PageSix::onMouseMove()
{
    qDebug() << "LOG[PageSix] : onMouseMove()";
}

void PageSix::on_answerButton_clicked()
{
    nextPage();
}
