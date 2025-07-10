#ifndef PATH_HPP
#define PATH_HPP

#include <functional>
#include "data.hpp"   
#include "math_utils.hpp" 
#include <string>

bool diff_or_div_all_data(data_num &num, long double n, function<long double(long double, long double)> func, bool check) {
    vector<long double> temp_1;
    for (int i = 1; i < num.data[n].size(); i++) {
        temp_1.push_back(func(num.data[n][i], num.data[n][i-1]));
    }

    if (check) {
        for (int i = 1; i < temp_1.size(); i++) {
            if (abs(temp_1[i] - temp_1[i-1]) > 1e-6) return false;
        }
    }

    num.data.push_back(temp_1);
    return true;
}

bool find_path(data_num &num, string &path) {
    data_num original = num;
    int size = num.data[0].size();

    if (size < 3) {
        cout << "fail (data too short)\n";
        return false;
    }

    function<long double(long double, long double)> funcs[2] = {diff, divide};

    for (int length = 1; length < size; length++) {
        int max_code = 1 << length;

        for (int code = 0; code < max_code; code++) {
            num = original;
            path = toBinaryInteger(code, length);
            bool success = true;
            for (int i = 0; i < path.size(); i++) {
                if (path[i] == '0') {
                    success = diff_or_div_all_data(num, i, diff, i == path.size() - 1);
                } else {
                    success = diff_or_div_all_data(num, i, divide, i == path.size() - 1);
                }
            }
            if (success) {
                for (char ch : path) {
                    num.parameter["ove"].push_back(ch - '0');
                }
                return true;
            }
        }
    }
    num = original;
    return false;
}

bool diff_or_div_many_lines(data_num &num, function<long double(long double, long double)> func) {
    bool temp;
    data_num x = num;
    for (int i = 0; i < num.data[0].size()-2; i++) {
        temp = diff_or_div_all_data(num, i, func, i == num.data[0].size() - 3);
    }
    if (!temp) num = x;
    return temp;
}

long double find_n_overlapping(data_num &num, string path) {
    reverse(path.begin(), path.end());
    long long size = num.n-num.data[0].size();
    for (int i = 0; i < size; i++) {
        num.data[num.data.size()-1].push_back(num.data[num.data.size()-1][0]);
    }
    int k = 0;
    for (int i = num.data.size()-2; i >= 0; i--) {
        long long s = num.data[i].size()-1;
        for (int j = 0; j < size; j++) {
            if (path[k] == '0') {
                num.data[i].push_back(num.data[i][s+j] + num.data[i+1][s+j]);
            } else {
                num.data[i].push_back(num.data[i][num.data[i].size()-1] * num.data[i+1][num.data[i].size()-1]);
            }
        }
        k++;
    }
    return num.data[0][num.n-1];
}

#endif