#ifndef ABSTRACTSCHOOL_H_INCLUDED
#define ABSTRACTSCHOOL_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "person.h"
#include "student.h"
#include "teacher.h"
using namespace std;
namespace edu{
namespace neu{
namespace csye6205{
class abstractSchool{
public:
    abstractSchool();
    virtual ~abstractSchool();
    virtual void enrollStudents(student s) = 0;
    virtual void showStudents() = 0;
    virtual void enrollTeachers(teacher t)=0;
    virtual void showTeachers() = 0;
};
}
}
}

#endif // ABSTRACTSCHOOL_H_INCLUDED
