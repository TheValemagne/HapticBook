#ifndef MOVABLEELEMENT_H
#define MOVABLEELEMENT_H

#include <QPoint>
#include "Element.h"

class MovableElement : public Element
{
public:
    MovableElement(const QPixmap &image, QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    bool isMovable;
    QPoint position;
};

#endif // MOVABLEELEMENT_H
