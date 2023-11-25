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
    bool hasRockCollide;
    bool hasRockInvisibleCollide;
    bool hasMarkerCollide;
    QPoint defaultRockPosition;
    virtual void showEvent(QShowEvent *event) override;


private:
    Ui::PageTwo *ui;
    QPoint ipPosition;

private slots:
    void on_ip_labelMove();
    void on_ip_mouseRelease();
    void onCollision();
    void onRockInvisibleCollision();
    void onMarkerCollision();
    void onRockAnimationFinished();
};

#endif // PAGETWO_H
