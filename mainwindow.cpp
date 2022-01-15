#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "simulation.h"

#include <QDebug>
#include <QTimer>
#include <unistd.h>
#include <stdio.h>

const int baseInterval = 500;
const double baseSpeed = 20;
const QString logInfo = "[LOG] ";

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), launched{false}
{
    simulation = new Simulation();
    ui->setupUi(this);
    ui->openGlWid->setSimulation(simulation);
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
    if(isActive())
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

void MainWindow::on_zoomIn_clicked()
{
    qDebug() << logInfo << "Zoom In";
    ui->openGlWid->increaseZoom();
    ui->openGlWid->update();
}


void MainWindow::on_zoomOut_clicked()
{
    qDebug() << logInfo << "Zoom Out";
    ui->openGlWid->decreaseZoom();
    ui->openGlWid->update();
}


void MainWindow::on_removeV_clicked()
{
    qDebug() << logInfo << "Remove Car";
    simulation->removeACar();
    ui->openGlWid->update();
}


void MainWindow::on_addV_clicked()
{
    qDebug() << logInfo << "Add Car";
    simulation->addCar();
    ui->openGlWid->update();
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << logInfo << "Gestion Simulation";
    if(!isActive())
    {
        updater->start();
        launched = true;
        QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
        buttonSender->setText("Arrêter la simulation");
    }
    else
    {
        updater->stop();
        QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
        launched = false;
        buttonSender->setText("Lancer la simulation");
    }
}

bool MainWindow::isActive()
{
    return updater->isActive();
}


double MainWindow::calculPourcentSpeed(int newSpeed)
{
    //500 * ratio => 20 => 500
    return (baseInterval * newSpeed)/100.0;
}

void MainWindow::on_timeSlider_valueChanged(int newSpeed)
{
    if(newSpeed == 0)
    {
        qDebug() << logInfo << "Simulation en pause";
        updater->stop();
    }
    else
    {
        if(launched)
        {
            updater->start();
        }
        qDebug() << logInfo << "Vitesse de la simulation: " << calculPourcentSpeed(newSpeed) << "%";
        updater->setInterval(calculInterval(newSpeed));
    }
}
