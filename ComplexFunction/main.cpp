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

std::complex<double> func(std::complex<double> b, std::complex<double> c, std::complex<double> e,
                          std::complex<double> a, std::complex<double> d, std::complex<double> z){
    return (a * pow(z,2) + b * z + c) / (d * z + e);
}

class House {
public:
    House (double weigth, double height,
           double scale, double a):
    weigth_(weigth),
    height_(height),
    scale_(scale),
    a_(a ){}

    //передавать граф в параметрах
    void Draw() {
        {
            svg::PlotSVG graph("house.svg",(a_ * weigth_* weigth_)/scale_, height_/scale_);
            graph.line(0, height_ * 0.7, weigth_/2, height_, svg::COLOR_GREEN);
            graph.line(weigth_/2, height_, weigth_, height_*0.7, svg::COLOR_GREEN);
            graph.line(weigth_, height_*0.7, weigth_, 0, svg::COLOR_GREEN);
            graph.line(weigth_, 0, 0, 0, svg::COLOR_GREEN);
            graph.line(0, 0, 0, height_*0.7, svg::COLOR_GREEN);
            graph.line(weigth_*0.7, height_*0.6, weigth_*0.3, height_*0.6, svg::COLOR_GREEN);
            graph.line(weigth_*0.3, height_*0.6, weigth_*0.3, height_*0.2, svg::COLOR_GREEN);
            graph.line(weigth_*0.3, height_*0.2, weigth_*0.7, height_*0.2, svg::COLOR_GREEN);
            graph.line(weigth_*0.7, height_*0.2, weigth_*0.7, height_*0.6, svg::COLOR_GREEN);
            graph.point(0, 0, "red");
            graph.point(weigth_*0.7, height_*0.6, "red");
            graph.point(weigth_*0.3, height_*0.2, "red");
            graph.point(weigth_*0.3, height_*0.6, "red");
            graph.point(weigth_*0.7, height_*0.2, "red");
            graph.point(0, height_ * 0.7, "red");
            graph.point(weigth_, 0, "red");
            graph.point(weigth_, height_* 0.7, "red");
            graph.point(0,height_* 0.7, "red");
            graph.point(weigth_ / 2, height_, "red");

        }
        system("convert house.svg house.jpg");
        cv::Mat image = cv::imread("house.jpg");
        cv::imshow( WINDOW_NAME, image );
    }

    double weigth_;
    double height_;
    double scale_;
    double a_;
};

/// Global Variables
///
//TODO : Extract UI to sepatate
const int alpha_slider_max =10;
int alpha_slider = 1;
double alpha = 1;
double beta = 0;


typedef std::function<void(int val)> ChangeFunc;

void on_changed( int val, void* user_data ) {
    assert(user_data);
    ChangeFunc* func = reinterpret_cast<ChangeFunc*>(user_data);
    (*func)(val);
}


int main() {
    cv::namedWindow(WINDOW_NAME);

    House house(1,1,0.9,1);
    ChangeFunc on_scale_change = [&house] (int val){
        house.scale_ = (val+1)/10.0;
        house.Draw();
    };

    ChangeFunc on_a_change = [&house] (int val){
        house.a_ = (val)/10.0;
        house.Draw();
    };

    cv::createTrackbar( "a ", WINDOW_NAME, &alpha_slider, alpha_slider_max, on_changed,
                        &on_a_change);
//    cv::createTrackbar( "b ", WINDOW_NAME, &alpha_slider, alpha_slider_max, on_changed,
//                        &on_b_change);
//    cv::createTrackbar( "c ", WINDOW_NAME, &alpha_slider, alpha_slider_max, on_changed,
//                        &on_c_change);

    cv::createTrackbar( "scale ", WINDOW_NAME, &alpha_slider, alpha_slider_max, on_changed,
                        &on_scale_change);
    house.Draw();
    cv::waitKey(0);

    return 0;
}

