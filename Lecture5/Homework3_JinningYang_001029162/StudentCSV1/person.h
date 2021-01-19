#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;
namespace edu{
namespace neu{
namespace csye6205{
class person{
protected:
    int age;
    string lastName;
    string firstName;
    string id;
    string personType;
public:
    person();
    person(int age,string lastName,string firstName,string id,string personType);
    virtual ~person();
    string toString();
};
}
}
}

#endif // PERSON_H_INCLUDED
