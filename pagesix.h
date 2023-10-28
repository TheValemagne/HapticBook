#ifndef PAGESIX_H
#define PAGESIX_H

#include "page.h"

namespace Ui {
class PageSix;
}

class PageSix : public Page
{
    Q_OBJECT

public:
    explicit PageSix(QStackedWidget *parent = 0);
    ~PageSix();
    void onMouseMove() override;

private:
    Ui::PageSix *ui;
};

#endif // PAGESIX_H
