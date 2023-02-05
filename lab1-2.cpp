#include <iostream>
#include <string>

using namespace std;

class Student{
public:
    string name;
    int exam_scores[4];
    void get_minimum_final_score();
    void print_name_and_score();
    int minimum_final_score;
    Student(string);
};

int main() {
    string student_name;
    cin >> student_name;
    Student student(student_name);
    for(int i = 0; i < 3; i++){
        cin >> student.exam_scores[i];
    }
    student.get_minimum_final_score();
    student.print_name_and_score();
    return 0;
}

void Student::get_minimum_final_score(){
    int sum = 0;
    for (int i = 0; i <= 2; i++){
        sum += exam_scores[i];
    }
    minimum_final_score = 240 - sum;
    if (minimum_final_score < 0)
        minimum_final_score = 0;
}

void Student::print_name_and_score(){
    cout << name << ' ' << minimum_final_score;
}

Student::Student(string n){
    name = n;
}