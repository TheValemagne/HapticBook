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

private:
    Ui::PageFour *ui;
};

#endif // PAGEFOUR_H
