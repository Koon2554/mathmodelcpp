#include <bits/stdc++.h>
#include "inc/create_test_case.hpp"
#include "inc/allinc.hpp"
#include "inc/calculater.hpp"
using namespace std;
#define test_max 1e4

struct test_res {
    bool ans, memory, time;
};

long long t = 0;

test_res test_calculater(vector<long double> data, data_num num) {
    test_res test;
    result res;
    res = calculater(num);
    if (res.memory > 500) {
        test.memory = false;
    } else {
        test.memory = true;
    }
    if (res.time > 15000000) {
        test.time = false;
    } else {
        test.time = true;
    }
    if (res.ans != longDoubleToString(data[num.n-1])) {
        test.ans = false;
    } else {
        test.ans = true;
    }
    t += res.time;
    return test;
}

int main() {
    long long pass = 0, fail = 0;
    vector<pair<int, int>> count;
    t = 0;
    for (int i = 0; i < test_max; i++) {
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
    count.push_back({pass, fail});
    pass = 0;
    fail = 0;
    cout << "arithmetic\n" << "pass : " << count[0].first << "\n" << "fail : " << count[0].second << "\n" << "time : " << t/(count[0].first+count[0].second) << "\n";
    t = 0;
    for (int i = 0; i < test_max; i++) {
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
    count.push_back({pass, fail});
    pass = 0;
    fail = 0;
    cout << "geometric\n" << "pass : " << count[1].first << "\n" << "fail : " << count[1].second << "\n" << "time : " << t/(count[1].first+count[1].second) << "\n";
    t = 0;
    for (int i = 0; i < test_max; i++) {
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
    count.push_back({pass, fail});
    pass = 0;
    fail = 0;
    cout << "recursive\n" << "pass : " << count[2].first << "\n" << "fail : " << count[2].second << "\n" << "time : " << t/(count[2].first+count[2].second) << "\n";
    t = 0;
    for (int i = 0; i < test_max; i++) {
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
    count.push_back({pass, fail});
    pass = 0;
    fail = 0;
    cout << "poly_diff\n" << "pass : " << count[3].first << "\n" << "fail : " << count[3].second << "\n" << "time : " << t/(count[3].first+count[3].second) << "\n";
    t = 0;
    for (int i = 0; i < test_max; i++) {
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
    count.push_back({pass, fail});
    pass = 0;
    fail = 0;
    cout << "poly_div\n" << "pass : " << count[4].first << "\n" << "fail : " << count[4].second << "\n" << "time : " << t/(count[4].first+count[4].second) << "\n";
    cout << "sum : " << count[0].first+count[1].first+count[2].first+count[3].first+count[4].first;
    return 0;
}