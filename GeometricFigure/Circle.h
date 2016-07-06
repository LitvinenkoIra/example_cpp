#pragma once
#include "GeometricFigure.h"
#include <string>
#include <exception>
class Circle :public GeometricFigure{
	double center_x, center_y, radius;
	bool check(double radius){
		return (radius>0);
	}

public:
	class BadCircleException :public std::exception{
	public:
		const char* what(){
			return "Bad circle! Please,try to create an object again";
		}
	};
	Circle() :GeometricFigure(){
		radius = center_x = center_y = 0;
	}
	Circle(double center_x0, double center_y0, double radius0){
		if (check(radius0)){
			center_x = center_x0;
			center_y = center_y0;
			radius = radius0;
		}
		else
			throw BadCircleException();
	}
	double getPerimeter() const{
		return 2 * pi*radius;
	}
	double getArea() const{
		return pi*radius*radius;
	}
	void moveVertical(double n){
		center_y += n;
	}
	void moveHorizont(double n){
		center_x += n;
	}
	std::string Info()const{
		return "Circle: Radius=" + std::to_string(radius) + ',' + "Center:(" + std::to_string(center_x) + ',' + std::to_string(center_y) + ")\n";
	}
};
