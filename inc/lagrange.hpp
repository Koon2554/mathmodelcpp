#ifndef LAGRANGE_HPP
#define LAGRANGE_HPP

#include <bits/stdc++.h>
#include "allinc.hpp"
using namespace std;

struct point {
    long double x;
    long double y;
};

long double Lagrange_Polynomial(vector<point> p, long double x) {
    long double sum = 0;
    for (int i = 0; i < p.size(); i++) {
        long double poly = p[i].y;
        for (int j = 0; j < p.size(); j++) {
            if (j != i) {
                poly *= ((x - p[j].x)/(p[i].x - p[j].x));
            }
        }
        sum += poly;
    }
    return sum;
}

#endif
