#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->startButton->setCursor(Qt::PointingHandCursor);

    // Instancier les controleurs
    soundController = SoundController::getInstance();
    hapticController = HapticController::getInstance(this);

    // Initialisation des pages
    pageOne = new PageOne(ui->book);
    pageTwo = new PageTwo(ui->book);
    pageThree = new PageThree(ui->book);
    pageFour = new PageFour(ui->book);
    pageFive = new PageFive(ui->book);
    pageSix = new PageSix(ui->book);
    pageSeven = new PageSeven(ui->book);
    pageEight = new PageEight(ui->book);

    // Ajouter les pages au QStackedWidget de la page principale (mainwindow)
    ui->book->addWidget(pageOne);
    ui->book->addWidget(pageTwo);
    ui->book->addWidget(pageThree);
    ui->book->addWidget(pageFour);
    ui->book->addWidget(pageFive);
    ui->book->addWidget(pageSix);
    ui->book->addWidget(pageSeven);
    ui->book->addWidget(pageEight);

    // son de démarrage
    //soundController->playSound("main_theme", true);
    ui->book->setCurrentIndex(7);
}

MainWindow::~MainWindow()
{
    delete ui;

    // supprimer les pages
    if (pageOne)
        delete pageOne;
    if (pageTwo)
        delete pageTwo;
    if (pageThree)
        delete pageThree;
    if (pageFour)
        delete pageFour;
    if (pageFive)
        delete pageFive;
    if (pageSix)
        delete pageSix;
    if (pageSeven)
        delete pageSeven;
    if (pageEight)
        delete pageEight;

    // supprimer les controlleurs
    if (hapticController)
       delete hapticController;
    if (soundController)
        delete soundController;
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) 
{
    // uniquement prévue pour le développement
    if (event->key() == Qt::Key_Escape) { // fermer l'application avec le bouton "echap"
        stopSoundsAndEffects();
        QApplication::quit();
    }
    else if (event->key() == Qt::Key_Left) { // passer à la page précédente avec flèche droite
        stopSoundsAndEffects();
        ui->book->setCurrentIndex(ui->book->currentIndex()-1);
    }
    else if (event->key() == Qt::Key_Right) { // passer à la page suivante avec flèche droite
        stopSoundsAndEffects();
        ui->book->setCurrentIndex(ui->book->currentIndex()+1);
    }
}

/**
* Stop les sons et les effets haptiques en cours
*/
void MainWindow::stopSoundsAndEffects()
{
    hapticController->stopAllEffects();
    soundController->stopAllSounds();
}

/**
* Démarage du livre avec passage à la première scène
*/
void MainWindow::on_startButton_clicked()
{
    stopSoundsAndEffects();
    ui->book->setCurrentIndex(1);
}

void MainWindow::on_startButton_pressed()
{
    ui->startButton->setCursor(Qt::ClosedHandCursor);
}

void MainWindow::on_startButton_released()
{
    ui->startButton->setCursor(Qt::PointingHandCursor);
}

/**
* Permet de lancer la musique au retour à la page d'accueil
*/
void MainWindow::on_book_currentChanged(int pageIndex)
{
    // uniquement pour la permière page du livre
    if (pageIndex != 0){
        return;
    }

    // son de démarrage
    soundController->playSound("main_theme", true);
}
