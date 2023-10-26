#include "pageone.h"
#include "ui_pageone.h"
#include"Model/MovableElement.h"
#include<QUrl>
#include<QString>
#include<QDebug>

PageOne::PageOne(QStackedWidget *parent) :
    Page(parent),
    ui(new Ui::PageOne)
{
    ui->setupUi(this);
    //image = QPixmap(); // Remplacez par le chemin de votre image
    QString qs = QString(":/images/space_ship.png");
    Element *rocket = new MovableElement(qs, QPoint(50, 50), this); // Remplacez "parentWidget" par le parent approprié
    addElement("rocket", rocket);

    // Ajoutez l'objet Element à votre interface utilisateur, par exemple, à un layout ou à un widget
    this->show();
}

PageOne::~PageOne()
{
    delete ui;
}

void PageOne::onMouseMove() {
    qDebug() << "LOG[PageOne] : onMouseMove()";
    QLabel* earth = ui->earth;
    Element* rocket = getElement("rocket");
    QPoint* rocketHead = new QPoint(rocket->x() + rocket->width(),
                                                                 rocket->y() + rocket->height());

    if (rocketHead->x() >= earth->x() && rocketHead->y() >= earth->y()){
        qDebug() << "LOG[PageOne] : rocket in earth";
    }
}


