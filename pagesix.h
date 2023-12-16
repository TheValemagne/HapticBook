#ifndef PAGESIX_H
#define PAGESIX_H

#include<QTimer>
#include "page.h"

namespace Ui {
class PageSix;
}

/**
 * Classe représentant la page 6
 */
class PageSix : public Page
{
    Q_OBJECT

public:
    explicit PageSix(QStackedWidget *parent = 0);
    ~PageSix();
    virtual void showEvent(QShowEvent *event) override;

private slots:
    void on_answerButton_clicked();

    void on_lemur_enterEvent();

    void on_lemur_leaveEvent();

    void on_lemur_mouseMove();

    void on_answerButton_pressed();

    void on_answerButton_released();

private:
    Ui::PageSix *ui;
    bool hasTouchedFur; // si la fourure a déjà été touché une fois
    bool isFirstMove; // si premier mouvement
    QTimer *soundTimer; // timer pour le crie du lémurien
    QTimer *notificationTimer; // timer pour l'affichage de la notification

    /**
    * Acfficher ou cacher la notification et le bouton associé
    */
    void showNotification(bool isVisible);

    /**
    * Lancement du son à la fin du délais
    */
    void onSoundTimeOut();

    /**
    * Affichage de la notification à la fin du délais
    */
    void onNotificationTimeOut();
};

#endif // PAGESIX_H
