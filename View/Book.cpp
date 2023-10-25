//
// Created by remiz on 21/10/2023.
//

#include "Book.h"

Book::Book() {

}

Page* Book::getCurrentPage() {
    int index = this->currentIndex();
    return pages.at(index);
}
