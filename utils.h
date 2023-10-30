#ifndef UTILS_H
#define UTILS_H

#include <QLabel>

class Utils
{
public:
    Utils();
    static bool collision(QLabel* elem1, QLabel* elem2);
    static void delay(int secondsToWait);
};

#endif // UTILS_H
