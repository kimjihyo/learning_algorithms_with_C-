#include <iostream>
#include <string>
using namespace std;

class Student {
    public:
        Student(string newName, int newStudentNumber) {
            name = newName;
            studentNumber = newStudentNumber;
        }
        string getName() {
            return name;
        }
        int getStudentNumber() {
            return studentNumber;
        }
        void setName(string name) {
            this->name = name;
        }
        void setStudentNumber(int studentNumber) {
            this->studentNumber = studentNumber;
        }

    private:
        string name;
        int studentNumber;

};

void process_student(Student student) {
    student.setName("Daniel Kim");
    student.setStudentNumber(123);
}

int main() {
    Student me("Jihyo Kim", 10);
    process_student(me);
    cout << me.getName()<< endl;
    cout << me.getStudentNumber() << endl;
    return 0;
}