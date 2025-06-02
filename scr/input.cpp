#include <bits/stdc++.h>
#include "../inc/input.hpp"
using namespace std;

void input(vector<vector<float>>& num) {
    string line;
    getline(cin, line);
    stringstream ss(line); 
    int temp;
    while (ss >> temp) {
        num[0].push_back(temp); 
    }
}
