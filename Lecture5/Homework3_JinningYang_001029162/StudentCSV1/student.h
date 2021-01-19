#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include "person.h"
#include <utility>
#include <vector>

namespace edu{
namespace neu{
namespace csye6205{
class student:public person{
private:
    double gpa;
    string studentId;
    class CsvEntry {
    protected:
        vector<pair<size_t, size_t>> attributes;
        string l;
    public:
        CsvEntry(string s);
        template <typename T>
        T getAttr(size_t idx);
        size_t nAttr();
        friend class student;
    };
public:
    student();
    student(string id,int age,string lastName,string firstName,string studentId,double gpa,string personType);
    student(string csvLine);
    virtual ~student();
    string toString();
    friend class CsvEntry;
};
}
}
}

#endif // STUDENT_H_INCLUDED
