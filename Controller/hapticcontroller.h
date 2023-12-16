//
// Created by remiz on 21/10/2023.
//

#ifndef HAPTICCONTROLLER_H
#define HAPTICCONTROLLER_H

#undef UNICODE

#include <QMainWindow>
#include <ifc.h>
#include <QMap>

/**
 * Classe pour contrôler les effets haptiques du livre
 */
class HapticController {
public:
        ~HapticController();

        /**
        * Retourne l'instance du controlleur ou la créer avec la fenêtre principale
        *
        * @param w la fênetre principale, uniquement pour créer une instance
        * @return le controleur haptique
        */
        static HapticController* getInstance(QMainWindow *window = nullptr);
        HapticController(HapticController &other) = delete;
        void operator=(const HapticController &) = delete;

        /**
        * Lance l'effet haptique voulu
        *
        * @param effectName clé de l'effet à lancer
        */
        void startEffect(const QString& effectName);

        /**
        * Arrête l'effet haptique voulu
        *
        * @param effectName clé de l'effet à arrêter
        */
        void stopEffect(const QString& effectName);

        /**
        * Arrêter tous les effets haptiques entregistrés
        */
        void stopAllEffects();

        /**
        * Vérifie si un effet est déja lancé
        *
        * @param effectName clé de l'effet à controller
        * @return vrai si l'effet est déjà lancé
        */
        bool isEffectPlaying(const QString& effectName);

protected:
        HapticController(QMainWindow *window);
        static HapticController* instance;

private:
        CImmMouse* mMouse;      // Mouse device
        CImmProject* mProject;  // IFC Project
        QMainWindow *mWindow;   // Window
        QMap<QString, CImmCompoundEffect*> effects; // Effects
        QMap<QString, bool> effectsIsPlaying;

        /**
        * Ajout et initialisation d'un effet haptique du projet
        *
        * @param keyName nom de la clé où stocker l'effet
        * @param effectName nom de l'effet dans le fichier immersion studio
        */
        void addEffect(const QString& keyName, const CHAR *effectName);

        /**
        * Vérifie si un effet est initialisé
        *
        * @param effectName clé de l'effet à controller
        * @return vrai si l'effet est initialisé
        */
        bool isEffectInitialized(const QString& effectName);
};


#endif //HAPTICCONTROLLER_H
