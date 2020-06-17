#include <StatusDate.h>
#include <Helpper.h>
#include <fstream>
#include <iostream>
#include <map>
using namespace std;


void StatusDate ::addOrUpdateStatus(vector<Employee*> list){
    cout<< "nhap id nhan vien muon diem danh" <<endl;
    string idNV;
    cin >> idNV;
    while (Helpper::checkId(list, idNV) == 1) {
        cout << "khong co nhan vien, xin nhap lai:  " << endl;
        cin >>idNV;

    }


    // mo file csv nhan viên điểm danh
    ifstream ifs("C:\\Users\\khiem\\Desktop\\fileNV\\"+idNV+".csv", ios::in);


    // mở đọc file để check xem có ngày trùng không nếu trùng thì thay đổi trạng thái điểm danh
    // mở file điểm danh theo nhân viên rồi cho vào map <ngày ,trạng thái>
    std:: map <std ::string ,std ::string> mapRollCall;

    int n=Helpper ::numberLine("C:\\Users\\khiem\\Desktop\\fileNV\\"+idNV+".csv"); // lấy ra số dòng
    for (int i=0 ; i < n ; i++){
        char lines[500];
        fflush(stdin);
        ifs.getline(lines,500);
        string str = lines;
        vector<string> v = Helpper::split (str, ',');
        mapRollCall[v.at(0)]=v.at(1);

    }
    ifs.close();
    StatusDate::addOrUpdateStatus1(mapRollCall,idNV);
    return;

}
void StatusDate::writeRollCall(map<string,string> mapRollCall ,string idNV){
    ofstream fstream_ob;
    fstream_ob.open("C:\\Users\\khiem\\Desktop\\fileNV\\"+idNV+".csv", ios::trunc);
    for (map<string ,string> :: iterator it =mapRollCall.begin(); it !=mapRollCall.end(); it++) {
        fstream_ob << it->first<<","<<it->second<<endl;
    }
    fstream_ob.close();

}
void StatusDate::addOrUpdateStatus1(map<std::string, std::string> mapRollCall ,string idNV){
    cout<< "nhap ngay nhan vien muon diem danh" <<endl;
    string date;
    cin >> date;
    cout<<"test"<<endl;
    while (Helpper::checkDateOfBirth(date) == 0) {
        cout << "Ngay thang nam sinh khong hop le, vui long nhap lai:" << endl;
        cin>> date;
    }

    // duyệt vòng nếu trùng thì sửa hoặc không muốn sửa thì thoát
    for (map<string ,string> :: iterator it =mapRollCall.begin(); it !=mapRollCall.end(); it++) {
        if (it->first==date) {
            cout<<"ngay " << date << "  da ton tai ,ban co muon thay doi status ko , y /n "<<endl;
            string opption;
            cin>> opption;
            if(opption == "y"){
                cout<< "trang thai diem danh cu la " <<it->second <<endl;

                cout<< "nhap trang thai nhan vien muon diem danh" <<endl;
                string status;
                cin >> status;
                while(Helpper::checkStatus(status) ==0){
                    cout<<"dinh dang sai , xin nhap lai "<<endl;
                    cin >> status;
                }
                it->second=status;
                StatusDate::writeRollCall(mapRollCall,idNV);
                return;
            }
            else{
                // trường hợp ko muốn sửa nữa thì out
                return;
            }
        }
    }


    // trường hợp không trùng ngày thì thêm vào dòng thôi
    cout<< "nhap trang thai nhan vien muon diem danh" <<endl;
    string status;
    cin >> status;
    while(Helpper::checkStatus(status) ==0){
        cout<<"dinh dang sai , xin nhap lai "<<endl;
        cin >> status;
    }

    // mở file ghi và gi thêm 1 dòng
    fstream output("C:\\Users\\khiem\\Desktop\\fileNV\\"+idNV+".csv", ios::app);
    output << date<<","<<status<<endl;
    // đóng đọc file
    output.close();

}

