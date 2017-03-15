#ifndef SVG_GRAPH_H
#define SVG_GRAPH_H

//#include <complex>
//#include <cmath>
#include <fstream>
#include <assert.h>
#include <sstream>
#include <map>
#include <string>
namespace svg {
const std::string  XML_HEADER = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>";

enum SVGColor{
    COLOR_RED,
    COLOR_BLUE,
    COLOR_GREEN
};

static std::map<SVGColor, std::string> m = {{COLOR_RED, "stroke:rgba(250, 0, 0, 255);"},
                                               {COLOR_BLUE, "stroke:rgba(0, 0, 250, 255);"},
                                               {COLOR_GREEN, "stroke:rgba(0, 250, 0, 255);"}};

std::string create_svg_header(int w, int h ) {
    std::stringstream ss;
    ss <<  "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" ";
    ss << " height=\"" << h <<"\"";
    ss << " width=\"" << h <<"\"";
    ss << " id=\"3d-graph\" style=\"";
    ss << "height: " << h << "px; width:" << w << "px; margin: 0 auto; padding: 5px;\">";
    return ss.str();
}

static int radius = 1;
class SVGGraph {

public:

    SVGGraph(const std::string& file, int weight, int height)
        :file_stream_(file.c_str()),
        weight_(weight), height_(height) {
        assert(file_stream_.is_open());
        file_stream_ << XML_HEADER << create_svg_header(weight, height) << std::endl;
    }

    ~SVGGraph() {
        file_stream_ << "</svg>" << std::endl;
        file_stream_.close();
    }

    virtual void line(int x1, int y1, int x2, int y2, SVGColor color) {

        file_stream_ << std::endl;
        file_stream_ << "<line ";
        file_stream_ << " x1= \"" << x1 <<"\"";
        file_stream_ << " y1= \"" << y1 <<"\"";
        file_stream_ << " x2= \"" << x2 <<"\"";
        file_stream_ << " y2= \"" << y2 <<"\"";
        file_stream_ << " style = \"" << m[color] << "stroke-width:2" << "\"/>";
        file_stream_ << std::endl;

    }

    virtual void point(int x, int y, std::string color_point){
        file_stream_ << std::endl;
        file_stream_ << "<circle ";
        file_stream_ << " cx= \"" << x << "\"";
        file_stream_ << " cy= \"" << y << "\"";
        file_stream_ << " r = \"" << radius << "\"";
        file_stream_ << " stroke= \"" << color_point << "\"";
        file_stream_ << " stroke-width=\"3\" fill=\"none\" />";
    }

    std::ofstream file_stream_;
    int weight_;
    int height_;

};

static int kweight = 500;
static int kheight = 500;

class PlotSVG {
private:
    SVGGraph graph;
    double x_max_;
    double y_max_;

public:
    PlotSVG(const std::string& file, double x_max, double y_max)
        :graph(file, kweight, kheight), x_max_(x_max), y_max_(y_max){
        line(-x_max_, 0, x_max_, 0, COLOR_BLUE);
        line(0, -y_max_, 0, y_max_, COLOR_BLUE);
        point(0, 0, "black");
    }

    void point (double x, double y, std::string color_point) {
        // TODO : Add color with default parameter
        x = x + x_max_;
        x = x * (kweight / (x_max_ * 2 ));
        y = y_max_ - y;
        y = y * (kheight / (y_max_ * 2 ));
        graph.point(x, y, color_point);
    }

    void line(double x1, double y1, double x2, double y2, SVGColor color) {
        // TODO : Add color with default parameter
        // TODO : Extract transform to pixel
        // TODO : Extract move to positive functions

        move_coordinates_x(x1, x2);
        move_coordinates_y(y1, y2);
        transform(x1, y1, x2, y2);

        std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << std::endl;
        graph.line(x1, y1, x2, y2, color);
    }

    void move_coordinates_x(double& x1, double& x2){
        x1 = x1 + x_max_;
        x2 = x2 + x_max_;
    }

    void move_coordinates_y( double& y1, double& y2){
        y1 = y_max_ - y1;
        y2 = y_max_ - y2;
    }

    void transform(double& x1, double& y1, double& x2, double& y2){
        x1 = x1 * (kweight / (x_max_ * 2 ));
        x2 = x2 * (kweight / (x_max_ * 2 ));
        y1 = y1 * (kheight / (y_max_ * 2 ));
        y2 = y2 * (kheight / (y_max_ * 2 ));
    }


};

}

#endif // SVG_GRAPH_H

