#pragma once
#include"GeometricFigure.h"
class Quadrangle :public GeometricFigure{
public:
	double a_x, a_y, b_x, b_y, c_x, c_y, d_x, d_y;
	Quadrangle(){
		a_x = a_y = b_x = b_y = c_x = c_y = d_x = d_y = 0;
	}
	Quadrangle(double a_x0, double a_y0, double b_x0, double b_y0, double c_x0, double c_y0, double d_x0, double d_y0) :GeometricFigure(){
		a_x = a_x0; a_y = a_y0;
		b_x = b_x0; b_y = b_y0;
		c_x = c_x0; c_y = c_y0;
		d_x = d_x0; d_y = d_y0;
	}
	double getPerimeter() const{
		double CB = GeometricFigure::getLength(c_x, c_y, b_x, b_y);
		double BA = GeometricFigure::getLength(b_x, b_y, a_x, a_y);
		double AD = GeometricFigure::getLength(a_x, a_y, d_x, d_y);
		double DC = GeometricFigure::getLength(d_x, d_y, c_x, c_y);
		return CB + BA + AD + DC;
	}
	void moveVertical(double n){
		a_y += n; b_y += n; c_y += n; d_y += n;
	}
	void moveHorizont(double n){
		a_x += n; b_x += n; c_x += n; d_x += n;
	}
};
