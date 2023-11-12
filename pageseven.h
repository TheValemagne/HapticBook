#ifndef PAGESEVEN_H
#define PAGESEVEN_H

#include "page.h"

namespace Ui {
class PageSeven;
}

class PageSeven : public Page
{
    Q_OBJECT

public:
    explicit PageSeven(QStackedWidget *parent = 0);
    ~PageSeven();

private:
    Ui::PageSeven *ui;
};

#endif // PAGESEVEN_H
