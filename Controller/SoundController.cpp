//
// Created by remiz on 21/10/2023.
//

#include "SoundController.h"

SoundController::SoundController() {
    sounds = QMap<QString, QMediaPlayer*>();

    this->addSound("intro", "qrc:/sounds/intro.wav");
    this->addSound("test", "qrc:/sounds/test.wav");
}

void SoundController::addSound(const QString& soundName, const QString& soundFilePath)
{
    QMediaPlayer* mediaPlayer = new QMediaPlayer;
    mediaPlayer->setMedia(QUrl(soundFilePath));
    sounds[soundName] = mediaPlayer;
}

void SoundController::playSound(const QString& soundName, bool loop)
{
    if (sounds.contains(soundName))
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
