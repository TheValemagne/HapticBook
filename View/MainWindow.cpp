//
// Created by remiz on 21/10/2023.
//

#include "MainWindow.h"

MainWindow::MainWindow(Book *book) {
    this->book = book;
    setWindowTitle("Hello world!");
    resize(1000, 700);
    show();
}
