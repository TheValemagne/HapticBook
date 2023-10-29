#include "page.h"
#include "Controller/HapticController.h"
#include "Controller/SoundController.h"

Page::Page(QStackedWidget *parent): QWidget(parent)
{
    this->book = parent;
    hasCollide = false;
}

void Page::nextPage() {
    // arreter tous les effets en cours de la page
    HapticController::getInstance()->stopAllEffects();
    SoundController::getInstance()->stopAllSounds();

    qDebug() << "LOG[Page] : " <<  "Current Index : " << book->currentIndex() << "Count : " << book->count();
   if(book->currentIndex() < book->count() - 1){
      book->setCurrentIndex(book->currentIndex()+1);
   }
}

void Page::changeCurcor(const QString& cursorImage, int cursorX, int cursorY){
    QCursor c = QCursor(QPixmap(cursorImage), cursorX, cursorY);
    setCursor(c);
}

void Page::addElement(const QString& elementName, Element* element) {
    elements.insert(elementName, element);
}

Element* Page::getElement(const QString &elementName){
    return elements.value(elementName);
}
