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

signals:
    void mousePress();
    void mouseRelease();
    void labelMove();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
private:
    QPoint mousePos;
};

#endif // MOVABLELABEL_H
