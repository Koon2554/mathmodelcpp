#include <bits/stdc++.h>
#include "inc/create_test_case.hpp"
#include "inc/allinc.hpp"
#include "inc/calculater.hpp"
using namespace std;

#define test_max 1e5

struct test_res {
    bool ans, memory, time;
};

long long t = 0;

test_res test_calculater(vector<long double> data, data_num num) {
    test_res test;
    result res = calculater(num);

    test.memory = (res.memory <= 500);
    test.time   = (res.time   <= 1000000);
    test.ans    = (res.ans == longDoubleToString(data[num.n-1]));

    t += res.time;
    return test;
}

auto print_result = [](const string &name, long long pass, long long fail_ans,
                       long long fail_mem, long long fail_time, long long total_time) {
    long long total = pass + fail_ans + fail_mem + fail_time;
    cout << "==== " << name << " ====\n";
    cout << "Pass        : " << pass << "\n";
    cout << "Fail Answer : " << fail_ans << "\n";
    cout << "Fail Memory : " << fail_mem << "\n";
    cout << "Fail Time   : " << fail_time << "\n";
    cout << "Pass (%)    : " << (pass/total)*100 << "\n";
    cout << "Average Time (µs/test) : " << (total ? total_time / total : 0) << "\n";
    cout << "------------------------\n";
};

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

    for (int s = 0; s < seq_names.size(); s++) {
        long long pass = 0, fail_ans = 0, fail_mem = 0, fail_time = 0;
        t = 0;

        for (int i = 0; i < test_max; i++) {
            vector<long double> data = seq_generators[s]();
            data_num num; 
            num.is_harmoni = false;
            num.data[0] = vector<long double>(data.begin(), data.begin()+6);
            uniform_int_distribution<int> dist_n(0, (int)data.size()-1);
            num.n = dist_n(gen);
            test_res test = test_calculater(data,num);
            if (!test.ans) fail_ans++;
            if (!test.memory) fail_mem++;
            if (!test.time) fail_time++;
            if (test.ans && test.memory && test.time) pass++;
        }

        print_result(seq_names[s], pass, fail_ans, fail_mem, fail_time, t);
    }

    return 0;
}








