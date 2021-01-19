#include "school.h"
#include "teacher.h"
#include "fileUtil.h"
#include "student.h"

namespace edu {
namespace neu {
namespace csye6205 {
school::school() {};
school::~school() {};
void school::enrollStudents(student s) {
    students.emplace_back(s);
}
void school::showStudents() {
    for(student s:students) {
        cout<<s.toString()<<endl;
    }
}

void school::enrollTeachers(teacher t) {
    teachers.emplace_back(t);
}
void school::showTeachers() {
    for(teacher t:teachers) {
        cout<<t.toString()<<endl;
    }
}
void school::demo() {
    teacher t1("0020",45,"Pauli","Ernst","Teacher",10023.4);
    enrollTeachers(t1);
    showTeachers();
    FileUtil f("C:\\Users\\kathe\\OneDrive\\Documents\\C++\\Lecture5\\Homework3_JinningYang_001029162\\students.csv");
    auto l = f.nextLine();
    while ((l = f.nextLine()).length()) {
        students.emplace_back(l);
    }
    for (auto &it : students) {
        cout << it.toString() << endl;
    }
}
}
}
}
