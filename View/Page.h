//
// Created by remiz on 21/10/2023.
//

#ifndef UNTITLED2_PAGE_H
#define UNTITLED2_PAGE_H


#include <QWidget>

class Page : public QWidget {
Q_OBJECT

public:
    Page(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
};


#endif //UNTITLED2_PAGE_H
