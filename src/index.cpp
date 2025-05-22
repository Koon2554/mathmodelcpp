#include <bits/stdc++.h>
#include "data.h"
#define VERSION "v.1.0.1"
using namespace std;

int main() {
    int count = 0;
    int n;
    vector<vector<float>> num(1);
    input(num);
    cin >> n;
    starttime();
    vector<float> v;
    int result = checktype(num, v);
    switch (result) {
        case 0:
            cout << sequence(num, n);
            break;
        case 1:
            cout << maxsequence(num, n);
            break;
        case 2:
            cout << geometry(num, n);
            break;
        case 3:
            cout << maxgeometry(num, n);
            break;
        case 4:
            cout << findnpath(num, v, n);
            break;
        default:
            cout << "I not known";
            break;
    }
    cout << "\n";
    stoptime();
    return 0;
}
