#ifndef TIME_HPP
#define TIME_HPP

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
high_resolution_clock::time_point t_start, t_stop;

void start_time() {
    t_start = high_resolution_clock::now();
}

long long stop_time() {
    t_stop = high_resolution_clock::now();
    auto durationns = duration_cast<nanoseconds>(t_stop - t_start);
    return durationns.count();
}

#endif
