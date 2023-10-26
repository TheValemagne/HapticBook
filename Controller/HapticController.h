//
// Created by remiz on 21/10/2023.
//

#ifndef UNTITLED2_HAPTICCONTROLLER_H
#define UNTITLED2_HAPTICCONTROLLER_H

#undef UNICODE

#include <QMainWindow>
#include <ifc.h>
#include <QMap>

class HapticController {
public:
    HapticController(QMainWindow *fen);
    void startEffect(const QString& effectName);
    void stopEffect(const QString& effectName);
    void stopAllEffects();

private:
    CImmMouse* mMouse;      // Mouse device
    CImmProject* mProject;  // IFC Project
    QMainWindow *mWindow;   // Window
    QMap<QString, CImmCompoundEffect*> effects; // Effects

    void addEffect(const QString& keyName, const CHAR *effectName);
    bool isEffectInitialized(const QString& effectName);
};


#endif //UNTITLED2_HAPTICCONTROLLER_H
