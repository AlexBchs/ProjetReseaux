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
        void on_addCarClicked();

        void on_removeCarClicked();

        void ZoomOut();

        void ZoomIn();

        void update();

        void startAndStop();

        void changeSpeed(int position);

        int calculInterval(int speed);

        double getSpeedRatio(int speed);


private:
        Ui::MainWindow *ui;

        Simulation* simulation;

        QTimer* updater;

        int currentTick = 0;

        bool launched;
};
#endif // MAINWINDOW_H
