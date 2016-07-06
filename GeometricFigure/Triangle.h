#pragma once
#include"GeometricFigure.h"
#include <string>
class Triangle :public GeometricFigure{
	double a_x, a_y, b_x, b_y, c_x, c_y;
	bool checkTriangle(double a_x, double a_y, double b_x, double b_y, double c_x, double c_y){
		double CB = GeometricFigure::getLength(c_x, c_y, b_x, b_y);
		double BA = GeometricFigure::getLength(b_x, b_y, a_x, a_y);
		double AC = GeometricFigure::getLength(a_x, a_y, c_x, c_y);
		return (CB<BA + AC && BA<CB + AC && AC<CB + BA);
	}
public:
	class BadTriangleException :public std::exception{
	public:
		const char* what(){
			return "Bad triangle! Please,try to create an object again";
		}
	};
	Triangle(){
		a_x = a_y = b_x = b_y = c_x = c_y = 0;
	}
	Triangle(double a_x0, double a_y0, double b_x0, double b_y0, double c_x0, double c_y0){
		if (checkTriangle(a_x0, a_y0, b_x0, b_y0, c_x0, c_y0)){
			a_x = a_x0; a_y = a_y0;
			b_x = b_x0; b_y = b_y0;
			c_x = c_x0; c_y = c_y0;
		}
		else
			throw BadTriangleException();
	}
	double getPerimeter() const{
		double CB = GeometricFigure::getLength(c_x, c_y, b_x, b_y);
		double BA = GeometricFigure::getLength(b_x, b_y, a_x, a_y);
		double AC = GeometricFigure::getLength(a_x, a_y, c_x, c_y);
		return CB + BA + AC;
	}
	double getArea() const{
		double CB = GeometricFigure::getLength(c_x, c_y, b_x, b_y);
		double BA = GeometricFigure::getLength(b_x, b_y, a_x, a_y);
		double AC = GeometricFigure::getLength(a_x, a_y, c_x, c_y);
		double p = (CB + BA + AC) / 2;
		return sqrt(p*(p - CB)*(p - BA)*(p - AC));
	}
	void moveVertical(double n){
		a_y += n; b_y += n; c_y += n;
	}
	void moveHorizont(double n){
		a_x += n; b_x += n; c_x += n;
	}

	std::string Info()const{
		return "Triangle: A(" + std::to_string(a_x) + ',' + std::to_string(a_y) + "),B(" + std::to_string(b_x) + ',' + std::to_string(b_y) + "),C(" + std::to_string(c_x) + ',' + std::to_string(c_y) + ")\n";
	}
};
