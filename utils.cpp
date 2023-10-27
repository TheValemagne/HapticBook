#include "utils.h"
#include<QRect>
Utils::Utils()
{

}

 bool Utils::collision(QLabel* elem1, QLabel* elem2) {
     // Obtenez les rectangles de collision des deux éléments
     QRect rect1 = elem1->geometry();
     QRect rect2 = elem2->geometry();

     // Utilisez la fonction intersects() pour vérifier la collision
     bool collisionDetected = rect1.intersects(rect2);

     return collisionDetected;
 }
