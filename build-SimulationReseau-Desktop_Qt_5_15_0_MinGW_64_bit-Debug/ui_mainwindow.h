/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "mapopengl.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *timeLab;
    QSlider *timeSlider;
    QLabel *titleLab;
    QLabel *zoomLab;
    QLabel *vehicleLab;
    QPushButton *addV;
    MapOpenGL *openGlWid;
    QPushButton *zoomOut;
    QPushButton *launchButton;
    QPushButton *removeV;
    QPushButton *zoomIn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1264, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        timeLab = new QLabel(centralwidget);
        timeLab->setObjectName(QString::fromUtf8("timeLab"));
        timeLab->setGeometry(QRect(950, 290, 261, 48));
        QFont font;
        font.setPointSize(20);
        font.setBold(false);
        font.setUnderline(true);
        timeLab->setFont(font);
        timeLab->setAlignment(Qt::AlignCenter);
        timeSlider = new QSlider(centralwidget);
        timeSlider->setObjectName(QString::fromUtf8("timeSlider"));
        timeSlider->setGeometry(QRect(950, 344, 261, 15));
        QFont font1;
        font1.setPointSize(10);
        timeSlider->setFont(font1);
        timeSlider->setMaximum(100);
        timeSlider->setSingleStep(1);
        timeSlider->setValue(20);
        timeSlider->setOrientation(Qt::Horizontal);
        titleLab = new QLabel(centralwidget);
        titleLab->setObjectName(QString::fromUtf8("titleLab"));
        titleLab->setGeometry(QRect(440, 0, 371, 48));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(true);
        titleLab->setFont(font2);
        titleLab->setTextFormat(Qt::RichText);
        zoomLab = new QLabel(centralwidget);
        zoomLab->setObjectName(QString::fromUtf8("zoomLab"));
        zoomLab->setGeometry(QRect(954, 156, 261, 48));
        zoomLab->setFont(font);
        zoomLab->setAlignment(Qt::AlignCenter);
        vehicleLab = new QLabel(centralwidget);
        vehicleLab->setObjectName(QString::fromUtf8("vehicleLab"));
        vehicleLab->setGeometry(QRect(954, 60, 261, 47));
        vehicleLab->setFont(font);
        vehicleLab->setAlignment(Qt::AlignCenter);
        addV = new QPushButton(centralwidget);
        addV->setObjectName(QString::fromUtf8("addV"));
        addV->setGeometry(QRect(954, 113, 120, 31));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(128, 128, 128, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        addV->setPalette(palette);
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(true);
        addV->setFont(font3);
        addV->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid black;\n"
"    border-radius: 6px;\n"
"   /* background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #272521, stop: 1 #0d0c0b);*/\n"
"	background-color: grey;\n"
"    min-width: 80px;\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #0d0c0b, stop: 1 #272521);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        openGlWid = new MapOpenGL(centralwidget);
        openGlWid->setObjectName(QString::fromUtf8("openGlWid"));
        openGlWid->setGeometry(QRect(20, 50, 902, 488));
        zoomOut = new QPushButton(centralwidget);
        zoomOut->setObjectName(QString::fromUtf8("zoomOut"));
        zoomOut->setGeometry(QRect(954, 210, 120, 47));
        QFont font4;
        font4.setPointSize(24);
        font4.setBold(true);
        zoomOut->setFont(font4);
        zoomOut->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid black;\n"
"    border-radius: 6px;\n"
"   /* background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #272521, stop: 1 #0d0c0b);*/\n"
"	background-color: grey;\n"
"    min-width: 80px;\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #0d0c0b, stop: 1 #272521);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        launchButton = new QPushButton(centralwidget);
        launchButton->setObjectName(QString::fromUtf8("launchButton"));
        launchButton->setGeometry(QRect(950, 430, 261, 41));
        QFont font5;
        font5.setPointSize(14);
        font5.setBold(false);
        launchButton->setFont(font5);
        launchButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid black;\n"
"    border-radius: 6px;\n"
"   /* background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #272521, stop: 1 #0d0c0b);*/\n"
"	background-color: grey;\n"
"    min-width: 80px;\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #0d0c0b, stop: 1 #272521);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        removeV = new QPushButton(centralwidget);
        removeV->setObjectName(QString::fromUtf8("removeV"));
        removeV->setGeometry(QRect(1080, 113, 135, 31));
        removeV->setFont(font3);
        removeV->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid black;\n"
"    border-radius: 6px;\n"
"   /* background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #272521, stop: 1 #0d0c0b);*/\n"
"	background-color: grey;\n"
"    min-width: 80px;\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #0d0c0b, stop: 1 #272521);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        zoomIn = new QPushButton(centralwidget);
        zoomIn->setObjectName(QString::fromUtf8("zoomIn"));
        zoomIn->setGeometry(QRect(1080, 210, 135, 47));
        zoomIn->setFont(font4);
        zoomIn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid black;\n"
"    border-radius: 6px;\n"
"   /* background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #272521, stop: 1 #0d0c0b);*/\n"
"	background-color: grey;\n"
"    min-width: 80px;\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #0d0c0b, stop: 1 #272521);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1264, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        timeLab->setText(QApplication::translate("MainWindow", "Temps", nullptr));
        titleLab->setText(QApplication::translate("MainWindow", "Bienvenue dans la simulation !", nullptr));
        zoomLab->setText(QApplication::translate("MainWindow", "Zoom", nullptr));
        vehicleLab->setText(QApplication::translate("MainWindow", "G\303\251rer les voitures", nullptr));
        addV->setText(QApplication::translate("MainWindow", "Ajouter", nullptr));
        zoomOut->setText(QApplication::translate("MainWindow", "-", nullptr));
        launchButton->setText(QApplication::translate("MainWindow", "Lancer la simulation", nullptr));
        removeV->setText(QApplication::translate("MainWindow", "Supprimer", nullptr));
        zoomIn->setText(QApplication::translate("MainWindow", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
