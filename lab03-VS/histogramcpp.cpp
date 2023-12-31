#include <iostream>
#include "histogram.h"
#include <vector>
#include <cassert>

using namespace std;

void find_minmax(vector<double> numbers, double& min, double& max) {
    if (numbers.size() == 0)
        return;
    else {
        min = numbers[0];
        max = numbers[0];
        for (double number : numbers) {
            if (min > number) min = number;
            if (max < number) max = number;
        }
    }
}