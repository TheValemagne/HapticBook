#ifndef ROCKET_H
#define ROCKET_H

#include "movableelement.h"

class Rocket : public MovableElement
{
public:
    Rocket(const QString& src, const QPoint &position, Page *parent = nullptr);
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
protected:
    bool isEffectActive;
};

#endif // ROCKET_H
