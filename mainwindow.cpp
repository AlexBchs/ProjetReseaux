#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "simulation.h"

#include <QDebug>
#include <QTimer>
#include <unistd.h>
#include <stdio.h>

const int baseInterval = 500;
const double baseSpeed = 20;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    simulation = new Simulation();
    ui->setupUi(this);
    ui->openGlWid->setSimulation(simulation);
    launched = false;

    updater = new QTimer(this);
    updater->setInterval(baseInterval);
    connect( updater, SIGNAL(timeout()), this, SLOT(update()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete simulation;
}

void MainWindow::update()
{
    if(launched && updater->isActive())
    {
        simulation->update();
        ui->openGlWid->update();
    }
}

double MainWindow::getSpeedRatio(int newSpeed)
{
    return baseSpeed/newSpeed;
}

int MainWindow::calculInterval(int newSpeed)
{
    //500 * ratio => 20 => 500
    return baseInterval * getSpeedRatio(newSpeed);
}

void MainWindow::changeSpeed(int newSpeed)
{
    if(newSpeed == 0)
    {
        updater->stop();
    }
    else
    {
        updater->setInterval(calculInterval(newSpeed));
    }
}

void MainWindow::on_zoomIn_clicked()
{
    qDebug() << "In";
    ui->openGlWid->increaseZoom();
    ui->openGlWid->update();
}


void MainWindow::on_zoomOut_clicked()
{
    qDebug() << "Out";
    ui->openGlWid->decreaseZoom();
    ui->openGlWid->update();
}


void MainWindow::on_removeV_clicked()
{
    qDebug() << "RemoveV";
    simulation->removeACar();
    ui->openGlWid->update();
}


void MainWindow::on_addV_clicked()
{
    qDebug() << "AddV";
    simulation->addCar();
    ui->openGlWid->update();
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "Gestion Simulation";
    if(!launched)
    {
        launched = true;
        updater->start();
        QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
        buttonSender->setText("Arrêter la simulation");
    }
    else
    {
        updater->stop();
        launched = false;
        QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
        buttonSender->setText("Lancer la simulation");
    }
}
