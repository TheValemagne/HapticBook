#ifndef MOVABLELABEL_H
#define MOVABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <QMouseEvent>
#include <Qt>

class MovableLabel : public QLabel
{
    Q_OBJECT
public:
    MovableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());

    bool isMovable;
    QCursor openHandCursor;
    QCursor closedHandCursor;

    void setLocked(bool isLocked);

signals:
    void mousePress();
    void mouseRelease();
    void labelMove();
    void enterEvent();

protected:
    bool isLocked;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    virtual void enterEvent(QEvent *event) override;

private:
    QPoint mousePos;
};

#endif // MOVABLELABEL_H
