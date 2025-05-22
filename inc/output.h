#ifndef OUTPUT_H
#define OUTPUT_H
#include <bits/stdc++.h>
using namespace std;

void output2D(vector<vector<float>>& num) {
    for (int i = 0; i < num.size(); i++) {
        for (int j = 0; j < num.at(i).size(); j++) {
            cout << num.at(i).at(j) << " ";
        }
        cout << "\n";
    }
}

void output1D(vector<float>& num) {
    for (int i = 0; i < num.size(); i++) {
        cout << num.at(i) << " ";
    }
}

#endif
