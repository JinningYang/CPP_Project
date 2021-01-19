#pragma once

#include "Bread.hpp"

namespace edu {
namespace neu {
namespace csye6205 {
class LightBread : public Bread {
public:
  LightBread(const std::string name, const double price, const int id, const int calories)
      : Bread(name, price, id, calories) {}
};
} // namespace csye6205
} // namespace neu
} // namespace edu