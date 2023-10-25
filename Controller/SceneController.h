//
// Created by remiz on 21/10/2023.
//

#ifndef UNTITLED2_SCENECONTROLLER_H
#define UNTITLED2_SCENECONTROLLER_H


#include "../View/Book.h"

class SceneController {
public:
    SceneController(Book *book);

private:
    Book *book;
};


#endif //UNTITLED2_SCENECONTROLLER_H
