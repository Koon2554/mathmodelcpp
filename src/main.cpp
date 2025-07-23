#include <bits/stdc++.h> 
#include "memory.hpp"
#include "time.hpp"
#include "allinc.hpp"
using namespace std;

struct result {
    string ans;
    long long time;
    long long memory;
};

result calculater(data_num &num, string &line) { 
    result res;
    start_memory();
    starttime();
    if (!num.is_harmoni) {
        res.ans = longDoubleToString(find_n(num));
    } else {
        res.ans = "1/(" + longDoubleToString(find_n(num)) + ")";
    }
    res.time = stoptime(); 
    res.memory = stop_memory();
    return res;
}

int main() {
    result res;
    data_num num;
    string line;
    input(num, line);
    res = calculater(num, line);
    cout << res.ans << " " << res.time << " " << res.memory;
    return 0;
}
