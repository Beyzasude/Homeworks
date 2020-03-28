#include "Triangle.h"
#include <iostream>
#include <cmath>
#include <map>
#include <array>
#include "Point.h"

using namespace std;

Triangle::Triangle(const Point& a, const Point& b, const Point& c, const Color& color)
{
	setA(a);
	setB(b);
	setC(c);
	this->color = color;
}

Triangle::Triangle(const vector<Point>& pts, const Color& color)
{
	setA(pts[0]);
	setB(pts[1]);
	setC(pts[2]);
	this->color = color;
	
}

Triangle::Triangle(const array<Point, NUMBER_OF_CORNERS>& pts, const Color& color)
{
	setA(pts[0]);
	setB(pts[1]);
	setC(pts[2]);
	this->color = color;
}

Point Triangle::getA() const noexcept
{
	return pts[0];
}

Point Triangle::getB() const noexcept
{
	return pts[1];
}

Point Triangle::getC() const noexcept
{
	return pts[2];
}

auto Triangle::getColor() const noexcept
{
	return color;
}

string Triangle::getColorAsString() const noexcept
{
	const map<Color, string>map = {
		{Triangle::Color::RED, "Red"},
		{Triangle::Color::BLUE, "Blue"},
		{Triangle::Color::WHITE, "White"},
		{Triangle::Color::BLACK, "Black"},
		{Triangle::Color::GREEN, "Green"}
	};
	auto selectedColor{ Triangle::color };
	return map.at(selectedColor);
}

double Triangle::getPerimeter() const noexcept
{
	 double x = sqrt(pow((pts[1].coords[0]) - (pts[0].coords[0]), 2) + pow((pts[1].coords[1]) - (pts[0].coords[1]), 2));
	 double y = sqrt(pow((pts[2].coords[0]) - (pts[1].coords[0]), 2) + pow((pts[2].coords[1]) - (pts[1].coords[1]), 2));
	 double z = sqrt(pow((pts[2].coords[0]) - (pts[0].coords[0]), 2) + pow((pts[2].coords[1]) - (pts[0].coords[1]), 2));
	 double s = x + y + z;
	return  s;
}

bool Triangle::setA(const Point& pt)
{
	pts[0].coords[0] = pt.coords[0];
	pts[0].coords[1] = pt.coords[1];
	return false;
}

bool Triangle::setB(const Point& pt)
{
	pts[1].coords[0] = pt.coords[0];
	pts[1].coords[1] = pt.coords[1];
	return false;
}

bool Triangle::setC(const Point& pt)
{
	pts[2].coords[0] = pt.coords[0];
	pts[2].coords[1] = pt.coords[1];
	return false;
}

bool Triangle::isValid() const
{
	int x = sqrt(pow((pts[1].coords[0]) - (pts[0].coords[0]), 2) + pow((pts[1].coords[1]) - (pts[0].coords[1]), 2));
	int y = sqrt(pow((pts[2].coords[0]) - (pts[1].coords[0]), 2) + pow((pts[2].coords[1]) - (pts[1].coords[1]), 2));
	int z = sqrt(pow((pts[2].coords[0]) - (pts[0].coords[0]), 2) + pow((pts[2].coords[1]) - (pts[0].coords[1]), 2));
	if ((x - y) < z && (x + y) > z && (z - y) < x && (z + y) > x && (z - x) < y && (z + x) > y)
		return true;
	else
		return false;
}

double Triangle::printInfo() const noexcept
{
   cout << "Triangle" << endl << "  Number of points: 3" << endl << "points: " << (a.x, a.y) << ", " << (b.x, b.y) << ", " << (c.x, c.y) << endl << "primeter: " << getPerimeter() << endl << "color: " << getColorAsString() << endl;
}
