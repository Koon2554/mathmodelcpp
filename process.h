#ifndef PROCESS_H
#define PROCESS_H
#include <bits/stdc++.h>
using namespace std;

void diffsequence(vector<vector<float>> &num) {
    int i = 0;
    while (num.at(i).size() > 1) {
        vector<float> v;
        for (int j = 0; j < num[i].size() - 1; j++) {
            v.push_back(num[i][j + 1] - num[i][j]);
        }
        num.push_back(v);
        i++;
    }
}

void diffgeometry(vector<vector<float>> &num) {
    int i = 0;
    while (num.at(i).size() > 1) {
        vector<float> v;
        for (int j = 0; j < num[i].size() - 1; j++) {
            v.push_back(num[i][j + 1] / num[i][j]);
        }
        num.push_back(v);
        i++;
    }
}

void div(vector<vector<float>> &num, int i) {
    vector<float> v;
    for (int j = 0; j < num[i].size() - 1; j++) {
        v.push_back(num[i][j + 1] / num[i][j]);
    }
    num.push_back(v);
}

void diff(vector<vector<float>> &num, int i) {
    vector<float> v;
    for (int j = 0; j < num[i].size() - 1; j++) {
        v.push_back(num[i][j + 1] - num[i][j]);
    }
    num.push_back(v);
}

bool check(int a, float b, vector<vector<float>> &num) {
    bool set;
    for (int i = 0; i < num.at(a).size(); i++) {
        if (num.at(a).at(i) == b) {
            set = true;
        } else {
            set = false;
            break;
        }
    }
    return set;
}

void bin2(int n, vector<float>& v, int size) {
    if (n == 0) {
        v.push_back(0);
        return;
    } else if (n == 1) {
        v.push_back(1);
        v.push_back(0);
        return;
    }
    while (n > 0) {
        v.push_back(n % 2);
        n = (n - n % 2) / 2;
    }
    while (v.size() < size) {
        v.push_back(0);
    }
    reverse(v.begin(), v.end());
    return;
}

bool checkpath(vector<vector<float>> &input, vector<float>& path) {
    vector<vector<float>> num = input;
    for (int i = 0; i < path.size(); i++) {
        if (path.at(i) == 0) {
            diff(num, i);
        } else if (path.at(i) == 1) {
            div(num, i);
        }
    }
    if (check(path.size(), 0, num) || check(path.size(), 1, num)) {
        return true;
    } else {
        return false;
    }
}

bool findpath(vector<vector<float>>& num, vector<float>& v) {
    for (int i = 0; i < pow(2, num.at(0).size())-1; i++) {
        bin2(i, v, num.size());
        if (checkpath(num, v)) {
            return true;
            break;
        }
        v.clear();
    }
    return false;
}

int checktype(vector<vector<float>> &num, vector<float>& v) {
    vector<vector<vector<float>>> dataq;
    dataq.push_back(num);
    dataq.push_back(num);
    dataq.push_back(num);
    diffsequence(dataq.at(0));
    diffgeometry(dataq.at(1));
    int result = INT_MAX;
    int i = 0;
    while (i < dataq.at(0).size() && dataq.at(0).at(i).size() > 0) {
        if (check(i, 0, dataq.at(0))) {
            diffsequence(num);
            if (i <= 2) {
                result = 0;
            }
            else {
                result = 1;
            }
            break;
        }
        i++;
    }

    if (result == INT_MAX) {
        int j = 0;
        while (j < dataq.at(1).size() && dataq.at(1).at(j).size() > 0) {
            if (check(j, 1, dataq.at(1))) {
                diffgeometry(num);
                if (j <= 2) {
                    result = 2;
                }
                else {
                    result = 3;
                }
                break;
            }
            j++;
        }
    }

    if (result == INT_MAX) {
        if (findpath(dataq.at(2), v)) {
            result = 4;
        }
    }
    return result;
}
#endif