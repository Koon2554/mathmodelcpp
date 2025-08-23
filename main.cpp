#include <bits/stdc++.h> 
#include "inc/memory.hpp"
#include "inc/time.hpp"
#include "inc/allinc.hpp"
using namespace std;

int main() {
    result res;
    data_num num;
    string line;
    input(num, line);
    res = calculater(num);
    cout << res.ans << " " << res.time << " " << res.memory;
    return 0;
}
