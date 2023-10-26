#include "element.h"
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>
#include <QPixmap>
#include <QDebug>
#include <QString>

Element::Element(const QString& src, const QPoint &position, QWidget *parent):
    QLabel(parent)
{
    // initiatilisation des attributs
    image = QPixmap(src);
    if(image.isNull())
        qDebug()<<"LOG[Element] : image is null";

    this->position = position;

    // initiatilisation du QLabel
    setParent(parent);
    setPixmap(image);
    move(this->position);
}
