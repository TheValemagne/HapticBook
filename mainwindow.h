#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include "Controller/SoundController.h"
#include "Controller/HapticController.h"

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

private:
    Ui::MainWindow *ui;
    QWidget* pageOne;
    QWidget* pageTwo;
    SoundController soundController;
    HapticController hapticController;
};

#endif // MAINWINDOW_H
