#ifndef ELEMENT_H
#define ELEMENT_H

#include <QLabel>
#include<QPixmap>
#include<QWidget>
#include<QPoint>
#include <QString>
#include"page.h"
class Page;
class Element : public QLabel
{
    Q_OBJECT

public:
    Element(const QString& src, const QPoint &position, Page *parent = nullptr);
protected:
    Page* page;
private:
    QPixmap image;

};

#endif // ELEMENT_H
