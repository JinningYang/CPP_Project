#ifndef ITEMFACTORY_HPP_INCLUDED
#define ITEMFACTORY_HPP_INCLUDED

#pragma once

#include "AbstractItemFactoryAPI.h"
#include "Item.hpp"


#include <string>

namespace edu {
namespace neu {
namespace csye6205 {

class ItemFactory :public AbstractItemFactoryAPI{
public:
  ItemFactory() = delete;
  using type = enum { ITEM, ELECTRONICS, BREAD, LIGHTBREAD };
  static std::unique_ptr<Item> getItem(const std::string name, const double price, const int id,
                       const type t) {
    if (t == ITEM) {
      return std::make_unique<Item>(name, price, id);
    }
    return nullptr;
  }

};

} // namespace csye6205
} // namespace neu
} // namespace edu

#endif // ITEMFACTORY_HPP_INCLUDED
