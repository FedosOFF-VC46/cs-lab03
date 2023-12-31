#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include "svg.h"
using namespace std;


void svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='-50 -50 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end() {
    cout << "</svg>\n";
}
void svg_text(double left, double baseline, string text, double font_size) {
    cout << "<text x='" << left << "' y='" << baseline << "' font-size='" << font_size << "'>'" << text << "'</text>";
}
void svg_rect(double x, double y, double width, double height, string stroke, string fill) {
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height << "' stroke='" << stroke << "' fill='" << fill << "'></rect>\n";

}
void up_line(double x1, double y1, double x2, double y2, string stroke, double strong_width, string stroke_dasharray) {
    cout << "<line x1='" << x1 << "' y1='" << y1 << "' x2='" << x2 << "' y2='" << y2 << "' stroke='" << stroke << "' stroke-width='" << "' stroke-dasharray='" << stroke_dasharray << "'/>";
}

void histogram_lines(double IMAGE_WIDTH, double IMAGE_HEIGHT, string dashed)
{
    up_line(30, 0, IMAGE_WIDTH, 0, "#474A51", 4, "10 10");
    up_line(IMAGE_WIDTH - 50, 0, IMAGE_WIDTH - 50, IMAGE_HEIGHT - 50, "#474A51", 4, "10 10");
    up_line(IMAGE_WIDTH - 50, IMAGE_HEIGHT - 50, 30, IMAGE_HEIGHT - 50, "#474A51", 4, "10 10");
    up_line(30, IMAGE_HEIGHT - 50, 30, 0, "#474A51", 4, dashed);
}

void show_histogram_svg(const vector<size_t> bins, size_t height_bin) {
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 700;
    const auto TEXT_LEFT = 40;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BLOCK_WIDTH = 10;
    string dashed = "0";
    const auto HISTOGRAM_MAX_WIDTH = IMAGE_WIDTH - TEXT_LEFT - TEXT_WIDTH;
    size_t max_bin = bins[0];
    test_height(height_bin, bins.size(), IMAGE_HEIGHT);
    for (size_t bin : bins) {
        if (max_bin < bin) max_bin = bin;
    }

    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;
    
    for (size_t bin : bins) {
        size_t height = bin;
        if (max_bin * BLOCK_WIDTH > HISTOGRAM_MAX_WIDTH) {
            height = HISTOGRAM_MAX_WIDTH * (static_cast<double> (bin) / (max_bin * BLOCK_WIDTH));
        }
        const double bin_width = BLOCK_WIDTH * height;
        double font_size = height_bin / 2;
        svg_text(TEXT_LEFT, top + height_bin / 2, to_string(bin), font_size);
        svg_rect(TEXT_WIDTH + height_bin, top, bin_width, height_bin, "#474A51", "#DC143C");
        top += height_bin;
    }

    histogram_lines(IMAGE_WIDTH, IMAGE_HEIGHT, dashed);

    svg_end();
}

void test_height(size_t& height_bin, size_t bins_count, const size_t IMAGE_HEIGHT) {
    if (height_bin * bins_count > IMAGE_HEIGHT) {
        height_bin = (IMAGE_HEIGHT / bins_count);
    }
}