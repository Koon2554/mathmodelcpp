#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

#include <bits/stdc++.h>
#include "data.hpp"
#include "path.hpp"
#include "math_utils.hpp"
#include "lagrange.hpp"
using namespace std;

bool check_recursive(data_num num) {
    for (int i = 0; i < num.data[0].size()-2; i++) {
        if (num.data[0][i] + num.data[0][i+1] != num.data[0][i+2]) {
            return false;
        }
    }
    return true;
}

long double find_n_recursive(data_num &num) {
    long long i = num.data[0].size();
    while (i <= num.n-1) {
        num.data[0].push_back(num.data[0][i-1] + num.data[0][i-2]);
        i++;
    }
    return num.data[0][num.n-1];
}

long double find_n_arithmetic_sequence(data_num num) {
    return num.data[0][0] + (num.n - 1) * num.data[1][0];
}

long double find_n_geometric_sequence(data_num num) {
    return num.data[0][0] * pow(num.data[1][0], num.n - 1);
}

long double find_n_poly_diff_sequence(data_num num, vector<long double> parameter) {
    long double sum = 0;
    int max_term = min((long long)parameter.size() - 1, num.n - 1);
    for (int i = 1; i <= max_term; i++) {
        sum += binomial(num.n - 1, i) * parameter[i];    
    }
    sum += parameter[0];
    return sum;
}

long double find_n_poly_div_sequence(data_num num, vector<long double> parameter) {
    long double log_sum = log(parameter[0]);

    for (int i = 1; i < parameter.size(); i++) {
        log_sum += binomial(num.n - 1, i) * log(parameter[i]);
    }
    return expl(log_sum);
}

long double find_Lagrange_Polynomial(data_num num) {
    vector<point> p;
    for (int i = 0; i < num.data[0].size(); i++) {
        point t;
        t.x = i+1;
        t.y = num.data[0][i];
        p.push_back(t);
    }
    return Lagrange_Polynomial(p, num.n+1);
}


long double find_n(data_num &num) {
    data_num temp;
    temp = num;
    string path;

    if (check(diff_all_data(num, 0))) {
        num = diff_all_data(num, 0);
        return find_n_arithmetic_sequence(num);
    } else if (check(div_all_data(num, 0))) {
        num = div_all_data(num, 0);
        return find_n_geometric_sequence(num);
    } else if (diff_many_lines(num)) {
        vector<long double> parameter;
        for (int i = 0; i < num.data.size(); i++) {
            if (!num.data[i].empty()) {
                parameter.push_back(num.data[i][0]);
            }
        }
        return find_n_poly_diff_sequence(num, parameter);
    } else if (div_many_lines(num)) {
        vector<long double> parameter;
        for (int i = 0; i < num.data.size(); i++) {
            if (!num.data[i].empty()) {
                parameter.push_back(num.data[i][0]);
            }
        }
        return find_n_poly_div_sequence(num, parameter);
    } else if (check_recursive(num)) {
        return find_n_recursive(num);
    } else if (find_path(num, path)) {
        return find_n_overlapping(num, path);
    } else {
        return find_Lagrange_Polynomial(num);
    }
}

#endif