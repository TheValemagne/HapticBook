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
    virtual void showEvent(QShowEvent *event) override;

private slots:
    void on_wale_labelMove();
    void on_wale_mouseRelease();
    void on_wale_mousePress();
    void animate_wale();

private:
    Ui::PageFour *ui;
    void onCollision();
};

#endif // PAGEFOUR_H
