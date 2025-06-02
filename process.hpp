#ifndef PROCESS_H
#define PROCESS_H

#include <bits/stdc++.h>
using namespace std;

void diffsequence(vector<vector<float>> &num);

void diffgeometry(vector<vector<float>> &num);

void div(vector<vector<float>> &num, int i);

void diff(vector<vector<float>> &num, int i);

bool check(int a, float b, vector<vector<float>> &num);

void bin2(int n, vector<float>& v, int size);

bool checkpath(vector<vector<float>> &input, vector<float>& path);

bool findpath(vector<vector<float>>& num, vector<float>& v);

int checktype(vector<vector<float>> &num, vector<float>& v);

#endif