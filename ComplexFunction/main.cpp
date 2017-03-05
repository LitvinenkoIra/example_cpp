#include <iostream>
#include <complex>
#include <cmath>
#include <fstream>
#include <assert.h>
#include <sstream>
#include <stdlib.h>
#include <functional>
#include "svg_graph.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdexcept>


std::string WINDOW_NAME = "Win name";


//using namespace std;
//void generate(std::complex<double> result){
//    static std::complex<double> previous_result = 0 + 0i;
//    cout << "<line x1=\"" << previous_result.real() << "\" y1=\"" << previous_result.imag()
//         << "\" x2=\"" << result.real() << "\" y2=\"" << result.imag() << "\" style=\"stroke:rgba(250,200,200,0.5);stroke-width:2\"/>" << std::endl;
//    previous_result = result;
//}

class FuncR {
public:
    FuncR():
        a_(1),
        b_(1),
        c_(1),
        d_(1),
        e_(1) {

    }

    void Draw() {
        {
            svg::SVGGraphMoved graph("test.svg", 600, 600);
            double old_y = 0;
            try {
              old_y = func(0);
            }catch (std::exception E){
                std::cout << E.what() << std::endl;
            }
            double inc = 5;
            for (double z = -200; z < 200; z += inc) {
                try {
                    double y = func(z);
                    graph.line(z - inc, old_y, z , y);
                    std::cout << " z = " << z << " y = " << y << std::endl;
                    old_y = y;
                } catch (std::exception E){
                   std::cout << E.what() << std::endl;
                }
            }
        }
        system("convert test.svg test.jpg");
        cv::Mat image = cv::imread("test.jpg");
        cv::imshow( WINDOW_NAME, image );
    }

    double func(double z) {
        if ((d_ * z + e_) == 0){
            throw std::overflow_error("Divide by zero exception");
        }

        return (a_ * pow(z, 2) + b_ * z + c_) / (d_ * z + e_);
    }

    double a_;
    double b_;
    double c_;
    double d_;
    double e_;
};

std::complex<double> func(std::complex<double> b, std::complex<double> c, std::complex<double> e,
                          std::complex<double> a, std::complex<double> d, std::complex<double> z){
    return (a * pow(z,2) + b * z + c) / (d * z + e);
}



/// Global Variables
const int alpha_slider_max =500;
int alpha_slider = 1;
double alpha = 1;
double beta = 0;
///**
// * @function on_trackbar
// * @brief Callback for trackbar
// */
void on_a_changed( int val, void* user_data ) {
    assert(user_data);
    FuncR* func = reinterpret_cast<FuncR*>(user_data);
    func->a_ =  val;
    func->Draw();
}

void on_b_changed( int val, void* user_data ) {
    assert(user_data);
    FuncR* func = reinterpret_cast<FuncR*>(user_data);
    func->b_ =  val;
    func->Draw();
}

void on_c_changed( int val, void* user_data ) {
    assert(user_data);
    FuncR* func = reinterpret_cast<FuncR*>(user_data);
    func->c_ =  val;
    func->Draw();
}

void on_d_changed( int val, void* user_data ) {
    assert(user_data);
    FuncR* func = reinterpret_cast<FuncR*>(user_data);
    func->d_ =  val;
    func->Draw();
}

void on_e_changed( int val, void* user_data ) {
    assert(user_data);
    FuncR* func = reinterpret_cast<FuncR*>(user_data);
    func->e_ =  val;
    func->Draw();
}



//void on_changed( int val, void* user_data ) {
//   assert(user_data);
//   FuncR* func = reinterpret_cast<FuncR*>(user_data);
//   func->Draw();
//}


int main() {
    FuncR function;
    cv::namedWindow(WINDOW_NAME);

    cv::createTrackbar( "a ", WINDOW_NAME, 0, alpha_slider_max, on_a_changed
                        ,&function);
    cv::createTrackbar( "b ", WINDOW_NAME, 0, alpha_slider_max, on_b_changed,
                        &function);
    cv::createTrackbar( "c ", WINDOW_NAME, 0, alpha_slider_max, on_c_changed,
                        &function);
    cv::createTrackbar( "d ", WINDOW_NAME, 0, alpha_slider_max, on_d_changed,
                        &function);
    cv::createTrackbar( "e ", WINDOW_NAME, 0, alpha_slider_max, on_e_changed,
                        &function);
    on_a_changed(alpha_slider, &function);


    function.Draw();
    cv::waitKey(0);
    //    while (true) {
    //        double a;

    //        cv::waitKey(0);
    //    }
    return 0;
    //    std::complex<double> end = 50. + 100i;
    //    std::complex<double> step = 1 + 1i;
    //    std::complex<double> a, b, c, d, e;
    //    a = 5 + 3i;
    //    b = 1 + 1i;
    //    c = 2 + 2i;
    //    d = 1 + 1i;
    //    std::complex<double> z = 40. + 10i;
    //    std::complex<double> result;
    //    while((z.real() < end.real()) && z.imag() < end.imag()){
    //        result = func(b, c, e, a, d, z);
    //        z = z + step;
    //        generate(result);
    //    }
    //    return 0;
}

