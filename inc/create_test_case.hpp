#ifndef CREATE_TEST_CASE_HPP
#define CREATE_TEST_CASE_HPP

#include <bits/stdc++.h>
#include "math_utils.hpp"
using namespace std;

// _______________________ ARITHMETIC SEQUENCE _______________________
vector<long double> create_arithmetic_sequence(long double high_a1, long double high_d, int n) {
      high_a1 = min(high_d, 1e63);
      high_d = min(n, 1e63/n);
      random_device rd;
      mt19937 gen(rd());
      uniform_real_distribution<long double> dist_a1(1, high_a1), dist_d(1, high_d);
      long double a1 = round_long_double(dist_a1(gen));
      long double d = round_long_double(dist_d(gen));
      vector<long double> num;
      num.push_back(a1);
      for (int i = 1; i < n; ++i) {
          num.push_back(num[i-1] + d);
      }
      return num;
}
// _______________________ GEOMETRIC SEQUENCE _______________________
vector<long double> create_geometric_sequence(long double high_a1, long double high_r, int n) {
    high_a1 = min(high_a1, 1e6L);
    high_r = min(high_r, pow(1e12L/high_a1, 1.0/(max(1,n-1))));
    random_device rd; mt19937 gen(rd());
    uniform_real_distribution<long double> dist_a1(1, high_a1);
    uniform_real_distribution<long double> dist_r(0.01, high_r);
    long double a1 = round_long_double(dist_a1(gen));
    long double r = round_long_double(dist_r(gen));

    vector<long double> num(n);
    num[0] = a1;
    for (int i = 1; i < n; ++i) {
        num[i] = round_long_double(num[i-1] * r);
    }
    return num;
}

// _______________________ RECURSIVE SEQUENCE _______________________
vector<long double> create_recursive_sequence(long double high_a, int n) {
    n = min(n, 100);
    random_device rd; mt19937 gen(rd());
    uniform_real_distribution<long double> dist(1, min(high_a, 1e12L));
    vector<long double> num(n);
    num[0] = round_long_double(dist(gen));
    if(n>1) num[1] = round_long_double(dist(gen));
    for (int i = 2; i < n; ++i) {
        num[i] = num[i-1] + num[i-2];
    }
    return num;
}

// _______________________ POLY DIFFERENCE SEQUENCE _______________________
vector<long double> create_poly_diff_sequence(long double high_bn, long long high_layer, int n) {
     high_layer = min(log(1e63)/log(n), high_layer);
     random_device rd;
     mt19937 gen(rd());
     uniform_int_distribution<long long> dist_layer(3, high_layer);
     uniform_real_distribution<long double> dist_bn(1, high_bn);
     int layer = dist_layer(gen);
     vector<long long> bn;
     for (int i = 0; i < layer; i++) {
          bn.push_back(round_long_double(dist_bn(gen)));
     }
     vector<vector<long double>> num;
     num.push_back(vector<long double>(n+layer, bn[0]));
     for (int i = 1; i < layer; i++) {
          vector<long double> temp;
          temp.push_back(bn[i]);
          for (int j = 1; j < n+layer-i-1; j++) {
               temp.push_back(num[i-1][j-1]+temp[j-1]);
          }
          num.push_back(temp);
      }
      return num[num.size()-1];
}

// _______________________ POLY DIVISION SEQUENCE _______________________
vector<long double> create_poly_div_sequence(long double high_bn, long long high_layer, int n) {
      high_bn = min(high_bn, pow(1e63, 1/(n*high_layer)));
      random_device rd;
      mt19937 gen(rd());
      uniform_int_distribution<long long> dist_layer(3, high_layer);
      uniform_real_distribution<long double> dist_bn(0.01, high_bn);
      int layer = dist_layer(gen);
      vector<long long> bn;
      for (int i = 0; i < layer; i++) {
            bn.push_back(dist_bn(gen));
            cout << bn[i] << "\n";
      }
      vector<vector<long double>> num;
      num.push_back(vector<long double>(n+layer, bn[0]));
      for (int i = 1; i < layer; i++) {
            vector<long double> temp;
            temp.push_back(bn[i]);
            for (int j = 1; j < n+layer-i-1; j++) {
                  temp.push_back(round_long_double(num[i-1][j-1]*temp[j-1]));
            }
            num.push_back(temp);
      }
      return num[num.size()-1];
}

// _______________________ LAGRANGE POLYNOMIAL SEQUENCE _______________________
vector<long double> create_lagrange_polynomial_sequence(int high_degree, long double high_coef, int n) {
    high_degree = min(high_degree, 5); // ลด degree เพื่อ safety
    high_coef = min(high_coef, 1e6L/pow(max(1,n), high_degree));
    random_device rd; mt19937 gen(rd());
    uniform_int_distribution<long long> dist_degree(2, high_degree);
    uniform_real_distribution<long double> dist_coef(-high_coef, high_coef);

    int degree = dist_degree(gen);
    vector<long double> coeffs(degree+1);
    for(int j=0;j<=degree;j++) coeffs[j]=round_long_double(dist_coef(gen));

    vector<long double> num(n);
    for(int i=0;i<n;i++){
        long double sum=0;
        for(int j=0;j<=degree;j++){
            sum += coeffs[j]*pow(i,j);
        }
        num[i] = round_long_double(sum);
    }
    return num;
}

#endif















