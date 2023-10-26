#ifndef PAGE_H
#define PAGE_H
#include<QMap>
#include<QString>
#include <QStackedWidget>
#include <QWidget>
#include "Model/Element.h"
#include<QDebug>
class Element;
class Page : public QWidget
{
public:
    Page(QStackedWidget *parent);
     void nextPage();
    // Elements management
    void addElement(const QString& elementName, Element* element);
    Element *getElement(const QString& elementName);
    // abstract
     virtual void onMouseMove() = 0; // custom function for listen element movement
private:
    QMap<QString, Element*> elements;
    QStackedWidget* book;
};

#endif // PAGE_H
