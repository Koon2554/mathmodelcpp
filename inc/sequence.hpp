#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

#include <string>
#include "data.hpp"
#include "path.hpp"
#include "math_utils.hpp"
#include "lagrange.hpp"

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
    return num.parameter["ari"][0] + (num.n - 1) * num.parameter["ari"][1];
}

long double find_n_geometic_sequence(data_num num) {
    return num.parameter["geo"][0] * pow(num.parameter["geo"][1], num.n - 1);
}

long double find_n_poly_diff_sequence(data_num num) {
    long double sum = 0;
    for (int i = 1; i < min(num.n, num.parameter["poly-diff"].size()-2); i++) {
        sum += binomial(num.n - 1, i)*num.parameter["poly-diff"][i];
    }
    sum += num.parameter["poly-diff"][0];
    return sum;
}

long double find_n_poly_div_sequence(data_num num) {
    long double sum = 1;
    for (int i = 1; i < num.parameter["poly-div"].size(); i++) {
        sum *= pow(num.parameter["poly-div"][i], binomial(num.n - 1, i));
    }
    sum *= num.parameter["poly-div"][0];
    return sum;
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
    if (diff_or_div_all_data(num, 0, diff, true)) { 
        num.parameter["ari"] = {num.data[0][0], num.data[1][0]};
        return find_n_arithmetic_sequence(num);
    } else if (diff_or_div_all_data(num, 0, divide, true)) {
        num.parameter["geo"] = {num.data[0][0], num.data[1][0]};
        return find_n_geometic_sequence(num);
    } else if (diff_or_div_many_lines(num, diff)) {
        for (int i = 0; i < num.data.size(); i++) {
            if (!num.data[i].empty()) {
                num.parameter["poly-diff"].push_back(num.data[i][0]);
            }
        }
        return find_n_poly_diff_sequence(num);
    } else if (diff_or_div_many_lines(num, divide)) {
        for (int i = 0; i < temp.data.size(); i++) {
            if (!num.data[i].empty()) {
                num.parameter["poly-div"].push_back(num.data[i][0]);
            }
        }
        return find_n_poly_div_sequence(num);
    } else if (check_recursive(num)) {
        num.parameter["rec"].push_back(find_n_recursive(num));
        return num.parameter["rec"][0];
    } else if (find_path(num, path)) {
        num.parameter["over"].push_back(find_n_overlapping(num, path));
        return num.parameter["over"][0];
    } else {
        return find_Lagrange_Polynomial(num);
    }
}

#endif