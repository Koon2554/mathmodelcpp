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

long long binomial(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;

    long long res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - k + i) / i;
    }
    return res;
}

long double min(long double a, long double b) {
    return (a < b)? a : b;
}

long double round_long_double(long double x) {
    return round(x * 1000.0L) / 1000.0L;
}

string longDoubleToString(long double value, int precision = 3) {
    ostringstream oss;
    oss << fixed << setprecision(precision) << value;
    return oss.str();
}

#endif
