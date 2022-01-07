#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "simulation.h"

#include <QTimer>
#include <unistd.h>
#include <stdio.h>

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
    if(launched) simulation->update();
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

void MainWindow::on_zoomOutClicked()
{
    ui->openGlWid->decreaseZoom();
    ui->openGlWid->update();
}

void MainWindow::on_zoomInClicked()
{
    ui->openGlWid->increaseZoom();
    ui->openGlWid->update();
}

void MainWindow::on_LaunchClicked()
{
    if(!launched)
    {
        launched = true;
        QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
        buttonSender->setText("Arreter");
    }
    else
    {
        launched = false;
        QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
        buttonSender->setText("Lancer");
    }
}
