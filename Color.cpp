#include "Color.h"

Color::Color(int r, int g, int b, int a): r(r), g(g), b(b), alpha(a)
{
}

Color::Color(int r, int g, int b) : r(r), g(g), b(b), alpha(255)
{
}

Color::Color(const Color& c, int a) : r(c.r), g(c.g), b(c.b), alpha(a)
{
}

Color::Color(const Color& c) : r(c.r), g(c.g), b(c.b), alpha(c.alpha)
{
}

int Color::R() const 
{
	return this->r;
}

int Color::G() const 
{
	return this->g;
}

int Color::B() const 
{
	return this->b;
}

int Color::Alpha() const 
{
	return this->alpha;
}

void Color::setR(int r) 
{
	this->r = r;
}

void Color::setG(int g) 
{
	this->g = g;
}

void Color::setB(int b) 
{
	this->b = b;
}

void Color::setAlpha(int alpha) {
	this->alpha = alpha;
}