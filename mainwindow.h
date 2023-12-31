#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

#include "Controller/soundcontroller.h"
#include "Controller/hapticcontroller.h"
#include "page.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyReleaseEvent(QKeyEvent *event);

private slots:
    void on_startButton_clicked();

    void on_book_currentChanged(int arg1);

    void on_startButton_pressed();

    void on_startButton_released();

private:
    Ui::MainWindow *ui;
    Page* pageOne;
    Page* pageTwo;
    Page* pageThree;
    Page* pageFour;
    Page* pageFive;
    Page* pageSix;
    Page* pageSeven;
    Page* pageEight;

    SoundController* soundController;
    HapticController* hapticController;

    void stopSoundsAndEffects();
};

#endif // MAINWINDOW_H
