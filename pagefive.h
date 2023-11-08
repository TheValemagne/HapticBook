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
    void showEmergencyTransmitter(bool isVisible);

private slots:
    void on_smallEmergencyTransmitter_clicked();

    void on_sosButton_clicked();

    void on_treeTrunk1_labelMove();

    void on_treeTrunk1_mouseRelease();

    void on_treeTrunk2_labelMove();

    void on_treeTrunk2_mouseRelease();

private:
    Ui::PageFive *ui;
};

#endif // PAGEFIVE_H
