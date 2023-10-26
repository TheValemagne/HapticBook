#ifndef PAGEONE_H
#define PAGEONE_H

#include <QWidget>
#include <QPixmap>
#include <QMouseEvent>
#include"page.h"

namespace Ui {
class PageOne;
}

class PageOne : public QWidget, public Page
{
    Q_OBJECT

public:
    explicit PageOne(QWidget *parent = 0);
    ~PageOne();
     void mouseMoveEvent(QMouseEvent *event) override;

private:
    Ui::PageOne *ui;
};

#endif // PAGEONE_H
