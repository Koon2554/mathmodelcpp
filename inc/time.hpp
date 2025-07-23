#ifndef TIME_H
#define TIME_H

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
high_resolution_clock::time_point t_start, t_stop;

void starttime() {
    t_start = high_resolution_clock::now();
}

long long stoptime() {
    t_stop = high_resolution_clock::now();
    auto durationns = duration_cast<nanoseconds>(t_stop - t_start);
    return durationns.count();
}

#endif
