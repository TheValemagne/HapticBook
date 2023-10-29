#ifndef PAGEFIVE_H
#define PAGEFIVE_H

#include "page.h"

namespace Ui {
class PageFive;
}

class PageFive : public Page
{
    Q_OBJECT

public:
    explicit PageFive(QStackedWidget *parent = 0);
    ~PageFive();
    void onMouseMove() override;
private:
    void hideEmergencyTransmitter(bool shouldHide);

private slots:
    void on_smallEmergencyTransmitter_clicked();

    void on_sosButton_clicked();

private:
    Ui::PageFive *ui;
};

#endif // PAGEFIVE_H
