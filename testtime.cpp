#include <bits/stdc++.h>
using namespace std;
#define TIME_MAX 100000

string extractVersion(const string& filepath) {
    ifstream file(filepath);
    string line;
    while (getline(file, line)) {
        size_t pos = line.find("v.");
        if (pos != string::npos) {
            string rest = line.substr(pos);
            size_t end = 0;
            while (end < rest.size() && (isalnum(rest[end]) || rest[end] == '.' || rest[end] == '-')) {
                ++end;
            }
            return rest.substr(0, end);
        }
    }
    return "Version not found";
}

int main() {
    int count = 0;
    // คอมไพล์โปรแกรมหลัก
    if (system("g++ -std=c++17 index.cpp -o program.exe") != 0) {
        cerr << "Compilation failed!" << endl;
        return 1;
    }
    
    // เปิดไฟล์อินพุตและเอาท์พุต
    ifstream input_file("input.txt");
    ifstream expected_file("output.txt");

    if (!input_file.is_open() || !expected_file.is_open()) {
        cerr << "Error opening files!" << endl;
        return 1;
    }
    
    // อ่านข้อมูลทั้งหมดจากไฟล์
    string input_data((istreambuf_iterator<char>(input_file)), istreambuf_iterator<char>());
    
    // เตรียมไฟล์ output สำหรับเก็บผลลัพธ์จริง
    ofstream actual_file("actual_output.txt");
    ofstream error_file("error.txt");
    
    // สร้าง temporary file สำหรับแต่ละเทสต์เคส
    int test_case = 1;
    bool all_passed = true;
    string expected_line;
    
    while (input_data.size() > 0 && getline(expected_file, expected_line)) {
        // ตัดช่องว่างท้ายบรรทัด
        expected_line.erase(expected_line.find_last_not_of(" \n\r\t") + 1);

        // สร้างไฟล์อินพุตชั่วคราวสำหรับเทสต์เคสนี้
        ofstream temp_input("temp_input.txt");
        
        // อ่านข้อมูลใน input.txt จนถึงบรรทัดว่าง (หรือสิ้นสุดไฟล์)
        string line;
        size_t pos = 0;
        size_t line_end = 0;
        
        // อ่านบรรทัดแรก (ตัวเลขในลำดับ)
        line_end = input_data.find('\n', pos);
        string input_line1 = "";
        if (line_end != string::npos) {
            input_line1 = input_data.substr(pos, line_end - pos);
            temp_input << input_line1 << endl;
            pos = line_end + 1;
        }

        // อ่านบรรทัดที่สอง (ค่าที่ต้องการคำนวณ)
        line_end = input_data.find('\n', pos);
        string input_line2 = "";
        if (line_end != string::npos) {
            input_line2 = input_data.substr(pos, line_end - pos);
            temp_input << input_line2 << endl;
            pos = line_end + 1;
        }

        
        temp_input.close();
        
        // ตัดข้อมูลที่ใช้ไปแล้วออกจาก input_data
        input_data = input_data.substr(pos);
        
        // รันโปรแกรมกับอินพุตชั่วคราว
        system("program.exe < temp_input.txt > temp_output.txt");
        
        // อ่านผลลัพธ์
        ifstream temp_output("temp_output.txt");
        // ตัดช่องว่างท้ายบรรทัดifstream 
        string actual_line, actual_line2;
        getline(temp_output, actual_line);
        getline(temp_output, actual_line2);
        
        // ตัดช่องว่างท้าย
        actual_line.erase(actual_line.find_last_not_of(" \n\r\t") + 1);
        actual_line2.erase(actual_line2.find_last_not_of(" \n\r\t") + 1);
        // ตัวแปรเก็บ durationns.count()
        long long durationns_count = 0;

        // ดึงค่า durationns.count() จาก actual_line2 (ตัวเลขในวงเล็บ)
        regex duration_regex(R"(.*\((\d+)\))");  // ค้นหาตัวเลขที่อยู่ในวงเล็บ
        smatch match;
        if (regex_search(actual_line2, match, duration_regex)) {
            // เอาตัวเลขที่อยู่ในวงเล็บมาเก็บในตัวแปร
            durationns_count = stoll(match[1]);  // ใช้ stoll เพื่อแปลงจาก string เป็น long long
        }
        // เขียนผลลัพธ์ลงในไฟล์รวม
        actual_file << actual_line << endl;
        
        // ตรวจสอบผลลัพธ์
        if (actual_line != expected_line) {
            cout << "Test case " << test_case << " failed\n";
            cout << "   Got: " << actual_line << "\n";
            cout << "   Expected: " << expected_line << "\n";
            cout << "   Input line 1: " << input_line1 << "\n";
            cout << "   Input line 2: " << input_line2 << "\n";
            error_file << actual_line << endl << expected_line << endl << input_line1 << endl << input_line2 << endl << test_case << endl << "-----------" << endl;
            all_passed = false;        
        } else if (durationns_count > TIME_MAX) {
            cout << "Execution timed out (Test case " << test_case << " )"  << endl;
            error_file << "Execution timed out" << endl << durationns_count << endl << test_case << endl << "-----------" << endl;
            all_passed = false;        
        } else {
            cout << "Test case " << test_case << " passed\n";
            count++;
        }
        
        test_case++;
        temp_output.close();
    }
    
    actual_file.close();
    
    // สรุปผลการทดสอบ
    cout << "\n=== Test summary ===\n";
    cout << "Total cases: " << (test_case-1) << "\n";
    cout << "pass: " << count << " / " << (test_case-1) << "\n";
    cout << (all_passed ? "All passed!" : "Some failed!") << endl;
    string version = extractVersion("index.cpp"); 
    ofstream run_file("runtest.txt", ios::app);
    run_file << endl << "testtime" << endl << "version : " << version << endl << "Total cases: " << (test_case-1) << endl << "pass: " << count << " / " << (test_case-1) << endl << (all_passed ? "All passed!" : "Some failed!") << endl << "--------------------" << endl; 
    // ลบไฟล์ชั่วคราว
    remove("temp_input.txt");
    remove("temp_output.txt");
    remove("actual_output.txt");
    
    return all_passed ? 0 : 1;
}