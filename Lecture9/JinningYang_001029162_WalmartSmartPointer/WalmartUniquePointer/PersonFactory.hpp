#ifndef PERSONFACTORY_HPP_INCLUDED
#define PERSONFACTORY_HPP_INCLUDED

#include "AbstractPersonFactoryAPI.h"
#include "Person.hpp"
namespace edu {
namespace neu {
namespace csye6205 {
class PersonFactory:public AbstractPersonFactoryAPI{
public:
    PersonFactory()=delete;
    using type =enum{PERSON};
    static std::unique_ptr<Person>getPerson(const std::string firstName, const std::string lastName, const int id,
         const int age,const type t){
         if(t==PERSON){
            return std::make_unique<Person>(firstName,lastName,id,age);
         }
         return nullptr;
    }


};
} // namespace csye6205
} // namespace neu
} // namespace edu

#endif // PERSONFACTORY_HPP_INCLUDED
