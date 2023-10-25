//
// Created by remiz on 21/10/2023.
//

#ifndef UNTITLED2_MAINWINDOW_H
#define UNTITLED2_MAINWINDOW_H


#include <QMainWindow>
#include "Book.h"

class MainWindow : public QMainWindow {
public:
    MainWindow(Book *book);

private:
    Book *book;
};


#endif //UNTITLED2_MAINWINDOW_H
