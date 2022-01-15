#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "mapopengl.h"
#include "simulation.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:
        void update();

        void changeSpeed(int position);

        int calculInterval(int speed);

        double getSpeedRatio(int speed);

        void on_zoomIn_clicked();
        void on_zoomOut_clicked();
        void on_removeV_clicked();
        void on_addV_clicked();


        void on_pushButton_clicked();

        bool isActive();

private:
        Ui::MainWindow *ui;

        Simulation* simulation;

        QTimer* updater;

        int currentTick = 0;
};
#endif // MAINWINDOW_H
