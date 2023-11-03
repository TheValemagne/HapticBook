#include "pagetwo.h"
#include "ui_pagetwo.h"
#include"Model/MovableElement.h"
#include<QUrl>
#include<QString>
#include<QDebug>
#include"utils.h"
PageTwo::PageTwo(QStackedWidget *parent) :
    Page(parent, 2),
    ui(new Ui::PageTwo)
{
    ui->setupUi(this);
    // Remplacez par le chemin de votre image
    QString qs = QString(":/images/ip_submarine.png");
    Element *ip_submarine = new MovableElement(qs, QPoint(467, 593), this); // Remplacez "parentWidget" par le parent approprié
    addElement("ip_submarine", ip_submarine);

    // Ajoutez l'objet Element à votre interface utilisateur, par exemple, à un layout ou à un widget
    this->show();
}

PageTwo::~PageTwo()
{
    delete ui;
}

void PageTwo::onMouseMove()
{
    qDebug() << "LOG[PageTwo] : onMouseMove()";
}


