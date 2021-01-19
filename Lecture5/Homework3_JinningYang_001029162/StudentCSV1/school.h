#ifndef SCHOOL_H_INCLUDED
#define SCHOOL_H_INCLUDED
#include "abstractSchool.h"

namespace edu{
namespace neu{
namespace csye6205{
class school:public abstractSchool{
private:
    vector<student>students;
    vector<teacher>teachers;
public:
    school();
    virtual ~school();
    virtual void enrollStudents(student s);
    virtual void showStudents();
    virtual void enrollTeachers(teacher t);
    virtual void showTeachers();
    virtual void demo();
};
}
}
}

#endif // SCHOOL_H_INCLUDED
