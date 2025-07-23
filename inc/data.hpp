#ifndef DATA_HPP
#define DATA_HPP

#include <vector>
#include <map>
#include <string>

struct data_num {
    vector<vector<long double>> data;
    long double n;
    map<string, vector<long double>> parameter;
    vector<long double> reciprocal_index;
    bool is_harmoni = true;
    data_num() : data(1), n(0), parameter{}, reciprocal_index{} {}
};

bool is_valid_token(const string& s) {
    for (char c : s) {
        if (!(isdigit(c) || c == '.' || c == '/')) return false;
    }
    return !s.empty();
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
                num.reciprocal_index.push_back(index);
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

    for (char c : line) {
        if (isalnum(c) || c == '.' || c == '/' || c == '(' || c == ')') {
            temp += c;
            if (c == '.') dot_count++;
        } else {
            push_data(num, temp, dot_count);
        }
    }
    push_data(num, temp, dot_count);
    if (num.reciprocal_index.size() != num.data[0].size()) {
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
