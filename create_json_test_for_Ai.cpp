#include <bits/stdc++.h>
#include "inc/create_test_case.hpp"
using namespace std;
#define test_max 1e5

int main() {
    vector<string> seq_names = {"Arithmetic", "Geometric", "Recursive", "Poly_diff", "Poly_div"};
    random_device rd; mt19937 gen(rd());
    vector<function<vector<long double>()>> seq_generators = {
        [](){ return create_arithmetic_sequence(100000, 100000, 500); },
        [](){ return create_geometric_sequence(10, 10, 500); },
        [](){ return create_recursive_sequence(100000, 500); },
        [](){ return create_poly_diff_sequence(100000, 3, 500); },
        [](){ return create_poly_div_sequence(100, 3, 500); }
    };
    
    ofstream problem("problem.json");
    ofstream answer("answer.json"); 
    string p = "", ans = "";
    p += "[ \n";
    ans += "[ \n";
    
    for (int s = 0; s < seq_names.size(); s++) {
        for (int i = 0; i < test_max; i++) {
            bool c = true;
            while (c) { 
                vector<long double> data = seq_generators[s](), num;
                uniform_int_distribution<int> dist_n(0, (int)data.size()-1);
                int n = dist_n(gen);
                if (longDoubleToString(data[n]) != "-9223372036854775808.000") {
                    c = false;
                } else {
                    continue;
                }
                num = vector<long double>(data.begin(), data.begin() + 6);
                p += "    { \"id\" : \"";
                for (int j = 0; j < num.size(); j++) {
                    p += longDoubleToString(num[j]);
                    if (j != num.size()-1) p += ", ";
                    else {
                        p += "\", \"n\" : ";
                        p += longDoubleToString(n);
                        if (s == (int)seq_names.size()-1 && i == test_max-1) p += " }\n";
                        else p += " },\n";
                    }
                }
                if (s == (int)seq_names.size()-1 && i == test_max-1) ans += "    { \"answer\" : " + longDoubleToString(data[n]) + "} \n";
                else ans += "    { \"answer\" : " + longDoubleToString(data[n]) + "}, \n";
            }
        }
    }
    p += "]";
    ans += "]";
    problem << p;
    answer << ans;
    return 0;

}
