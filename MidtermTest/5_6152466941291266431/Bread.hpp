#pragma once

#include "Item.hpp"
#include <string>

namespace edu {
namespace neu {
namespace csye6205 {

class Bread : public Item {
private:
  int _calories;

public:
  Bread(const std::string name, const double price, const int id,
        const int calories)
      : Item(name, price, id), _calories(calories) {}
  std::string info() const {
    return Item::info() + ", calories: " + std::to_string(_calories);
  }
};

} // namespace csye6205
} // namespace neu
} // namespace edu