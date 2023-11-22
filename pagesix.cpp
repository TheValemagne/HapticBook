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
    ui->answerButton->setCursor(QCursor(Qt::PointingHandCursor));
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

void PageSix::on_lemur_enterEvent()
{
    if (!isCurrentPage()){ // avec mouse tracking, l'événement est capter même lorsque la page n'est pas affiché à l'écran
        return;
    }

    qDebug() << "LOG[Lemur] enter event";
    HapticController::getInstance()->startEffect("fur");
    setCursor(QCursor(QPixmap(":images/ips_hand.png"), 64, 65));
}

void PageSix::on_lemur_leaveEvent()
{
    qDebug() << "LOG[Lemur] leave event";
    HapticController::getInstance()->stopEffect("fur");
    setCursor(QCursor(Qt::ArrowCursor));
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
