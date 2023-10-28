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

private:
    Ui::PageThree *ui;
};

#endif // PAGETHREE_H
