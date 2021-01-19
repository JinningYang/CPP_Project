#include "person.h"
using namespace std;
namespace edu{
namespace neu{
namespace csye6205{
person::person(){};
person::~person(){};
person::person(int age,string lastName,string firstName,string id,string personType){
    this->age=age;
    this->lastName=lastName;
    this->firstName=firstName;
    this->id=id;
    this->personType=personType;
}
string person::toString(){
    return firstName+" "+lastName+", age "+to_string(age);
}
}
}
}
