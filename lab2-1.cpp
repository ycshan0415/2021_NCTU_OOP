#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Student {
public:
	Student( ) { }
	string generate_address(){
        string _return = "";
        _return += "1001 University Road, Hsinchu, Taiwan 300, ROC, dorm ";
        _return += dormitory + ", (";
        _return += ID + ") ";
        _return += first_name + " " + last_name;
        
        return _return;
    }
    
    void setFirstName(string fn){
        first_name = fn;
    }
    
    void setLastName(string ln){
        last_name = ln;
    }
    
    void setdormitory(string dorm){
        dormitory = dorm;
    }
    
    void setID(string id){
        ID = id;
    }

private:
	string first_name;
    string last_name;
	string dormitory;
	string ID;
};


int main() {
  	Student mStudent;
    string f, l, d, i;
    
    cin >> f >> l >> d >> i;
    mStudent.setFirstName(f);
    mStudent.setLastName(l);
    mStudent.setdormitory(d);
    mStudent.setID(i);
    
  	cout << mStudent.generate_address() << endl;
    return 0;
}