#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "simulation.h"

#include <QTimer>
#include <unistd.h>
#include <stdio.h>

const int baseTimeur = 500;
const double baseSpeed = 20;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    simulation = new Simulation();
    ui->setupUi(this);
    ui->openGlWid->setSimulation(simulation);
    launched = false;

    updater = new QTimer(this);
    updater->setInterval(500);
    updater->start();
    connect( updater, SIGNAL(timeout()), this, SLOT(update()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete simulation;
}

void MainWindow::update()
{
    if(launched)
    {
        simulation->update();
    }
    ui->openGlWid->update();
}

void MainWindow::on_addCarClicked()
{
    simulation->addCar();
    ui->openGlWid->update();
}

void MainWindow::on_removeCarClicked()
{
    simulation->removeACar();
    ui->openGlWid->update();
}

void MainWindow::ZoomOut()
{
    ui->openGlWid->decreaseZoom();
    ui->openGlWid->update();
}

void MainWindow::ZoomIn()
{
    ui->openGlWid->increaseZoom();
    ui->openGlWid->update();
}

void MainWindow::startAndStop()
{
    if(!launched)
    {
        launched = true;
        QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
        buttonSender->setText("Arrêter");
    }
    else
    {
        launched = false;
        QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
        buttonSender->setText("Lancer");
    }
}

double MainWindow::getSpeedRatio(int newSpeed)
{
    return baseSpeed/newSpeed;
}

int MainWindow::calculInterval(int newSpeed)
{
    //500 * ratio => 20 => 500
    return 500 * (baseSpeed/newSpeed);
}

void MainWindow::changeSpeed(int newSpeed)
{
    updater->setInterval(calculInterval(newSpeed));
}
