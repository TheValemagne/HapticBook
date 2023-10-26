#ifndef ELEMENT_H
#define ELEMENT_H

#include <QLabel>
#include<QPixmap>
#include<QWidget>
#include <QMoveEvent>

class Element : public QLabel
{
    Q_OBJECT

public:
    Element(const QPixmap &image, QWidget *parent = nullptr);

protected:
};

#endif // ELEMENT_H
