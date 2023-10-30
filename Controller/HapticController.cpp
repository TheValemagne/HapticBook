//
// Created by remiz on 21/10/2023.
//
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "HapticController.h"

HapticController::HapticController(QMainWindow *w): mWindow(w) {
    // Init mouse
    mMouse = new CImmMouse();
    if (!mMouse->Initialize(qWinAppInst(), (HWND)mWindow->effectiveWinId())) {
        delete mMouse;
        mMouse = NULL;
        QMessageBox::critical(mWindow, "Error", "LOG[HapticController] : Unable to initialize mouse device, haptic effects will not be available");
        return;
    }

    // Init project
    mProject = new CImmProject();
    if (mProject->OpenFile("./../HapticBook/resources/effects/effects.ifr", mMouse)) {
        effects = QMap<QString, CImmCompoundEffect*>();

        // Init all effects
        this->addEffect("sand", "Sand");
        this->addEffect("water", "Water");
        this->addEffect("shaking", "Shaking");
        this->addEffect("landing", "Landing");
        this->addEffect("heavy_load", "HeavyLoad");
    } else {
        QMessageBox::critical(mWindow, "Error", "LOG[HapticController] : Unable to open IFC file, haptic effects will not be available");
        delete mProject;
        mProject = NULL;
        return;
    }
}

HapticController::~HapticController()
{
    effects.clear();
    if (mProject)
        delete mProject;
    if (mMouse)
        delete mMouse;
    if (instance)
        instance = nullptr;
}

HapticController* HapticController::instance = nullptr;

HapticController* HapticController::getInstance(QMainWindow *window)
{
    if (window != nullptr && instance == nullptr){
        instance = new HapticController(window);
    }

    return instance;
}

void HapticController::addEffect(const QString &keyName, const CHAR *effectName)
{
    effects[keyName] = mProject->CreateEffect(effectName,
                                                                                mMouse,
                                                                                IMM_PARAM_NODOWNLOAD);
    if (!effects[keyName]){
        QMessageBox::warning(mWindow, "Error", "LOG[HapticController] : Unable to create effect '" + keyName + "', this effect will not be available");
        CImmCompoundEffect* effect = effects.take(keyName);
        delete effect;
    }
}

bool HapticController::isEffectInitialized(const QString &effectName)
{
    return effects.contains(effectName) && effects[effectName];
}

void HapticController::startEffect(const QString &effectName)
{
    if (this->isEffectInitialized(effectName)) {
        effects[effectName]->Start();
    }
}

void HapticController::stopEffect(const QString &effectName)
{
    if (this->isEffectInitialized(effectName)) {
        effects[effectName]->Stop();
    }
}

void HapticController::stopAllEffects()
{
    QMap<QString, CImmCompoundEffect*>::iterator it = effects.begin();
    while (it != effects.end()) {
        stopEffect(it.key());
        ++it;
    }
}
