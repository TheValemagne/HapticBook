#ifndef PAGE_H
#define PAGE_H

#include <QMap>
#include <QString>
#include <QStackedWidget>
#include <QWidget>
#include <QDebug>

#include "Model/Element.h"

class Element;
class Page : public QWidget
{
public:
    Page(QStackedWidget *parent);
    ~Page();
    void nextPage();
    void changeCurcor(const QString& cursorImage, int cursorX, int cursorY);
    // Elements management
    void addElement(const QString& elementName, Element* element);
    Element *getElement(const QString& elementName);
    // abstract
    virtual void onMouseMove() = 0; // custom function for listen element movement
private:
    QMap<QString, Element*> elements;
    QStackedWidget* book;
 protected:
    bool hasCollide;
};

#endif // PAGE_H
