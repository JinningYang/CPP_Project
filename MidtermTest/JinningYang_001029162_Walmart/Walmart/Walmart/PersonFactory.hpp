#ifndef PERSONFACTORY_HPP_INCLUDED
#define PERSONFACTORY_HPP_INCLUDED

#include "Person.hpp"
namespace edu {
namespace neu {
namespace csye6205 {
class PersonFactory{
public:
    PersonFactory()=delete;
    using type =enum{PERSON};
    static Person *getPerson(const std::string firstName, const std::string lastName, const int id,
         const int age,const type t){
         if(t==PERSON){
            return new Person(firstName,lastName,id,age);
         }

    }

};

} // namespace csye6205
} // namespace neu
} // namespace edu

#endif // PERSONFACTORY_HPP_INCLUDED
