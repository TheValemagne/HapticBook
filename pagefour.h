#ifndef PAGEFOUR_H
#define PAGEFOUR_H

#include "page.h"

namespace Ui {
    class PageFour;
}

/**
 * Classe représentant la page 4
 */
class PageFour : public Page
{
    Q_OBJECT

public:
    explicit PageFour(QStackedWidget *parent = 0);
    ~PageFour();
    virtual void showEvent(QShowEvent *event) override;
    /**
    * Fonction de mise à jour de l'animation
    */
    void updateAnimation();

    /**
    * Mettre à jour le numéro de l'image pour la prochaine itération
    */
    void updateImageIndex();

private slots:
    void on_wale_labelMove();
    void on_wale_mouseRelease();
    void on_wale_mousePress();
    void onAnimationFinished();
    void on_ip_labelMove();
    void on_ip_mouseRelease();

private:
    Ui::PageFour *ui;
    void onCollision();
    QTimer *animationTimer;
    int currentImageNumber;
    bool isForward;
};

#endif // PAGEFOUR_H
