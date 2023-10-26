#include "pageone.h"
#include "ui_pageone.h"
#include"Model/Element.h"
#include<QUrl>
#include<QString>
#include<QDebug>

PageOne::PageOne(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageOne)
{
    ui->setupUi(this);
    //image = QPixmap(); // Remplacez par le chemin de votre image
    QString qs = QString(":/images/Images/space_ship.png");
    Element *element = new Element(qs, QPoint(50, 50), this); // Remplacez "parentWidget" par le parent approprié

    // Ajoutez l'objet Element à votre interface utilisateur, par exemple, à un layout ou à un widget
    this->show();
}

PageOne::~PageOne()
{
    delete ui;
}
