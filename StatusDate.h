#ifndef STATUSDATE_H
#define STATUSDATE_H
#include <iostream>
#include<vector>
#include<Employee.h>
#include<map>
using namespace std;
class StatusDate{
private:
    std:: string _date;
    std:: string _status;

private:
    StatusDate(
            const std::string &date,
            const std::string &status
            );

public:

    void setDate(const std::string &date);
    void setStatus(const std::string &status);
public:
    const std::string &getDate() const;
    const std::string &getStatus() const;


    // đọc dữ liệu điểm danh của từng nhân viên
    // hàm thêm trạng thái nhân viên theo ngày
    // nếu ngày nhập vào trùng có thể sửa hoặc không
    static void addOrUpdateStatus(vector<Employee*> list);
    static void addOrUpdateStatus1(map <std ::string ,std ::string> mapRollCall ,string idNV);


    static void writeRollCall(map<string,string> mapRollCall ,string idNV);

};



#endif // STATUSDATE_H
