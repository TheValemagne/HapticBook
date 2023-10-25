//
// Created by remiz on 21/10/2023.
//

#ifndef UNTITLED2_BOOK_H
#define UNTITLED2_BOOK_H


#include <QStackedWidget>
#include "Page.h"

class Book : public QStackedWidget {
public:
    Book();
    Page* getCurrentPage();

private:
    QList<Page*> pages;

};


#endif //UNTITLED2_BOOK_H
