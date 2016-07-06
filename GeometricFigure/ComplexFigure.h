#include"GeometricFigure.h"
#include"Circle.h"
#include"Triangle.h"
#include"Rhombus.h"
#include"Rectangle.h"
#include"Trapeze.h"
#include <vector>
#include <iostream>
class ComplexFigure{
	std::vector<GeometricFigure*>compfig;
public:
	~ComplexFigure();
	void addCircle(double center_x0, double center_y0, double radius0);
	void addTriangle(double a_x0, double a_y0, double b_x0, double b_y0, double c_x0, double c_y0);
	void addRhombus(double a_x0, double a_y0, double b_x0, double b_y0, double c_x0, double c_y0, double d_x0, double d_y0);
	void addRectangle(double a_x0, double a_y0, double b_x0, double b_y0, double c_x0, double c_y0, double d_x0, double d_y0);
	void addTrapeze(double a_x0, double a_y0, double b_x0, double b_y0, double c_x0, double c_y0, double d_x0, double d_y0);
	void del(unsigned number);
	double getPerimeter() const;
	double getArea() const;
	void moveVertical(double n);
	void moveHorizontal(double n);
	void menu();
	void Info();
};

void ComplexFigure::addCircle(double center_x0, double center_y0, double radius0){
	compfig.push_back(new Circle(center_x0, center_y0, radius0));
}

void ComplexFigure::addTriangle(double a_x0, double a_y0, double b_x0, double b_y0, double c_x0, double c_y0){
	compfig.push_back(new Triangle(a_x0, a_y0, b_x0, b_y0, c_x0, c_y0));
}

void ComplexFigure::addRhombus(double a_x0, double a_y0, double b_x0, double b_y0, double c_x0, double c_y0, double d_x0, double d_y0){
	compfig.push_back(new Rhombus(a_x0, a_y0, b_x0, b_y0, c_x0, c_y0, d_x0, d_y0));
}
void ComplexFigure::addRectangle(double a_x0, double a_y0, double b_x0, double b_y0, double c_x0, double c_y0, double d_x0, double d_y0){
	compfig.push_back(new Rectangle(a_x0, a_y0, b_x0, b_y0, c_x0, c_y0, d_x0, d_y0));
}

void ComplexFigure::addTrapeze(double a_x0, double a_y0, double b_x0, double b_y0, double c_x0, double c_y0, double d_x0, double d_y0){
	compfig.push_back(new Trapeze(a_x0, a_y0, b_x0, b_y0, c_x0, c_y0, d_x0, d_y0));
}
void ComplexFigure::del(unsigned number)
{
	if (number >= compfig.size()) throw std::exception();
	delete compfig[number];
	compfig.erase(compfig.begin() + number);
}
ComplexFigure::~ComplexFigure()
{
	for (unsigned i = 0; i<compfig.size(); i++)
		delete compfig[i];
}

void ComplexFigure::menu()
{
	char c;
	unsigned number;
	double center_x0, center_y0, radius0;
	double a_x0, a_y0, b_x0, b_y0, c_x0, c_y0, d_x0, d_y0;
	std::string line;
	std::vector <std::string> p;
	do
	{
		std::cout << "1. Add circle" << std::endl;
		std::cout << "2. Add triangle" << std::endl;
		std::cout << "3. Add rhombus" << std::endl;
		std::cout << "4. Add rectangle" << std::endl;
		std::cout << "5. Add trapeze" << std::endl;
		std::cout << "6. Delete" << std::endl;
		std::cout << "7. Move vertical" << std::endl;
		std::cout << "8. Move horizontal" << std::endl;
		std::cout << "9. Info" << std::endl;
		std::cout << "0. Exit " << std::endl;
		std::cin >> c;

		try
		{
			switch (c)
			{
				
			case '1':
					std::cout << "Enter the coordinates of the center and radius" << std::endl;
					std::cin >> center_x0 >> center_y0 >> radius0;
					addCircle(center_x0, center_y0, radius0);
					break;
			case '2':
					std::cout<<"Enter the coordinates of the three vertices" << std::endl;
					std::cin >> a_x0 >> a_y0 >> b_x0 >> b_y0 >> c_x0 >> c_y0;
					addTriangle(a_x0, a_y0, b_x0, b_y0, c_x0, c_y0);
					break;
			case '3':
					std::cout<<"Enter the coordinates of the four vertices" << std::endl;
					std::cin >> a_x0 >> a_y0 >> b_x0 >> b_y0 >> c_x0 >> c_y0 >> d_x0 >> d_y0;
					addRhombus(a_x0, a_y0, b_x0, b_y0, c_x0, c_y0, d_x0, d_y0);
					break;
			case '4':
					std::cout<<"Enter the coordinates of the four vertices" << std::endl;
					std::cin >> a_x0 >> a_y0 >> b_x0 >> b_y0 >> c_x0 >> c_y0 >> d_x0 >> d_y0;
					addRectangle(a_x0, a_y0, b_x0, b_y0, c_x0, c_y0, d_x0, d_y0);
					break;
			case '5':
					std::cout<<"Enter the coordinates of the four vertices" << std::endl;
					std::cin >> a_x0 >> a_y0 >> b_x0 >> b_y0 >> c_x0 >> c_y0 >> d_x0 >> d_y0;
					addTrapeze(a_x0, a_y0, b_x0, b_y0, c_x0, c_y0, d_x0, d_y0);
					break;
			case '6':
					std::cin >>number; 
					del(number);
					break;
			case '7':
					std::cin >> a_x0;
					moveVertical(a_x0);
					break;
			case '8':
					std::cin >> a_x0;
					moveHorizontal(a_x0);
			case '9':
					Info();
					break;
			}
		}
		catch (const std::exception &)
		{
			std::cout << "Error!!! Please,try to create an object again" << std::endl;
		}
	} while (c != '0');
}

double ComplexFigure::getPerimeter()const{
	double summ = 0;
	for (unsigned i = 0; i < compfig.size(); i++)
		summ += compfig[i]->getPerimeter();
	return summ;
}

double ComplexFigure::getArea()const{
	double summ = 0;
	for (unsigned i = 0; i < compfig.size(); i++)
		summ += compfig[i]->getArea();
	return summ;
}

void ComplexFigure::moveHorizontal(double n){
	for (unsigned i = 0; i < compfig.size(); i++)
		compfig[i]->moveHorizont(n);
}

void ComplexFigure::moveVertical(double n){
	for (unsigned i = 0; i < compfig.size(); i++)
		compfig[i]->moveVertical(n);
}

void ComplexFigure::Info(){
	for (unsigned i = 0; i < compfig.size(); i++)
		std::cout << compfig[i]->Info();
	std::cout << "Perimeter=" << ComplexFigure::getPerimeter() << std::endl << "Area=" << ComplexFigure::getArea() << std::endl;
	std::cout << std::endl;
}