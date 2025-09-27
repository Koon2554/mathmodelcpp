#include <bits/stdc++.h>
#include "inc/create_test_case.hpp"
using namespace std;
#define test_max 1e0

int main() {
    ofstream problem("problem.json");
    ofstream answer("answer.json"); 
    string p = "", ans = "";
    p += "[ \n";
    ans += "[ \n";
    for (int i = 0; i < test_max; i++) {
        vector<long double> data, num;
        data = create_arithmetic_sequence(1000000, 1000000, 100);
        num = vector<long double>(data.begin(), data.begin() + 6);
        for (int l = 0; l < data.size(); l++) {
            p += "{ \"id\" : \"";
            for (int j = 0; j < num.size(); j++) {
                p += longDoubleToString(num[j]);
                if (j != num.size()-1) p += ", ";
                else {
                    p += "\", \"n\" : ";
                    p += longDoubleToString(l);
                    p += " },\n";
                }
            }
            ans += "{ \"answer\" : " + longDoubleToString(data[l]) + "}, \n";
        }
    }
    for (int i = 0; i < test_max; i++) {
        vector<long double> data, num;
        data = create_geometric_sequence(10, 10, 100);
        num = vector<long double>(data.begin(), data.begin() + 6);
        for (int l = 0; l < data.size(); l++) {
            p += "{ \"id\" : \"";
            for (int j = 0; j < num.size(); j++) {
                p += longDoubleToString(num[j]);
                if (j != num.size()-1) p += ", ";
                else {
                    p += "\", \"n\" : ";
                    p += longDoubleToString(l);
                    p += " },\n";
                }
            }
            ans += "{ \"answer\" : " + longDoubleToString(data[l]) + "}, \n";
        }          
    }
    for (int i = 0; i < test_max; i++) {
        vector<long double> data, num;
        data = create_recursive_sequence(1000000, 100);
        num = vector<long double>(data.begin(), data.begin() + 6);
        for (int l = 0; l < data.size(); l++) {
            p += "{ \"id\" : \"";
            for (int j = 0; j < num.size(); j++) {
                p += longDoubleToString(num[j]);
                if (j != num.size()-1) p += ", ";
                else {
                    p += "\", \"n\" : ";
                    p += longDoubleToString(l);
                    p += " },\n";
                }
            }
            ans += "{ \"answer\" : " + longDoubleToString(data[l]) + "}, \n";
        }         
    }

    for (int i = 0; i < test_max; i++) {
        vector<long double> data, num;
        data = create_poly_diff_sequence(1000000, 5, 100);
        num = vector<long double>(data.begin(), data.begin() + 6);
        for (int l = 0; l < data.size(); l++) {
            p += "{ \"id\" : \"";
            for (int j = 0; j < num.size(); j++) {
                p += longDoubleToString(num[j]);
                if (j != num.size()-1) p += ", ";
                else {
                    p += "\", \"n\" : ";
                    p += longDoubleToString(l);
                    p += " },\n";
                }
            }
            ans += "{ \"answer\" : " + longDoubleToString(data[l]) + "}, \n";
        }
    }
    for (int i = 0; i < test_max; i++) {
        vector<long double> data, num;
        data = create_poly_div_sequence(9, 4, 100);
        num = vector<long double>(data.begin(), data.begin() + 6);
        for (int l = 0; l < data.size(); l++) {
            p += "{ \"id\" : \"";
            for (int j = 0; j < num.size(); j++) {
                p += longDoubleToString(num[j]);
                if (j != num.size()-1) p += ", ";
                else {
                    p += "\", \"n\" : ";
                    p += longDoubleToString(l);
                    if (i == test_max-1 && l == data.size()-1) p += " } \n";
                    else p += "}, \n";
                }
            }
            if (i == test_max-1 && l == data.size()-1) ans += "{ \"answer\" : " + longDoubleToString(data[l]) + "} \n";
            else ans += "{ \"answer\" : " + longDoubleToString(data[l]) + "}, \n";
        }
    }
    p += "]";
    ans += "]";
    problem << p;
    answer << ans;
    return 0;
}