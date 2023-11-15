#ifndef PAGETWO_H
#define PAGETWO_H

#include"page.h"

namespace Ui {
    class PageTwo;
}

class PageTwo : public Page {
Q_OBJECT

public:
    explicit PageTwo(QStackedWidget *parent = 0);

    ~PageTwo();

private:
    Ui::PageTwo *ui;
    QPoint ipPosition;

private slots:
    void on_ip_labelMove();
    void on_ip_mouseRelease();
    void onCollision();

};

#endif // PAGETWO_H
