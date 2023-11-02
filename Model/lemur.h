#ifndef LEMUR_H
#define LEMUR_H

#include "Element.h"
#include <QEvent>

class Lemur : public Element
{
public:
    Lemur(const QString& src, const QPoint &position, Page *parent = nullptr);
    void mouseMoveEvent(QMouseEvent *event) override;
protected:
    virtual void enterEvent(QEvent *event) override;
    virtual void leaveEvent(QEvent  *event) override;
};

#endif // LEMUR_H
