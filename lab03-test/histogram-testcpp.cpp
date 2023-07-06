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

int
main() {
    test_positive();
    test_negative();
    equal();
    one_num();
    test_void();
}