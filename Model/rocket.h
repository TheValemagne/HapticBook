#ifndef ROCKET_H
#define ROCKET_H

#include "movableelement.h"

class Rocket : public MovableElement
{
public:
    Rocket(const QString& src, const QPoint &position, Page *parent = nullptr);
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif // ROCKET_H
