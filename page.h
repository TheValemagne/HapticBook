#ifndef PAGE_H
#define PAGE_H

#include <QMap>
#include <QString>
#include <QStackedWidget>
#include <QWidget>
#include <QDebug>

#include "Model/element.h"

class Element;
class Page : public QWidget
{
public:
    Page(QStackedWidget *parent, int pageIndex);
    ~Page();
    bool isCurrentPage();
    // abstract
    virtual void onMouseMove() = 0; // custom function for listen element movement
private:
    QMap<QString, Element*> elements;
    QStackedWidget* book;
    int pageIndex;
 protected:
    bool hasCollide;
    void changeCurcor(const QString& cursorImage, int cursorX, int cursorY);
    void nextPage();
    void stopSoundsAndEffects();

    // Elements management
    void addElement(const QString& elementName, Element* element);
    Element *getElement(const QString& elementName);
};

#endif // PAGE_H
