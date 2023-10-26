#ifndef MOVABLEELEMENT_H
#define MOVABLEELEMENT_H

#include <QPoint>
#include <QMouseEvent>
#include "Element.h"

class MovableElement : public Element
{
public:
    MovableElement(const QString& src, const QPoint &position, QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    bool isMovable;
    QPoint mousePos;
};

#endif // MOVABLEELEMENT_H
