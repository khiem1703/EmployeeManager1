#include <map>
#include <RollCallHistory.h>
#include <iostream>
#include <fstream>

#include<Employee.h>
#include<Helpper.h>

using namespace std;

map<string ,string> RollCallHistory:: filterByMonth(vector<Employee*> list){

    map<string ,string> mapRollCallByMonth;
    cout<<"nhap vao id nhan vien muon xem lich su"<<endl;
    string idNV;
    cin >> idNV;

    while (Helpper::checkId(list, idNV) == 1) {
        cout << "khong co nhan vien, xin nhap lai:  " << endl;
        cin >>idNV;
    }

    cout<<"nhap vao thang nhan vien muon xem lich su"<<endl;
    string month;
    cin >> month;

    ifstream ifs("C:\\Users\\khiem\\Desktop\\fileNV\\"+idNV+".csv", ios::in);

    int n=Helpper ::numberLine("C:\\Users\\khiem\\Desktop\\fileNV\\"+idNV+".csv"); // lấy ra số dòng
    for (int i=0 ; i < n ; i++){
        char lines[500];
        fflush(stdin);
        ifs.getline(lines,500);
        string str = lines;
        vector<string> v = Helpper::split (str, '/');
        if(v.at(1)==month){
            vector<string> a = Helpper::split (str, ',');
            mapRollCallByMonth[a.at(0)]=a.at(1);
        }

    }
    ifs.close();
    return  mapRollCallByMonth;




}

