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
    rocketPosition = ui->rocket->pos();
}

PageOne::~PageOne()
{
    delete ui;
}

void PageOne::showEvent(QShowEvent *event)
{
    Page::showEvent(event);
    ui->explosion->hide();
}

void PageOne::hideEvent(QHideEvent *event)
{
    Page::hideEvent(event);
    ui->rocket->move(rocketPosition);
    ui->rocket->show();
}

void PageOne::onCollision()
{
    qDebug() << "LOG[PageOne] : rocket over earth";

    stopSoundsAndEffects();
    SoundController::getInstance()->playSound("explosion");
    Utils::delay(0.2); // attend 20 ms
    ui->explosion->show();
    HapticController::getInstance()->startEffect("landing");
    Utils::delay(2); // attend 2 sec avant de passer à la suite
}

void PageOne::on_rocket_labelMove()
{
     SoundController::getInstance()->playSound("alarm", true);
     HapticController::getInstance()->startEffect("shaking");

     if (Utils::collision(ui->rocket,  ui->earth) && !hasCollide){
         hasCollide = true;
         ui->rocket->hide();
         onCollision();
         nextPage();
     }
}

void PageOne::on_rocket_mouseRelease()
{
    stopSoundsAndEffects();
}
