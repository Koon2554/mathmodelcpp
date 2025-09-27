#ifndef DATA_HPP
#define DATA_HPP

#include <bits/stdc++.h>
using namespace std;

struct data_num {
    vector<vector<long double>> data; //ข้อมูลทั้งหมด
    long double n; //พจน์ที่ต้องการ
    long double reciprocal_index; //จำนวนจุดที่เป็นเศษส่วน
    bool is_harmoni = true; //เช็คว่าเป็น harmoni หรือไม่
    data_num() : data(1), n(0), reciprocal_index(0) {}
};

bool is_valid_token(const string& s) {
    if (s.empty()) return false;
    int start = (s[0] == '-') ? 1 : 0;
    for (int i = start; i < s.size(); ++i) {
        if (!(isdigit(s[i]) || s[i] == '.' || s[i] == '/')) return false;
    }
    return true;
}

void push_data(data_num &num, string &temp, int &dot_count) {
    if (temp.empty()) return;
    if (num.data.empty()) num.data.resize(1);

    int index = num.data[0].size();

    if (temp.find("1/(") == 0) {
        size_t close = temp.find(')');
        if (close != string::npos && close > 3) {
            string inside = temp.substr(3, close - 3);
            if (is_valid_token(inside)) {
                num.data[0].push_back(stold(inside));
                num.reciprocal_index++;
                index++;
            }

            string after = temp.substr(close + 1);
            if (is_valid_token(after)) {
                num.data[0].push_back(stold(after));
            }
        }
    } else if (is_valid_token(temp)) {
        num.data[0].push_back(stold(temp));
    }

    temp.clear();
    dot_count = 0;
}

void Filter_data(data_num &num, string &line) {
    string temp;
    int dot_count = 0;

    auto should_include = [&](char c, int i) -> bool {
        if (isdigit(c) || c == '/') return true;
        if (c == '.') {
            if (dot_count > 0) return false;
            return (i + 1 < line.size() && isdigit(line[i + 1]));
        }
        if (c == '(') {
            return (i + 1 < line.size() && isdigit(line[i + 1]) && i > 0 && line[i - 1] == '/');
        }
        if (c == ')') {
            return (i > 0 && isdigit(line[i - 1]) && (i + 1 == line.size() || (line[i + 1] != ')' && line[i + 1] != ',' && line[i + 1] != '/')));
        }
        if (c == '-') {
            return ((i == 0 && i + 1 < line.size() && (isdigit(line[i + 1]) || line[i + 1] == '.')) || (i > 0 && !isdigit(line[i - 1]) && i + 1 < line.size() && (isdigit(line[i + 1]) || line[i + 1] == '.')));
        }
        return false;
    };

    for (int i = 0; i < line.size(); i++) {
        if (should_include(line[i], i)) {
            temp += line[i];
            if (line[i] == '.') dot_count++;
        } else {
            if (!temp.empty()) {
                push_data(num, temp, dot_count);
                temp.clear();
                dot_count = 0;
            }
        }
    }

    if (!temp.empty()) {
        push_data(num, temp, dot_count);
    }

    if (num.reciprocal_index != num.data[0].size()) {
        num.is_harmoni = false;
    }
}


void input(data_num &num, string &line) {
    getline(cin, line);
    cin >> num.n;
    cin.ignore();
    Filter_data(num, line);
}

#endif
