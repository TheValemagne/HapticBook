#include "utils.h"
#include<QRect>
#include <QEventLoop>
#include <QTimer>

Utils::Utils()
{

}

bool Utils::collision(QLabel* element1, QLabel* element2)
{
    // Obtenez les rectangles de collision des deux éléments
    QRect rect1 = element1->geometry();
    QRect rect2 = element2->geometry();

    // Utilisez la fonction intersects() pour vérifier la collision
    bool collisionDetected = rect1.intersects(rect2);

    return collisionDetected;
}

void Utils::delay(double secondsToWait)
{
        QEventLoop loop;
        QTimer t;
        t.connect(&t, &QTimer::timeout, &loop, &QEventLoop::quit);
        t.start(secondsToWait * 1000); // conversion en ms
        loop.exec();
}
