//
// Created by remiz on 21/10/2023.
//

#include "soundcontroller.h"
#include <QMediaPlayer>

SoundController::SoundController() {
    sounds = QMap<QString, QMediaPlayer*>();

    this->addSound("alarm", "qrc:/sounds/alarm.mp3");
    this->addSound("explosion", "qrc:/sounds/explosion.mp3");
}

SoundController::~SoundController()
{
    qDeleteAll(sounds);
    sounds.clear();
    if (instance) {
       instance = nullptr;
    };
}

SoundController* SoundController::instance = nullptr;

SoundController* SoundController::getInstance()
{
    if(!instance){
        instance = new SoundController();
    }

    return instance;
}

void SoundController::addSound(const QString& soundName, const QString& soundFilePath)
{
    QMediaPlayer* mediaPlayer = new QMediaPlayer;
    mediaPlayer->setMedia(QUrl(soundFilePath));
    sounds[soundName] = mediaPlayer;
}

void SoundController::playSound(const QString& soundName, bool loop)
{
    if (sounds.contains(soundName) && !this->isSoundPlaying(soundName))
    {
        QMediaPlayer* mediaPlayer = sounds[soundName];

        if (loop) {
            mediaPlayer->connect(mediaPlayer, &QMediaPlayer::stateChanged, [=](QMediaPlayer::State state) {
                if (state == QMediaPlayer::StoppedState) {
                    mediaPlayer->play();
                }
            });
        }

        mediaPlayer->play();
    }
}

void SoundController::restartSound(const QString& soundName)
{
    if (sounds.contains(soundName))
    {
        if (this->isSoundPlaying(soundName))
            sounds[soundName]->setPosition(0);
        else
            this->playSound(soundName);
    }
}

void SoundController::stopSound(const QString& soundName)
{
    if (sounds.contains(soundName))
    {
        QMediaPlayer* mediaPlayer = sounds[soundName];
        mediaPlayer->disconnect(mediaPlayer, &QMediaPlayer::stateChanged, 0, 0);
        mediaPlayer->stop();
    }
}

void SoundController::stopAllSounds()
{
    for (const QString& key : sounds.keys()) {
        stopSound(key);
    }
}

bool SoundController::isSoundPlaying(const QString& soundName)
{
    if (sounds.contains(soundName))
    {
        QMediaPlayer* mediaPlayer = sounds[soundName];
        return mediaPlayer->state() == QMediaPlayer::PlayingState;
    }
    return false;
}
