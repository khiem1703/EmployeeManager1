#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <vector>

using namespace std;
class Employee{

private:
    std::string _id;
    std::string _name;
    std::string _dateOfBirth;
    std::string _address;
    std::string _department;
    // construster
private:
    Employee(const std::string &id,
             const std::string &name,
             const std::string &dateOfBirth,
             const std::string &address,
             const std::string &department);


    // set
public:
    void setId(const std::string &id);
    void setName(const std::string &name);
    void setDateOfBirth(const std::string &dateOfBirth);
    void setAddress(const std::string &address);
    void setDepartment(const std::string &department);
    //get
public:
    const std::string &getId() const;
    const std::string &getName() const;
    const std::string &getDateOfBirth() const;
    const std::string &getAddress() const;
    const std::string &getDepartment() const;

    Employee(){};
    ~Employee(){};
    // ham khac
public:

    // thêm nhân viên  , ghi ra luôn vào cuối file
    // input :nhập từ bàn phím thông tin nhân viên
    // output : ghi vào cuối file lưu thông tin nhân viên và set các thuộc tính vào đối tượng nhân viên luôn
    virtual void enterEmployee(vector<Employee*> list,string url);

    // in ra theo từng nhân viên
    virtual void printEmployee();

    // tìm kiếm nhân viên theo tên ,id ,name ,address ,deparment, ngày sinh
    // tìm kiếm theo id yêu cầu chính xác id
    // tìm kiếm theo tên , address ,deparment ,.. thì cho phép tìm kiếm gần đúng()
    static void searchEmployee( vector<Employee*> list);

    // đọc dữ liệu từ file
    // input: file , list các nhân viên (dùng để check trùng id) ,đếm dòng)
    // output : lấy ra các thuộc tính của nhân viên và thêm vào đối tượng đó

    void readData(ifstream & ,vector<Employee*> list); // hàm này đọc dữ liệu từ data gốc
    void readImport(ifstream & ,vector<Employee*> list ,int *linePtr ); // hàm này đọc đồng thời check data xem hợp lệ không

    // hàm import
    // đầu vào: list để thêm đối tượng vào
    // thêm các đối tượng vào list , tạo các file điểm danh

    void write(ofstream &);

};

#endif // EMPLOYEE_H
