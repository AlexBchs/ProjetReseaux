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

        void on_zoomOutClicked();

        void on_zoomInClicked();

        void on_LaunchClicked();

        void update();

    private:
        Ui::MainWindow *ui;

        Simulation* simulation;

        QTimer* updater;

        bool launched;
};
#endif // MAINWINDOW_H
