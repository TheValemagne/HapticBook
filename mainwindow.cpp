#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Controller/SoundController.h"
#include "Controller/HapticController.h"

#include "pageone.h"
#include "pagetwo.h"
#include "pagethree.h"
#include "pagefour.h"
#include "pagefive.h"
#include "pagesix.h"
#include "pageseven.h"
#include "pageeight.h"

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
    pageThree = new PageThree(ui->book);
    pageFour = new PageFour(ui->book);
    pageFive = new PageFive(ui->book);
    pageSix = new PageSix(ui->book);
    pageSeven = new PageSeven(ui->book);
    pageEight = new PageEight(ui->book);

    // Ajouter les pages aux QStackedWidget de la page principale (mainwindow)
    ui->book->addWidget(pageOne);
    ui->book->addWidget(pageTwo);
    ui->book->addWidget(pageThree);
    ui->book->addWidget(pageFour);
    ui->book->addWidget(pageFive);
    ui->book->addWidget(pageSix);
    ui->book->addWidget(pageSeven);
    ui->book->addWidget(pageEight);

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
    delete pageThree;
    delete pageFour;
    delete pageFive;
    delete pageSix;
    delete pageEight;
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
