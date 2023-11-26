//
// Created by remiz on 21/10/2023.
//

#include "soundcontroller.h"
#include "../utils.h"
#include <QMediaPlayer>

SoundController::SoundController() {
    sounds = QMap<QString, QMediaPlayer*>();

    this->addSound("alarm", getSoundPath("alarm"));
    this->addSound("explosion", getSoundPath("explosion"));
    this->addSound("main_theme", getSoundPath("main_theme"));
    this->addSound("bubbles", getSoundPath("bubbles"));
    this->addSound("swim", getSoundPath("swim"));
    this->addSound("wale_cry", getSoundPath("wale_cry"));
    this->addSound("wale_ambiant", getSoundPath("wale_ambiant"));
    this->addSound("bite", getSoundPath("bite"));
    this->addSound("sliding_rock", getSoundPath("sliding_rock"));
    this->addSound("ip_force", getSoundPath("ip_effort"));
    this->addSound("rainforest", getSoundPath("rainforest"));
    this->addSound("lemur_cry", getSoundPath("lemur_cry"));
}

QString SoundController::getSoundPath(QString name)
{
    return QString("qrc:/sounds/%1.mp3").arg(name);
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

void SoundController::playSound(const QString& soundName, bool loop, double loopDelay)
{
    if (sounds.contains(soundName) && !this->isSoundPlaying(soundName))
    {
        QMediaPlayer* mediaPlayer = sounds[soundName];

        if (loop) {
            mediaPlayer->connect(mediaPlayer, &QMediaPlayer::stateChanged, [=](QMediaPlayer::State state) {
                if (state == QMediaPlayer::StoppedState) {
                    Utils::delay(loopDelay); // si non null, applique un délais avant de relancer le son
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
