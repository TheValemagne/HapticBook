#ifndef MOVABLEELEMENT_H
#define MOVABLEELEMENT_H

#include <QPoint>
#include <QMouseEvent>
#include "element.h"

class MovableElement : public Element
{
public:
    MovableElement(const QString& src, const QPoint &position, Page *parent = nullptr);
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
protected:
    bool isMovable;
private:
    QPoint mousePos;
};

#endif // MOVABLEELEMENT_H
