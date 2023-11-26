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
    virtual void showEvent(QShowEvent *event) override;


private:
    Ui::PageSeven *ui;
    void onCollision();
    void onTractorBeamCollision();

private slots:
    void on_ip_labelMove();

};

#endif // PAGESEVEN_H
