#ifndef ELEMENT_H
#define ELEMENT_H

#include <QLabel>
#include<QPixmap>
#include<QWidget>
#include<QPoint>
#include <QString>

class Element : public QLabel
{
    Q_OBJECT

public:
    Element(const QString& src, const QPoint &position, QWidget *parent = nullptr);
protected:
private:
    QPixmap image;
    QPoint position;
};

#endif // ELEMENT_H
