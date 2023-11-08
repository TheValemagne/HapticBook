#ifndef PAGE_H
#define PAGE_H

#include <QMap>
#include <QString>
#include <QStackedWidget>
#include <QWidget>
#include <QDebug>

class Page : public QWidget
{
public:
    Page(QStackedWidget *parent, int pageIndex);
    ~Page();
    // abstract
    virtual void onMouseMove() = 0; // custom function for listen element movement
private:
    QStackedWidget* book;
    int pageIndex;
 protected:
    bool hasCollide;
    bool isCurrentPage();
    void changeCurcor(const QString& cursorImage, int cursorX, int cursorY);
    void nextPage();
    void stopSoundsAndEffects();
};

#endif // PAGE_H
