#ifndef TREETRUNK_H
#define TREETRUNK_H

#include "movableelement.h"

class TreeTrunk : public MovableElement
{
public:
    TreeTrunk(const QString& src, const QPoint &position, Page *parent = nullptr);
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif // TREETRUNK_H
