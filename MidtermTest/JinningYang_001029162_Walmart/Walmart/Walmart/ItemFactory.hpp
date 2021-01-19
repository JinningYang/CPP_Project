#ifndef ITEMFACTORY_HPP_INCLUDED
#define ITEMFACTORY_HPP_INCLUDED

#pragma once

#include "Bread.hpp"
#include "Electronics.hpp"
#include "Item.hpp"
#include "LightBread.hpp"

#include <string>

namespace edu {
namespace neu {
namespace csye6205 {

class ItemFactory {
public:
  ItemFactory() = delete;
  using type = enum { ITEM, ELECTRONICS, BREAD, LIGHTBREAD };
  static Item *getItem(const std::string name, const double price, const int id,
                       const type t) {
    if (t == ITEM) {
      return new Item(name, price, id);
    }
    if (t == ELECTRONICS) {
      return new Electronics(name, price, id);
    }
    return getItem(name, price, id, 0, t);
  }
  static Bread *getItem(const std::string name, const double price, const int id,
                        const double calories, const type t) {
    if (t == BREAD) {
      return new Bread(name, price, id, calories);
    }
    if (t == LIGHTBREAD) {
      return new LightBread(name, price, id, calories);
    }
    return nullptr;
  }
};

} // namespace csye6205
} // namespace neu
} // namespace edu

#endif // ITEMFACTORY_HPP_INCLUDED
