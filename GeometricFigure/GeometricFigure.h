#pragma once
#include <exception>
#include <cmath>
#include <string>
static const double pi = 3.14159265358979323846;
class GeometricFigure{
public:
	virtual double getPerimeter() const = 0;
	virtual double getArea() const = 0;
	virtual void moveVertical(double n) = 0;
	virtual void moveHorizont(double n) = 0;
	virtual std::string Info()const = 0;
	static double getLength(double ax, double ay, double bx, double by){
		return sqrt((bx - ax)*(bx - ax) + (by - ay)*(by - ay));
	}
};