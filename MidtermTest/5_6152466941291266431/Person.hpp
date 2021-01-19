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
};
} // namespace csye6205
} // namespace neu
} // namespace edu