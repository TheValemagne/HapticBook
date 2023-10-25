//
// Created by remiz on 21/10/2023.
//

#ifndef UNTITLED2_ELEMENT_H
#define UNTITLED2_ELEMENT_H


#include <QPoint>
#include <QSize>

class Element {
public:
    Element();
    virtual void abstractMethod() = 0;

private:
    QPoint position;
    QSize size;
    int rotation;
};


#endif //UNTITLED2_ELEMENT_H
