#ifndef PAGESIX_H
#define PAGESIX_H

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
    void onMouseMove() override;

private slots:
    void on_answerButton_clicked();

    void on_lemur_enterEvent();

    void on_lemur_leaveEvent();

    void on_lemur_mouseMove();

private:
    Ui::PageSix *ui;
    bool hasTouchedFur;
    void showNotification(bool isVisible);
};

#endif // PAGESIX_H
