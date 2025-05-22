#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
high_resolution_clock::time_point t_start, t_stop;

void starttime() {
    t_start = high_resolution_clock::now();
}

void stoptime() {
    t_stop = high_resolution_clock::now();
    auto durationms = duration_cast<milliseconds>(t_stop - t_start);
    auto durationns = duration_cast<nanoseconds>(t_stop - t_start);
    cout << "Take time: " << durationms.count() << " ms(" << durationns.count() << ")" << endl;
}

#endif
