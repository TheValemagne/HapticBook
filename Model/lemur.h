#ifndef LEMUR_H
#define LEMUR_H

#include <QLabel>
#include <QEvent>

class Lemur : public QLabel
{
    Q_OBJECT
public:
    Lemur(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());

signals:
    void mouseMove();
    void enterEvent();
    void leaveEvent();

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    virtual void enterEvent(QEvent *event) override;
    virtual void leaveEvent(QEvent  *event) override;
};

#endif // LEMUR_H
