#ifndef SVG_GRAPH_H
#define SVG_GRAPH_H

//#include <complex>
//#include <cmath>
#include <fstream>
#include <assert.h>
#include <sstream>
namespace svg {
const std::string  XML_HEADER = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>";

std::string create_svg_header(int w, int h ) {
    std::stringstream ss;
    ss <<  "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" ";
    ss << " height=\"" << h <<"\"";
    ss << " width=\"" << h <<"\"";
    ss << " id=\"3d-graph\" style=\"";
    ss << "height: " << h << "px; width:" << w << "px; margin: 0 auto; padding: 5px;\">";
    return ss.str();
}

class SVGGraph {
public:
    SVGGraph(const std::string& file, int weight, int height)
        :file_stream_(file.c_str()),
          style_("stroke:rgba(250, 0, 0, 255);stroke-width:2"),
        weight_(weight), height_(height) {
        assert(file_stream_.is_open());
        file_stream_ << XML_HEADER << create_svg_header(weight, height) << std::endl;
    }

    ~SVGGraph() {
        file_stream_ << "</svg>" << std::endl;
        file_stream_.close();
    }

    virtual void line(int x1, int y1, int x2, int y2) {

        file_stream_ << std::endl;
        file_stream_ << "<line ";
        file_stream_ << " x1= \"" << x1 <<"\"";
        file_stream_ << " y1= \"" << y1 <<"\"";
        file_stream_ << " x2= \"" << x2 <<"\"";
        file_stream_ << " y2= \"" << y2 <<"\"";
        file_stream_ << " style = \"" << style_ << "\"/>";
        file_stream_ << std::endl;

    }

    std::string style_;
    std::ofstream file_stream_;
    int weight_;
    int height_;
};

class SVGGraphMoved : public SVGGraph {
public:
    SVGGraphMoved(const std::string& file, int weight, int height)
        :SVGGraph(file, weight, height){}

    void line(int x1, int y1, int x2, int y2) override{
        x1 += (weight_/2);
        x2 += (weight_/2);
        y1 += (height_/2);
        y2 += (height_/2);
        SVGGraph::line(x1, y1, x2, y2);

    }
};

}

#endif // SVG_GRAPH_H

