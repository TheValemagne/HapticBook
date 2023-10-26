#include "element.h"
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>
#include <QPixmap>

Element::Element(const QPixmap &image, QWidget *parent):
    QLabel("Writing test")
{
    setPixmap(image);
    move(50, 50);
    setParent(parent);
}
