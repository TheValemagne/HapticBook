#ifndef PAGE_H
#define PAGE_H
#include<QMap>
#include<QString>
#include <QWidget>
#include "Model/Element.h"

class Page : QWidget
{
public:
    Page(QWidget *parent);
    void addElement(const QString& elementName, Element* element);
    Element *getElement(const QString& elementName);
private:
    QMap<QString, Element*> elements;
};

#endif // PAGE_H
