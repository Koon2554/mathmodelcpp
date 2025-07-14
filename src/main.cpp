#include <bits/stdc++.h> 
#include "memory.hpp"
#include "time.hpp"
#include "allinc.hpp"
using namespace std;

int main() { 
    start_memory();
    data_num num;
    string line;
    input(num, line);
    starttime();
    Filter_data(num, line);
    if (!num.is_harmoni) {
        cout << longDoubleToString(find_n(num));
    } else {
        cout << "1/(" << longDoubleToString(find_n(num)) << ")";
    }
    cout << "\n" << "-----------------------------";
    stoptime(); 
    stop_memory();
    return 0;
}
