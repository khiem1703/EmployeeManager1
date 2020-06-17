#ifndef ROLLCALLHISTORY_H
#define ROLLCALLHISTORY_H
#include <map>
#include<Employee.h>
using namespace std;
class RollCallHistory{
public:
    static map<string ,string>  filterByMonth(vector<Employee*> list); //nhập  mã nhân viên , tháng muốn lọc


};
#endif // ROLLCALLHISTORY_H
