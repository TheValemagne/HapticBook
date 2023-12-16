#ifndef PAGETHREE_H
#define PAGETHREE_H

#include "page.h"

namespace Ui {
class PageThree;
}

/**
 * Classe représentant la page 3
 */
class PageThree : public Page
{
    Q_OBJECT

public:
    explicit PageThree(QStackedWidget *parent = 0);
    ~PageThree();

private slots:
    void on_wale_labelMove();
    void on_wale_mouseRelease();
    void on_wale_mousePress();

private:
    Ui::PageThree *ui;
    void onCollision();
};

#endif // PAGETHREE_H
