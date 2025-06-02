#include <bits/stdc++.h>
using namespace std;

int main() {
    char order;
    cout << "RUN time(t) / resuit(r) : ";
    cin >> order;
    if (order == 'r') {
        system("g++ testresult.cpp -o test.exe && test.exe");
    } else if (order == 't') {
        system("g++ testtime.cpp -o test.exe && test.exe");
    }
}