#include "pageone.h"
#include "ui_pageone.h"
#include"Model/Element.h"

PageOne::PageOne(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageOne)
{
    ui->setupUi(this);
    image = QPixmap(":/resources/Images/space_ship.png"); // Remplacez par le chemin de votre image
    Element *element = new Element(image, this); // Remplacez "parentWidget" par le parent approprié

    // Ajoutez l'objet Element à votre interface utilisateur, par exemple, à un layout ou à un widget
    this->show();
}

PageOne::~PageOne()
{
    delete ui;
}
