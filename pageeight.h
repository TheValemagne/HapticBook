#ifndef PAGEEIGHT_H
#define PAGEEIGHT_H

#include "page.h"
#include <QShowEvent>

namespace Ui {
class PageEight;
}

class PageEight : public Page
{
    Q_OBJECT

public:
    explicit PageEight(QStackedWidget *parent = 0);
    ~PageEight();
    virtual void showEvent(QShowEvent *event) override;

private slots:
    void on_closeButton_clicked();

private:
    Ui::PageEight *ui;
};

#endif // PAGEEIGHT_H
