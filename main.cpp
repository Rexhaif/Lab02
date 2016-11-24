#include <iostream>
#include <cmath>
#include <cstdlib>

float summarize(float x, const float EPS);

void printTable(float (*summarize)(float, const float),
               const float EPS,
               float start, float incBy, float lim);

float summarize(float x, const float EPS) {
    float accum = 0;
    float hAccum = -1;

    for (unsigned j = 0; fabs(hAccum) > EPS ; ++j) {
        accum  += hAccum;
        hAccum *= ((-1 * x)/(j + 1));
    }
    return accum;
}

void printTable(float (*func)(float, const float), const float EPS,
               float start, float incBy, float lim) {
    std::cout << "| x  | " << "f(x) " << std::endl;
    std::cout << "------------------" << std::endl;
    for (float curr = start; fabs(curr) < fabs(lim); curr += incBy) {
        std::cout << "| " << curr << "  | " << func(curr, EPS) << std::endl;
    }
}

int main() {
    printTable(&summarize, 0.00001, 1.0, 1.0, 10.0);
    return 0;
}