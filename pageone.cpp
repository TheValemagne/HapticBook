#include <QString>
#include <QDebug>

#include "pageone.h"
#include "ui_pageone.h"
#include "Controller/hapticcontroller.h"
#include "Controller/soundcontroller.h"
#include "utils.h"

PageOne::PageOne(QStackedWidget *parent) :
    Page(parent, 1),
    ui(new Ui::PageOne)
{
    ui->setupUi(this);
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

    if (Utils::collision(ui->rocket,  ui->earth) && !hasCollide){
        hasCollide = true;
        ui->rocket->setHidden(true);
        onCollision();
        nextPage();
    }
}



void PageOne::on_rocket_labelMove()
{
    onMouseMove();

    if (ui->rocket->isMovable) {
        SoundController::getInstance()->playSound("alarm", true);
    }

    if (ui->rocket->isMovable){
        HapticController::getInstance()->startEffect("shaking");
    }
}

void PageOne::on_rocket_mouseRelease()
{
    HapticController::getInstance()->stopEffect("shaking");
}
