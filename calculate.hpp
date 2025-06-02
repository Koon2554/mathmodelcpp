#ifndef CALCULATE_H
#define CALCULATE_H

#include <bits/stdc++.h>
using namespace std;

int fac(int n);

int binom(int n, int m);

int sequence(vector<vector<float>>& num, int n);

float sequencex(vector<vector<float>>& num, int layer);

int maxsequence(vector<vector<float>>& num, int n);

int geometry(vector<vector<float>>& num, int n);

float geometryx(vector<vector<float>>& num, int layer);

int maxgeometry(vector<vector<float>>& num, int n);

int setting(vector<vector<float>>& num, vector<float>& path);

int findnpath(vector<vector<float>>& num, vector<float>& path, int n);

#endif