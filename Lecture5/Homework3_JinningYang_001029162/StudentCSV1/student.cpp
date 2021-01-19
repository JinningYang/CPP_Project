#include "student.h"
#include <cassert>

namespace edu{
namespace neu{
namespace csye6205{
//template specification to get different value types--double,int,string
template <>
string student::CsvEntry::getAttr<string>(size_t idx) {
    assert(idx < nAttr());
    return l.substr(attributes[idx].first, attributes[idx].second);
}

template <>
int student::CsvEntry::getAttr<int>(size_t idx) {
    return stoi(getAttr<string>(idx));
}

template <>
double student::CsvEntry::getAttr<double>(size_t idx) {
    return stod(getAttr<string>(idx));
}

student::student(){}
student::student(string id,int age,string lastName,string firstName,string studentId,double gpa,string personType){
    this->id=id;
    this->age=age;
    this->lastName=lastName;
    this->firstName=firstName;
    this->studentId=studentId;
    this->gpa=gpa;
    this->personType=personType;
}

student::student(string csvLine) {
    CsvEntry e(csvLine);
    id = e.getAttr<string>(0);
    age = e.getAttr<int>(4);
    lastName = e.getAttr<string>(3);
    firstName = e.getAttr<string>(2);
    studentId = e.getAttr<string>(1);
    gpa = e.getAttr<double>(5);
    personType = e.getAttr<string>(6);
}

student::~student(){};
// Parse a line of CSV into entries.
// Only store the offset of each attributes.
student::CsvEntry::CsvEntry(string s) : l(s) {
    decltype(l.find(',')) posa = 0, posb;
    while (true) {
        posb = l.substr(posa).find(',');
        attributes.emplace_back(make_pair(posa, posb));
        if(posb == string::npos) {
            break;
        }
        posa += posb + 1;
    }
}

//
size_t student::CsvEntry::nAttr() {
    return attributes.size();
}

string student::toString(){
    return id+", "+studentId+", "+firstName+", "+lastName+", "+to_string(age)+", "+to_string(gpa);
}

}
}
}
