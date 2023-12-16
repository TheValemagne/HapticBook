#ifndef PAGESEVEN_H
#define PAGESEVEN_H

#include "page.h"

namespace Ui {
class PageSeven;
}

/**
 * Classe représentant la page 7
 */
class PageSeven : public Page
{
    Q_OBJECT

public:
    explicit PageSeven(QStackedWidget *parent = 0);
    ~PageSeven();
    virtual void showEvent(QShowEvent *event) override;


private:
    bool tractorBeamCollision = false;

    Ui::PageSeven *ui;
    void onCollision();
    void onTractorBeamCollision();
    void onTractorBeamDeactivation();
    void onTractorBeamDeactivationFinished();

private slots:
    void on_ip_labelMove();
    void on_ip_mouseRelease();

    void startAnimationUFOLeft();

    void onAnimationUFOLeftFinished();

    void onTractorBeamCollisionReverse();
};

#endif // PAGESEVEN_H
