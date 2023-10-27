#ifndef PAGETWO_H
#define PAGETWO_H

#include <QStackedWidget>
#include <QPixmap>
#include <QMouseEvent>
#include"page.h"

namespace Ui {
class PageTwo;
}

class PageTwo : public Page
{
    Q_OBJECT

public:
    explicit PageTwo(QStackedWidget *parent = 0);
    ~PageTwo();
    void onMouseMove() override;

private:
    Ui::PageTwo *ui;
};

#endif // PAGETWO_H
