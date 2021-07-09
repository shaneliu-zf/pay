class Attendance:public set<date>{
public:
    void print(){
        for(set<date>::iterator i=begin();i!=end();i++){
            cout<<" "<< *i;
        }
    }
};

class AttendanceList{
private:
    map<int,Attendance>personal_attendance;
    string filename;
public:
    AttendanceList(string _filename=""){
        filename=_filename;
        fstream file;
        file.open(filename.c_str(),ios::in);
        int employee_id;
        string date;
        while(file>>employee_id>>date){
            personal_attendance[employee_id].insert(date);
        }
        file.close();
    }
    Attendance get(int employee_id){
        return personal_attendance[employee_id];
    }
    void print(){
        for(map<int,Attendance>::iterator i=personal_attendance.begin();i!=personal_attendance.end();i++){
            cout<< (i->first) << ":";
            (i->second).print();
            cout<<endl;
        }
    }
    void add(int employee_id,string date){
        fstream file;
        file.open(filename.c_str(),ios::app|ios::out);
        file<<employee_id<<" "<<date<<endl;
        file.close();
    }
    void clear(){
        personal_attendance.clear();
        fstream file(filename.c_str(),ios::out|ios::trunc);
        file.close();
    }
};
