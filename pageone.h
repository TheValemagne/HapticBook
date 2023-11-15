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
    virtual void showEvent(QShowEvent *event) override;
    virtual void hideEvent(QHideEvent *event) override;

private slots:
    void on_rocket_labelMove();

    void on_rocket_mouseRelease();

private:
    Ui::PageOne *ui;
    void onCollision();
    QPoint rocketPosition;
};

#endif // PAGEONE_H
