#include "Hexagon.h"
#include <math.h>

int Hexagon::size = 40;//taille en pixel

Hexagon::Hexagon(const Point& p): p{p}, c{Color(0,0,0,64)}
{
}

void Hexagon::setColor(const Color& c) 
{
	this->c.setR(c.R());
	this->c.setG(c.G());
	this->c.setB(c.B());
	this->c.setAlpha(c.Alpha());
}

void Hexagon::setSize(int s) 
{
	Hexagon::size = s;
}

Color Hexagon::getColor() const 
{
	return this->c;
}

Point Hexagon::Position() {
	return this->p;
}

std::vector<Point> Hexagon::getPoints() const {
	
	std::vector<Point> tp;
	const double pi = 3.14159265358979323846;

	for (int i = 0; i < 6; i++) {

		Point v = Point{ static_cast<int>(p.X()*1.0 + size * cos((i*pi) / 3.0)),
						 static_cast<int>(p.Y()*1.0 + size * sin((i*pi) / 3.0)) };
		tp.push_back(v);
	}

	return tp;
}