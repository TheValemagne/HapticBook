#include <QString>
#include <QDebug>

#include "pageone.h"
#include "ui_pageone.h"
#include "Model/rocket.h"
#include "Controller/hapticcontroller.h"
#include "Controller/soundcontroller.h"
#include "utils.h"

PageOne::PageOne(QStackedWidget *parent) :
    Page(parent, 1),
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

void PageOne::onCollision()
{
    qDebug() << "LOG[PageOne] : rocket over earth";

    stopSoundsAndEffects();
    SoundController::getInstance()->playSound("explosion");
    Utils::delay(0.2); // attend 20 ms

    HapticController::getInstance()->startEffect("landing");
    Utils::delay(2); // attend 2 sec avant de passer à la suite
}

void PageOne::onMouseMove()
{
    qDebug() << "LOG[PageOne] : onMouseMove()";
    Element* rocket = getElement("rocket");

    if (Utils::collision(rocket,  ui->earth) && !hasCollide){
        hasCollide = true;
        rocket->setHidden(true);
        onCollision();
        nextPage();
    }
}


