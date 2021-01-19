#include "teacher.h"

namespace edu{
namespace neu{
namespace csye6205{
teacher::teacher(){}
teacher::teacher(string id,int age,string lastName,string firstName,string personType,double wage){
    this->id=id;
    this->age=age;
    this->lastName=lastName;
    this->firstName=firstName;
    this->personType=personType;
    this->wage=wage;
}
teacher::~teacher(){};


string teacher::toString(){
    return id+", "+firstName+", "+lastName+", "+to_string(age)+", "+to_string(wage);
}

}
}
}
