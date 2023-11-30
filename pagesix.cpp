#include "pagesix.h"
#include "ui_pagesix.h"
#include "Model/lemur.h"
#include "Controller/hapticcontroller.h"
#include "Controller/soundcontroller.h"
#include "utils.h"

PageSix::PageSix(QStackedWidget *parent) :
    Page(parent, 6),
    ui(new Ui::PageSix)
{
    ui->setupUi(this);
    ui->answerButton->setCursor(Qt::PointingHandCursor);
}

PageSix::~PageSix()
{
    delete ui;
}

void PageSix::showEvent(QShowEvent *event)
{
    Page::showEvent(event);
    hasTouchedFur = false;
    isFirstMove = true;
    showNotification(false);
    SoundController::getInstance()->playSound("rainforest", true);
}

void PageSix::showNotification(bool isVisible)
{
    ui->notification->setHidden(!isVisible);
    ui->answerButton->setHidden(!isVisible);
}

void PageSix::on_answerButton_clicked()
{
    if(hasCollide){
        return;
     }

    hasCollide = true;
    HapticController::getInstance()->startEffect("click");
    Utils::delay(0.5);
    nextPage();
}

void PageSix::on_answerButton_pressed()
{
     ui->answerButton->setCursor(Qt::ClosedHandCursor);
}

void PageSix::on_answerButton_released()
{
    ui->answerButton->setCursor(Qt::PointingHandCursor);
}

void PageSix::on_lemur_enterEvent()
{
    if (!isCurrentPage()){ // avec mouse tracking, l'événement est capter même lorsque la page n'est pas affiché à l'écran
        return;
    }

    qDebug() << "LOG[Lemur] enter event";
    HapticController::getInstance()->startEffect("fur");
    SoundController::getInstance()->playSound("lemur_cry", true);
    setCursor(QCursor(QPixmap(":images/ips_hand.png"), 48, 45));
}

void PageSix::on_lemur_leaveEvent()
{
    qDebug() << "LOG[Lemur] leave event";
    HapticController::getInstance()->stopEffect("fur");
    unsetCursor();
}

void PageSix::on_lemur_mouseMove()
{
    if (!isCurrentPage()){ // avec mouse tracking, l'événement est capter même lorsque la page n'est pas affiché à l'écran
       return;
    }

    if(isFirstMove){ // évite un temps de chargement lorsque la souris est à l'emplacement du lémurien lors du changement de page
        isFirstMove = false;
        return;
    }

    if (hasTouchedFur) {
        return;
    }

    qDebug() << "Show notification soon";
    hasTouchedFur = true;
    Utils::delay(4);
    showNotification(true);
}
