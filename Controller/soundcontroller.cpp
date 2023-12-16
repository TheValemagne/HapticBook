#include "soundcontroller.h"
#include "../utils.h"
#include <QMediaPlayer>

SoundController::SoundController() {
    sounds = QMap<QString, QMediaPlayer*>();

    // Initialisation des sons
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
    this->addSound("ufo", getSoundPath("ufo"));
    this->addSound("ufo_away", getSoundPath("ufo_away"));
    this->addSound("tractor_beam", getSoundPath("tractor_beam"));
    this->addSound("tractor_beam_off", getSoundPath("tractor_beam_off"));
    this->addSound("heart", getSoundPath("heart"));
    this->addSound("stomac", getSoundPath("stomac"));
    this->addSound("sea", getSoundPath("sea"));
    this->addSound("underwater", getSoundPath("underwater"));
    this->addSound("walk_sand", getSoundPath("walk_sand"));
    this->addSound("barf", getSoundPath("barf"));
    this->addSound("sneezed", getSoundPath("sneezed"));
    this->addSound("notification", getSoundPath("notification"));
}

QString SoundController::getSoundPath(QString name)
{
    return QString("qrc:/sounds/%1.mp3").arg(name);
}

SoundController::~SoundController()
{
    // suppime les pointeurs dans la liste
    qDeleteAll(sounds);
    // supprime la liste de son
    sounds.clear();

    // supprime le pointeur de l'instance
    if (instance) {
       instance = nullptr;
    };
}

SoundController* SoundController::instance = nullptr;

SoundController* SoundController::getInstance()
{
    if(!instance){ // créer l'instance si inexistante
        instance = new SoundController();
    }

    return instance;
}

void SoundController::addSound(const QString& soundName, const QString& soundFilePath)
{
    QMediaPlayer* mediaPlayer = new QMediaPlayer;
    mediaPlayer->setMedia(QUrl(soundFilePath)); // connection entre le media player et le fichier son
    sounds[soundName] = mediaPlayer;
}

void SoundController::playSound(const QString& soundName, bool loop)
{
    if (sounds.contains(soundName) && !this->isSoundPlaying(soundName)) // uniquement si son initialisé et pas en cours de lecture
    {
        QMediaPlayer* mediaPlayer = sounds[soundName];

        if (loop) { // lecture en boucle du son
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
    if (sounds.contains(soundName)) // uniquement si le son existe dans la liste
    {
        if (this->isSoundPlaying(soundName)) // si actuellement joué
            sounds[soundName]->setPosition(0);
        else
            this->playSound(soundName);
    }
}

void SoundController::stopSound(const QString& soundName)
{
    if (sounds.contains(soundName)) // uniquement si le son existe dans la liste
    {
        QMediaPlayer* mediaPlayer = sounds[soundName];
        mediaPlayer->disconnect(mediaPlayer, &QMediaPlayer::stateChanged, 0, 0); // arrêter la boucle
        mediaPlayer->stop(); // arrêter le son
    }
}

void SoundController::stopAllSounds()
{
    for (const QString& key : sounds.keys()) {
        stopSound(key); // arrêter le son
    }
}

bool SoundController::isSoundPlaying(const QString& soundName)
{
    if (sounds.contains(soundName)) // uniquement si le son existe dans la liste
    {
        QMediaPlayer* mediaPlayer = sounds[soundName];
        return mediaPlayer->state() == QMediaPlayer::PlayingState;
    }
    return false;
}
