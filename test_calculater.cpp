#include <bits/stdc++.h>
#include "inc/create_test_case.hpp"
#include "inc/allinc.hpp"
#include "inc/calculater.hpp"
using namespace std;
#define test_max 1000

struct test_res {
    bool ans, memory, time;
};

test_res test_calculater(vector<long double> data, data_num num) {
    test_res test;
    result res;
    res = calculater(num);
    if (res.memory > 500) {
        test.memory = false;
    } else {
        test.memory = true;
    }
    if (res.time > 10000000) {
        test.time = false;
    } else {
        test.time = true;
    }
    if (res.ans != longDoubleToString(data[num.n-1])) {
        test.ans = false;
    } else {
        test.ans = true;
    }
    return test;
}

int main() {
    long long pass = 0, fail = 0;
    for (int i = 0; i <= test_max; i++) {
        vector<long double> data;
        data = create_arithmetic_sequence(1000000, 1000000, 100);
        data_num num;
        num.is_harmoni = false;
        num.data[0] = vector<long double>(data.begin(), data.begin() + 6);
        for (int j = 0; j < data.size(); j++) {
            num.n = j;
            test_res test = test_calculater(data, num);
            if (test.ans && test.memory && test.time) {
                pass++;
            } else {
                fail++;
            }
        }
    }
    cout << pass << "\n" << fail << "\n";
    pass = 0;
    fail = 0;

    for (int i = 0; i <= test_max; i++) {
        vector<long double> data;
        data = create_geometric_sequence(10, 10, 100);
        data_num num;
        num.is_harmoni = false;
        num.data[0] = vector<long double>(data.begin(), data.begin() + 6);
        for (int j = 0; j < data.size(); j++) {
            num.n = j;
            test_res test = test_calculater(data, num);
            if (test.ans && test.memory && test.time) {
                pass++;
            } else {
                fail++;
            }
        }
    }
    cout << pass << "\n" << fail << "\n";
    pass = 0;
    fail = 0;

    for (int i = 0; i <= test_max; i++) {
        vector<long double> data;
        data = create_recursive_sequence(1000000, 100);
        data_num num;
        num.is_harmoni = false;
        num.data[0] = vector<long double>(data.begin(), data.begin() + 6);
        for (int j = 0; j < data.size(); j++) {
            num.n = j;
            test_res test = test_calculater(data, num);
            if (test.ans && test.memory && test.time) {
                pass++;
            } else {
                fail++;
            }
        }
    }
    cout << pass << "\n" << fail << "\n";
    pass = 0;
    fail = 0;

    for (int i = 0; i <= test_max; i++) {
        vector<long double> data;
        data = create_poly_diff_sequence(1000000, 5, 100);
        data_num num;
        num.is_harmoni = false;
        num.data[0] = vector<long double>(data.begin(), data.begin() + 6);
        for (int j = 0; j < data.size(); j++) {
            num.n = j;
            test_res test = test_calculater(data, num);
            if (test.ans && test.memory && test.time) {
                pass++;
            } else {
                fail++;
            }
        }
    }
    cout << pass << "\n" << fail << "\n";
    pass = 0;
    fail = 0;

    for (int i = 0; i <= test_max; i++) {
        vector<long double> data;
        data = create_poly_div_sequence(9, 4, 100);
        data_num num;
        num.is_harmoni = false;
        num.data[0] = vector<long double>(data.begin(), data.begin() + 6);
        for (int j = 0; j < data.size(); j++) {
            num.n = j;
            test_res test = test_calculater(data, num);
            if (test.ans && test.memory && test.time) {
                pass++;
            } else {
                fail++;
            }
        }
    }
    cout << pass << "\n" << fail << "\n";
    pass = 0;
    fail = 0;
    return 0;

}
