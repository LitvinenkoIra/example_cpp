#include "Quadrangle.h"
#include <string>
class Rhombus :public Quadrangle{
	bool checkRhombus(double a_x, double a_y, double b_x, double b_y, double c_x, double c_y, double d_x, double d_y){
		double CB = GeometricFigure::getLength(c_x, c_y, b_x, b_y);
		double BA = GeometricFigure::getLength(b_x, b_y, a_x, a_y);
		double AD = GeometricFigure::getLength(a_x, a_y, d_x, d_y);
		double DC = GeometricFigure::getLength(d_x, d_y, c_x, c_y);
		double k1 = (b_y - a_y) / (b_x - a_x);
		double k2 = (c_y - b_y) / (c_x - b_x);
		double k3 = (d_y - c_y) / (d_x - c_x);
		double k4 = (a_y - d_y) / (a_x - d_x);;
		return (CB == BA&&CB == AD&&CB == DC&&k1 == k3&&k2 == k4);
	}
public:
	class BadRhombusException :public std::exception{
	public:
		const char* what(){
			return "Bad rhombus! Please,try to create an object again";
		}
	};
	Rhombus() :Quadrangle(){}
	Rhombus(double a_x0, double a_y0, double b_x0, double b_y0, double c_x0, double c_y0, double d_x0, double d_y0) :Quadrangle(a_x0, a_y0, b_x0, b_y0, c_x0, c_y0, d_x0, d_y0){
		if (!checkRhombus(a_x0, a_y0, b_x0, b_y0, c_x0, c_y0, d_x0, d_y0))
			throw BadRhombusException();
	}

	double getPerimeter(){
		return Quadrangle::getPerimeter();
	}
	double getArea()const{
		double AC = GeometricFigure::getLength(a_x, a_y, c_x, c_y);
		double BD = GeometricFigure::getLength(b_x, b_y, d_x, d_y);
		return 0.5*AC*BD;
	}
	void moveVertical(double n){
		Quadrangle::moveVertical(n);
	}
	void moveHorizont(double n){
		Quadrangle::moveHorizont(n);
	}
	std::string Info()const{
		return "Rhombus: A(" + std::to_string(a_x) + ',' + std::to_string(a_y) + "),B(" + std::to_string(b_x) + ',' + std::to_string(b_y) + "),C(" + std::to_string(c_x) + ',' + std::to_string(c_y) + "),D(" + std::to_string(d_x) + ',' + std::to_string(d_y) + ")\n";
	}
};