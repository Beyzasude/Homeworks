#include "Quadrilateral.h"
#include <iostream>
using namespace std;

Quadrilateral::Quadrilateral(const Point& a, const Point& c, const Color& color)
{
	setA(a);
	setC(c);
	pts[1].coords[0] = pts[0].coords[0];
	pts[1].coords[1] = pts[2].coords[1];

	pts[3].coords[0] = pts[2].coords[0];
	pts[3].coords[1] = pts[0].coords[1];

	this->color = color;
}

Quadrilateral::Quadrilateral(const Point& a, double width, double height, const Color& color)
{
	pts[1].coords[0] = pts[0].coords[0] + width;  
	pts[1].coords[1] = pts[0].coords[1];         

	pts[2].coords[0] = pts[0].coords[0] + width; 
	pts[2].coords[1] = pts[0].coords[1] - height; 

	pts[3].coords[0] = pts[0].coords[0];         
	pts[3].coords[1] = pts[0].coords[1] - height;  

	this->color = color;
}

Quadrilateral::Quadrilateral(const Point& a, const Point& b, const Point& c, const Point& d, const Color& color)
{
	setA(a);
	setB(b);
	setC(c);
	setD(d);
	this->color = color;
}

Quadrilateral::Quadrilateral(const array<Point, NUMBER_OF_CORNERS>& pts, const Color& color)
{
	setA(pts[0]);
	setB(pts[1]);
	setC(pts[2]);
	setD(pts[3]);
	this->color = color;
}

Point Quadrilateral::getA() const noexcept
{
	return pts[0];
}

Point Quadrilateral::getB() const noexcept
{
	return pts[1];
}

Point Quadrilateral::getC() const noexcept
{
	return  pts[2];
}

Point Quadrilateral::getD() const noexcept
{
	return  pts[3];
}

auto Quadrilateral::getColor() const noexcept
{
	return color;
}

string Quadrilateral::getColorAsString() const noexcept
{
	const map<Color, string> colorToStringMap = {
		{Quadrilateral::Color::RED, "Red"},
		{Quadrilateral::Color::BLUE, "Blue"},
		{Quadrilateral::Color::WHITE, "White"},
		{Quadrilateral::Color::BLACK, "Black"},
		{Quadrilateral::Color::GREEN, "Green"}
	};
	auto selectedColor{ Quadrilateral::color };
	return colorToStringMap.at(selectedColor);
}

double Quadrilateral::getPerimeter() const noexcept
{
	double k = sqrt(pow((pts[1].coords[0]) - (pts[0].coords[0]), 2) + pow((pts[1].coords[1]) - (pts[0].coords[1]), 2));
	double l = sqrt(pow((pts[3].coords[0]) - (pts[2].coords[0]), 2) + pow((pts[3].coords[1]) - (pts[2].coords[1]), 2));
	double m = sqrt(pow((pts[3].coords[0]) - (pts[0].coords[0]), 2) + pow((pts[3].coords[1]) - (pts[0].coords[1]), 2));
	double n = sqrt(pow((pts[2].coords[0]) - (pts[1].coords[0]), 2) + pow((pts[2].coords[1]) - (pts[1].coords[1]), 2));
	double a = k + l + m + n;
	return a;
}

bool Quadrilateral::isValid() const
{
	if ((a.x == b.x && a.x == c.x )|| (a.x == b.x && a.x == d.x) || (b.x = a.x && b.x == c.x) ||( b.x == a.x && b.x == d.x) || (c.x == a.x && c.x == b.x) || (c.x == a.x && c.x == d.x) || (d.x == a.x && d.x == b.x) || (d.x == a.x && d.x == c.x))

	return false;
}

bool Quadrilateral::setA(const Point& pt)
{
	pts[0].coords[0] = pt.coords[0];
	pts[0].coords[1] = pt.coords[1];
	return false;
}

bool Quadrilateral::setB(const Point& pt)
{
	pts[1].coords[0] = pt.coords[0];
	pts[1].coords[1] = pt.coords[1];
	return false;
}

bool Quadrilateral::setC(const Point& pt)
{
	pts[2].coords[0] = pt.coords[0];
	pts[2].coords[1] = pt.coords[1];
	return false;
}

bool Quadrilateral::setD(const Point& pt)
{
	pts[3].coords[0] = pt.coords[0];
	pts[3].coords[1] = pt.coords[1];
	return false;
}

double Quadrilateral::printInfo() const noexcept
{

	cout << "Quadrilateral" << endl << "  Number of points: 4" << endl << "points: " << (a.x, a.y) << ", " << (b.x, b.y) << ", " << (c.x, c.y) << ", " << (d.x, d.y) << endl << "primeter: " << getPerimeter() << endl << "color: " << getColorAsString() << endl;
}
