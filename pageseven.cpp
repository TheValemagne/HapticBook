#include "pageseven.h"
#include "ui_pageseven.h"
#include "utils.h"
#include "Controller/hapticcontroller.h"

PageSeven::PageSeven(QStackedWidget *parent) :
    Page(parent, 7),
    ui(new Ui::PageSeven)
{
    ui->setupUi(this);
}

PageSeven::~PageSeven()
{
    delete ui;
}

void PageSeven::showEvent(QShowEvent *event) {
    Page::showEvent(event);
}

void PageSeven::on_ip_labelMove() {
    if (Utils::collision(ui->ip,  ui->exit) && !hasCollide){
        hasCollide = true;
        onCollision();
    }

    if (Utils::collision(ui->ip,  ui->tractorBeam)) {
        onTractorBeamCollision();
    } else {
        HapticController::getInstance()->stopEffect("tractor_beam");
    }
}

void PageSeven::onCollision() {
    nextPage();
}

void PageSeven::onTractorBeamCollision() {
    HapticController::getInstance()->startEffect("tractor_beam");
}
