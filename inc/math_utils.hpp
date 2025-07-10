#ifndef MATH_UTILS_HPP
#define MATH_UTILS_HPP

#include <bits/stdc++.h>
#include "data.hpp"
#include "sequence.hpp"
#include "path.hpp"
#include "lagrange.hpp"
using namespace std;

long double diff(long double a, long double b) {
    return a - b;
}

long double divide(long double a, long double b) {
    return a / b; 
}

string toBinaryInteger(int n, int length) {
    string result;
    for (int i = length - 1; i >= 0; i--) {
        result += ((n >> i) & 1) ? '1' : '0';
    }
    return result;
}

long double binomial(long double n, long double k) {
    if (k > n) return 0;
    long double res = 1;
    for (long double i = 1; i <= k; ++i) {
        res *= n - i + 1;
        res /= i;
    }
    return res;
}

long double min(long double a, long double b) {
    return (a < b)? a : b;
}

string longDoubleToString(long double value, int precision = 0) {
    ostringstream oss;
    oss << fixed << setprecision(precision) << value;
    return oss.str();
}

#endif