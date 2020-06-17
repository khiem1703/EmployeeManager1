#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <Employee.h>
#include <Helpper.h>
#include <iostream>
#include <cstring>

#include <StatusDate.h>


using namespace std;


int main()
{
    // lấy data từ file gốc
    vector<Employee*> list;
    Employee *employee;
    int n;
    n=Helpper ::numberLine("C:\\Users\\khiem\\Desktop\\Data.csv"); // lấy ra số dòng
    ifstream ifs("C:\\Users\\khiem\\Desktop\\Data.csv", ios::in);
    for (int i=0 ; i < n ; i++){
        employee = new Employee();
        employee->readData(ifs,list);
        list.push_back(employee);
    }


    int choice;
    do {
        cout <<"===========================================" << endl;
        cout <<"= 1-Nhap nhan vien " << endl;
        cout <<"= 2-Tim nhan vien " << endl;
        cout <<"= 3-In ra tat ca " << endl;
        cout <<"= 4-Import nhan vien" << endl;
        cout <<"= 5-Diem danh nhan vien" << endl;




        cout <<"= Chon khac de thoat                      =" << endl;
        cout <<"===========================================" << endl;
        cout << "Chon chuc nang (1-2-3-4-5 hoac khac):" << endl;
        cout << "Moi ban nhap lai lua chon = ";
        cin >> choice;

        if (choice == 1) {
            string a = "yes";
            while (a == "yes") {
                employee = new Employee();
                employee->enterEmployee(list,"C:\\Users\\khiem\\Desktop\\ImportData.csv");
                list.push_back(employee);

                cout << "Ban muon nhap tiep khong, an yes; neu muon thoat an phim bat ky \n" << endl;
                cin >> a;
            }
        }

        else if(choice == 2){
            employee->searchEmployee(list);
        }


        else if (choice ==3){
            if(list.size() == 0 ){
                cout << "Danh sach khong co nhan vien nao";
            }else{
                for (int i = 0; i < list.size(); i++ ){
                    list[i]->printEmployee();
                }
            }
        }

        else if (choice ==4) { // tạo tất cả các file nhân viên chỉ lần đầu muốn
            cout << "Nhap vao dia chi file can import" <<endl;
            string path;
            cin>> path ;
            path="C:\\Users\\khiem\\Desktop\\"+path;

            // phần này chỉ lấy ra số dòng trong file csv và xuống khỏi dòng đầu tiên
            ifstream ifs(path, ios::in);
            string abc;
            ifs >> abc;
            char ss[5];
            ifs.getline(ss, 3);// loai bo xuong dong

            //đếm số dòng trong file
            int n;
            n=Helpper ::numberLine(path); // lấy ra số dòng
            n=n-1;

            // dùng để lấy đc dòng nào bị sai
            int line=1 ;
            int *linePtr=&line;

            // thêm các nhân viên vào list để dễ thao tác


            Employee *employee;
            for (int i=0 ; i < n ; i++){
                employee = new Employee();
                employee->readImport(ifs ,list ,linePtr);

                list.push_back(employee);
            }
            ifs.close();


        }
        else if(choice ==5){ // lưu thông tin điểm danh
            // nhập vào id , nhập vào ngày muốn điểm danh ,nhập vào trạng thái muốn điểm danh
            StatusDate::addOrUpdateStatus(list);

        }
        else{
            break;
        }

    }

    while (true);

    ifs.close(); // đóng đọc file
    return 0;
}
