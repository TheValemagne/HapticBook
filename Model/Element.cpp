#include "element.h"
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>
#include <QPixmap>
#include <QDebug>
Element::Element(const QPixmap &image, QWidget *parent):
    QLabel("Writing test")
{
    if(image.isNull())
       qDebug()<<"isNull image ";
    setPixmap(image);
    move(50, 50);
    setParent(parent);
}
