class Point
{

private:

	int x;
	int y;

public:

	Point(int x, int y);
	Point();
	int X() const;
	int Y() const;
	void setX(int x);
	void setY(int y);
	double Distance(Point& p);

};

