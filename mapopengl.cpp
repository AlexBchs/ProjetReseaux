#include "mapopengl.h"
#include "point.h"
#include "hexagon.h"
#include "node.h"

#include <QPainter>
#include <QCoreApplication>
#include <iostream>
#include <QDebug>

const double maxZoom = 2, minZoom = 0.25, stepZoom = 0.25;
const double baseSizeX = 399, baseSizeZ = 200;

MapOpenGL::MapOpenGL(QWidget* parent) : QOpenGLWidget (parent), zoom{1}
{}

void MapOpenGL::initializeGL()
{
    bg = new QImage();
    if(bg->load(QString("../SimulationReseau/Ressources/mulhouse.png")))
    {
        qDebug() << "Map de Mulhouse chargé";
    }
    else
    {
        qDebug() << "Map de Mulhouse introuvable";
    }
    car = new QImage();
    if(bg->load(QString("../SimulationReseau/Ressources/voiture.png")))
    {
        qDebug() << "Image de voiture chargé";
    }
    else
    {
        qDebug() << "Image de voiture introuvable";
    }
}

void MapOpenGL::setSimulation(Simulation* simul)
{
    simulation = simul;
}

void MapOpenGL::increaseZoom()
{
    if(maxZoom < zoom)
    {
        zoom += stepZoom;
    }
}
void MapOpenGL::decreaseZoom()
{
    if(minZoom > zoom)
    {
        zoom -= stepZoom;
    }
}

void MapOpenGL::paintGL()
{
    qDebug() << "Debut paint";
    paintMap();
    paintGrille();
    paintNodes();
    paintRoutes();
    paintVoitures();

    qDebug() << "Dessin Termine";
}

void MapOpenGL::paintMap()
{
    qDebug() << "Dessin Map";
    QPainter p(this);

    QRectF target( 0, 0, baseSizeX * zoom, baseSizeZ * zoom);
    p.drawImage( target, *car);

}


void MapOpenGL::paintGrille()
{
    qDebug() << "Dessin Grille";
    QPainter p(this);
    p.setPen(Qt::yellow);

    std::vector<Hexagon> hexagons = simulation->getGrid().getHexagons();
    for(unsigned long int i = 0; i < hexagons.size(); ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            p.drawLine(QLineF( hexagons[i][j].getX() * zoom,
                               hexagons[i][j].getY() * zoom,
                               hexagons[i][j+1].getX()*zoom,
                               hexagons[i][j+1].getY()*zoom));
        }
    }
}

void MapOpenGL::paintNodes()
{
    qDebug() << "Dessin Nodes";
    QPainter p(this);

    p.setPen(Qt::red);
    for(unsigned long int i = 0; i < simulation->getNodes().size(); ++i)
    {
        p.drawEllipse((simulation->getNodes()[i]->getX() - 3)*zoom,
                      (simulation->getNodes()[i]->getY() - 3)*zoom,
                      6, 6);
    }
}

void MapOpenGL::paintRoutes()
{
    qDebug() << "Dessin Routes";
    QPainter p(this);

    p.setPen(Qt::blue);
    for(unsigned long int i = 0; i< simulation->getRoutes().size(); ++i)
    {
        Node* node1 = simulation->getRoutes()[i]->getNode1();
        Node* node2 = simulation->getRoutes()[i]->getNode2();
        p.drawLine( QLineF( node1->getX()*zoom, node1->getY()*zoom,
                            node2->getX()*zoom, node2->getY()*zoom));
    }
}

void MapOpenGL::paintVoitures()
{
    qDebug() << "Dessin Voitures";
    QPainter p(this);

    vector<Car* > cars = simulation->getCars();
    for(unsigned long int i = 0; i< cars.size(); ++i)
    {
        Point point = cars[i]->getPosition();
        QRectF target((point.getX()-6)*zoom,
                      (point.getY()-6)*zoom,
                      12*zoom, 12*zoom);
        p.drawImage(target, *car);
    }
}