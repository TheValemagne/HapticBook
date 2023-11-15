#ifndef PAGETHREE_H
#define PAGETHREE_H

#include "page.h"

namespace Ui {
class PageThree;
}

class PageThree : public Page
{
    Q_OBJECT

public:
    explicit PageThree(QStackedWidget *parent = 0);
    ~PageThree();
    void onMouseMove() override;

private slots:
    void on_wale_labelMove();
    void on_wale_mouseRelease();

private:
    Ui::PageThree *ui;
    void onCollision();
};

#endif // PAGETHREE_H
