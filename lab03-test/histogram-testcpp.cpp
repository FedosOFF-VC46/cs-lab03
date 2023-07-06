#include <iostream>
#include "histogram-test.h"
#include <vector>
#include <cassert>

using namespace std;

void test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({ 1, 2, 3 }, min, max);
    assert(min == 1);
    assert(max == 3);
}

void test_negative() {
    double min = 0;
    double max = 0;
    find_minmax({ -2, -1, -3 }, min, max);
    assert(min == -3);
    assert(max == -1);

}
void equal() {
    double min = 0;
    double max = 0;
    find_minmax({ 3, 3, 3 }, min, max);
    assert(min == 3);
    assert(max == min);

}
void one_num() {
    double min = 0;
    double max = 0;
    find_minmax({ 1 }, min, max);
    assert(min == 1);
    assert(max == 1);

}
void test_void() {
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}

void find_minmax(vector<double> numbers, double& min, double& max) {
    if (numbers.size() == 0)
        return;
    else {
        min = numbers[0];
        max = numbers[0];
        if (numbers.size() == 0)
        {
            return;
        }
        for (double number : numbers) {
            if (min > number) min = number;
            if (max < number) max = number;
        }
    }
}

void up_line(double x1, double y1, double x2, double y2, string stroke, double strong_width, string stroke_dasharray) {
    cout << "<line x1='" << x1 << "' y1='" << y1 << "' x2='" << x2 << "' y2='" << y2 << "' stroke='" << stroke << "' stroke-width='" << "' stroke-dasharray='" << stroke_dasharray << "'/>";
}

bool yes_or_no(string dashed)
{
    if (dashed == "0")
        return false;
    else
        return true;
}

void histogram_lines(double IMAGE_WIDTH, double IMAGE_HEIGHT, string dashed)
{
    if (yes_or_no(dashed) == true) {
        up_line(30, 0, IMAGE_WIDTH, 0, "#474A51", 4, dashed);
        up_line(IMAGE_WIDTH - 50, 0, IMAGE_WIDTH - 50, IMAGE_HEIGHT - 50, "#474A51", 4, dashed);
        up_line(IMAGE_WIDTH - 50, IMAGE_HEIGHT - 50, 30, IMAGE_HEIGHT - 50, "#474A51", 4, dashed);
        up_line(30, IMAGE_HEIGHT - 50, 30, 0, "#474A51", 4, dashed);
    }
    else return;
}

void test_dashed() {
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 700;
    string dashed = "0";
    histogram_lines(IMAGE_WIDTH, IMAGE_HEIGHT, dashed);
    assert(dashed == "10 10");
}

int
main() {
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 700;
    test_positive();
    test_negative();
    equal();
    one_num();
    test_void();
    test_dashed();
}