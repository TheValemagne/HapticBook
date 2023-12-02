#ifndef PAGESIX_H
#define PAGESIX_H

#include<QTimer>
#include "page.h"

namespace Ui {
class PageSix;
}

class PageSix : public Page
{
    Q_OBJECT

public:
    explicit PageSix(QStackedWidget *parent = 0);
    ~PageSix();
    virtual void showEvent(QShowEvent *event) override;

private slots:
    void on_answerButton_clicked();

    void on_lemur_enterEvent();

    void on_lemur_leaveEvent();

    void on_lemur_mouseMove();

    void on_answerButton_pressed();

    void on_answerButton_released();

private:
    Ui::PageSix *ui;
    bool hasTouchedFur;
    bool isFirstMove;
    QTimer *soundTimer;
    QTimer *notificationTimer;
    void showNotification(bool isVisible);
    void onSoundTimeOut();
    void onNotificationTimeOut();
};

#endif // PAGESIX_H
