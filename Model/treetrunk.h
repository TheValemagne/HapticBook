#ifndef TREETRUNK_H
#define TREETRUNK_H

#include "movableelement.h"

class TreeTrunk : public MovableElement
{
public:
    TreeTrunk(const QString& src, const QPoint &position, Page *parent = nullptr);
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
protected:
    bool isEffectActive;
};

#endif // TREETRUNK_H
