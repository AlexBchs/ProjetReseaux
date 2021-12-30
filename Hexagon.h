#include "Point.h";
#include "Color.h";

class Hexagon
{

private:

	Point p;
	Color c;

public:

	static int size;
	Hexagon(const Point& p);
	void setColor(const Color& col);
	static void setSize(int s);
	Color getColor() const;
	Point Position();
	std::vector<Point> getPoints() const;
};

