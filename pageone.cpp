#include<QString>
#include<QDebug>

#include "pageone.h"
#include "ui_pageone.h"
#include "Model/rocket.h"
#include "Controller/HapticController.h"
#include"utils.h"

PageOne::PageOne(QStackedWidget *parent) :
    Page(parent),
    ui(new Ui::PageOne)
{
    ui->setupUi(this);
    // Remplacez par le chemin de votre image
    QString qs = QString(":/images/space_ship.png");
    Element *rocket = new Rocket(qs, QPoint(50, 50), this); // Remplacez "parentWidget" par le parent approprié
    addElement("rocket", rocket);

    // Ajoutez l'objet Element à votre interface utilisateur, par exemple, à un layout ou à un widget
    this->show();
}

PageOne::~PageOne()
{
    delete ui;
}

void PageOne::onMouseMove()
{
    qDebug() << "LOG[PageOne] : onMouseMove()";
    Element* rocket = getElement("rocket");

    if (Utils::collision(rocket,  ui->earth) && !hasCollide){
        qDebug() << "LOG[PageOne] : rocket over earth";
        hasCollide = true;
        rocket->setHidden(true);
        HapticController::getInstance()->stopAllEffects();
        HapticController::getInstance()->startEffect("landing");
        // TODO effet crash + son
        Utils::delay(0.6); // attend 1 sec avant de passer à la suite
        nextPage();
    }
}


