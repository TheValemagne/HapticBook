#include "page.h"
#include "Controller/hapticcontroller.h"
#include "Controller/soundcontroller.h"

Page::Page(QStackedWidget *parent, int pageIndex): QWidget(parent)
{
    this->book = parent;
    this->pageIndex = pageIndex;
    hasCollide = false;
}

Page::~Page()
{

}

bool Page::isCurrentPage()
{
    return this->book->currentIndex() == pageIndex;
}

void Page::nextPage() 
{
    // arreter tous les effets en cours de la page
    stopSoundsAndEffects();

   qDebug() << "LOG[Page] : " <<  "Current Index : " << book->currentIndex() << "Count : " << book->count();
   if(book->currentIndex() < book->count() - 1){
      book->setCurrentIndex(book->currentIndex()+1);
   }
}

void Page::changeCurcor(const QString& cursorImage, int cursorX, int cursorY)
{
    QCursor c = QCursor(QPixmap(cursorImage), cursorX, cursorY);
    setCursor(c);
}

void Page::stopSoundsAndEffects()
{
    HapticController::getInstance()->stopAllEffects();
    SoundController::getInstance()->stopAllSounds();
}
