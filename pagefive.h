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
    virtual void showEvent(QShowEvent *event) override;
    virtual void hideEvent(QHideEvent *event) override;
private:
    void showEmergencyTransmitter(bool isVisible);
    void setCursors();
    QPoint treeTrunkPosition1;
    QPoint treeTrunkPosition2;

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
