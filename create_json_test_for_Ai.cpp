#include <bits/stdc++.h>
#include "inc/create_test_case.hpp"
using namespace std;
#define test_max 1e1

int main() {
    vector<string> seq_names = {"Arithmetic", "Geometric", "Recursive", "Poly_diff", "Poly_div"};
    random_device rd; mt19937 gen(rd());
    vector<function<vector<long double>()>> seq_generators = {
        [](){ return create_arithmetic_sequence(1000000, 1000000, 100); },
        [](){ return create_geometric_sequence(10, 10, 100); },
        [](){ return create_recursive_sequence(1000000, 100); },
        [](){ return create_poly_diff_sequence(1000000, 5, 100); },
        [](){ return create_poly_div_sequence(100, 5, 100); }
    };
    
    // ofstream problem("problem.json");
    // ofstream answer("answer.json"); 
    string p = "", ans = "";
    p += "[ \n";
    ans += "[ \n";
    
    for (int s = 0; s < seq_names.size(); s++) {
        for (int i = 0; i < test_max; i++) {
            vector<long double> data = seq_generators[s](), num;
            num = vector<long double>(data.begin(), data.begin() + 6);
            uniform_int_distribution<int> dist_n(0, (int)data.size()-1);
            p += "    { \"id\" : \"";
            int n = dist_n(gen);
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
    p += "]";
    ans += "]";
    cout << p << "\n" << ans << "\n";
    // problem << p;
    // answer << ans;
    return 0;

}





