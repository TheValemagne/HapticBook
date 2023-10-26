#ifndef PAGE_H
#define PAGE_H
#include<QMap>
#include<QString>
#include "Model/Element.h"

class Page
{
public:
    Page();
    void addElement(const QString& elementName, Element* element);
private:
    QMap<QString, Element*> elements;
};

#endif // PAGE_H
