#include <bits/stdc++.h>
#include "../inc/output.hpp"
using namespace std;

void output2D(vector<vector<float>> num) {
    for (auto i = 0; i < num.size(); i++) {
        for (auto j = 0; j < num.at(i).size(); j++) {
            cout << num.at(i).at(j) << " ";
        }
        cout << "\n";
    }
}

void output1D(vector<float> num) {
    for (auto i = 0; i < num.size(); i++) {
        cout << num.at(i) << " ";
    }
}
