#ifndef PAGEFIVE_H
#define PAGEFIVE_H

#include "page.h"

namespace Ui {
class PageFive;
}

/**
 * Classe représentant la page 5
 */
class PageFive : public Page
{
    Q_OBJECT

public:
    explicit PageFive(QStackedWidget *parent = 0);
    ~PageFive();
    virtual void showEvent(QShowEvent *event) override;
    virtual void hideEvent(QHideEvent *event) override;
private:
    /**
    * Gestion de l'affichage ou non de la grande balsie de détresse
    *
    * @param isVisible si vrai la grande balise sera affichée, sinon cachée
    */
    void showEmergencyTransmitter(bool isVisible);

    /**
    * Initialisation des curseurs de la page et des labels "troncs d'arbres" pour afficher le guidage
    */
    void setCursors();

    /**
    * Définie le comportement d'un tronc lors du déplacement
    */
    void onTreeTrunkMove();

    /**
    * Définie le comportement d'un tronc lors du relachement de la souris
    */
    void onTreeTrunkRelease();

    QPoint treeTrunkPosition1;
    QPoint treeTrunkPosition2;

private slots:
    void on_smallEmergencyTransmitter_clicked();

    void on_sosButton_clicked();

    void on_treeTrunk1_labelMove();

    void on_treeTrunk1_mouseRelease();

    void on_treeTrunk2_labelMove();

    void on_treeTrunk2_mouseRelease();

    void on_sosButton_pressed();

    void on_sosButton_released();

private:
    Ui::PageFive *ui;
};

#endif // PAGEFIVE_H
