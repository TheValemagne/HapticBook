#include "utils.h"
#include<QRect>
Utils::Utils()
{

}

 bool Utils::collision(QLabel* element1, QLabel* element2) {
     // Obtenez les rectangles de collision des deux éléments
     QRect rect1 = element1->geometry();
     QRect rect2 = element2->geometry();

     // Utilisez la fonction intersects() pour vérifier la collision
     bool collisionDetected = rect1.intersects(rect2);

     return collisionDetected;
 }
