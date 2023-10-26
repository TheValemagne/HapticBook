#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Controller/SoundController.h"

#include"pageone.h"
#include"pagetwo.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialisation des pages
    pageOne = new PageOne(ui->book);
    pageTwo = new PageTwo(ui->book);

    // Ajouter les pages aux QStackedWidget de la page principale (mainwindow)
    ui->book->addWidget(pageOne);
    ui->book->addWidget(pageTwo);

        this->soundController = SoundController();
        //this->soundController.playSound("intro", true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pageOne;
    delete pageTwo;
}


void MainWindow::on_startButton_clicked()
{
     ui->book->setCurrentIndex(1);
    this->soundController.stopAllSounds();
    //this->soundController.playSound("test");
}
