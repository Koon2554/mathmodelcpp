#ifndef CALCULATER_HPP
#define CALCULATER_HPP

#include <bits/stdc++.h>
#include "data.hpp"
#include "sequence.hpp"
#include "math_utils.hpp"
#include "memory.hpp"
#include "time.hpp"
using namespace std;

struct result {
    string ans;
    long long time;
    long long memory;
};

result calculater(data_num &num) { 
    result res;
    start_memory();
    start_time();
    if (!num.is_harmoni) {
        res.ans = longDoubleToString(find_n(num));
    } else {
        res.ans = "1/(" + longDoubleToString(find_n(num)) + ")";
    }
    res.time = stop_time(); 
    res.memory = stop_memory();
    return res;
}

#endif