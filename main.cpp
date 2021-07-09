#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<set>
using namespace std;

typedef string date;

#include "Attendance.hpp"
#include "Employee.hpp"

int main(){
    AttendanceList attendance_list("Attendance.txt");
    AttendanceList leave_list("Leave.txt");
    EmployeeList employee_list;

    string cmd;
    int employee_id;
    string date;
    string name;
    int daily_income;
    cout<<"==================================="<<endl;
    cout<<"**these command are you can use:**"<<endl;
    cout<<"new attendance"<<endl;
    cout<<"new leave"<<endl;
    cout<<"new employee"<<endl;
    cout<<"print attendance"<<endl;
    cout<<"print leave"<<endl;
    cout<<"print employee"<<endl;
    cout<<"count pay"<<endl;
    cout<<"exit"<<endl;
    cout<<"==================================="<<endl;
    while(true){
        cout<<">> ";
        getline(cin,cmd);
        if(cmd=="exit")break;
        else if(cmd=="new attendance"){
            cout<<"please input employee's ID and attendance date(separated by one space):";
            cin>>employee_id>>date;
            getchar();
            attendance_list.add(employee_id,date);
        }
        else if(cmd=="new leave"){
            cout<<"please input employee's ID and attendance date(separated by one space):";
            cin>>employee_id>>date;
            getchar();
            leave_list.add(employee_id,date);
        }
        else if(cmd=="new employee"){
            cout<<"please input employee's ID and name and daily income(separated by one space):";
            cin>>employee_id>>name>>daily_income;
            getchar();
            employee_list.add(employee_id,name,daily_income);
        }
        else if(cmd=="print attendance"){
            attendance_list.print();
        }
        else if(cmd=="print leave"){
            leave_list.print();
        }
        else if(cmd=="print employee"){
            employee_list.print();
        }
        else if(cmd=="count pay"){
            employee_list.pay(attendance_list,leave_list);
        }
        else{
            cout<<"Sorry, i cant understand your command."<<endl;
        }
    }
    return 0;
}
