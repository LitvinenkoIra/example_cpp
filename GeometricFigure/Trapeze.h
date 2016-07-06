#pragma once
#include"Quadrangle.h"
#include <string>
class Trapeze :public Quadrangle{
	bool checkTrapeze(double a_x, double a_y, double b_x, double b_y, double c_x, double c_y, double d_x, double d_y){
		double k1 = (b_y - c_y) / (c_x - b_x);
		double k2 = (a_y - d_y) / (d_x - a_x);
		double k3 = (a_y - b_y) / (b_x - a_x);
		double k4 = (c_y - d_y) / (d_x - c_x);
		return ((k1 == k2&&k3 != k4) || (k3 == k4&&k1 != k2));
	}
public:
	class BadTrapezeException :public std::exception{
	public:
		const char* what(){
			return "Bad trapeze! Please,try to create an object again";
		}
	};
	Trapeze() :Quadrangle(){}
	Trapeze(double a_x0, double a_y0, double b_x0, double b_y0, double c_x0, double c_y0, double d_x0, double d_y0) :Quadrangle(a_x0, a_y0, b_x0, b_y0, c_x0, c_y0, d_x0, d_y0){
		if (!checkTrapeze(a_x0, a_y0, b_x0, b_y0, c_x0, c_y0, d_x0, d_y0))
			throw BadTrapezeException();
	}
	double getPerimeter(){
		return Quadrangle::getPerimeter();
	}
	double getArea() const{
		double CB = GeometricFigure::getLength(c_x, c_y, b_x, b_y);
		double BA = GeometricFigure::getLength(b_x, b_y, a_x, a_y);
		double AD = GeometricFigure::getLength(a_x, a_y, d_x, d_y);
		double DC = GeometricFigure::getLength(d_x, d_y, c_x, c_y);
		return 0.5*(AD + CB)*sqrt(BA*BA - ((((AD - CB)*(AD - CB) + BA*BA - DC*DC) / (2 * (AD - CB)))*(((AD - CB)*(AD - CB) + BA*BA - DC*DC) / (2 * (AD - CB)))));
	}
	void moveVertical(double n){
		Quadrangle::moveVertical(n);
	}
	void moveHorizont(double n){
		Quadrangle::moveHorizont(n);
	}
	std::string Info()const{
		return "Trapeze: A(" + std::to_string(a_x) + ',' + std::to_string(a_y) + "),B(" + std::to_string(b_x) + ',' + std::to_string(b_y) + "),C(" + std::to_string(c_x) + ',' + std::to_string(c_y) + "),D(" + std::to_string(d_x) + ',' + std::to_string(d_y) + ")\n";
	}
};