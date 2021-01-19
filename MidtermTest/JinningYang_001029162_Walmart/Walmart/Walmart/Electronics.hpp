#ifndef ELECTRONICS_HPP_INCLUDED
#define ELECTRONICS_HPP_INCLUDED

#pragma once

#include "Item.hpp"

namespace edu {
namespace neu {
namespace csye6205 {

class Electronics : public Item {
public:
  Electronics(const std::string name, const double price, const int id)
      : Item(name, price, id) {}
};

} // namespace csye6205
} // namespace neu
} // namespace edu

#endif // ELECTRONICS_HPP_INCLUDED
