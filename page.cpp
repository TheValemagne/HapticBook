#include "page.h"

Page::Page(QStackedWidget *parent): QWidget(parent)
{
    this->book = parent;
}

void Page::nextPage() {
    qDebug() << "LOG[Page] : " <<  "Current Index : " << book->currentIndex() << "Count : " << book->count();
   if(book->currentIndex() < book->count() - 1)
      book->setCurrentIndex(book->currentIndex()+1);
}

void Page::addElement(const QString& elementName, Element* element) {
    elements.insert(elementName, element);
}

Element* Page::getElement(const QString &elementName){
    return elements.take(elementName);
}
