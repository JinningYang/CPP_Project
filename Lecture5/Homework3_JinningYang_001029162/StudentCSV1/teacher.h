#ifndef TEACHER_H_INCLUDED
#define TEACHER_H_INCLUDED
#include "person.h"

namespace edu{
namespace neu{
namespace csye6205{
class teacher:public person{
private:
    double wage;
public:
    teacher();
    teacher(string id,int age,string lastName,string firstName,string personType,double wage);
    virtual ~teacher();
    string toString();

};
}
}
}


#endif // TEACHER_H_INCLUDED
