//
// Created by remiz on 21/10/2023.
//

#ifndef SOUNDCONTROLLER_H
#define SOUNDCONTROLLER_H

#include <QString>
#include <QMediaPlayer>
#include <QMap>

/**
 * Cette classe est utilisée pour contrôler le son du jeu.
 * Elle est utilisée pour jouer tous les sons du jeu.
 * Elle doit être capable de jouer un son (en boucle ou non), de reprendre le lecteur s'il est déjà en train de jouer, d'arrêter le lecteur, de mettre le lecteur en pause.
 */
class SoundController
{
public:
    ~SoundController();
    /**
    * Retourne l'instance du controlleur ou la créer
    * @return le controlleur audio
    */
    static SoundController* getInstance();
    SoundController(SoundController &other) = delete;
    void operator=(const SoundController &) = delete;
    /**
    * Ajout et initialisation d'un son
    *
    * @param keyName nom de la clé où stocker le son
    * @param effectName chemin vers le fichier de son
    */
    void addSound(const QString& soundName, const QString& soundFilePath);
    
    /**
    * Joue le son voulu
    *
    * @param effectName clé du son à lancer
    * @param loop si vrai jouer le son en boucle, sinon qu'une seule fois
    */
    void playSound(const QString& soundName, bool loop = false);

    /**
    * Relancer le son voulu depuis le début
    *
    * @param effectName clé du son à relancer
    */
    void restartSound(const QString& soundName);

    /**
    * Arrêter le son voulu
    *
    * @param effectName clé du son à arrêter
    */
    void stopSound(const QString& soundName);

    /**
    * Arrêter tous les sons entregistrés
    */
    void stopAllSounds();

    /**
    * Vérifie si un son est en cours de lecture
    *
    * @param effectName clé du son à controller
    * @return vrai si le son est en cours de lecture
    */
    bool isSoundPlaying(const QString& soundName);
protected:
    SoundController();
    static SoundController* instance;
private:
    QMap<QString, QMediaPlayer*> sounds;

    /**
    * Retourne le chemin d'un fichier de son
    * @param name nom du son sans l'extension
    * @return le chemin complet du fichier son
    */
    QString getSoundPath(QString name);
};


#endif //SOUNDCONTROLLER_H
