#include "pageone.h"
#include "ui_pageone.h"
#include "Model/Element.h"
#include "Model/movableelement.h"
#include<QUrl>
#include<QString>
#include<QDebug>
PageOne::PageOne(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageOne)
{
    ui->setupUi(this);
    image = QPixmap(":/images/Images/space_ship.png"); // Remplacez par le chemin de votre image
    if(image.isNull())
       qDebug()<<"isNull image pageone";
    Element *element = new MovableElement(image, this); // Remplacez "parentWidget" par le parent approprié

    // Ajoutez l'objet Element à votre interface utilisateur, par exemple, à un layout ou à un widget
    this->show();
}

PageOne::~PageOne()
{
    delete ui;
}
