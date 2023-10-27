#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Controller/SoundController.h"
#include "Controller/HapticController.h"

#include"pageone.h"
#include"pagetwo.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    hapticController(this),
    soundController()
{
    ui->setupUi(this);

    // Initialisation des pages
    pageOne = new PageOne(ui->book);
    pageTwo = new PageTwo(ui->book);

    // Ajouter les pages aux QStackedWidget de la page principale (mainwindow)
    ui->book->addWidget(pageOne);
    ui->book->addWidget(pageTwo);

    // Instancier les controleurs
    this->soundController = SoundController();
    //this->soundController.playSound("intro", true);

    this->hapticController.startEffect("water");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pageOne;
    delete pageTwo;
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape) {
        close();
    }
    else if (event->key() == Qt::Key_Left) {
        ui->book->setCurrentIndex(ui->book->currentIndex()-1);
    }
    else if (event->key() == Qt::Key_Right) {
        ui->book->setCurrentIndex(ui->book->currentIndex()+1);
    }
    }

void MainWindow::on_startButton_clicked()
{
    ui->book->setCurrentIndex(1);
    this->soundController.stopAllSounds();
    this->hapticController.stopAllEffects();
    this->hapticController.startEffect("ressort");
    //this->soundController.playSound("test");
}
