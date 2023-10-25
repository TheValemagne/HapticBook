//
// Created by remiz on 21/10/2023.
//

#include "Page.h"

Page::Page(QWidget *parent) : QWidget(parent) {
    // Initialisation de la page
}

void Page::mousePressEvent(QMouseEvent *event) {
    // Redéfinition de la gestion de l'événement de clic de souris
}

void Page::keyPressEvent(QKeyEvent *event) {
    // Redéfinition de la gestion de l'événement de touche enfoncée
}

void Page::dragEnterEvent(QDragEnterEvent *event) {
    // Redéfinition de la gestion de l'événement de glisser-déposer (entrée)
}

void Page::dragLeaveEvent(QDragLeaveEvent *event) {
    // Redéfinition de la gestion de l'événement de glisser-déposer (sortie)
}

void Page::mouseMoveEvent(QMouseEvent *event) {
    // Redéfinition de la gestion de l'événement de mouvement de souris
}
