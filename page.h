#ifndef PAGE_H
#define PAGE_H

#include <QMap>
#include <QString>
#include <QStackedWidget>
#include <QWidget>
#include <QDebug>

/**
* Classe représentant une page du livre
*/
class Page : public QWidget
{
public:
    /**
    * Classe représentant une page du livre
    *
    * @param parent le widget parent
    * @param pageIndex l'index de la page dans le livre
    */
    Page(QStackedWidget *parent, int pageIndex);
    ~Page();
    virtual void showEvent(QShowEvent *event) override;
private:
    QStackedWidget* book;
    int pageIndex;
 protected:
    bool hasCollide;
    /**
    * Vérifie si la page est actuellement affiché dans le livre
    *
    * @return vrai si la page est actuellement affichée sur l'écran
    */
    bool isCurrentPage();

    /**
    * Changement de la page du livre
    *
    * @param stopSoundAndEffect si vrai, arrête tous les sons et effets en cours avant le changement de page
    */
    void nextPage(bool stopSoundAndEffect = true);

    /**
    * Changement de la page du livre
    *
    * @param stopSoundAndEffect si vrai, arrête tous les sons et effets en cours avant le changement de page
    */
    void stopSoundsAndEffects();
};

#endif // PAGE_H
