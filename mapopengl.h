#ifndef MAPOPENGL_H
#define MAPOPENGL_H

#include <QOpenGLWidget>
#include "simulation.h"

class MapOpenGL : public QOpenGLWidget
{
    public :
        MapOpenGL(QWidget* parent = nullptr);

        virtual void initializeGL();
        virtual void paintGL();

        void setSimulation(Simulation* simul);
        void setSpeedSimulation(int speed);
        void increaseZoom();
        void decreaseZoom();
        void paintMap();
        void paintGrille();
        void paintNodes();
        void paintRoutes();
        void paintVoitures();
        void setHexagonColor(QColor qColor, int idHexagon);

    private :
        QImage* bg;
        QImage* car;
        Simulation* simulation;
        double zoom;
};

#endif // MAPOPENGL_H
