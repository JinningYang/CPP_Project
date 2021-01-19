#ifndef PERSON_HPP_INCLUDED
#define PERSON_HPP_INCLUDED

#pragma once

#include "AbstractPersonAPI.h"

#include <string>

namespace edu {
namespace neu {
namespace csye6205 {
class Person : public AbstractPersonAPI {
  std::string _firstName, _lastName;
  int _id, _age;

public:
  Person(const std::string firstName, const std::string lastName, const int id,
         const int age)
      : _firstName(firstName), _lastName(lastName), _id(id), _age(age) {}
  const std::string firstName() const { return _firstName; }
  const std::string lastName() const { return _lastName; }
  int id() const { return _id; }
  int age() const { return _age; }
  std::string info() {
    return "Person #" + std::to_string(_id) + ": " + _firstName + " " +
           _lastName + ", age " + std::to_string(_age);
    }

    virtual int getAge() const{
        return _age;
    }

	virtual void setAge(int age){
        this->_age = age;
	}

	virtual const std::string& getFirstName() const{
        return _firstName;
	}

	virtual void setFirstName(const std::string &firstName){
        this->_firstName = firstName;
	}

	virtual int getId() const{
        return _id;
	}

	virtual void setId(int id){
        this->_id = id;
	}
	virtual const std::string& getLastName() const{
        return _lastName;
    }
	virtual void setLastName(const std::string &lastName){
        this->_lastName = lastName;
	}

};


} // namespace csye6205
} // namespace neu
} // namespace edu

#endif // PERSON_HPP_INCLUDED
