#ifndef PATH_HPP
#define PATH_HPP

#include <functional>
#include "data.hpp"   
#include "math_utils.hpp" 
#include <string>

bool check(const data_num &num) {
    for (int i = 1; i < num.data[num.data.size()-1].size(); i++) {
        if (abs(num.data[num.data.size()-1][i] - num.data[num.data.size()-1][i-1]) > 1e-6) return false;
    }
    return true;
}

data_num diff_all_data(data_num num, long double n) {
    vector<long double> temp;
    for (int i = 1; i < num.data[n].size(); i++) {
        temp.push_back(num.data[n][i] - num.data[n][i-1]);
    }
    num.data.push_back(temp);
    return num;
}

data_num div_all_data(data_num num, long double n) {
    vector<long double> temp;
    for (int i = 1; i < num.data[n].size(); i++) {
        temp.push_back(num.data[n][i] / num.data[n][i-1]);
    }
    num.data.push_back(temp);
    return num;
}

bool find_path(data_num &num, string &path) {
    data_num original = num;
    int size = num.data[0].size();

    if (size < 3) {
        cout << "fail (data too short)\n";
        return false;
    }

    for (int length = 1; length < size; length++) {
        int max_code = 1 << length;

        for (int code = 0; code < max_code; code++) {
            num = original;
            path = toBinaryInteger(code, length);
            bool success = true;
            for (int i = 0; i < path.size(); i++) {
                if (path[i] == '0') {
                    if (i == path.size()-1) {
                        success = check(num);
                    }
                    num = diff_all_data(num, i);
                } else {
                    if (i == path.size()-1) {
                        success = check(num);
                    }
                    num = div_all_data(num, i);
                }
            }
            if (success) {
                return true;
            }
        }
    }
    num = original;
    return false;
}

bool diff_many_lines(data_num &num) {
    bool temp;
    data_num x = num;
    for (int i = 0; i < num.data[0].size()-2; i++) {
        if (i == num.data[0].size()-3) {
            temp = check(num);
        } else {
            num = diff_all_data(num, i);
        }
    }
    if (!temp) num = x;
    return temp;
}

bool div_many_lines(data_num &num) {
    bool temp;
    data_num x = num;
    for (int i = 0; i < num.data[0].size()-2; i++) {
        if (i == num.data[0].size()-3) {
            temp = check(num);
        } else {
            num = div_all_data(num, i);
        }
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
                num.data[i].push_back(num.data[i][s+j] * num.data[i+1][s+j]);
            }
        }
        k++;
    }
    return num.data[0][num.n-1];
}

#endif
