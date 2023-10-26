#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Controller/SoundController.h"


MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    this->soundController = SoundController();
//    this->soundController.playSound("test", true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startButton_clicked()
{
     ui->book->setCurrentIndex(1);
//    this->soundController.stopAllSounds();
//    this->soundController.playSound("intro");
}
