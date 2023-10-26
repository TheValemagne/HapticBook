#include "page.h"

Page::Page()
{

   // elements = QMap();
}

void Page::addElement(const QString& elementName, Element* element) {
    elements.insert(elementName, element);
}
