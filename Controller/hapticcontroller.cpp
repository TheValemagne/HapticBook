#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "hapticcontroller.h"

HapticController::HapticController(QMainWindow *w): mWindow(w) {
    // Initialisation de souris haptique
    mMouse = new CImmMouse();
    if (!mMouse->Initialize(qWinAppInst(), (HWND)mWindow->effectiveWinId())) {
        delete mMouse;
        mMouse = NULL;
        mProject = NULL;
        QMessageBox::critical(mWindow, "Error", "LOG[HapticController] : Unable to initialize mouse device, haptic effects will not be available");
        return;
    }

    // Initialisation du project immersion studio
    mProject = new CImmProject();
    if (mProject->OpenFile("./../HapticBook/resources/effects/effects.ifr", mMouse)) {
        effects = QMap<QString, CImmCompoundEffect*>();
        effectsIsPlaying = QMap<QString, bool>();

        // Initialisation de tous les effets
        this->addEffect("water", "Water");
        this->addEffect("shaking", "Shaking");
        this->addEffect("landing", "Landing");
        this->addEffect("heavy_load", "HeavyLoad");
        this->addEffect("click", "Click");
        this->addEffect("fur", "Fur");
        this->addEffect("wale", "Wale");
        this->addEffect("waleback", "WaleBack");
        this->addEffect("page2_wall", "Page2Wall");
        this->addEffect("rock_push", "RockPush");
        this->addEffect("rock_sliding", "RockSliding");
        this->addEffect("tractor_beam", "tractor2");
        this->addEffect("heart", "Heart");
        this->addEffect("walk_sand", "Sandwalk");


    } else { // si immpossible d'ouvrir le cfichier de projet immersion studio
        QMessageBox::critical(mWindow, "Error", "LOG[HapticController] : Unable to open IFC file, haptic effects will not be available");
        delete mProject;
        mProject = NULL;
        return;
    }
}

HapticController::~HapticController()
{
    // supprime les effets
    effects.clear();
    // supprime le pointeur sur le fichier immersion studio
    if (mProject)
        delete mProject;
    // supprime le pointeur sur l'objet souris
    if (mMouse)
        delete mMouse;
    // supprime le poiteur sur l'instance
    if (instance)
        instance = nullptr;
}

HapticController* HapticController::instance = nullptr;

HapticController* HapticController::getInstance(QMainWindow *window)
{
    if (window && !instance){ // créé l'instance si inexistante et la fenêtre est fournie
        instance = new HapticController(window);
    }

    return instance;
}

void HapticController::addEffect(const QString &keyName, const CHAR *effectName)
{
    effectsIsPlaying[keyName] = false;
    effects[keyName] = mProject->CreateEffect(effectName,
                                              mMouse,
                                              IMM_PARAM_NODOWNLOAD);

    if (!effects[keyName]){ // si l'effet n'a pu être créé
        QMessageBox::warning(mWindow, "Error", "LOG[HapticController] : Unable to create effect '" + keyName + "', this effect will not be available");
        CImmCompoundEffect* effect = effects.take(keyName);
        delete effect;
    }
}

bool HapticController::isEffectInitialized(const QString &effectName)
{
    return effects.contains(effectName) && effects[effectName] && effectsIsPlaying.contains(effectName);
}

void HapticController::startEffect(const QString &effectName)
{
    if (this->isEffectInitialized(effectName) && !this->isEffectPlaying(effectName)) { // uniquement si effet initialisé et pas en cours
        effects[effectName]->Start(); // lancer l'effet
        effectsIsPlaying[effectName] = true;
    }
}

void HapticController::stopEffect(const QString &effectName)
{
    if (this->isEffectInitialized(effectName)) { // uniquement si effet initialisé
        effects[effectName]->Stop(); // arrêter l'effet
        effectsIsPlaying[effectName] = false;
    }
}

void HapticController::stopAllEffects()
{
    QMap<QString, CImmCompoundEffect*>::iterator it = effects.begin();
    while (it != effects.end()) {
        stopEffect(it.key()); // arrêter l'effets
        ++it;
    }
}

bool HapticController::isEffectPlaying(const QString &effectName)
{
    if (this->isEffectInitialized(effectName)) { // uniquement si effet initialisé
        return effectsIsPlaying[effectName];
    }
    return false;
}
