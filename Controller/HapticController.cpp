//
// Created by remiz on 21/10/2023.
//
#include <QApplication>
#include <QMessageBox>
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
    if (mProject->OpenFile("./effets.ifr", mMouse)) {
        effects = QMap<QString, CImmCompoundEffect*>();

        // Init all effects
        this->addEffect("ressort", "Ressort");
        this->addEffect("sand", "Sable");
        this->addEffect("water", "Eau");
        this->addEffect("EFFET QUI MARCHE PAS", "HIHIHIHHIHI jescxiwte pas");
    } else {
        QMessageBox::critical(mWindow, "Error", "LOG[HapticController] : Unable to open IFC file, haptic effects will not be available");
        return;
    }
}

void HapticController::addEffect(const QString &keyName, const CHAR *effectName) {
    effects[keyName] = mProject->CreateEffect(effectName, mMouse, IMM_PARAM_NODOWNLOAD);
    if (!effects[keyName]) QMessageBox::warning(mWindow, "Error", "LOG[HapticController] : Unable to create effect '" + keyName + "', this effect will not be available");
}

bool HapticController::isEffectInitialized(const QString &effectName) {
    return effects.contains(effectName) && effects[effectName];
}

void HapticController::startEffect(const QString &effectName) {
    if (this->isEffectInitialized(effectName)) {
        effects[effectName]->Start();
    }
}

void HapticController::stopEffect(const QString &effectName) {
    if (this->isEffectInitialized(effectName)) {
        effects[effectName]->Stop();
    }
}

void HapticController::stopAllEffects() {
    QMap<QString, CImmCompoundEffect*>::iterator it = effects.begin();
    while (it != effects.end()) {
        stopEffect(it.key());
        ++it;
    }
}
