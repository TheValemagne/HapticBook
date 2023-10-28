//
// Created by remiz on 21/10/2023.
//

#ifndef HAPTICCONTROLLER_H
#define HAPTICCONTROLLER_H

#undef UNICODE

#include <QMainWindow>
#include <ifc.h>
#include <QMap>

class HapticController {
public:
        static HapticController* getInstance(QMainWindow *window = nullptr);
        HapticController(HapticController &other) = delete;
        void operator=(const HapticController &) = delete;
        void startEffect(const QString& effectName);
        void stopEffect(const QString& effectName);
        void stopAllEffects();

protected:
        HapticController(QMainWindow *window);
        static HapticController* instance;

private:
    CImmMouse* mMouse;      // Mouse device
    CImmProject* mProject;  // IFC Project
    QMainWindow *mWindow;   // Window
    QMap<QString, CImmCompoundEffect*> effects; // Effects

    void addEffect(const QString& keyName, const CHAR *effectName);
    bool isEffectInitialized(const QString& effectName);
};


#endif //HAPTICCONTROLLER_H
