#ifndef UTILS_H
#define UTILS_H

#include <QLabel>

class Utils
{
public:
    Utils();
    /**
    * Vérifie si deux widgets sont entrés en collision
    *
    * @param elem1 premier élément
    * @param elem2 deuxième élément
    * @return vrai si les deux éléments sont entrés en collision, sinon faux
    */
    static bool collision(QLabel* elem1, QLabel* elem2);

    /**
    * Lancement d'un délais d'attente avant de passe à la suite, sans bloquer l'interface
    */
    static void delay(double secondsToWait);
};

#endif // UTILS_H
