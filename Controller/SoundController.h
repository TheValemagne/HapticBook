//
// Created by remiz on 21/10/2023.
//

#ifndef SOUNDCONTROLLER_H
#define SOUNDCONTROLLER_H

#include <QString>
#include <QMediaPlayer>
#include <QMap>

/*
 * This class is used to control the sound of the game.
 * It is used to play all the sounds of the game.
 * It need to be able to play a sound (in a loop or not), resume the player if it is already playing, stop the player, pause the player.
 */
class SoundController
{
public:
    ~SoundController();
    static SoundController* getInstance();
    SoundController(SoundController &other) = delete;
    void operator=(const SoundController &) = delete;
    void addSound(const QString& soundName, const QString& soundFilePath);
    void playSound(const QString& soundName, bool loop = false);
    void stopSound(const QString& soundName);
    void stopAllSounds();
protected:
    SoundController();
    static SoundController* instance;
private:
    QMap<QString, QMediaPlayer*> sounds;
};


#endif //SOUNDCONTROLLER_H
