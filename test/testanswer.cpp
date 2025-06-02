#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream output_file("output.txt");
    ifstream answer_file("answer.txt");
    if (!output_file.is_open() || !answer_file.is_open()) {
        cerr << "Error opening files!" << endl;
        return 1;
    }
    vector<double> answer, output;
    string line;
    
    long long line_count_answer = 0;
    while (getline(answer_file, line)) {
        double num = stod(line);
        answer.push_back(num);
        line_count_answer++;
    }
    answer_file.close();

    long long line_count_output = 0;
    while (getline(output_file, line)) {
        double num = stod(line);
        output.push_back(num);
        line_count_output++;
    }
    output_file.close();
    
    long long count = 0;
    for (long long i = 0; i < min(line_count_output, line_count_answer); i++) {
        if (output[i] == answer[i]) {
            count++;
        }
    }

    cout << "pass " << count/min(line_count_output, line_count_answer)*100 << " %" << endl;

    if (line_count_answer != line_count_output) {
        if (line_count_output > line_count_answer) {
            cout << "Data from item " << line_count_answer+1;
            cout << " of output file will not be calculated.";
        } else if (line_count_answer > line_count_output) {
            cout << "Data from item " << line_count_output+1;
            cout << " of answer file will not be calculated.";
        }
    }
    return 0;
}
