#include "pagesix.h"
#include "ui_pagesix.h"
#include "Model/lemur.h"
#include "Controller/hapticcontroller.h"
#include "utils.h"

PageSix::PageSix(QStackedWidget *parent) :
    Page(parent, 6),
    ui(new Ui::PageSix)
{
    ui->setupUi(this);
    changeCurcor(":images/ips_hand.png", 43, 43);
    hasTouchedFur = false;
    showNotification(false);
    this->show();
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

void PageSix::on_lemur_enterEvent()
{
    if (!isCurrentPage()){ // avec mouse tracking, l'événement est capter même lorsque la page n'est pas affiché à l'écran
        return;
    }
    qDebug() << "LOG[Lemur] enter event";
    HapticController::getInstance()->startEffect("fur");
}

void PageSix::on_lemur_leaveEvent()
{
    qDebug() << "LOG[Lemur] leave event";
    HapticController::getInstance()->stopEffect("fur");
}

void PageSix::on_lemur_mouseMove()
{
    if (!isCurrentPage()){ // avec mouse tracking, l'événement est capter même lorsque la page n'est pas affiché à l'écran
       return;
    }
    onMouseMove();
}
