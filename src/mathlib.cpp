#include "mathlib.h"

double square(double x) { return x * x; }
double cube(double x) { return x * x * x; }
double power(double x, int n) {
    if (n == 0) return 1.0;
    double result = 1.0;
    int exponent = n < 0 ? -n : n;
    for (int i = 0; i < exponent; ++i) result *= x;
    return n < 0 ? 1.0 / result : result;
}
double factorial(int n) {
    if (n < 0) return 0.0;
    double result = 1.0;
    for (int i = 2; i <= n; ++i) result *= i;
    return result;
}
