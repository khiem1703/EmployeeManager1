#ifndef HELPPER_H
#define HELPPER_H
#include <vector>
#include <sstream>
#include <Employee.h>
#include<map>
using namespace std;
class Helpper{
public:
     static int numberLine(string path); // lấy ra số dòng trong file csv
     static vector<string> split (const string &s, char delim) ; // tách theo chuỗi theo dấu
     static int isSubstring(string s1, string s2); // kiểm tra 1 string thuộc 1 string ko
     static int checkId(vector<Employee*> list, string id); // kiem tra id trung ko
     static int checkDateOfBirth(string dateOfBirth); // kiem tra ngay hop le ko
     static int checkStatus(string status); // check trạng thái điểm danh có đúng định dạng không


};
#endif // HELPPER_H
