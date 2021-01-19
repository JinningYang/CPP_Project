#pragma once

#include <string>

namespace edu {
namespace neu {
namespace csye6205 {
class AbstractPersonAPI {
public:
  virtual ~AbstractPersonAPI() {}
  virtual std::string info() = 0;
  virtual int id() const = 0;
  virtual int age() const = 0;
  virtual const std::string firstName() const = 0;
  virtual const std::string lastName() const = 0;
};
} // namespace csye6205
} // namespace neu
} // namespace edu
