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
    Element *element = new MovableElement(qs, QPoint(50, 50), this); // Remplacez "parentWidget" par le parent approprié
    addElement("rocket", element);
    // Ajoutez l'objet Element à votre interface utilisateur, par exemple, à un layout ou à un widget
    this->show();
}

PageOne::~PageOne()
{
    delete ui;
}

void PageOne::onMouseMove() {
    qDebug() << "LOG[PageOne] : onMouseMove()";
}


