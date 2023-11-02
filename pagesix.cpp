#include "pagesix.h"
#include "ui_pagesix.h"
#include "Model/lemur.h"
#include "utils.h"

PageSix::PageSix(QStackedWidget *parent) :
    Page(parent),
    ui(new Ui::PageSix)
{
    ui->setupUi(this);
    changeCurcor(":images/ips_hand.png", 43, 43);
    hasTouchedFur = false;

    QString qs = QString(":/images/lemur.png");
    Element *lemur = new Lemur(qs, QPoint(301, 0), this); // Remplacez "parentWidget" par le parent approprié
    addElement("lemur", lemur);

    // cacher la notification et le bouton confirmer position
    showNotification(false);
}

PageSix::~PageSix()
{
    delete ui;
}

void PageSix::showNotification(bool isVisible)
{
    ui->notification->setHidden(!isVisible);
    ui->answerButton->setHidden(!isVisible);
}

void PageSix::onMouseMove()
{
    qDebug() << "LOG[PageSix] : onMouseMove()";
    if (!hasTouchedFur) {
        qDebug() << "Show notification soon";
        hasTouchedFur = true;
        Utils::delay(4);
        showNotification(true);
    }
}

void PageSix::on_answerButton_clicked()
{
    if(!hasCollide){
        hasCollide = true;
        nextPage();
    }
}
