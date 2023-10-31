#include "element.h"
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>
#include <QPixmap>
#include <QDebug>
#include <QString>

Element::Element(const QString& src,
                               const QPoint &position,
                               Page *parent):
    QLabel(parent)
{
    // initiatilisation des attributs
    page = parent;
    image = QPixmap(src);
    if(image.isNull())
        qDebug()<<"LOG[Element] : image is null " << src;

    // initiatilisation du QLabel
    setParent(parent);
    setPixmap(image);
    move(position);
}
