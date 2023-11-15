#ifndef PAGEFOUR_H
#define PAGEFOUR_H

#include "page.h"

namespace Ui {
class PageFour;
}

class PageFour : public Page
{
    Q_OBJECT

public:
    explicit PageFour(QStackedWidget *parent = 0);
    ~PageFour();

private slots:
    void on_wale_labelMove();
    void on_wale_mouseRelease();

private:
    Ui::PageFour *ui;
    void onCollision();
};

#endif // PAGEFOUR_H
