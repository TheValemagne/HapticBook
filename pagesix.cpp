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
    hasTouchedFur = false; // stocke si la fourure a déjà été touchée
    isFirstMove = true; // stocke si c'est le premier mouvement sur la fourure
    showNotification(false); // cacher la notification
    SoundController::getInstance()->playSound("rainforest", true);
}

void PageSix::showNotification(bool isVisible)
{
    ui->notification->setHidden(!isVisible);
    ui->answerButton->setHidden(!isVisible);
}

void PageSix::on_answerButton_clicked()
{
    if(hasCollide){ // si le bouton a déjà été appuyé
        return;
     }

    hasCollide = true;
    HapticController::getInstance()->startEffect("click");
    soundTimer->deleteLater();
    notificationTimer->deleteLater();
    Utils::delay(0.5); // attend 0.5 sec
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
    // afficher la main de l'extraterrestre lorsque le curseur est sur les lémuriens
    setCursor(QCursor(QPixmap(":images/ips_hand.png"), 48, 45));
}

void PageSix::on_lemur_leaveEvent()
{
    qDebug() << "LOG[Lemur] leave event";
    HapticController::getInstance()->stopEffect("fur");
    unsetCursor();
}

void PageSix::onSoundTimeOut()
{
    soundTimer->stop();

    SoundController::getInstance()->playSound("lemur_cry");
}

void PageSix::onNotificationTimeOut()
{
    notificationTimer->stop();

    qDebug() << "Show notification soon";
    showNotification(true);
    SoundController::getInstance()->playSound("notification");
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

    if (hasTouchedFur) { // les timers ont déjà été lancé
        return;
    }

    hasTouchedFur = true;

    // Initialiser le timer pour le son
   soundTimer = new QTimer(this);
   connect(soundTimer, &QTimer::timeout, this, &PageSix::onSoundTimeOut);

    // Initialiser le timer pour la notification
    notificationTimer = new QTimer(this);
    connect(notificationTimer, &QTimer::timeout, this, &PageSix::onNotificationTimeOut);

    // Lancement des intervalles
    soundTimer->start(2000);
    notificationTimer->start(9000);
}
