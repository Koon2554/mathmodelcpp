#ifndef CALCULATE_H
#define CALCULATE_H
#include <bits/stdc++.h>
using namespace std;

int fac(int n) {
    if (n == 0) return 1;
    int f = 1;
    for (int i = 2; i <= n; ++i) {
        f *= i;
    }
    return f;
}

int binom(int n, int m) {
    return fac(n) / (fac(m) * fac(n - m));
}

int sequence(vector<vector<float>>& num, int n) {
    return num.at(0).at(0)+(n-1)*num.at(1).at(0);
}

float sequencex(vector<vector<float>>& num, int layer) {
    int last = num[layer].size() - 1;
    float last_val = num[layer][last];
    float diff = num[layer + 1][last];
    return last_val + diff;
}

int maxsequence(vector<vector<float>>& num, int n) {
    int sum = 0;
    for (int i = 1; i < num.size()-1; i++) {
        sum += binom(n - 1, i) * num[i][0];
    }
    return num[0][0] + sum;
}

int geometry(vector<vector<float>>& num, int n) { 
    return num.at(0).at(0)*pow(num.at(1).at(0), (n-1));
}

float geometryx(vector<vector<float>>& num, int layer) {
    int last = num[layer].size() - 1;
    float last_val = num[layer][last];
    float diff = num[layer + 1][last];
    return last_val * diff;
}


int maxgeometry(vector<vector<float>>& num, int n) {
    int sum = 1;
    for (int i = 1; i < num.size()-1; i++) {
        sum *= pow(num[i][0], binom(n-1, i));
    }
    return num[0][0] * sum;
}

int setting(vector<vector<float>>& num, vector<float>& path) {
    for (int i = 0; i < path.size(); i++) {
        if (path.at(i) == 0) {
            diff(num, i);
        } else if (path.at(i) == 1) {
            div(num, i);
        }
    }
    return 0;
}

int findnpath(vector<vector<float>>& num, vector<float>& path, int n) {
    setting(num, path);
    for (int i = num.at(num.size()-1).size(); i < n-(num.size()-1); i++) {
        num.at(num.size()-1).push_back(num.at(num.size()-1).at(i-1));
    }
    while (num[0].size() < n) {
        for (int i = num.size() - 2; i >= 0; i--) {
            if (num[i].size() >= num[0].size() + 1) continue;

            float next = 0;
            if (path[i] == 0) {
                next = sequencex(num, i);
            } else if (path[i] == 1) {
                next = geometryx(num, i);
            }
            num[i].push_back(next);
        }
    }
    return num.at(0).at(n-1);
}

#endif