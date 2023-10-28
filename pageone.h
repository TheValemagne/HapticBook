#ifndef PAGEONE_H
#define PAGEONE_H

#include"page.h"

namespace Ui {
class PageOne;
}

class PageOne : public Page
{
    Q_OBJECT

public:
    explicit PageOne(QStackedWidget *parent = 0);
    ~PageOne();
    void onMouseMove() override;

private:
    Ui::PageOne *ui;
};

#endif // PAGEONE_H
