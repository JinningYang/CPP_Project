#ifndef ABSTRACTITEMAPI_H_INCLUDED
#define ABSTRACTITEMAPI_H_INCLUDED

#pragma once

#include <functional>
#include <string>

namespace edu {
namespace neu {
namespace csye6205 {

class AbstractItemAPI {
public:
  virtual ~AbstractItemAPI(){};
  virtual std::string info() const = 0;
  virtual const std::string name() const = 0;
  virtual int id() const = 0;
  virtual double price() const = 0;
};
} // namespace csye6205
} // namespace neu
} // namespace edu



#endif // ABSTRACTITEMAPI_H_INCLUDED
