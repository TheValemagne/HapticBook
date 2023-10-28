#include "page.h"
#include "Controller/HapticController.h"

Page::Page(QStackedWidget *parent): QWidget(parent)
{
    this->book = parent;
    hasCollide = false;
}

void Page::nextPage() {
    HapticController::getInstance()->stopAllEffects();
    qDebug() << "LOG[Page] : " <<  "Current Index : " << book->currentIndex() << "Count : " << book->count();
   if(book->currentIndex() < book->count() - 1){
      book->setCurrentIndex(book->currentIndex()+1);
   }
}

void Page::addElement(const QString& elementName, Element* element) {
    elements.insert(elementName, element);
}

Element* Page::getElement(const QString &elementName){
    return elements.value(elementName);
}
