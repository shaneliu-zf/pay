class Employee{
private:
    int employee_id;
    string name;
    int daily_income;
public:
    Employee(int _employee_id=0,string _name="",int _daily_income=0){
        employee_id=_employee_id;
        name=_name;
        daily_income=_daily_income;
    }
    void print(){
        cout<<name<<", Daily income :"<<daily_income;
    }
    int pay(AttendanceList attendance_list,AttendanceList leave_list){
        int attendance_days=attendance_list.get(employee_id).size();
        int leave_days=leave_list.get(employee_id).size();
        return (attendance_days+leave_days)*daily_income;
    }
};
class EmployeeList{
private:
    map<int,Employee>employees;
public:
    EmployeeList(){
         fstream file;
         file.open("Employee.txt",ios::in);
         int employee_id,daily_income;
         string name;
         while(file>>employee_id>>name>>daily_income){
             employees[employee_id]=Employee(employee_id,name,daily_income);
         }
         file.close();
    }
    void print(){
        for(map<int,Employee>::iterator i=employees.begin();i!=employees.end();i++){
            cout<< (i->first) << ":";
            (i->second).print();
            cout<<endl;
        }
    }
    void add(int employee_id,string name,int daily_income){
        fstream file;
        file.open("Employee.txt",ios::app|ios::out);
        file<<employee_id<<" "<<name<<" "<<daily_income<<endl;
        file.close();
    }
    void pay(AttendanceList attendance_list,AttendanceList leave_list){
        for(map<int,Employee>::iterator i=employees.begin();i!=employees.end();i++){
            cout<< (i->first) << ":";
            (i->second).print();
            cout<<" pay:"<<(i->second).pay(attendance_list,leave_list)<<endl;
        }
    }
};
