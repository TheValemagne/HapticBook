#include "pagefour.h"
#include "ui_pagefour.h"
#include<QString>
#include<QDebug>
#include<QTimer>
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
    Utils::delay(0.2); // attend 20 ms
}

PageFour::~PageFour()
{
    delete ui;
}

// Fonction de mise à jour de l'animation
void PageFour::updateAnimation()
{
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
        qDebug() << "LOG[PageFour] : show page";
         // Initialiser le QTimer
        animationTimer = new QTimer(this);

        // Connecter le signal timeout du QTimer à la fonction de mise à jour de l'image
        connect(animationTimer, &QTimer::timeout, this, &PageFour::updateAnimation);

        // Définir l'intervalle de temps entre chaque mise à jour (par exemple, 200 millisecondes)
        animationTimer->start(125);
}

void PageFour::onCollision()
{
    qDebug() << "LOG[PageFour] : wale over IP";


    Utils::delay(1.2); // attend 2 sec avant de passer à la suite
}

void PageFour::on_wale_labelMove()
{
/*    if (Utils::collision(ui->wale,  ui->ip) && !hasCollide){
        hasCollide = true;
        onCollision();
        nextPage(true);
        ui->wale->setHidden(true);
    }*/
}

void PageFour::on_wale_mousePress()
{
    qDebug() << "LOG[PageFour] : mouse press";
}

void PageFour::on_wale_mouseRelease()
{

}
