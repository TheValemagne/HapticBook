#include "pagefour.h"
#include "ui_pagefour.h"
#include<QString>
#include<QDebug>
#include<QPropertyAnimation>
#include<QTimer>
#include <math.h>
#include"utils.h"
#include "Controller/hapticcontroller.h"
#include "Controller/soundcontroller.h"

PageFour::PageFour(QStackedWidget *parent) :
    Page(parent, 4),
    ui(new Ui::PageFour),
    currentImageNumber(1),
    isForward(true)
{
    ui->setupUi(this);
    ui->ip->setHidden(true);
    ui->walk->setHidden(true);
    Utils::delay(0.2); // attend 20 ms
}

PageFour::~PageFour()
{
    delete ui;
   // if(animationTimer != nullptr) delete animationTimer;
}

void PageFour::updateAnimation()
{
    qDebug() << "LOG[PageFour] : update animation";
    // Construire le chemin de l'image en fonction du numéro actuel
    QString imagePath = QString(":/images/wale_heart%1.png").arg(currentImageNumber);

    // Charger l'image dans le QLabel
    ui->wale->setPixmap(QPixmap(imagePath));

    // Mettre à jour le numéro de l'image pour la prochaine itération
    updateImageIndex();

    // Inverser la direction lorsque nous atteignons la dernière image ou la première image
    if (currentImageNumber == 1 || currentImageNumber == 5)
        isForward = !isForward;
}

void PageFour::updateImageIndex() {
    if (isForward)
        currentImageNumber++;
    else
        currentImageNumber--;

    // Assurez-vous que le numéro de l'image reste dans la plage valide (1 à 5)
    if (currentImageNumber > 5)
        currentImageNumber = 4;
    else if (currentImageNumber < 1)
        currentImageNumber = 2;
}


void PageFour::showEvent(QShowEvent *event) {
    Q_UNUSED(event);
    qDebug() << "LOG[PageFour] : show page";

    // Initialiser le QTimer
    animationTimer = new QTimer(this);

    // Connecter le signal timeout du QTimer à la fonction de mise à jour de l'image
    connect(animationTimer, &QTimer::timeout, this, &PageFour::updateAnimation);

    //jouer son d'ambiance
    SoundController::getInstance()->playSound("underwater", true);
}

void PageFour::onCollision()
{
    qDebug() << "LOG[PageFour] : wale over beach";
    // Arrêter le QTimer and stop move
    animationTimer->stop();

    ui->arrow->setHidden(true);
    ui->wale->setLocked(true);

    // position ip under wale
    ui->ip->setHidden(false);
    ui->ip->setGeometry(ui->wale->pos().x() + (ui->wale->width()*0.7) - ui->ip->width()/2, ui->wale->pos().y() + (ui->wale->height()*0.62) - ui->ip->height()/2, ui->ip->width(), ui->ip->height());

    //jouer son sneezed
    SoundController::getInstance()->playSound("sneezed", false);
    Utils::delay(0.5);

    // Initialise l'image à une baleine sans coeur
    QString imagePath = QString(":/images/wale_small1.png");
    QPixmap image = QPixmap(imagePath);
    ui->wale->setPixmap(image);
    ui->wale->setFixedSize(image.size());

    // stop sound heart
    SoundController::getInstance()->stopSound("heart");
    // stop haptic heart
    HapticController::getInstance()->stopEffect("heart");
    Utils::delay(0.02);

    for (int i = 2; i < 8; ++i) {
        QString path = QString(":/images/wale_small%1.png").arg(QString::number(i));
        QPixmap image = QPixmap(path);
        ui->wale->setPixmap(image);
        ui->wale->setFixedSize(image.size());
        //if(i == 4) ui->ip->setHidden(true);
        Utils::delay(0.01);
    }

    float expulsion = 175;
    qDebug() << "LOG[PageFour] : expulsion = " << expulsion << "; x = " << ui->wale->pos().x();
    int durationAnimation = 1000;

    // Créer une animation qui expluse ip du ventre de la baleine
    QPropertyAnimation *animation = new QPropertyAnimation(ui->ip, "geometry");
    animation->setDuration(durationAnimation);
    animation->setStartValue(ui->ip->geometry());
    animation->setEndValue(QRect(ui->ip->pos().x() + expulsion, ui->ip->pos().y(), ui->ip->width(), ui->ip->height()));
    animation->setEasingCurve(QEasingCurve::OutCirc);

    // Connecter la fonction à l'événement finished de l'animation
    connect(animation, &QPropertyAnimation::finished, this, &PageFour::onAnimationFinished);

    animation->start();
}

void PageFour::onAnimationFinished()
{
    qDebug() << "LOG[PageFour] : animation finished";

    // stop sound underwater
    SoundController::getInstance()->stopSound("underwater");
    // hide wale
    ui->wale->setHidden(true);

    // set walk help position
    ui->walk->setHidden(false);
    ui->walk->setGeometry(ui->ip->pos().x() + (ui->ip->width() * 0.8), ui->ip->pos().y() + (ui->ip->height() * 0.9) - (ui->walk->height()/4), ui->walk->width(), ui->walk->height());

    SoundController::getInstance()->playSound("sea", true);
    Utils::delay(1);
    for (int i = 2; i < 8; ++i) {
        QString path = QString(":/images/small_ip_landscape%1.png").arg(QString::number(i));
        QPixmap image = QPixmap(path);

        ui->ip->setPixmap(image);
        ui->ip->setFixedSize(image.size());

        Utils::delay(0.02);
    }
}

// on ip move
void PageFour::on_ip_labelMove()
{
    // play haptic walk_sand
    HapticController::getInstance()->startEffect("walk_sand");
    // play sound walk_sand
    SoundController::getInstance()->playSound("walk_sand", true);

    if (Utils::collision(ui->end,  ui->ip) && !hasCollide){
        hasCollide = true;
        qDebug() << "LOG[PageFour] : ip collision with end";
        // stop all sounds and effects
        stopSoundsAndEffects();
        nextPage(true);
        ui->wale->hide();
        ui->ip->hide();
    }
}

// mouse release and stop sound walk_sand
void PageFour::on_ip_mouseRelease()
{
    qDebug() << "LOG[PageFour] : ip mouse release";
    // stop sound walk_sand
    SoundController::getInstance()->stopSound("walk_sand");
    // stop haptic walk_sand
    HapticController::getInstance()->stopEffect("walk_sand");
}

void PageFour::on_wale_labelMove()
{
    int xWale = ui->wale->pos().x() + ui->wale->width();
    int yWale = -ui->wale->pos().y() - ui->wale->height();

    double distance = (-0.85*xWale + yWale + 1000) / sqrt(-0.85*-0.85 + 1);


    qDebug() << "LOG[PageFour] : distance" << distance;
    if(distance < 10 && !hasCollide){
        onCollision();
    }
}

void PageFour::on_wale_mousePress()
{
    qDebug() << "LOG[PageFour] : mouse press";
    // Définir l'intervalle de temps entre chaque mise à jour (par exemple, 200 millisecondes)
    animationTimer->start(140);

    // jouer son heart
    SoundController::getInstance()->playSound("heart", true);
    Utils::delay(0.01);
    // play haptic heart
    HapticController::getInstance()->startEffect("heart");
}

void PageFour::on_wale_mouseRelease()
{
    // Arrêter le QTimer and stop move
    animationTimer->stop();

    // stop sound heart
    SoundController::getInstance()->stopSound("heart");
    // stop haptic heart
    HapticController::getInstance()->stopEffect("heart");
}
